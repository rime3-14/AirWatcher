#include <iostream>
#include <vector>
#include <ctime>
#include "../include/services/ReliabilityService.h"
#include "../include/models/sensors/Sensor.h"
#include "../include/models/sensors/Measurement.h"
#include "../include/services/Service.h"

using namespace std;

void testAnalyseSensor() {
    cout << "\n--- Test : AnalyseSensor ---" << endl;
    
    ReliabilityService service;
    
    // créer test sensor avec des mesures
    vector<MeasurementGroup> measurements;
    MeasurementGroup mg1;
    mg1.measurementO3.setValue(40);
    mg1.measurementNO2.setValue(60);
    mg1.measurementSO2.setValue(100);
    mg1.measurementPM10.setValue(30);
    measurements.push_back(mg1);
    
    Sensor sensor("TEST_SENSOR", 48.8566, 2.3522, true, measurements);
    
    // Test
    bool result = service.analyseSensor(sensor);
    cout << "Analyse du capteur " << sensor.getId() << " : " << (result ? "Fiable" : "Non fiable") << endl;
    cout << "✅ Test AnalyseSensor terminé." << endl;
}

void testCalculateZScoreDeviationBetween() {
    cout << "\n--- Test : CalculateZScoreDeviationBetween ---" << endl;
    
    ReliabilityService service;
    
    // créer test sensor avec des mesures 
    vector<MeasurementGroup> sensorMeasurements;
    MeasurementGroup mg1;
    mg1.measurementO3.setValue(40);
    mg1.measurementNO2.setValue(60);
    mg1.measurementSO2.setValue(100);
    mg1.measurementPM10.setValue(30);
    sensorMeasurements.push_back(mg1);
    
    Sensor testSensor("TEST_SENSOR", 48.8566, 2.3522, true, sensorMeasurements);
    
    // créer d'autres capteurs pour la comparaison
    vector<Sensor> otherSensors;
    
    // Sensor 1 with similar measurements
    vector<MeasurementGroup> measurements1;
    MeasurementGroup mg2;
    mg2.measurementO3.setValue(42);
    mg2.measurementNO2.setValue(58);
    mg2.measurementSO2.setValue(98);
    mg2.measurementPM10.setValue(32);
    measurements1.push_back(mg2);
    otherSensors.push_back(Sensor("SENSOR_1", 48.8567, 2.3523, true, measurements1));
    
    // Sensor 2 with different measurements
    vector<MeasurementGroup> measurements2;
    MeasurementGroup mg3;
    mg3.measurementO3.setValue(60);
    mg3.measurementNO2.setValue(80);
    mg3.measurementSO2.setValue(120);
    mg3.measurementPM10.setValue(50);
    measurements2.push_back(mg3);
    otherSensors.push_back(Sensor("SENSOR_2", 48.8568, 2.3524, true, measurements2));
    
    // Calcul z-score
    float zScore = service.calculateZScoreDeviationBetween(testSensor, otherSensors);
    cout << "Z-score du capteur " << testSensor.getId() << " : " << zScore << endl;
    
    // Interpreter
    if (abs(zScore) < 2) {
        cout << "Le capteur montre des mesures cohérentes avec les autres capteurs." << endl;
    } else if (abs(zScore) < 3) {
        cout << "Le capteur montre des mesures modérément déviantes." << endl;
    } else {
        cout << "Le capteur montre des mesures fortement déviantes." << endl;
    }
    
    cout << "✅ Test CalculateZScoreDeviationBetween terminé." << endl;
}

void testEmptySensorList() {
    cout << "\n--- Test : EmptySensorList ---" << endl;
    
    ReliabilityService service;
    
    // créer test sensor
    vector<MeasurementGroup> measurements;
    MeasurementGroup mg;
    mg.measurementO3.setValue(40);
    mg.measurementNO2.setValue(60);
    mg.measurementSO2.setValue(100);
    mg.measurementPM10.setValue(30);
    measurements.push_back(mg);
    
    Sensor testSensor("TEST_SENSOR", 48.8566, 2.3522, true, measurements);
    
    // Test with empty sensor list
    vector<Sensor> emptySensors;
    float zScore = service.calculateZScoreDeviationBetween(testSensor, emptySensors);
    cout << "Z-score avec liste vide : " << zScore << endl;
    cout << "✅ Test EmptySensorList terminé." << endl;
}

void testIdenticalMeasurements() {
    cout << "\n--- Test : IdenticalMeasurements ---" << endl;
    
    ReliabilityService service;
    
    // créer test sensor
    vector<MeasurementGroup> measurements;
    MeasurementGroup mg;
    mg.measurementO3.setValue(40);
    mg.measurementNO2.setValue(60);
    mg.measurementSO2.setValue(100);
    mg.measurementPM10.setValue(30);
    measurements.push_back(mg);
    
    Sensor testSensor("TEST_SENSOR", 48.8566, 2.3522, true, measurements);
    
    // créer d'autres capteurs avec des mesures identiques
    vector<Sensor> otherSensors;
    for (int i = 0; i < 3; i++) {
        otherSensors.push_back(Sensor("SENSOR_" + to_string(i), 48.8566 + i*0.0001, 2.3522 + i*0.0001, true, measurements));
    }
    
    float zScore = service.calculateZScoreDeviationBetween(testSensor, otherSensors);
    cout << "Z-score avec mesures identiques : " << zScore << endl;
    cout << "✅ Test IdenticalMeasurements terminé." << endl;
}

int main() {
    cout << "=== Début des tests ReliabilityService ===" << endl;
    
    testAnalyseSensor();
    testCalculateZScoreDeviationBetween();
    testEmptySensorList();
    testIdenticalMeasurements();
    
    cout << "\n=== Tous les tests sont terminés. ===" << endl;
    return 0;
} 