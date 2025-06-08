/*************************************************************************
                           SensorRepository  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <SensorRepository> (fichier SensorRepository.h) ----------------
#if ! defined ( SensorRepository_H )
#define SensorRepository_H

//--------------------------------------------------- Interfaces utilisées
#include <vector> 
#include "dataAccess/Repository.h"
#include "models/sensors/Sensor.h"
#include "models/sensors/Measurement.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <SensorRepository>
// Fait office de DAO et récupère les informations voulues sur les capteurs pour les requêtes. 
//------------------------------------------------------------------------

class SensorRepository : public Repository
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

Sensor& getSensor(const Sensor& sensor);

vector<Sensor> getSensorsInCircularRadius(float centerLatitude, float centerLongitude, float radius); 

vector<Sensor> getAllSensorsExcept(float centerLatitude, float centerLongitude, float radius); 

vector<Sensor> getAll(); 

void markSensorAsUnreliable(Sensor sensor); 

//------------------------------------------------- Surcharge d'opérateurs
    SensorRepository & operator = ( const SensorRepository & unSensorRepository );
    // Mode d'emploi :
    //
    // Contrat :

//------------------------------------------------- Getters - Setters

//-------------------------------------------- Constructeurs - destructeur

    SensorRepository ( const SensorRepository & unSensorRepository );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    SensorRepository ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~SensorRepository ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <SensorRepository>

#endif // SensorRepository_H

