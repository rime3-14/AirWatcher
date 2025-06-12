#include <iostream>
#include <cassert>
#include <string>
#include "dataAccess/AirCleanerRepository.h"
#include "models/sensors/AirCleaner.h"

using namespace std;

int main() {

    cout << "Réalisation des tests unitaires pour la classe <AirCleanerRepository>" << endl;

    AirCleanerRepository airCleanerRepo;

    // Test getAll()
    vector<AirCleaner> airCleaners = airCleanerRepo.getAll();
    assert(!airCleaners.empty());
    cout << "Nombre de purificateurs d'air chargés : " << airCleaners.size() << endl;

    // Test getAirCleanerById() sur un purificateur existant
    string testAirCleanerId = airCleaners[0].getId(); 
    AirCleaner ac = airCleanerRepo.getAirCleanerById(testAirCleanerId);

    assert(ac.getId() == testAirCleanerId);
    cout << "getAirCleanerById fonctionne pour ID : " << testAirCleanerId << endl;

    // Test getAirCleanerById() sur un ID inexistant
    AirCleaner notFoundAC = airCleanerRepo.getAirCleanerById("UnknownID_123456");
    assert(notFoundAC.getId() == ""); // supposé vide si non trouvé
    cout << "getAirCleanerById renvoie un objet vide pour un ID inexistant." << endl;

    cout << "Tous les tests unitaires pour la classe <AirCleanerRepository> ont été validés." << endl;
    
    return EXIT_SUCCESS;
}
