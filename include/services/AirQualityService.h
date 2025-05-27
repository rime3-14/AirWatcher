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
#include "Service.h"
#include <string>

//------------------------------------------------------------- Constantes
int ATMOO3[] = {29, 54, 79, 104, 129, 149, 179, 209, 239};
int ATMOSO2[] = {39, 79, 119, 159, 199, 249, 299, 399, 499};
int ATMONO2[] = {29, 54, 84, 109, 134, 164, 199, 274, 399};
int ATMOPM10[] = {6, 13, 20, 27, 34, 41, 49, 64, 79};


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

    virtual void Executer() override;
    // Mode d'emploi :
    //  Exécute le service d’analyse de qualité de l’air.
    // Contrat :
    //  Doit être appelée via un objet concret.

    bool IsEarlier(time_t t1, time_t t2);

    int AirQualityService::calculateAirQuality(MeasurementGroup Measurements);

    int calculateAvgAirQuality(Sensor selectedSensor, time_t beg, time_t end);

//-------------------------------------------- Constructeurs - destructeur
    AirQualityService();
    // Mode d'emploi :
    //  Constructeur par défaut.

    virtual ~AirQualityService();
    // Mode d'emploi :
    //  Destructeur virtuel.

};

#endif // AIRQUALITYSERVICE_H