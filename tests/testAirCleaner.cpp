#include <iostream>
#include "../include/models/sensors/AirCleaner.h"
#include <cassert>
using namespace std; 

int main() {
    cout << "Réalisation des tests unitaires pour la classe <AirCleaner>" << endl;

    // Test constructeur par défaut
    AirCleaner ac1;
    assert(ac1.getId() == "");
    assert(ac1.getRadius() == -1);  // supposé valeur par défaut si initialisée comme ça
    cout << "Constructeur par défaut OK." << endl;

    // Test constructeur avec paramètres
    string id = "AC123";
    float lat = 48.8566f;
    float lon = 2.3522f;
    time_t debut = 1680000000;
    time_t fin = 1680003600;

    AirCleaner ac2(id, lat, lon, debut, fin);
    assert(ac2.getId() == id);
    assert(ac2.getLatitude() == lat);
    assert(ac2.getLongitude() == lon);
    cout << "Constructeur avec paramètres OK." << endl;

    // Test opérateur égal ==
    AirCleaner ac3(id, lat, lon, debut, fin);
    assert(ac2 == ac3);
    AirCleaner ac4("OtherID", lat, lon, debut, fin);
    assert(!(ac2 == ac4));
    cout << "Opérateur == OK." << endl;

    // Test opérateur = (affectation)
    AirCleaner ac5;
    ac5 = ac2;
    assert(ac5 == ac2);
    cout << "Opérateur = OK." << endl;

    // Test opérateur << (affichage)
    cout << "Affichage AirCleaner via opérateur << :" << endl;
    cout << ac2 << endl;

    cout << "Validation des tests unitaires pour la classe <AirCleaner>." << endl;
    return EXIT_SUCCESS;
}
