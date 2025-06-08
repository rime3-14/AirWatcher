/*************************************************************************
                           AirCleaner  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <AirCleaner> (fichier AirCleaner.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <math.h>

//------------------------------------------------------ Include personnel
#include "models/sensors/AirCleaner.h"
#include "dataAccess/SensorRepository.h"
#include "services/AirQualityService.h"
#include "utils/Util.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


float AirCleaner::calculateRadiusPurifiedAir() {
// Algorithme : Pour calculer le rayon d'air purifié d'un Air Cleaner, on récupère le niveau de qualité de l'air 
// mesuré par les capteurs aux alentours. 
// On regarde si le niveau s'est amélioré après la période d'activité du Air Cleaner pour chacun d'entre eux, 
// puis on définit la distance avec le capteur le plus éloigné comme le rayon d'impact. 

    // Si le rayon a déjà été calculé auparavant, retourner la valeur 
    if(radius != -1) {
        return radius;
    }

    // Par hypothèse, un AirCleaner ne peut pas avoir un impact sur un rayon > distanceMax. 
    // Choix arbitraire du rayon d'impact maximum d'un AirCleaner
    //float distanceMax = 1000; 
    // Initialisation de la valeur de retour
    float r = 0; 
    /*
    // Récupération des capteurs situés autour du Air Cleaner 
    SensorRepository *sensorRepository = new SensorRepository(); 
    vector<Sensor> sensors = sensorRepository->getSensorsInCircularRadius(latitude, longitude, distanceMax); 

    // Initialisation du service de calcul de qualité de l'air 
    AirQualityService * airQualityService = new AirQualityService();

    // Parcours de tous les capteurs situés autour du Air Cleaner
    for (Sensor s : sensors) {

        float d = calculateDistance(this->latitude, this->longitude, s.getLatitude(), s.getLongitude());

        // Calculs du niveau de qualité de l'air avant et après la période d'activité du Air Cleaner 
        float AQbeforeAirCleaner = airQualityService->CalculateAvgAirQuality(s) 
        float AQafterAirCleaner = CalculateAvgAirQuality(s); 

        // Si on trouve un capteur plus éloigné
        if(aQafterAirCleaner < aQbeforeAirCleaner && d > r) {
            r = d; 
        }
    }
    */
    radius = r; 
    return r; 
}

float AirCleaner::calculateImprovedAirLevel() {
//
    float distanceMax; 

    if(radius != -1) {
        distanceMax = radius; 
    } else {
        distanceMax = 1000; 
    }
    float improvedAirLevel = 0; 

    /*
    int nbCloseSensors = 0; 
    SensorRepository *sensorRepository = new SensorRepository(); 
    MeasurementRepository *measurementRepository = new MeasurementRepository();
    vector<Sensor> sensors = sensorRepository->getSensorsInCircularRadius(latitude, longitude, distanceMax); 

    for (Sensor s : sensors) {
        float d = calculateDistance(latitude, longitude, s.getLatitude(), s.getLongitude());
        float AQbeforeAirCleaner = calculateAirQuality(s, measurementRepository->getMeasurements(s.getId(), 0, 0));  // !!!!!!!!!!!!!!
        float AQafterAirCleaner = calculateAirQuality(s,); 
        if(AQafterAirCleaner < AQbeforeAirCleaner) {
            nbCloseSensors++; 
            improvedAirLevel += aQbeforeAirCleaner-aQafterAirCleaner; 
        }
    }

    improvedAirLevel /= nbCloseSensors; 
    */
    return improvedAirLevel; 
}

//------------------------------------------------- Surcharge d'opérateurs
AirCleaner & AirCleaner::operator = (const AirCleaner & unAirCleaner)
{
    if (this != &unAirCleaner)
    {
        id = unAirCleaner.id;
        latitude = unAirCleaner.latitude;
        longitude = unAirCleaner.longitude;
        radius = unAirCleaner.radius;
        debut = unAirCleaner.debut;
        fin = unAirCleaner.fin;
    }
    return *this;
}

//------------------------------------------------- Getters - Setters

string AirCleaner::getId() const {
    return id; 
}

float AirCleaner::getLatitude() const  {
    return latitude; 
}

float AirCleaner::getLongitude() const {
    return longitude; 
}

float AirCleaner::getRadius() const {
    return radius; 
}


//-------------------------------------------- Constructeurs - destructeur
AirCleaner::AirCleaner (const AirCleaner & unAirCleaner)
: id(unAirCleaner.id),
  latitude(unAirCleaner.latitude),
  longitude(unAirCleaner.longitude),
  radius(unAirCleaner.radius),
  debut(unAirCleaner.debut),
  fin(unAirCleaner.fin)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AirCleaner>" << endl;
#endif
}

AirCleaner::AirCleaner ()
{
#ifdef MAP
    cout << "Appel au constructeur de <AirCleaner>" << endl;
#endif
} 



AirCleaner::AirCleaner (string anId, float lat , float lon, float aRadius) : id(anId), latitude (lat), longitude(lon), radius(aRadius)
{
#ifdef MAP
    cout << "Appel au constructeur de <AirCleaner>" << endl;
#endif
}


AirCleaner::~AirCleaner ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <AirCleaner>" << endl;
#endif
} 

ostream& operator<<(ostream& out, const AirCleaner& aC)
{
    out << "Informations concernant le Air Cleaner " << aC.getId() << " :\n";
    out << "Latitude : " << aC.getLatitude() << "\n";
    out << "Longitude : " << aC.getLongitude() << "\n";
    return out;
}