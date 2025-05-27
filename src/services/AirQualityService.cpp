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
using namespace std;
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "AirQualityService.h"
#include "Sensor.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void AirQualityService::Executer()
// Algorithme : Affiche un message simulant l’exécution du service
{
#ifdef MAP
    cout << "Appel à AirQualityService::Executer" << endl;
#endif
    cout << "Analyse de la qualité de l'air en cours..." << endl;
    // Ici on pourrait insérer des appels aux composants métier réels du service
    cout << "Analyse terminée." << endl;
} //----- Fin de Executer

bool AirQualityService::IsEarlier(time_t t1, time_t t2)
{
    return difftime(t1, t2) < 0;
}

int AirQualityService::calculateAirQuality(MeasurementGroup Measurements) {
    int IndexMax=1;
    int AirQualityIndex=0;
            for (int i=0; i<10; i++) {
                if ((Measurements.GetMeasurementO2()>ATMOO3[i]) || (Measurements.GetMeasurementNO2()>ATMONO2[i]) || (Measurements.GetMeasurementSO2()>ATMOSO2[i]) || (Measurements.GetMeasurementP10()>ATMOPM10[i])) {
                    IndexMax++;
                }
            }
            AirQualityIndex = AirQualityIndex + IndexMax;
            return AirQualityIndex;
} 

int AirQualityService::calculateAvgAirQuality(Sensor selectedSensor, time_t beg, time_t end) 
// Algorithme : Affiche un message simulant l’exécution du service
{
    int AirQualityIndex = 0;
    int NbMeasurements = 0;
    for (const Measurement& sensorMeasure : selectedSensor.GetMeasurements()) {
        int IndexMax=1;
        if ((beg==0 && end==0) || (IsEarlier(beg, sensorMeasure.GetTimestamp()) && IsEarlier(sensorMeasure.GetTimestamp(), end))) {
            for (int i=0; i<10; i++) {
                if ((sensorMeasure.GetMeasurementO2()>ATMOO3[i]) || (sensorMeasure.GetMeasurementNO2()>ATMONO2[i]) || (sensorMeasure.GetMeasurementSO2()>ATMOSO2[i]) || (sensorMeasure.GetMeasurementP10()>ATMOPM10[i])) {
                    IndexMax++;
                }
            }
            NbMeasurements = NbMeasurements + 4;
            AirQualityIndex = AirQualityIndex + IndexMax;
        }
    }        
    AirQualityIndex = AirQualityIndex/NbMeasurements;
    return AirQualityIndex;


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
