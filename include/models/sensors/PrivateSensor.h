/*************************************************************************
                           Measurement  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par Bindech Rida
    e-mail               : rida.bindech@gmail.com
*************************************************************************/

//---------- Interface de la classe <PrivateSensor> (fichier PrivateSensor.h) ----------------
#if ! defined ( PrivateSensor_H )
#define PrivateSensor_H


//--------------------------------------------------- Interfaces utilisées
#include "Sensor.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------

class PrivateSensor : public Sensor
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
    PrivateSensor & operator = ( const PrivateSensor & unPrivateSensor );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur

    PrivateSensor();
    // Mode d'emploi :
    //
    // Contrat :
    //

    PrivateSensor(const PrivateSensor& other);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    PrivateSensor(std::string id, float latitude, float longitude, bool reliability, Measurement* measurements);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~PrivateSensor();
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
