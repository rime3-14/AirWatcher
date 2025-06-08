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
#include <iostream>
#include <iomanip> // pour setprecision

//------------------------------------------------------ Include personnel
#include "models/sensors/Sensor.h"

using namespace std;

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

vector<MeasurementGroup> Sensor::getMeasurements() const
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

void Sensor::setProvider(const PrivateUser& newProvider)
{
    provider = newProvider;
}

void Sensor::setMeasurements(const vector<MeasurementGroup>& newMeasurements)
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
        provider = unSensor.provider;
        measurements = unSensor.measurements;
    }
    return *this;
}

bool Sensor::operator==(const Sensor& unSensor)
{
    return id == unSensor.id
        && latitude == unSensor.latitude
        && longitude == unSensor.longitude;
}

// ----------- Opérateur d'affichage -----------

std::ostream& operator<<(std::ostream& os, const Sensor& sensor)
{
    os << "Sensor ID: " << sensor.getId()
       << "\n  Location: (" << std::fixed << std::setprecision(4)
       << sensor.getLatitude() << ", " << sensor.getLongitude() << ")"
       << "\n  Reliability: " << (sensor.getReliability() ? "true" : "false")
       << "\n  Measurements: [" << std::endl;

    const auto& measurements = sensor.getMeasurements();
    for (const auto& group : measurements)
    {
        os << "    " << group << std::endl;
    }

    os << "]";
    return os;
}

//-------------------------------------------- Constructeurs - destructeur

Sensor::Sensor()
    : id(""), latitude(0.0f), longitude(0.0f), reliability(false), provider(), measurements()
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de Sensor" << endl;
#endif
}

Sensor::Sensor(const Sensor& unSensor)
    : id(unSensor.id), latitude(unSensor.latitude), longitude(unSensor.longitude),
      reliability(unSensor.reliability), provider(unSensor.provider),
      measurements(unSensor.measurements)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de Sensor" << endl;
#endif
}

Sensor::Sensor(const std::string& unId, float unLatitude, 
    float unLongitude, bool unReliability, const std::vector<MeasurementGroup>& unMeasurements)
    : id(unId), latitude(unLatitude), longitude(unLongitude),
      reliability(unReliability), provider(nullopt), // No provider
      measurements(unMeasurements)
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
