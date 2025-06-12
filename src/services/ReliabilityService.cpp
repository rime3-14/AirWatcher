#include <iostream>    
#include <cstring>     
#include <cmath>
#include <numeric>

using namespace std;

#include "../../include/services/reliabilityService.h"

void ReliabilityService::Executer() {
    cout << "Exécution du service d'analyse de fiabilité des capteurs." << endl;
}

bool ReliabilityService::analyseSensor(const Sensor& sensor) {
    // Analyse le capteur pour déterminer sa fiabilité
    return true; 
}

float ReliabilityService::calculateZScoreDeviationBetween(const Sensor& sensor, const std::vector<Sensor>& otherSensors) {
    if (otherSensors.empty()) {
        return 0.0f; // Pas de capteurs pour comparer
    }

    // calculer la moyenne des mesures des autres capteurs 
    float sum = 0.0f;
    int totalMeasurements = 0;
    for(const auto& otherSensor : otherSensors) {
        for(const auto& group : otherSensor.getMeasurements()) {
            sum += group.measurementO3.getValue() + 
                   group.measurementNO2.getValue() + 
                   group.measurementSO2.getValue() + 
                   group.measurementPM10.getValue();
            totalMeasurements += 4; // 4 types de mesures par groupe
        }
    }
    float mean = sum / totalMeasurements;

    // calculer l'ecart type des mesures des autres capteurs 
    float sq_sum = 0.0f;
    for (const auto& otherSensor : otherSensors) {
        for (const auto& group : otherSensor.getMeasurements()) {
            float diffO3 = group.measurementO3.getValue() - mean;
            float diffNO2 = group.measurementNO2.getValue() - mean;
            float diffSO2 = group.measurementSO2.getValue() - mean;
            float diffPM10 = group.measurementPM10.getValue() - mean;
            
            sq_sum += diffO3 * diffO3 + 
                     diffNO2 * diffNO2 + 
                     diffSO2 * diffSO2 + 
                     diffPM10 * diffPM10;
        }
    }
    float stddev = std::sqrt(sq_sum / totalMeasurements);

    // calculer le z-score pour le capteur
    float sensorSum = 0.0f;
    int sensorTotalMeasurements = 0;
    for(const auto& group : sensor.getMeasurements()) {
        sensorSum += group.measurementO3.getValue() + 
                    group.measurementNO2.getValue() + 
                    group.measurementSO2.getValue() + 
                    group.measurementPM10.getValue();
        sensorTotalMeasurements += 4;
    }
    float sensorMean = sensorSum / sensorTotalMeasurements;

    if (stddev == 0) {
        return 0.0f; // Écart type nul
    }

    return (sensorMean - mean) / stddev; // z-score
}