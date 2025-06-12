/*************************************************************************
                           AirQualityService  -  service d'analyse de qualité de l'air
                             -------------------
    début                : 26/05/2025
    copyright            : (C) 2025 par Bindech Rida
    e-mail               : rida.bindech@gmail.com
*************************************************************************/

//---------- Réalisation de la classe <AirQualityService> (fichier AirQualityService.h) ------------

#if ! defined ( AIRQUALITYSERVICE_H )
#define AIRQUALITYSERVICE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

#include "Service.h"
#include "models/sensors/Sensor.h"
#include "models/sensors/Measurement.h"
//------------------------------------------------------------- Constantes
extern int ATMOO3[9];
extern int ATMOSO2[9];
extern int ATMONO2[9];
extern int ATMOPM10[9];


//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AirQualityService>
//
// Fournit un service concret d’analyse de la qualité de l’air. Hérite de
// la classe abstraite Service et implémente la méthode Executer.
//------------------------------------------------------------------------

class AirQualityService : public Service
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques

    bool IsEarlier(time_t t1, time_t t2);

    int CalculateAirQuality(MeasurementGroup Measurements);

    float CalculateAvgAirQuality(const std::vector<MeasurementGroup>& measurements);

    float CalculateMeanAirQuality(float centerLatitude, float centerLongitude, int radius, time_t beg, time_t end);

    std::vector<Sensor*> CompareSensorAgainstOthers(Sensor sensor, time_t beg, time_t end);

    void SortDescByDifference(std::vector<Sensor*>& sensors, const std::vector<int>& values);

    void Executer() override; 

//-------------------------------------------- Constructeurs - destructeur
    AirQualityService();
    // Mode d'emploi :
    //  Constructeur par défaut.

    virtual ~AirQualityService();
    // Mode d'emploi :
    //  Destructeur virtuel.

};

#endif // AIRQUALITYSERVICE_H