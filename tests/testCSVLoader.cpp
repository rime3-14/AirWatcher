#include <iostream>
#include "dataAccess/CSVLoader.h"
#include <cassert>
using namespace std; 

int main() {
    cout << "Réalisation des tests unitaires pour la classe <CSVLoader>" << endl; 

    // ============================================================================================================================================
    // Test de chargement des capteurs
    CSVLoader& loader = CSVLoader::Instance();
    const vector<Sensor>& sensors = loader.getSensors();
    assert(!sensors.empty());
    cout << "Capteurs chargés avec succès : " << sensors.size() << " capteurs." << endl;
    // Affichage des capteurs pour vérification
    /*
    for (const auto& sensor : sensors) {
        cout << "Capteur ID: " << sensor.getId()
             << ", Latitude: " << sensor.getLatitude()
             << ", Longitude: " << sensor.getLongitude()
             << ", Fiabilité: " << (sensor.getReliability() ? "Oui" : "Non") << endl;
    }
    */

    // ============================================================================================================================================
    // Test de chargement des utilisateurs
    const vector<PrivateUser>& users = loader.getUsers();
    assert(!users.empty());
    cout << "Utilisateurs chargés avec succès : " << users.size() << " utilisateurs." << endl;
    // Affichage des utilisateurs pour vérification
    /*
    for (const auto& user : users) {
        cout << "Utilisateur ID: " << user.getId()
             << ", Points: " << user.getPoints()
             << ", Fiabilité: " << (user.isReliable() ? "Oui" : "Non") << endl;
        cout << "Capteurs associés : ";
        for (const auto& sensorId : user.getSensorsId()) {
            cout << sensorId << " ";
        }
        cout << endl;
    }
    */

    // ============================================================================================================================================
    // Test de chargement des purificateurs d'air
    const vector<AirCleaner>& airCleaners = loader.getAirCleaners();
    assert(!airCleaners.empty());
    cout << "Purificateurs d'air chargés avec succès : " << airCleaners.size() << " purificateurs." << endl;
    // Affichage des purificateurs d'air pour vérification
    /*
    for (const auto& airCleaner : airCleaners) {
        cout << airCleaner << endl;
    }
    */

    // ============================================================================================================================================
    // Test de chargement des fournisseurs de purificateurs d'air
    const vector<AirCleanerProviderUser>& providers = loader.getProviders();
    assert(!providers.empty());
    cout << "Fournisseurs de purificateurs d'air chargés avec succès : " << providers.size() << " fournisseurs." << endl;
    // Affichage des fournisseurs pour vérification
    /* 
    for (const auto& provider : providers) {
        cout << "Fournisseur ID: " << provider.getId() << endl;
        provider.showAirCleaners();
        cout << endl;
    }
    */
    cout << "Tous les tests unitaires pour la classe <CSVLoader> ont été validés." << endl; 
    return EXIT_SUCCESS; 
}

