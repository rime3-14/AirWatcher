/*************************************************************************
                           SensorRepository  
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par Ashley DUONG    
    e-mail               : ashley.duong@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <SensorRepository> (fichier SensorRepository.h) ----------------
#if ! defined ( SensorRepository_H )
#define SensorRepository_H

//--------------------------------------------------- Interfaces utilisées
#include <vector> 
#include "models/sensors/Sensor.h"
#include "models/sensors/Measurement.h"
#include "dataAccess/UserRepository.h"
#include "dataAccess/CSVLoader.h"
#include "models/users/PrivateUser.h"
#include "utils/Util.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <SensorRepository>
// Fait office de DAO et récupère les informations voulues sur les capteurs
// pour les requêtes. 
//------------------------------------------------------------------------

class SensorRepository  
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

Sensor getSensorById(string sensorId);

Sensor *  getSensor(const Sensor & sensor); 

vector<Sensor> getSensorsInCircularRadius(float centerLatitude, float centerLongitude, float radius); 

vector<Sensor> getAllSensorsExcept(Sensor &sensor); 

vector<Sensor> getAll() const; 

bool markSensorAsUnreliable(Sensor & sensor); 

//------------------------------------------------- Surcharge d'opérateurs

//------------------------------------------------- Getters - Setters

//-------------------------------------------- Constructeurs - destructeur

    SensorRepository ( const SensorRepository & unSensorRepository );

    SensorRepository ( );

    ~SensorRepository ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <SensorRepository>

#endif // SensorRepository_H

