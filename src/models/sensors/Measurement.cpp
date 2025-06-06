/*************************************************************************
                           Measurement  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par Bindech Rida
    e-mail               : rida.bindech@gmail.com
*************************************************************************/

//---------- Réalisation de la classe <Measurement> (fichier Measurement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <string>
#include <iostream>
#include <ctime>

//------------------------------------------------------ Include personnel
#include "sensors/Measurement.h"

//------------------------------------------------------------- Constantes


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

    // ----------- Getters -----------
    
    string Measurement::getUnit() const
    {
        return unit;
    }
    
    string Measurement::getDescription() const
    {
        return description;
    }
    
    float Measurement::getValue() const
    {
        return value;
    }
    
    // ----------- Setters -----------

    
    void Measurement::setUnit(const string& newunit)
    {
        unit = newunit;
    }
    
    void Measurement::setDescription(const string& newDescription)
    {
        description = newDescription;
    }
    
    void Measurement::setValue(float newvalue)
    {
        value = newvalue;
    }
    

//------------------------------------------------- Surcharge d'opérateurs
Measurement & Measurement::operator = ( const Measurement & unMeasurement )
// Algorithme :
//
{
    if (this != &unMeasurement)
    {
        unit = unMeasurement.unit;
        description = unMeasurement.description;
        value = unMeasurement.value;
    }
    return *this;
} //----- Fin de operator =

std::ostream& operator<<(std::ostream& os, const Measurement& m)
{
    os << "Measurement("
       << "ID: " << m.GetId()
       << ", Unit: " << m.Getunit()
       << ", Desc: " << m.GetDescription()
       << ", Value: " << std::fixed << std::setprecision(2) << m.Getvalue()
       << ", Timestamp: " << m.GetTimestamp()
       << ")";
    return os;
}

//-------------------------------------------- Constructeurs - destructeur
Measurement::Measurement() :  unit(""), description(""), value(0.0f)
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur par défaut de Measurement" << endl;
    #endif
    } //----- Fin de Measurement (constructeur par défaut)

Measurement::Measurement ( const Measurement & unMeasurement ) : unit(unMeasurement.unit), description(unMeasurement.description), value(unMeasurement.value)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de Measurement" << endl;
#endif
} //----- Fin de Measurement (constructeur de copie)


Measurement::Measurement (string ununit, string unDescription, float unvalue) : unit(ununit), description(unDescription), value(unvalue)

// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de Measurement" << endl;
#endif
} //----- Fin de Measurement


Measurement::~Measurement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de Measurement" << endl;
#endif
} //----- Fin de ~Measurement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

