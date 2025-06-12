#ifndef RELIABILITY_SERVICE_H
#define RELIABILITY_SERVICE_H
//--------------------------------------------------- Interfaces utilisées
// (Aucune interface externe n'est utilisée.)
using namespace std;

#include "Service.h"
#include "../models/sensors/Sensor.h"
#include <vector>

class ReliabilityService : public Service
{
public:
    bool analyseSensor(const Sensor& sensor);
    float calculateZScoreDeviationBetween(const Sensor& sensor, const std::vector<Sensor>& otherSensors);
    void Executer() override;
};

#endif 