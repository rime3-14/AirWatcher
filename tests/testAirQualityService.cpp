#include <iostream>
#include <cassert>
#include <vector>
#include <ctime>
#include "../include/services/AirQualityService.h"
#include "../include/models/sensors/Sensor.h"
#include "../include/models/sensors/Measurement.h"
#include "../include/dataAccess/MeasurementRepository.h"
#include "../include/dataAccess/SensorRepository.h"
#include "../include/utils/Util.h"

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

    vector<Sensor> sensors = sensorRepo.getAll();
    assert(!sensors.empty());

    // On prend les coordonnées du premier capteur
    float latitude = sensors[0].getLatitude();
    float longitude = sensors[0].getLongitude();
    int radius = 1000; // en mètres, à adapter selon ta logique métier

    // Définir une période de temps autour du 02/01/2019
    tm timeStructStart = {};
    timeStructStart.tm_year = 2019 - 1900;
    timeStructStart.tm_mon = 0;  // janvier
    timeStructStart.tm_mday = 1;
    time_t beg = mktime(&timeStructStart);

    tm timeStructEnd = {};
    timeStructEnd.tm_year = 2019 - 1900;
    timeStructEnd.tm_mon = 0;  // janvier
    timeStructEnd.tm_mday = 3;
    time_t end = mktime(&timeStructEnd);

    // Appel de la méthode
    float result = service.CalculateMeanAirQuality(latitude, longitude, radius, beg, end);
    cout << "Qualité de l'air moyenne entre le 01/01/2019 et le 03/01/2019 autour du capteur " 
         << sensors[0].getId() << " : " << result << endl;

    // Vérification que le résultat est dans une plage réaliste
    assert(result >= 0 && result <= 5);
}

void testCompareSensorAgainstOthers() {
    cout << "\n--- Test : CompareSensorAgainstOthers ---" << endl;

    AirQualityService service;
    SensorRepository sensorRepo;

    vector<Sensor> sensors = sensorRepo.getAll();
    assert(sensors.size() >= 2);  // il faut au moins 2 capteurs

    Sensor sensorRef = sensors[0];

    // Définir l'intervalle de temps
    tm timeStructBeg = {};
    timeStructBeg.tm_year = 2019 - 1900;
    timeStructBeg.tm_mon = 0;
    timeStructBeg.tm_mday = 2;
    time_t beg = mktime(&timeStructBeg);

    tm timeStructEnd = {};
    timeStructEnd.tm_year = 2019 - 1900;
    timeStructEnd.tm_mon = 0;
    timeStructEnd.tm_mday = 3;
    time_t end = mktime(&timeStructEnd);

    // Appel de la méthode réelle
    vector<Sensor*> comparison = service.CompareSensorAgainstOthers(sensorRef, beg, end);

    cout << "Comparaison du capteur " << sensorRef.getId() << " avec les autres :\n";
    for (Sensor* s : comparison) {
        cout << " -> " << s->getId() << endl;
        assert(s->getId() != sensorRef.getId()); // on ne compare pas à soi-même
    }

    assert(!comparison.empty());
    cout << "✅ Comparaison terminée avec succès." << endl;
}


void testSortDescByDifference() {
    cout << "\n--- Test : SortDescByDifference ---" << endl;

    // Création de capteurs avec le constructeur complet
    std::vector<MeasurementGroup> emptyMeasurements;
    Sensor s1("S1", 0.0f, 0.0f, true, emptyMeasurements);
    Sensor s2("S2", 0.0f, 0.0f, true, emptyMeasurements);
    Sensor s3("S3", 0.0f, 0.0f, true, emptyMeasurements);

    // Vecteur de pointeurs vers capteurs
    std::vector<Sensor*> sensors = { &s1, &s2, &s3 };

    // Valeurs associées
    std::vector<int> values = { 20, 10, 30 }; // S1=20, S2=10, S3=30

    // Appel de la méthode
    AirQualityService service;
    service.SortDescByDifference(sensors, values);

    // Affichage pour vérification visuelle
    cout << "Ordre après tri (croissant attendu selon la fonction actuelle):" << endl;
    for (Sensor* s : sensors) {
        cout << s->getId() << " ";
    }
    cout << endl;

    // Vérifications
    assert(sensors[0]->getId() == "S3"); // 10
    assert(sensors[1]->getId() == "S1"); // 20
    assert(sensors[2]->getId() == "S2"); // 30

    cout << "Tri effectué correctement (décroissant)." << endl;
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