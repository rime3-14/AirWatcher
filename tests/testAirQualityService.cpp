#include <iostream>
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
    cout << "\n--- Test : IsEarlier ---" << endl;
    AirQualityService service;
    time_t t1 = 1000;
    time_t t2 = 2000;

    bool ok = true;
    if (!service.IsEarlier(t1, t2)) {
        cout << "🔴 IsEarlier(t1, t2) a échoué" << endl;
        ok = false;
    }
    if (service.IsEarlier(t2, t1)) {
        cout << "🔴 IsEarlier(t2, t1) a échoué" << endl;
        ok = false;
    }
    if (ok) cout << "🟢 Test IsEarlier réussi" << endl;
}

void testCalculateAirQuality() {
    cout << "\n--- Test : CalculateAirQuality ---" << endl;
    AirQualityService service;
    MeasurementGroup mg;
    mg.measurementO3.setValue(40);
    mg.measurementNO2.setValue(60);
    mg.measurementSO2.setValue(100);
    mg.measurementPM10.setValue(30);
    int index = service.CalculateAirQuality(mg);

    if (index >= 1) {
        cout << "🟢 Test CalculateAirQuality réussi (index = " << index << ")" << endl;
    } else {
        cout << "🔴 Test CalculateAirQuality échoué (index = " << index << ")" << endl;
    }
}

void testCalculateAvgAirQuality() {
    cout << "\n--- Test : CalculateAvgAirQuality ---" << endl;
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

    if (avg > 0) {
        cout << "🟢 Test CalculateAvgAirQuality réussi (moyenne = " << avg << ")" << endl;
    } else {
        cout << "🔴 Test CalculateAvgAirQuality échoué (moyenne = " << avg << ")" << endl;
    }
}

void testCalculateMeanAirQuality() {
    cout << "\n--- Test : CalculateMeanAirQuality ---" << endl;
    AirQualityService service;
    SensorRepository sensorRepo;

    vector<Sensor> sensors = sensorRepo.getAll();
    if (sensors.empty()) {
        cout << "🔴 Aucun capteur disponible pour le test" << endl;
        return;
    }

    float latitude = sensors[0].getLatitude();
    float longitude = sensors[0].getLongitude();
    int radius = 1000;

    tm timeStructStart = {};
    timeStructStart.tm_year = 2019 - 1900;
    timeStructStart.tm_mon = 0;
    timeStructStart.tm_mday = 1;
    time_t beg = mktime(&timeStructStart);

    tm timeStructEnd = {};
    timeStructEnd.tm_year = 2019 - 1900;
    timeStructEnd.tm_mon = 0;
    timeStructEnd.tm_mday = 3;
    time_t end = mktime(&timeStructEnd);

    float result = service.CalculateMeanAirQuality(latitude, longitude, radius, beg, end);

    cout << "Résultat : " << result << endl;
    if (result >= 0 && result <= 5) {
        cout << "🟢 Test CalculateMeanAirQuality réussi" << endl;
    } else {
        cout << "🔴 Test CalculateMeanAirQuality échoué" << endl;
    }
}

void testCompareSensorAgainstOthers() {
    cout << "\n--- Test : CompareSensorAgainstOthers ---" << endl;

    AirQualityService service;
    SensorRepository sensorRepo;

    vector<Sensor> sensors = sensorRepo.getAll();
    if (sensors.size() < 2) {
        cout << "🔴 Pas assez de capteurs pour comparer" << endl;
        return;
    }

    Sensor sensorRef = sensors[0];

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

    vector<Sensor*> comparison = service.CompareSensorAgainstOthers(sensorRef, beg, end);

    bool ok = true;
    for (Sensor* s : comparison) {
        if (s->getId() == sensorRef.getId()) {
            cout << "🔴 Le capteur a été comparé à lui-même" << endl;
            ok = false;
        }
    }

    if (!comparison.empty() && ok) {
        cout << "🟢 Comparaison réussie avec " << comparison.size() << " capteurs" << endl;
    } else {
        cout << "🔴 Comparaison échouée" << endl;
    }
}

void testSortDescByDifference() {
    cout << "\n--- Test : SortDescByDifference ---" << endl;

    vector<MeasurementGroup> emptyMeasurements;
    Sensor s1("S1", 0.0f, 0.0f, true, emptyMeasurements);
    Sensor s2("S2", 0.0f, 0.0f, true, emptyMeasurements);
    Sensor s3("S3", 0.0f, 0.0f, true, emptyMeasurements);

    vector<Sensor*> sensors = { &s1, &s2, &s3 };
    vector<int> values = { 20, 10, 30 };

    AirQualityService service;
    service.SortDescByDifference(sensors, values);

    if (sensors[0]->getId() == "S3" && sensors[1]->getId() == "S1" && sensors[2]->getId() == "S2") {
        cout << "🟢 Tri décroissant effectué correctement" << endl;
    } else {
        cout << "🔴 Tri incorrect. Ordre obtenu : ";
        for (Sensor* s : sensors) {
            cout << s->getId() << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "=== Début des tests AirQualityService ===" << endl;

    testIsEarlier();
    testCalculateAirQuality();
    testCalculateAvgAirQuality();
    testCalculateMeanAirQuality();
    testCompareSensorAgainstOthers();
    testSortDescByDifference();

    cout << "\n✅ Tous les tests terminés (voir détails ci-dessus)." << endl;
    return 0;
}
