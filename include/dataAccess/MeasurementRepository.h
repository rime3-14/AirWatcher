/*************************************************************************
                           MeasurementRepository  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <MeasurementRepository> (fichier MeasurementRepository.h) ----------------
#if ! defined ( MeasurementRepository_H )
#define MeasurementRepository_H

//--------------------------------------------------- Interfaces utilisées
#include <vector> 
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <MeasurementRepository>
// Fait office de DAO et rRécupère les informations voulues sur les capteurs pour les requêtes. 
//------------------------------------------------------------------------

class MeasurementRepository : public Repository
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    vector<Measurement> getAllMeasurementsInTimeRange(List<Sensor> sensors, time_t begin, time_t end); 
    vector<Measurement> getMeasurementsInTimeRangeBySensor(Sensor sensor, time_t begin, time_t end);
    vector<Measurement> getMeasurementsBySensor(Sensor sensor);

//------------------------------------------------- Surcharge d'opérateurs
    MeasurementRepository & operator = ( const MeasurementRepository & unMeasurementRepository );
    // Mode d'emploi :
    //
    // Contrat :

//------------------------------------------------- Getters - Setters

//-------------------------------------------- Constructeurs - destructeur

    MeasurementRepository ( const MeasurementRepository & unMeasurementRepository );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    MeasurementRepository ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    MeasurementRepository ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~MeasurementRepository ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <MeasurementRepository>


#endif // MeasurementRepository_H

