
#include <iostream>
#include <string>
#include "../include/models/users/GovernmentUser.h"

int main() {
    // Récupération de l'instance singleton
    GovernmentUser* user = GovernmentUser::getInstance();

    // Vérification de l'ID (non défini ici car singleton sans paramètre)
    std::cout << "ID utilisateur : " << user->getId() << std::endl;

    // Vérification du rôle
    if (user->getRole() == UserType::Government) {
        std::cout << "Rôle : Government " << std::endl;
    } else {
        std::cout << " Erreur : rôle inattendu" << std::endl;
    }

    // Accès aux données
    user->accessAllData();

    // Test de la méthode d'authentification
    User* authenticated = user->authentificateUser(user->getId());
    std::cout << "Authentification : " << (authenticated != nullptr ? "Réussie" : "Échouée") << std::endl;

    return 0;
}
