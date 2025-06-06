/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par Bindech Rida
    e-mail               : rida.bindech@gmail.com
*************************************************************************/

//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "sensors/Sensor.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// ----------- Getters -----------

std::string Sensor::getId() const
{
    return id;
}

float Sensor::getLatitude() const
{
    return latitude;
}

float Sensor::getLongitude() const
{
    return longitude;
}

bool Sensor::getReliability() const
{
    return reliability;
}

Measurement* Sensor::getMeasurements() const
{
    return measurements;
}

// ----------- Setters -----------

void Sensor::setId(const std::string& newId)
{
    id = newId;
}

void Sensor::setLatitude(float newLatitude)
{
    latitude = newLatitude;
}

void Sensor::setLongitude(float newLongitude)
{
    longitude = newLongitude;
}

void Sensor::setReliability(bool newReliability)
{
    reliability = newReliability;
}

void Sensor::setMeasurements(Measurement* newMeasurements)
{
    measurements = newMeasurements;
}

//------------------------------------------------- Surcharge d'opérateurs

Sensor& Sensor::operator=(const Sensor& unSensor)
{
    if (this != &unSensor)
    {
        id = unSensor.id;
        latitude = unSensor.latitude;
        longitude = unSensor.longitude;
        reliability = unSensor.reliability;
        measurements = unSensor.measurements;
    }
    return *this;
}


bool Sensor::operator==(const Sensor& unSensor) {
    if(unSensor.id != this.id || unSensor.latitude != this.latitude || unSensor.longitude != this.longitude) {
        return false; 
    } else {
        return true; 
    }
}

std::ostream& operator<<(std::ostream& os, const Sensor& sensor)
{
    os << "Sensor ID: " << sensor.GetId()
       << "\n  Location: (" << std::fixed << std::setprecision(4)
       << sensor.GetLatitude() << ", " << sensor.GetLongitude() << ")"
       << "\n  Reliability: " << (sensor.GetReliability() ? "true" : "false")
       << "\n  Measurements: [";

    const auto& measurements = sensor.GetMeasurements();
    for (size_t i = 0; i < measurements.size(); ++i)
    {
        os << "\n    " << measurements[i];
    }

    if (!measurements.empty()) os << "\n  ";
    os << "]";
    return os;
}

//-------------------------------------------- Constructeurs - destructeur

Sensor::Sensor()
    : id(""), latitude(0.0f), longitude(0.0f), reliability(false), measurements(nullptr)
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de Sensor" << endl;
#endif
}

Sensor::Sensor(const Sensor& unSensor)
    : id(unSensor.id), latitude(unSensor.latitude), longitude(unSensor.longitude),
      reliability(unSensor.reliability), measurements(unSensor.measurements)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de Sensor" << endl;
#endif
}

Sensor::Sensor(std::string unId, float unLatitude, float unLongitude, bool unReliability, Measurement* unMeasurements)
    : id(unId), latitude(unLatitude), longitude(unLongitude),
      reliability(unReliability), measurements(unMeasurements)
{
#ifdef MAP
    cout << "Appel au constructeur paramétré de Sensor" << endl;
#endif
}

Sensor::~Sensor()
{
#ifdef MAP
    cout << "Appel au destructeur de Sensor" << endl;
#endif
}