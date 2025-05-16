/*************************************************************************
                           PrivateSensor  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par Bindech Rida
    e-mail               : rida.bindech@gmail.com
*************************************************************************/

//---------- Réalisation de la classe <PrivateSensor> (fichier PrivateSensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "PrivateSensor.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs
PrivateSensor& PrivateSensor::operator=(const PrivateSensor& unPrivateSensor)
// Algorithme :
//
{
    if (this != &unPrivateSensor)
    {
        Sensor::operator=(unPrivateSensor);
    }
    return *this;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
PrivateSensor::PrivateSensor()
    : Sensor()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de PrivateSensor" << endl;
#endif
} //----- Fin de PrivateSensor

PrivateSensor::PrivateSensor(const PrivateSensor& other)
    : Sensor(other)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de PrivateSensor" << endl;
#endif
} //----- Fin de PrivateSensor (copie)

PrivateSensor::PrivateSensor(std::string id, float latitude, float longitude, bool reliability, Measurement* measurements)
    : Sensor(id, latitude, longitude, reliability, measurements)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur paramétré de PrivateSensor" << endl;
#endif
} //----- Fin de PrivateSensor

PrivateSensor::~PrivateSensor()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de PrivateSensor" << endl;
#endif
} //----- Fin de ~PrivateSensor

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


