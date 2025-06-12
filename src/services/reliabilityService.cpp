#include <iostream>    
#include <cstring>     
#include <cmath>
#include <numeric>

using namespace std;

#include "services/ReliabilityService.h"


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
    for(const auto& otherSensor : otherSensors) {
        sum += std::accumulate(otherSensor.getMeasurements().begin(), otherSensor.getMeasurements().end(), 0.0f, [](float acc, const Measurement& m) {return acc+m.getValue();});
    }
    float mean = sum / otherSensors.size(); 



    // calculer l'ecart type des mesures des autres capteurs 
    float sq_sum = 0.0f;
    for (const auto& otherSensor : otherSensors) {
        for (const auto& measurement : otherSensor.getMeasurements()) {
            float diff = measurement.getValue() - mean;
            sq_sum += diff * diff; 
        }
    }
    float stddev = std::sqrt(sq_sum / (otherSensors.size()*otherSensors[0].getMeasurements().size()));

    // calculer le z-score pour le capteur
    float sensorSum = std::accumulate(sensor.getMeasurements().begin(), sensor.getMeasurements().end(), 0.0f, [](float acc, const Measurement& m) {return acc +m.getValue();});
    float sensorMean = sensorSum/sensor.getMeasurements().size();

    if (stddev == 0) {
        return 0.0f; // Écart type nul
    }

    return (sensorMean - mean) / stddev; // z-score
}