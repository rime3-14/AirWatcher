/*************************************************************************
                           MeasurementRepository  
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par Ashley DUONG
    e-mail               : ashley.duong@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <MeasurementRepository> (fichier MeasurementRepository.h) ----------------
#if ! defined ( MeasurementRepository_H )
#define MeasurementRepository_H

#include "models/sensors/Sensor.h"
#include "models/sensors/Measurement.h"

//--------------------------------------------------- Interfaces utilisées
#include <vector> 
using namespace std; 
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <MeasurementRepository>
// Fait office de DAO et rRécupère les informations voulues sur les 
// mesures effectuées par les capteurs utiles aux requêtes. 
//------------------------------------------------------------------------

class MeasurementRepository 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    vector<MeasurementGroup> getAllMeasurementsInTimeRange(vector<Sensor> sensors, time_t begin, time_t end);

    vector<MeasurementGroup> getMeasurementsInTimeRangeBySensor(const Sensor & sensor, time_t begin, time_t end);

    vector<MeasurementGroup> getAllMeasurementsBefore(vector<Sensor> sensors, time_t timestamp);

    vector<MeasurementGroup> getMeasurementsBySensorBefore(const Sensor & sensor, time_t timestamp);

    vector<MeasurementGroup> getAllMeasurementsAfter(vector<Sensor> sensors, time_t timestamp);

    vector<MeasurementGroup> getMeasurementsBySensorAfter(const Sensor & sensor, time_t timestamp);

    vector<MeasurementGroup> getMeasurementsBySensor(const Sensor& sensor);

//------------------------------------------------- Surcharge d'opérateurs
//------------------------------------------------- Getters - Setters

//-------------------------------------------- Constructeurs - destructeur

    MeasurementRepository ( const MeasurementRepository & unMeasurementRepository );

    MeasurementRepository ();

    ~MeasurementRepository ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <MeasurementRepository>


#endif // MeasurementRepository_H

