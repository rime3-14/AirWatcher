/*************************************************************************
                           MeasurementRepository  
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par Ashley DUONG
    e-mail               : ashley.duong@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <MeasurementRepository> (fichier MeasurementRepository.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <math.h>
#include <ctime>
#include "dataAccess/MeasurementRepository.h"
#include "dataAccess/CSVLoader.h"
using namespace std;

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

vector<MeasurementGroup> MeasurementRepository::getAllMeasurementsInTimeRange(vector<Sensor> sensors, time_t begin, time_t end) {
    vector<MeasurementGroup> res; 
    for(const Sensor &s : sensors) {
        vector<MeasurementGroup> measurementGroupBySensor = getMeasurementsInTimeRangeBySensor(s, begin, end);
        if(!measurementGroupBySensor.empty()) {
            res.insert(res.end(), measurementGroupBySensor.begin(), measurementGroupBySensor.end()); 
        }
    } return res; 
    
}
vector<MeasurementGroup> MeasurementRepository::getMeasurementsInTimeRangeBySensor(const Sensor & sensor, time_t begin, time_t end) {
    vector<MeasurementGroup> res;
    vector<MeasurementGroup> measurementGroupBySensor = sensor.getMeasurements();
        for(MeasurementGroup & measurementG : measurementGroupBySensor) {
            if(measurementG.timestamp >= begin && measurementG.timestamp <= end) {
                res.push_back(measurementG); 
            } else if(measurementG.timestamp > end) {
                break; 
            }
    } return res; 
}

vector<MeasurementGroup> MeasurementRepository::getAllMeasurementsBefore(vector<Sensor> sensors, time_t timestamp) {
    vector<MeasurementGroup> res; 
    for(const Sensor &s : sensors) {
        vector<MeasurementGroup> measurementGroupBySensor = getMeasurementsBySensorBefore(s, timestamp);
        if(!measurementGroupBySensor.empty()) {
            res.insert(res.end(), measurementGroupBySensor.begin(), measurementGroupBySensor.end()); 
        }
    } return res; 
 
}

vector<MeasurementGroup> MeasurementRepository::getMeasurementsBySensorBefore(const Sensor & sensor, time_t timestamp) {
    vector<MeasurementGroup> res;
    vector<MeasurementGroup> measurementGroupBySensor = sensor.getMeasurements();
        for(MeasurementGroup & measurementG : measurementGroupBySensor) {
            if(measurementG.timestamp <= timestamp) {
                res.push_back(measurementG); 
            } else {
                break; 
            }
    } return res;  
}

vector<MeasurementGroup> MeasurementRepository::getAllMeasurementsAfter(vector<Sensor> sensors, time_t timestamp) {
    vector<MeasurementGroup> res; 
    for(const Sensor &s : sensors) {
        vector<MeasurementGroup> measurementGroupBySensor = getMeasurementsBySensorAfter(s, timestamp);
        if(!measurementGroupBySensor.empty()) {
            res.insert(res.end(), measurementGroupBySensor.begin(), measurementGroupBySensor.end()); 
        }
    } return res; 
}

vector<MeasurementGroup> MeasurementRepository::getMeasurementsBySensorAfter(const Sensor & sensor, time_t timestamp){
    vector<MeasurementGroup> res;
    vector<MeasurementGroup> measurementGroupBySensor = sensor.getMeasurements();
        for(MeasurementGroup & measurementG : measurementGroupBySensor) {
            if(measurementG.timestamp >= timestamp) {
                res.push_back(measurementG); 
            } 
    } return res; 
}

vector<MeasurementGroup> MeasurementRepository::getMeasurementsBySensor(const Sensor & sensor) {
    return sensor.getMeasurements(); 
}

//------------------------------------------------- Surcharge d'opérateurs

//------------------------------------------------- Getters - Setters

//-------------------------------------------- Constructeurs - destructeur
MeasurementRepository::MeasurementRepository ( const MeasurementRepository & unMeasurementRepository )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <MeasurementRepository>" << endl;
#endif
} 

MeasurementRepository::MeasurementRepository ()
{
#ifdef MAP
    cout << "Appel au constructeur de <MeasurementRepository>" << endl;
#endif
} 

MeasurementRepository::~MeasurementRepository ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <MeasurementRepository>" << endl;
#endif
} 
