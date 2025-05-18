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
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Measurement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

    // ----------- Getters -----------

    std::string Measurement::GetId() const
    {
        return id;
    }
    
    std::string Measurement::Getunit() const
    {
        return unit;
    }
    
    std::string Measurement::GetDescription() const
    {
        return description;
    }
    
    float Measurement::Getvalue() const
    {
        return value;
    }
    
    std::string Measurement::GetTimestamp() const
    {
        return timestamp;
    }
    

    // ----------- Setters -----------

    void Measurement::SetId(const std::string& newId)
    {
        id = newId;
    }
    
    void Measurement::Setunit(const std::string& newunit)
    {
        unit = newunit;
    }
    
    void Measurement::SetDescription(const std::string& newDescription)
    {
        description = newDescription;
    }
    
    void Measurement::Setvalue(float newvalue)
    {
        value = newvalue;
    }
    
    void Measurement::SetTimestamp(const std::string& newTimestamp)
    {
        timestamp = newTimestamp;
    }


//------------------------------------------------- Surcharge d'opérateurs
Measurement & Measurement::operator = ( const Measurement & unMeasurement )
// Algorithme :
//
{
    if (this != &unMeasurement)
    {
        id = unMeasurement.id;
        unit = unMeasurement.unit;
        description = unMeasurement.description;
        value = unMeasurement.value;
        timestamp = unMeasurement.timestamp;
    }
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Measurement::Measurement() : id(""), unit(""), description(""), value(0.0f), timestamp("")
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur par défaut de Measurement" << endl;
    #endif
    } //----- Fin de Measurement (constructeur par défaut)

Measurement::Measurement ( const Measurement & unMeasurement ) : id(unMeasurement.id), unit(unMeasurement.unit), description(unMeasurement.description), value(unMeasurement.value), timestamp(unMeasurement.timestamp)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de Measurement" << endl;
#endif
} //----- Fin de Measurement (constructeur de copie)


Measurement::Measurement (std::string unId, std::string ununit, std::string unDescription, float unvalue, std::string unTimestamp) : id(unId), unit(ununit), description(unDescription), value(unvalue), timestamp(unTimestamp)

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

