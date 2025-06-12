#include <iostream>
#include <cassert>
#include <string>
#include "dataAccess/UserRepository.h"

using namespace std;

int main() {
    cout << "Réalisation des tests unitaires pour la classe <UserRepository>" << endl;

    UserRepository userRepo;

    // Test getAllPrivateUsers()
    vector<PrivateUser> privateUsers = userRepo.getAllPrivateUsers();
    assert(!privateUsers.empty());
    cout << "Nombre d'utilisateurs privés chargés : " << privateUsers.size() << endl;

    // Test getPrivateUserById() avec ID existant
    string existingId = privateUsers[0].getId();
    PrivateUser foundUser = userRepo.getPrivateUserById(existingId);
    assert(foundUser.getId() == existingId);
    cout << "getPrivateUserById avec ID existant a réussi." << endl;

    // Test getPrivateUserById() avec ID inexistant
    PrivateUser notFoundUser = userRepo.getPrivateUserById("ID_qui_n_existe_pas");
    assert(notFoundUser.getId() == "");  // supposé que l'objet vide a id = ""
    cout << "getPrivateUserById avec ID inexistant retourne un utilisateur vide." << endl;

    // Test getAllAirCleanerProviderUsers()
    vector<AirCleanerProviderUser> providers = userRepo.getAllAirCleanerProviderUsers();
    assert(!providers.empty());
    cout << "Nombre de fournisseurs de purificateurs d'air : " << providers.size() << endl;

    // Test getAirCleanerProviderUserById avec un ID existant
    if (!providers.empty()) {
        string existingProviderId = providers[0].getId(); // Assure-toi que getId() existe
        AirCleanerProviderUser foundProvider = userRepo.getAirCleanerProviderUserById(existingProviderId);
        assert(foundProvider.getId() == existingProviderId);
        cout << "getAirCleanerProviderUserById avec un ID existant a réussi." << endl;
    } else {
        cout << "Aucun fournisseur pour tester getAirCleanerProviderUserById avec un ID existant." << endl;
    }

    // Test getAirCleanerProviderUserById avec un ID inexistant
    AirCleanerProviderUser notFoundProvider = userRepo.getAirCleanerProviderUserById("ID_INEXISTANT_123");
    assert(notFoundProvider.getId() == ""); // ou toute autre condition définissant un objet "vide"
    cout << "getAirCleanerProviderUserById avec un ID inexistant retourne un objet vide comme attendu." << endl;

    // Test markPrivateUserAsUnreliable()
    PrivateUser testUser = privateUsers[0];
    bool wasReliable = testUser.isReliable(); 
    bool success = userRepo.markPrivateUserAsUnreliable(testUser);

    cout << "markPrivateUserAsUnreliable a retourné : " << (success ? "true" : "false") << endl;
    assert(success);

    // Rechargement des utilisateurs pour voir si la fiabilité a changé
    vector<PrivateUser> privateUsersUpdated = userRepo.getAllPrivateUsers();
    bool found = false;
    for (PrivateUser &pu : privateUsersUpdated) {
        if (pu == testUser) {
            assert(pu.isReliable() == false);
            found = true;
            cout << "L'utilisateur privé est maintenant marqué comme non fiable." << endl;
            break;
        }
    }
    assert(found); // l'utilisateur devrait toujours exister

    cout << "Tous les tests unitaires pour la classe <UserRepository> ont été validés." << endl;
    return EXIT_SUCCESS;
}
