/*************************************************************************
                           SensorRepository  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <SensorRepository> (fichier SensorRepository.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <math.h>
#include "dataAccess/Repository.h"
#include "dataAccess/SensorRepository.h"
#include "dataAccess/CSVLoader.h"
#include "utils/Util.h"
using namespace std;

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Sensor & SensorRepository::getSensor(Sensor sensor) {
    CSVLoader * csvLoader = new CSVLoader(); 
    vector<Sensor> & allSensors = csvLoader->getSensors(); 
    
}

vector<Sensor> SensorRepository::getAll() {
    CSVLoader * csvLoader = new CSVLoader(); 
    vector<Sensor> & allSensors = csvLoader->getSensors(); 
    vector<Sensor> res; 

    for (Sensor s : allSensors) {
        if (s.getReliability() == true) {
            res.push_back(s); 
        }
    }

    return res; 
}


vector<Sensor> SensorRepository::getSensorsInCircularRadius(float centerLatitude, float centerLongitude, float radius) {
        CSVLoader * csvLoader = new CSVLoader(); 
        vector<Sensor> allSensors = csvLoader->getSensors(); 
        vector<Sensor> res; 

        for (Sensor s : allSensors) {
            float distance = calculateDistance(centerLatitude, centerLongitude, s.getLatitude, s.getLongitude); 
            if (s.getReliability == true && distance <= radius) {
                res.push_back(s); 
            }
        }

        return res; 
}

vector<Sensor> SensorRepository::getAllSensorsExcept(const Sensor & sensor) {
        CSVLoader * csvLoader = new CSVLoader(); 
        vector<Sensor> allSensors = csvLoader->getSensors(); 
        vector<Sensor> res; 

        for (Sensor s : sensors) {
            if (s.getReliability == true && sensor != s) {
                    res.push_back(s);                 
            }
        }

        return res; 
}

void SensorRepository::markSensorAsUnreliable(Sensor sensor) {
    CSVLoader * csvLoader = new CSVLoader(); 
    vector<Sensor> & allSensors = csvLoader->getSensors(); 
    for(Sensor & s : sensors) {
        if(sensor == s) {
            s.setReliability(false);
            // si le capteur appartient au gouvernement, on marque seulement le capteur comme non fiable 
            if(sensor.getProvider() == null) {

            } else {
                // si le capteur appartient à un privateProvider, on parcourt les 
            }
             
            break; 
        }
    }
    
}

//------------------------------------------------- Surcharge d'opérateurs
SensorRepository & SensorRepository::operator = ( const SensorRepository & unSensorRepository )
// Algorithme :
//
{

} 

//------------------------------------------------- Getters - Setters

//-------------------------------------------- Constructeurs - destructeur
SensorRepository::SensorRepository ( const SensorRepository & unSensorRepository )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <SensorRepository>" << endl;
#endif
} 

SensorRepository::SensorRepository ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <SensorRepository>" << endl;
#endif
} 

SensorRepository::~SensorRepository ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <SensorRepository>" << endl;
#endif
} 
