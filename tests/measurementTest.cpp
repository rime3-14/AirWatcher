#include <iostream>
#include "../include/models/sensors/Measurement.h"
#include <cassert>
using namespace std; 

int main() {
    
    cout << "Réalisation des tests unitaires pour la classe <Measurement>" << endl; 
    // Construction par défaut
    cout << ".";
    Measurement m;
    assert(m.getUnit() == "");
    assert(m.getDescription() == "");
    assert(m.getValue() == 0.0f);
    cout << "."; 
    // Construction paramétrée
    Measurement m2("µg/m3", "concentration d'ozone", 50);
    assert(m2.getUnit() == "µg/m3");
    assert(m2.getDescription() == "concentration d'ozone");
    assert(m2.getValue() == 50);
    cout << ".";
    // Setter
    m2.setValue(60);
    assert(m2.getValue() == 60);
    cout << ".";
    // Surcharge =
    Measurement m3;
    m3 = m2;
    assert(m3.getUnit() == "µg/m3"); 
    assert(m3.getDescription() == "concentration d'ozone"); 
    assert(m3.getValue() == 60); 
    cout << "." << endl; 
    cout << "Tous les tests unitaires pour la classe <Measurement> ont été validés." << endl; 

    cout << "Réalisation des tests unitaires pour Struct <MeasurementGroup>" << endl; 
    Measurement m4 = Measurement("µg/m3", "concentration de NO2", 30);
    Measurement m5 = Measurement("µg/m3", "concentration de SO2", 20);
    Measurement m6 = Measurement("µg/m3", "concentration de P10", 15);
    MeasurementGroup mg;
    mg.measurementNO2 = m4; 
    mg.measurementSO = m5;
    mg.measurementP10 = m6;
    mg.measurementO3 = m2;
    cout << mg << endl; 
    cout << ".";

    return EXIT_SUCCESS; 
}
