#include <iostream>
#include <ctime>
#include "models/sensors/Measurement.h"

int main() {
    Measurement m("µg/m³", "Dioxyde d'azote", 34.2f);

    std::cout << "Test affichage : " << m << std::endl;

    // Test des getters
    std::cout << "Unit: " << m.getUnit() << std::endl;
    std::cout << "Description: " << m.getDescription() << std::endl;
    std::cout << "Value: " << m.getValue() << std::endl;

    // Test du setter
    m.setValue(55.0f);
    std::cout << "Nouveau m: " << m << std::endl;

    MeasurementGroup group;
    group.timestamp = time(nullptr);
    group.measurementO3 = Measurement("µg/m³", "Ozone", 12.5f);
    group.measurementNO2 = Measurement("µg/m³", "Dioxyde d'azote", 34.2f);
    group.measurementSO2 = Measurement("µg/m³", "Dioxyde de soufre", 20.1f);
    group.measurementP10 = Measurement("µg/m³", "Particules PM10", 45.6f);

    std::cout << group << std::endl;
    return 0;
}