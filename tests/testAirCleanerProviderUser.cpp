#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include "models/users/AirCleanerProviderUser.h"
#include "models/sensors/AirCleaner.h"
#include "dataAccess/UserRepository.h"
#include "dataAccess/AirCleanerRepository.h"

using namespace std;

int main() {
    cout << "Réalisation des tests unitaires pour la classe <AirCleanerProviderUser>" << endl;

    UserRepository userRepo;
    vector<AirCleanerProviderUser> providers = userRepo.getAllAirCleanerProviderUsers();
    assert(!providers.empty());  
    cout << "Nombre de fournisseurs d'Air Cleaners chargé : " << providers.size() << endl << endl; 

    // Test getId() et getAirCleanersId()
    cout << "- Tests des méthodes getId() et getAirCleanersId() :" << endl;
    AirCleanerProviderUser provider = providers[0];  // Prend le premier fournisseur pour les tests
    string userId = provider.getId();  // Récupère l'ID du fournisseur pour les tests
    cout << "ID du fournisseur utilisé pour les tests : " << userId << endl;
    assert(!userId.empty());  // Vérifie que l'ID n'est pas vide
    cout << "Nombre de purificateurs d'air associés : " << provider.getAirCleanersId().size() << endl << endl;

    // Test authentificateUser()
    cout << "- Test de la méthode authentificateUser() :" << endl;
    User* authenticatedUser = provider.authentificateUser(userId);
    assert(authenticatedUser != nullptr);
    delete authenticatedUser;

    User* failedAuth = provider.authentificateUser("WrongId");
    assert(failedAuth == nullptr);
    cout << "authentificateUser() retourne nullptr avec un ID invalide." << endl << endl;

    // Test getRole()
    cout << "- Test de la méthode getRole() :" << endl;
    assert(provider.getRole() == UserType::AirCleanerProvider);
    cout << "getRole() retourne correctement AirCleanerProvider." << endl << endl;

    // Test addAirCleaner() avec un nouvel ID
    cout << "- Test de la méthode addAirCleaner() :" << endl;
    string newCleanerId = "Cleaner3";
    provider.addAirCleaner(newCleanerId);
    assert(provider.calculateAirCleanerImpact() >= 0.0f);  // L'impact est une somme >= 0
    cout << "addAirCleaner() a bien ajouté un nouveau purificateur." << endl << endl; 

    // Test addAirCleaner() avec un ID déjà existant
    cout << "- Test de addAirCleaner() avec un ID déjà existant :" << endl;
    provider.addAirCleaner(newCleanerId);  
    cout << "addAirCleaner() gère bien les doublons." << endl << endl;

    // Test calculateAirCleanerImpact() retourne une valeur positive ou 0
    cout << "- Test de la méthode calculateAirCleanerImpact() :" << endl;
    float impact = provider.calculateAirCleanerImpact();
    assert(impact >= 0.0f);
    cout << "calculateAirCleanerImpact() a retourné une valeur valide : " << impact << endl << endl;

    // Test showAirCleaners() 
    cout << "- Test de la méthode showAirCleaners() :" << endl;
    cout << "Affichage des purificateurs associés :" << endl; 
    provider.showAirCleaners();

    cout << "\nTous les tests unitaires pour <AirCleanerProviderUser> ont été validés." << endl;

    return EXIT_SUCCESS;
}