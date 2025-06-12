#include <iostream>
#include <vector>
#include <string>
#include "../include/models/users/AirCleanerProviderUser.h"

using namespace std;

int main() {
    cout << "=== Début des tests pour AirCleanerProviderUser ===" << endl;

    // Création d’un utilisateur fournisseur d’air cleaner
    vector<string> cleaners = {"AC1", "AC2"};
    AirCleanerProviderUser user("provider123", cleaners);

    // Vérification de l'ID
    if (user.getId() == "provider123") {
        cout << "✅ Vérification de l'ID réussie" << endl;
    } else {
        cout << "🔴 Vérification de l'ID échouée" << endl;
    }

    // Vérification du rôle
    if (user.getRole() == UserType::AirCleanerProvider) {
        cout << "✅ Rôle correct : AirCleanerProvider" << endl;
    } else {
        cout << "🔴 Rôle incorrect" << endl;
    }

    // Test de la méthode addAirCleaner
    user.addAirCleaner("AC3");
    const auto& updatedCleaners = user.getAirCleanersId(); // on suppose que tu ajoutes cette méthode si nécessaire

    bool ac3Found = false;
    for (const auto& id : updatedCleaners) {
        if (id == "AC3") {
            ac3Found = true;
            break;
        }
    }
    if (ac3Found) {
        cout << "✅ Ajout de l'AirCleaner AC3 réussi" << endl;
    } else {
        cout << "🔴 Échec de l'ajout de l'AirCleaner AC3" << endl;
    }

    // Affichage des AirCleaners
    cout << "Liste des AirCleaners : ";
    user.showAirCleaners();

    // Test de la méthode d'authentification
    User* authenticated = user.authentificateUser("provider123");
    if (authenticated != nullptr) {
        cout << "✅ Authentification réussie" << endl;
    } else {
        cout << "🔴 Authentification échouée" << endl;
    }

    cout << "=== Fin des tests pour AirCleanerProviderUser ===" << endl;
    return 0;
}
