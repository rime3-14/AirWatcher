#include <iostream>
#include <cassert>
#include <string>
#include "dataAccess/SensorRepository.h"

using namespace std;

int main() {

    cout << "Réalisation des tests unitaires pour la classe <SensorRepository>" << endl;

    SensorRepository sensorRepo;

    // Test getAll()
    vector<Sensor> sensors = sensorRepo.getAll();
    assert(!sensors.empty());
    cout << "Nombre de capteurs chargés : " << sensors.size() << endl;

    // Test getSensorById() sur un capteur existant (prends l'ID du premier capteur)
    string sensorId = "Sensor7"; 
    Sensor s = sensorRepo.getSensorById(sensorId);
    assert(s.getLatitude() == 44);
    assert(s.getLongitude() == float(3.9)); 
    cout << "getSensorById fonctionne pour ID : " << sensorId << endl << endl;

    // Test getSensorsInCircularRadius()
    float centerLat = sensors[0].getLatitude();
    float centerLon = sensors[0].getLongitude();
    float radius = 10; 
    vector<Sensor> nearbySensors = sensorRepo.getSensorsInCircularRadius(centerLat, centerLon, radius);
    assert(!nearbySensors.empty());
    cout << "Nombre de capteurs fiables dans un rayon de " << radius << "  autour du capteur " << sensors[0].getId() << " : "<< nearbySensors.size() <<  endl;

    // Test markSensorAsUnreliable() sur un capteur
    bool success = sensorRepo.markSensorAsUnreliable(sensors[0]);
    cout << "markSensorAsUnreliable retourné : " << (success ? "true" : "false") << endl;
    // Après marquage, le capteur devrait être non fiable
    Sensor updatedSensor = sensorRepo.getSensorById(sensors[0].getId());
    assert(updatedSensor.getReliability() == false);
    cout << "Le capteur est maintenant marqué comme non fiable." << endl << endl; 

    cout << "Tous les tests unitaires pour la classe <SensorRepository> ont été validés." << endl; 
    return EXIT_SUCCESS;
}