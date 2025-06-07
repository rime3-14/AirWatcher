#include "models/sensors/Sensor.h"
#include "models/users/PrivateUser.h"
#include "models/sensors/Measurement.h"  // <-- important
#include <iostream>
#include <ctime>

int main() {
    MeasurementGroup mg;
    mg.timestamp = time(nullptr);
    mg.measurementO3 = Measurement("µg/m³", "Ozone", 12.5f);
    mg.measurementNO2 = Measurement("µg/m³", "Dioxyde d'azote", 34.2f);
    mg.measurementSO2 = Measurement("µg/m³", "Dioxyde de soufre", 20.1f);
    mg.measurementPM10 = Measurement("µg/m³", "Particules PM10", 45.6f);

    std::vector<MeasurementGroup> mgVec = {mg};
    PrivateUser userPrivate;

    Sensor s("S001", 45.75f, 4.85f, true, userPrivate, mgVec);

    std::cout << s << std::endl;
    return 0;
}