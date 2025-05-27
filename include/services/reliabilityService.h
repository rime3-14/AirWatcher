#ifndef RELIABILITY_SERVICE_H
#define RELIABILITY_SERVICE_H
//--------------------------------------------------- Interfaces utilisées
// (Aucune interface externe n'est utilisée.)
using namespace std;

#include "include/services/service.h"
#include "include/models/sensors/Sensor.h"
#include <vector>

class reliabilityService : public Service
{
    bool analyseSensor(const Sensor& sensor);
    float calculateZScoreDeviationBetween(const Sensor& sensor, const std::vector<Sensor>& otherSensors);
};

#endif 