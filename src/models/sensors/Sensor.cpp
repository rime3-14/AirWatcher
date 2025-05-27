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
#include "models/sensors/Sensor.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// ----------- Getters -----------

std::string Sensor::GetId() const
{
    return id;
}

float Sensor::GetLatitude() const
{
    return latitude;
}

float Sensor::GetLongitude() const
{
    return longitude;
}

bool Sensor::GetReliability() const
{
    return reliability;
}

Measurement* Sensor::GetMeasurements() const
{
    return measurements;
}

// ----------- Setters -----------

void Sensor::SetId(const std::string& newId)
{
    id = newId;
}

void Sensor::SetLatitude(float newLatitude)
{
    latitude = newLatitude;
}

void Sensor::SetLongitude(float newLongitude)
{
    longitude = newLongitude;
}

void Sensor::SetReliability(bool newReliability)
{
    reliability = newReliability;
}

void Sensor::SetMeasurements(Measurement* newMeasurements)
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