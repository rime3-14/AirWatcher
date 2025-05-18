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
#include <string>
#include <math.h>
using namespace std;

//------------------------------------------------------ Include personnel
#include "AirCleaner.h"
//#include "SensorRepository.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

float calculateDistance(float centerLat, float centerLong, float latitude, float longitude) {
// Retourne la distance entre un centre et un point en degrés (pour l'instant).
    float distanceEuclidienneDegre  = sqrt ((latitude-centerLat)*(latitude-centerLat) + (longitude - centerLong)*(longitude - centerLong)); 
    return distanceEuclidienneDegre; 
}

float AirCleaner::calculateRadiusPurifiedAir() {
// Algorithme : Pour calculer le rayon d'air purifié d'un Air Cleaner, on récupère le niveau de qualité de l'air mesuré par les capteurs aux alentours. On regarde si le niveau s'est amélioré après la période d'activité du Air Cleaner pour chacun d'entre eux, puis on définit la distance avec le capteur le plus éloigné comme le rayon d'impact. 

    // Si le rayon a déjà été calculé auparavant, retourner la valeur 
        if(radius != -1) {
        return radius;
    }

    // Par hypothèse, un AirCleaner ne peut pas avoir un impact sur un rayon > distanceMax. 
    // Choix arbitraire du rayon d'impact maximum d'un AirCleaner
    float distanceMax = 1000; 
    // Initialisation de la valeur de retour
    float r = 0; 

    // Récupération des capteurs situés autour du Air Cleaner 
    SensorRepository sensorRepository = new SensorRepository(); 
    vector<Sensor> sensors = sensorRepository.getSensorsInCircularRadius(latitude, longitude, distanceMax); 

    for s in sensors {

        float d = calculateDistance(this.latitude, this.longitude, s.getLatitude(), s.getLongitude());

        // Calculs du niveau de qualité de l'air avant et après la période d'activité du Air Cleaner 
        float AQbeforeAirCleaner = calculateAirQuality(s, ); 
        float AQafterAirCleaner = calculateAirQuality(s,); 

        // Si on trouve un capteur plus éloigné
        if(AQafterAirCleaner < AQbeforeAirCleaner && d > r) {
            r = d; 
        }
    }
    
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
    int nbCloseSensors = 0; 
    SensorRepository sensorRepository = new SensorRepository(); 
    vector<Sensor> sensors = sensorRepository.getSensorsInCircularRadius(latitude, longitude, distanceMax); 

    for s in sensors {
        float d = calculateDistance(latitude, longitude, s.getLatitude(), s.getLongitude());
        float AQbeforeAirCleaner = calculateAirQuality(s, ); 
        float AQafterAirCleaner = calculateAirQuality(s,); 
        if(AQafterAirCleaner < AQbeforeAirCleaner) {
            nbCloseSensors++; 
            improvedAirLevel += AQbeforeAirCleaner-AQafterAirCleaner; 
        }
    }

    improvedAirLevel /= nbCloseSensors; 
    return improvedAirLevel; 
}

//------------------------------------------------- Surcharge d'opérateurs
AirCleaner & AirCleaner::operator = ( const AirCleaner & unAirCleaner )
// Algorithme :
//
{

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
AirCleaner::AirCleaner ( const AirCleaner & unAirCleaner )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AirCleaner>" << endl;
#endif
} 

AirCleaner::AirCleaner ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AirCleaner>" << endl;
#endif
} 



AirCleaner::AirCleaner (string anId, float lat , float lon, float aRadius) : id(anId), latitude (lat), longitude(lon), radius(aRadius)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AirCleaner>" << endl;
    this.id = id; 
    this.latitude = la; 
    this.longitude = lo;
    this.radius = -1; 
#endif
} 


AirCleaner::~AirCleaner ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AirCleaner>" << endl;
#endif
} 
