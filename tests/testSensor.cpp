#include "models/sensors/Sensor.h"
#include "models/users/PrivateUser.h"
#include "models/sensors/Measurement.h"
#include <iostream>
#include <ctime>
#include <vector>

int main() {
    std::cout << "Début des tests unitaires pour la classe <Sensor>" << std::endl;

    // Création d’un MeasurementGroup
    MeasurementGroup mg;
    mg.timestamp = time(nullptr);
    mg.measurementO3 = Measurement("µg/m³", "Ozone", 12.5f);
    mg.measurementNO2 = Measurement("µg/m³", "Dioxyde d'azote", 34.2f);
    mg.measurementSO2 = Measurement("µg/m³", "Dioxyde de soufre", 20.1f);
    mg.measurementPM10 = Measurement("µg/m³", "Particules PM10", 45.6f);

    std::vector<MeasurementGroup> mgVec = {mg};

    // Création du capteur
    Sensor s("S001", 45.75f, 4.85f, true, mgVec);

    // Tests
    if (s.getId() == "S001") {
        std::cout << "🟢 Test ID capteur réussi" << std::endl;
    } else {
        std::cout << "🔴 Test ID capteur échoué" << std::endl;
    }

    if (s.getLatitude() == 45.75f) {
        std::cout << "🟢 Test latitude réussi" << std::endl;
    } else {
        std::cout << "🔴 Test latitude échoué" << std::endl;
    }

    if (s.getLongitude() == 4.85f) {
        std::cout << "🟢 Test longitude réussi" << std::endl;
    } else {
        std::cout << "🔴 Test longitude échoué" << std::endl;
    }

    if (s.getReliability()) {
        std::cout << "🟢 Test fiabilité capteur réussi" << std::endl;
    } else {
        std::cout << "🔴 Test fiabilité capteur échoué" << std::endl;
    }

    if (s.getMeasurements().size() == 1) {
        std::cout << "🟢 Test mesure(s) associée(s) réussi" << std::endl;
    } else {
        std::cout << "🔴 Test mesure(s) associée(s) échoué" << std::endl;
    }

    std::cout << "Affichage du capteur : " << std::endl;
    std::cout << s << std::endl;

    std::cout << "Fin des tests unitaires pour la classe <Sensor>" << std::endl;
    return 0;
}
