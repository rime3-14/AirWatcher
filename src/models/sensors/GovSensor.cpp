/*************************************************************************
                           GovSensor  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par Bindech Rida
    e-mail               : rida.bindech@gmail.com
*************************************************************************/

//---------- Réalisation de la classe <GovSensor> (fichier GovSensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "models/sensors/GovSensor.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs
GovSensor& GovSensor::operator=(const GovSensor& unGovSensor)
// Algorithme :
//
{
    if (this != &unGovSensor)
    {
        Sensor::operator=(unGovSensor);
    }
    return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
GovSensor::GovSensor()
    : Sensor()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de GovSensor" << endl;
#endif
} //----- Fin de GovSensor

GovSensor::GovSensor(const GovSensor& other)
    : Sensor(other)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de GovSensor" << endl;
#endif
} //----- Fin de GovSensor (copie)

GovSensor::GovSensor(std::string id, float latitude, float longitude, bool reliability, Measurement* measurements)
    : Sensor(id, latitude, longitude, reliability, measurements)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur paramétré de GovSensor" << endl;
#endif
} //----- Fin de GovSensor

GovSensor::~GovSensor()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de GovSensor" << endl;
#endif
} //----- Fin de ~GovSensor

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
