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

    // Test getAllAirCleanerProviderUsers()
    vector<AirCleanerProviderUser> providers = userRepo.getAllAirCleanerProviderUsers();
    assert(!providers.empty());
    cout << "Nombre de fournisseurs de purificateurs d'air : " << providers.size() << endl;

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
