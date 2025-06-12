#include <iostream> 
#include "../include/models/sensors/Measurement.h"

using namespace std;

int main() {
    cout << "Réalisation des tests unitaires pour la classe <Measurement>" << endl;

    // Construction par défaut
    cout << ".";
    Measurement m;
    if (m.getUnit() != "") 
        cout << "🔴 Le test sur getUnit() (constructeur par défaut) a échoué" << endl;
    if (m.getDescription() != "") 
        cout << "🔴 Le test sur getDescription() (constructeur par défaut) a échoué" << endl;
    if (m.getValue() != 0.0f) 
        cout << "🔴 Le test sur getValue() (constructeur par défaut) a échoué" << endl;

    cout << ".";

    // Construction paramétrée
    Measurement m2("µg/m3", "concentration d'ozone", 50);
    if (m2.getUnit() != "µg/m3") 
        cout << "🔴 Le test sur getUnit() (constructeur paramétré) a échoué" << endl;
    if (m2.getDescription() != "concentration d'ozone") 
        cout << "🔴 Le test sur getDescription() (constructeur paramétré) a échoué" << endl;
    if (m2.getValue() != 50) 
        cout << "🔴 Le test sur getValue() (constructeur paramétré) a échoué" << endl;

    cout << ".";

    // Setter
    m2.setValue(60);
    if (m2.getValue() != 60) 
        cout << "🔴 Le test sur setValue() a échoué" << endl;

    cout << ".";

    // Surcharge =
    Measurement m3;
    m3 = m2;
    if (m3.getUnit() != "µg/m3") 
        cout << "🔴 Le test sur getUnit() (opérateur =) a échoué" << endl;
    if (m3.getDescription() != "concentration d'ozone") 
        cout << "🔴 Le test sur getDescription() (opérateur =) a échoué" << endl;
    if (m3.getValue() != 60) 
        cout << "🔴 Le test sur getValue() (opérateur =) a échoué" << endl;

    cout << "." << endl;
    cout << "🟢 Les tests de la classe <Measurement> ont été réalisés avec succès." << endl << endl;


    cout << "Réalisation des tests unitaires pour la struct <MeasurementGroup>" << endl;

    Measurement m4("µg/m3", "concentration de NO2", 30);
    Measurement m5("µg/m3", "concentration de SO2", 20);
    Measurement m6("µg/m3", "concentration de P10", 15);
    MeasurementGroup mg;
    mg.measurementNO2 = m4;
    mg.measurementSO2 = m5;
    mg.measurementPM10 = m6;
    mg.measurementO3 = m2;

    cout << mg << endl;
    cout << "🟢 Le test de la struct <MeasurementGroup> a été réalisé avec succès." << endl;

    return EXIT_SUCCESS;
}

