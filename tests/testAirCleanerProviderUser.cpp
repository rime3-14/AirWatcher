
#include <iostream>
#include <vector>
#include <string>
#include "../include/models/users/AirCleanerProviderUser.h"

int main() {
    // Création d’un utilisateur fournisseur d’air cleaner
    std::vector<std::string> cleaners = {"AC1", "AC2"};
    AirCleanerProviderUser user("provider123", cleaners);

    // Vérification de l'ID
    std::cout << "ID utilisateur : " << user.getId() << std::endl;

    // Vérification du rôle
    if (user.getRole() == UserType::AirCleanerProvider) {
        std::cout << "Rôle : AirCleanerProvider " << std::endl;
    } else {
        std::cout << " Erreur : rôle inattendu" << std::endl;
    }

    // Test de la méthode addAirCleaner
    user.addAirCleaner("AC3");

    // Affichage des AirCleaners
    std::cout << "Liste des AirCleaners : ";
    user.showAirCleaners();

    // Test de la méthode d'authentification
    User* authenticated = user.authentificateUser("provider123");
    std::cout << "Authentification : " << (authenticated != nullptr ? "Réussie" : "Échouée") << std::endl;

    return 0;
}
