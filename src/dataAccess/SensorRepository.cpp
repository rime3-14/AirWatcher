/*************************************************************************
                           SensorRepository  
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par Ashley DUONG
    e-mail               : ashley.duong@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <SensorRepository> (fichier SensorRepository.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <math.h>
#include <optional>
#include "dataAccess/Repository.h"
#include "dataAccess/SensorRepository.h"
#include "dataAccess/UserRepository.h"
#include "dataAccess/CSVLoader.h"
#include "models/users/PrivateUser.h"
#include "utils/Util.h"
using namespace std;

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Sensor SensorRepository::getSensorById(string sensorId) {
    CSVLoader& csvLoader = CSVLoader::Instance();
    vector<Sensor> allSensors = csvLoader.getSensors(); 
    for (Sensor s : allSensors) {
        if(s.getId() == sensorId) {
            return s; 
        }
    }
    return Sensor(); 
}

Sensor * SensorRepository::getSensor(const Sensor & sensor) {
    CSVLoader& csvLoader = CSVLoader::Instance();
    vector<Sensor> allSensors = csvLoader.getSensors(); 
    for (Sensor &s : allSensors) {
        if(s == sensor) {
            return &s; 
        }
    }
    return nullptr; 
}

vector<Sensor> SensorRepository::getAll() const {
    CSVLoader& csvLoader = CSVLoader::Instance();
    return csvLoader.getSensors();
}


vector<Sensor> SensorRepository::getSensorsInCircularRadius(float centerLatitude, float centerLongitude, float radius) {
        CSVLoader& csvLoader = CSVLoader::Instance();
        vector<Sensor> allSensors = csvLoader.getSensors(); 
        vector<Sensor> res; 

        for (Sensor s : allSensors) {
            float distance = calculateDistance(centerLatitude, centerLongitude, s.getLatitude(), s.getLongitude()); 
            if (s.getReliability() == true && distance <= radius) {
                res.push_back(s); 
            }
        }

        return res; 
}

vector<Sensor> SensorRepository::getAllSensorsExcept(Sensor & sensor) {
        CSVLoader& csvLoader = CSVLoader::Instance();
        vector<Sensor> allSensors = csvLoader.getSensors(); 
        vector<Sensor> res; 

        for (Sensor s : allSensors) {
            if (s.getReliability() == true && !(sensor == s)) {
                    res.push_back(s);                 
            }
        }

        return res; 
}

bool SensorRepository::markSensorAsUnreliable(Sensor & sensor) {
    CSVLoader& csvLoader = CSVLoader::Instance();
    vector<Sensor> & allSensors = csvLoader.getSensors(); 
    for(Sensor & s : allSensors) {
        if(sensor == s) {
            s.setReliability(false);
            // si le capteur appartient au gouvernement, on marque seulement le capteur comme non fiable, sinon:  
            if(sensor.hasProvider()) {
                UserRepository userRepository; 
                if(userRepository.markPrivateUserAsUnreliable(sensor.getProvider())) {
                    return true; 
                } else {
                    return false; 
                }
            } else {
                return true; 
            }
        }
    } return false; // Capteur non trouvé 
    
}

//------------------------------------------------- Surcharge d'opérateurs

//------------------------------------------------- Getters - Setters

//-------------------------------------------- Constructeurs - destructeur
SensorRepository::SensorRepository ( const SensorRepository & unSensorRepository )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <SensorRepository>" << endl;
#endif
} 

SensorRepository::SensorRepository ()
{
#ifdef MAP
    cout << "Appel au constructeur de <SensorRepository>" << endl;
#endif
} 

SensorRepository::~SensorRepository ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <SensorRepository>" << endl;
#endif
} 
