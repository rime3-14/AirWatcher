#include <iostream>
#include <cassert>
#include <vector>
#include <ctime>
#include "services/AirQualityService.h"
#include "models/sensors/Sensor.h"
#include "models/sensors/Measurement.h"
#include "dataAccess/MeasurementRepository.h"
#include "dataAccess/SensorRepository.h"
#include "utils/Util.h"

using namespace std;

void testIsEarlier() {
    AirQualityService service;
    time_t t1 = 1000;
    time_t t2 = 2000;
    assert(service.IsEarlier(t1, t2));
    assert(!service.IsEarlier(t2, t1));
    cout << "testIsEarlier passed.\n";
}

void testCalculateAirQuality() {
    AirQualityService service;
    MeasurementGroup mg;
    mg.measurementO3.setValue(40);
    mg.measurementNO2.setValue(60);
    mg.measurementSO2.setValue(100);
    mg.measurementPM10.setValue(30);
    int index = service.CalculateAirQuality(mg);
    assert(index >= 1); // dépend des seuils
    cout << "testCalculateAirQuality passed.\n";
}

void testCalculateAvgAirQuality() {
    AirQualityService service;
    vector<MeasurementGroup> mgs(2);

    mgs[0].measurementO3.setValue(50);
    mgs[0].measurementNO2.setValue(50);
    mgs[0].measurementSO2.setValue(50);
    mgs[0].measurementPM10.setValue(10);

    mgs[1].measurementO3.setValue(70);
    mgs[1].measurementNO2.setValue(80);
    mgs[1].measurementSO2.setValue(60);
    mgs[1].measurementPM10.setValue(20);

    float avg = service.CalculateAvgAirQuality(mgs);
    assert(avg > 0);
    cout << "testCalculateAvgAirQuality passed.\n";
}

void testCalculateMeanAirQuality() {
    AirQualityService service;
    SensorRepository sensorRepo;
    MeasurementRepository measureRepo;

    vector<Sensor> sensors = sensorRepo.getAll();
    assert(!sensors.empty());

    tm timeStruct = {};
    timeStruct.tm_year = 2019 - 1900;
    timeStruct.tm_mon = 0;  // janvier
    timeStruct.tm_mday = 2;
    time_t timestamp = mktime(&timeStruct);

    // Méthode testée
    float result = service.CalculateMeanAirQuality(sensors[0], timestamp);
    cout << "Air quality moyenne du capteur " << sensors[0].getId() << " à la date du 02/01/2019 : " << result << endl;

    assert(result >= 0 && result <= 5); // Selon ton barème de qualité de l'air
}

void testCompareSensorAgainstOthers() {
    AirQualityService service;
    SensorRepository sensorRepo;

    vector<Sensor> sensors = sensorRepo.getAll();
    assert(sensors.size() >= 10);

    tm timeStruct = {};
    timeStruct.tm_year = 2019 - 1900;
    timeStruct.tm_mon = 0;
    timeStruct.tm_mday = 2;
    time_t timestamp = mktime(&timeStruct);

    vector<pair<string, float>> comparison = service.CompareSensorAgainstOthers(sensors[0], sensors, timestamp);
    cout << "Comparaison du capteur " << sensors[0].getId() << " avec les autres à la date du 02/01/2019 : " << endl;

    for (const auto& [id, diff] : comparison) {
        cout << " -> " << id << " : " << diff << endl;
        assert(diff >= 0); // Une différence absolue est toujours positive
    }

    assert(!comparison.empty());
}

void testSortDescByDifference() {
    AirQualityService service;

    vector<pair<string, float>> diffs = {
        {"Sensor1", 1.0},
        {"Sensor2", 3.5},
        {"Sensor3", 2.0}
    };

    vector<pair<string, float>> sorted = service.SortDescByDifference(diffs);

    assert(sorted[0].second >= sorted[1].second);
    assert(sorted[1].second >= sorted[2].second);
    cout << "Tri décroissant des différences : OK" << endl;
}

int main() {
    cout << "=== Début des tests AirQualityService ===" << endl;
    
    testIsEarlier();
    testCalculateAirQuality();
    testCalculateAvgAirQuality();
    testCalculateMeanAirQuality();
    testCompareSensorAgainstOthers(); 
    testSortDescByDifference(); 

    cout << "=== Tous les tests de base sont passés. ===" << endl;
    return 0;
}