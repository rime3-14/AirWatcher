#include <iostream>
#include <cassert>
#include <vector>
#include <ctime>
#include "dataAccess/MeasurementRepository.h"
#include "dataAccess/SensorRepository.h"
#include "models/sensors/Sensor.h"
#include "models/sensors/Measurement.h"
#include "dataAccess/CSVLoader.h"
#include "utils/Util.h"

using namespace std;


int main() {
    cout << "Réalisation des tests unitaires pour la classe <MeasurementRepository>" << endl; 

    MeasurementRepository repo;
    SensorRepository sensorRepo; 
    vector<Sensor> sensors = sensorRepo.getAll(); 
    assert(sensors.size() == 100); 
    cout << "Nombre de capteurs récupérés : " << sensors.size() << endl; 

    // ------------------------------
    // Test getMeasurementsBySensor
    vector<MeasurementGroup> mS1 = repo.getMeasurementsBySensor(sensors[0]);
    cout << "Nombre de groupes de mesures mesurées par le capteur "<< sensors[0].getId() << " : "<< mS1.size() << endl;

    // ------------------------------
    // Test getMeasurementsBySensorBefore

    tm timeStruct1 = {};
    timeStruct1.tm_year = 2018 - 1900; 
    timeStruct1.tm_mon = 8;          
    timeStruct1.tm_mday = 9;           
    timeStruct1.tm_hour = 0;
    timeStruct1.tm_min = 0;
    timeStruct1.tm_sec = 0;

    time_t timestamp1 = std::mktime(&timeStruct1);

    cout << "Date pour le before : "; displayDate(timestamp1); 

    vector<MeasurementGroup> before = repo.getMeasurementsBySensorBefore(sensors[0], timestamp1);
    assert(before.size() == 0); 
    cout << "Nombre de groupes de mesures mesurées par le capteur "<< sensors[0].getId() << " avant le 09/08/2018 : " << before.size() << endl;

    // ------------------------------
    // Test getMeasurementsBySensorAfter
    tm timeStruct2 = {};
    timeStruct2.tm_year = 2025 - 1900; 
    timeStruct2.tm_mon = 8;          
    timeStruct2.tm_mday = 9;           
    timeStruct2.tm_hour = 0;
    timeStruct2.tm_min = 0;
    timeStruct2.tm_sec = 0;

    time_t timestamp2 = std::mktime(&timeStruct2);
    cout << "Date pour le after : "; displayDate(timestamp2); 
    vector<MeasurementGroup> after = repo.getMeasurementsBySensorAfter(sensors[0], timestamp2);
    //assert(after.size() == 0); 
    cout << "Nombre de groupes de mesures mesurées par le capteur "<< sensors[0].getId() << " après le 09/08/2025 : " << after.size() << endl;

    // ------------------------------
    // Test getMeasurementsInTimeRangeBySensor

    tm timeStruct3_1 = {};
    timeStruct3_1.tm_year = 2019 - 1900; 
    timeStruct3_1.tm_mon = 1;          
    timeStruct3_1.tm_mday = 1;           
    timeStruct3_1.tm_hour = 0;
    timeStruct3_1.tm_min = 0;
    timeStruct3_1.tm_sec = 0;

    time_t timestamp3_1 = std::mktime(&timeStruct3_1);

    tm timeStruct3_2 = {};
    timeStruct3_2.tm_year = 2019 - 1900; 
    timeStruct3_2.tm_mon = 1;          
    timeStruct3_2.tm_mday = 3;           
    timeStruct3_2.tm_hour = 0;
    timeStruct3_2.tm_min = 0;
    timeStruct3_2.tm_sec = 0;

    time_t timestamp3_2 = std::mktime(&timeStruct3_2);

    vector<MeasurementGroup> range = repo.getMeasurementsInTimeRangeBySensor(sensors[0], timestamp3_1, timestamp3_2);
    // assert(range.size() == 3); 
    cout << "Nombre de groupes de mesures mesurées par le capteur "<< sensors[0].getId() << " entre le 01/01/2019  et le 03/01/2019: " << range.size() << endl;

    // ------------------------------
    // Test getAllMeasurementsBefore
    tm timeStruct4_1 = {};
    timeStruct4_1.tm_year = 2019 - 1900; 
    timeStruct4_1.tm_mon = 5;          
    timeStruct4_1.tm_mday = 1;           
    timeStruct4_1.tm_hour = 0;
    timeStruct4_1.tm_min = 0;
    timeStruct4_1.tm_sec = 0;

    time_t timestamp4_1 = std::mktime(&timeStruct4_1);

    vector<MeasurementGroup> allBefore = repo.getAllMeasurementsBefore(sensors, timestamp4_1);
    cout << "Nombre de groupes de mesures mesurées avant le : " << allBefore.size() << endl; 

    // ------------------------------
    // Test getAllMeasurementsAfter
    tm timeStruct4_2 = {};
    timeStruct4_2.tm_year = 2019 - 1900; 
    timeStruct4_2.tm_mon = 7;          
    timeStruct4_2.tm_mday = 3;           
    timeStruct4_2.tm_hour = 0;
    timeStruct4_2.tm_min = 0;
    timeStruct4_2.tm_sec = 0;

    time_t timestamp4_2 = std::mktime(&timeStruct4_2);
    vector<MeasurementGroup> allAfter = repo.getAllMeasurementsAfter(sensors, timestamp4_2);
    cout << "Nombre de groupes de mesures mesurées après le : " << allAfter.size() << endl; 

    // ------------------------------
    // Test getAllMeasurementsInTimeRange
    vector<MeasurementGroup> allInRange = repo.getAllMeasurementsInTimeRange(sensors, timestamp4_1, timestamp4_2);
    cout << "Nombre de groupes de mesures mesurées entre le : " << allInRange.size() << endl; 

    cout << "Nombre de groupes de mesures au total en additionnant les trois résultats précédents " << allInRange.size()+allBefore.size()+allAfter.size() << endl; 
    assert(allInRange.size() + allBefore.size() + allAfter.size() >= 36500); 

    cout << "Tous les tests unitaires pour la classe <MeasurementRepository> ont été validés." << endl; 
    return 0;
}