using namespace std;
#include <iostream>    
#include <cstring>     
#include <cmath>
#include <numeric>

#include "include/services/reliabilityService.h"

bool reliabilityService::analyseSensor(const Sensor& sensor) {
    // Analyse le capteur pour déterminer sa fiabilité
    return true; 
}

float reliabilityService::calculateZScoreDeviationBetween(const Sensor& sensor, const std::vector<Sensor>& otherSensors) {
    if (otherSensors.empty()) {
        return 0.0f; // Pas de capteurs pour comparer
    }

    // calculer la moyenne des mesures des autres capteurs 
    float sum = 0.0f;
    for(const auto& otherSensor : otherSensors) {
        sum += std::accumulate(otherSensor.GetMeasurements().begin(), otherSensor.GetMeasurements().end(), 0.0f, [](float acc, const Measurement& m) {return acc+m.Getvalue();});
    }
    float mean = sum / otherSensors.size(); 



    // calculer l'ecart type des mesures des autres capteurs 
    float sq_sum = 0.0f;
    for (const auto& otherSensor : otherSensors) {
        for (const auto& measurement : otherSensor.GetMeasurements()) {
            float diff = measurement.Getvalue() - mean;
            sq_sum += diff * diff; 
        }
    }
    float stddev = std::sqrt(sq_sum / (otherSensors.size()*otherSensors[0].GetMeasurements().size()));

    // calculer le z-score pour le capteur 
    float sensorSum = std::accumulate(sensor.GetMeasurements().begin(), sensor.GetMeasurements().end(), 0.0f, [](float acc, const Measurement& m) {return acc +m.Getvalue();});
    float sensorMean = sensorSum/sensor.GetMeasurements().size();
    
    if (stddev == 0) {
        return 0.0f; // Écart type nul
    }

    return (sensorMean - mean) / stddev; // z-score
}