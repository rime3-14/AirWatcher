/*************************************************************************
                           MeasurementRepository  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <MeasurementRepository> (fichier MeasurementRepository.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <math.h>
#include <ctime>
using namespace std;

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

vector<Measurement> MeasurementRepository::getAllMeasurementsInTimeRange(vector<Sensor> sensors, time_t begin, time_t end) {
    CSVLoader *csvLoader = new CSVLoader(); 
    vector<Sensor> & allSensors = csvLoader->getSensors(); 
    vector<Measurement> res; 
    for(Sensor s in allSensors) {
        measurements.push_back(s.getMeasurements)
    }

    
}
vector<Measurement> MeasurementRepository::getMeasurementsInTimeRangeBySensor(Sensor sensor, time_t begin, time_t end);
vector<Measurement> MeasurementRepository::getMeasurementsBySensor(Sensor sensor);

//------------------------------------------------- Surcharge d'opérateurs
MeasurementRepository & MeasurementRepository::operator = ( const MeasurementRepository & unMeasurementRepository )
// Algorithme :
//
{

} 

//------------------------------------------------- Getters - Setters

//-------------------------------------------- Constructeurs - destructeur
MeasurementRepository::MeasurementRepository ( const MeasurementRepository & unMeasurementRepository )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <MeasurementRepository>" << endl;
#endif
} 

MeasurementRepository::MeasurementRepository ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <MeasurementRepository>" << endl;
#endif
} 

MeasurementRepository::~MeasurementRepository ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <MeasurementRepository>" << endl;
#endif
} 
