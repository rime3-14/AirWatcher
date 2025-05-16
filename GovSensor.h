/*************************************************************************
                           Measurement  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par Bindech Rida
    e-mail               : rida.bindech@gmail.com
*************************************************************************/

//---------- Interface de la classe <GovSensor> (fichier GovSensor.h) ----------------
#if ! defined ( GOVSENSOR_H )
#define GOVSENSOR_H


//--------------------------------------------------- Interfaces utilisées
#include "Sensor.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------

class GovSensor : public Sensor
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    GovSensor & operator = ( const GovSensor & unGovSensor );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur

    GovSensor();
    // Mode d'emploi :
    //
    // Contrat :
    //

    GovSensor(const GovSensor& other);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    GovSensor(std::string id, float latitude, float longitude, bool reliability, Measurement* measurements);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~GovSensor();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // GOUVSENSOR_H