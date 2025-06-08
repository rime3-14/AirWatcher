/*************************************************************************
                           AirQualityService  -  Service concret
                             -------------------
    début                : 26/05/2025
    copyright            : (C) 2025 par Bindech Rida
    e-mail               : rida.bindech@gmail.com
*************************************************************************/

//---------- Réalisation de la classe <AirQualityService> (fichier AirQualityService.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>  // pour sqrt et abs

using namespace std;
//------------------------------------------------------ Include personnel
#include "services/AirQualityService.h"
#include "models/sensors/Sensor.h"
#include "dataAccess/MeasurementRepository.h"
#include "dataAccess/SensorRepository.h"
#include "dataAccess/UserRepository.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool AirQualityService::IsEarlier(time_t t1, time_t t2)
{
    return difftime(t1, t2) < 0;
}

int AirQualityService::CalculateAirQuality(MeasurementGroup Measurements) 
// Algorithme : Calcule la moyenne de qualité d'air d'un groupe de mesures donné
{
    int IndexMax=1;
    int AirQualityIndex=0;
            for (int i=0; i<10; i++) {
                if ((Measurements.measurementO3.getValue()>ATMOO3[i]) || (Measurements.measurementNO2.getValue()>ATMONO2[i]) || (Measurements.measurementSO2.getValue()>ATMOSO2[i]) || (Measurements.measurementPM10.getValue()>ATMOPM10[i])) {
                    IndexMax++;
                }
            }
            AirQualityIndex = AirQualityIndex + IndexMax;
            return AirQualityIndex;
} 

float AirQualityService::CalculateAvgAirQuality(const std::vector<MeasurementGroup>& measurements)
// Algorithme : Calcule la moyenne de qualité d'air d'un capteur sur une période donnée
{
    float totalIndex = 0.0f;
    int totalMeasurements = 0;

    for (const MeasurementGroup& measurementGroup : measurements) {
        int indexMax = CalculateAirQuality(measurementGroup);
        totalIndex += indexMax;
        totalMeasurements=totalMeasurements + 4; 
    }

    if (totalMeasurements == 0) return 0.0f; // éviter division par zéro

    return totalIndex / totalMeasurements;
}

float AirQualityService::CalculateMeanAirQuality(float centerLatitude, float centerLongitude, int radius, time_t beg, time_t end)
// Algorithme : Calcule la moyenne de qualité d'air sur une zone circulaire donnée sur une période donnée
{
    SensorRepository sensorRepository;
    std::vector<Sensor*> sensors = sensorRepository.GetSensorsInCircularRadius(centerLatitude, centerLongitude, radius);

    MeasurementRepository measurementRepository;
    std::vector<MeasurementGroup> measurements = measurementRepository.GetAllMeasurementsInTimeRange(sensors, beg, end);

    float meanAirQuality = CalculateAvgAirQuality(measurements);
    return meanAirQuality;
}

void AirQualityService::SortDescByDifference(std::vector<Sensor*>& sensors, const std::vector<int>& values)
{
    if (sensors.size() != values.size())
        throw std::invalid_argument("Les vecteurs doivent avoir la même taille");

    // Associer chaque sensor* à sa valeur correspondante
    std::vector<std::pair<int, Sensor*>> paired;
    for (size_t i = 0; i < sensors.size(); ++i)
    {
        paired.push_back(std::make_pair(values[i], sensors[i]));
    }

    // Trier les paires par la valeur (croissant)
    std::sort(paired.begin(), paired.end(),
        [](const std::pair<int, Sensor*>& a, const std::pair<int, Sensor*>& b)
        {
            return a.first < b.first;
        });

    // Réécrire le vecteur `sensors` trié
    for (size_t i = 0; i < sensors.size(); ++i)
    {
        sensors[i] = paired[i].second;
    }
}


float CompareSensorAgainstOthers(Sensor sensor, time_t beg, time_t end) 
{
    MeasurementRepository measurementRepository;
    std::vector<MeasurementGroup> measurements = measurementRepository.GetMeasurementsInTimeRangeBySensor(sensor, beg, end);

    float meanAirQuality = CalculateAvgAirQuality(measurements);
    return meanAirQuality;

    SensorRepository sensorRepository;
    std::vector<Sensor*> otherSensors = sensorRepository.GetAllSensorsExcept(sensor);
    std::vector<int> diffs;

    for (const Sensor& otherSensor : otherSensors)
    {
        std::vector<MeasurementGroup> otherMeasurements = measurementRepository.GetMeasurementsInTimeRangeBySensor(otherSensor, beg, end);
        float otherMeanAirQuality = CalculateAvgAirQuality(otherMeasurements);
        int diff = std::abs(static_cast<int>(otherMeanAirQuality - MeanAirQuality));
        diffs.push_back(diff);
    }
    SortDescByDifference(otherSensors, diffs);
    return otherSensors;

}

void AirQualityService::Executer()
{
    // Exemple basique, à adapter selon ce que tu veux que le service fasse
    std::cout << "Exécution du service d’analyse de la qualité de l’air." << std::endl;

    // Appel éventuel à d'autres méthodes d'analyse...
}


//-------------------------------------------- Constructeurs - destructeur
AirQualityService::AirQualityService()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de AirQualityService" << endl;
#endif
} //----- Fin de AirQualityService

AirQualityService::~AirQualityService()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de AirQualityService" << endl;
#endif
} //----- Fin de ~AirQualityService

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
