#include <iostream>
#include <vector>
#include <string>
#include "../include/models/users/PrivateUser.h"  // adapte le chemin selon ton arborescence

int main() {
    // Création d’un utilisateur privé
    PrivateUser user("user123");

    // Vérification de l'ID
    std::cout << "ID utilisateur : " << user.getId() << std::endl;

    // Test du rôle
    if (user.getRole() == UserType::Private) {
        std::cout << "Rôle : Private ✅" << std::endl;
    } else {
        std::cout << "❌ Erreur : rôle inattendu" << std::endl;
    }

    // Test ajout de points
    std::cout << "Ajout de points (true, true, false):" << std::endl;
    user.addPoint(true);
    user.addPoint(true);
    user.addPoint(false);

    std::cout << "Points accumulés : " << user.getPoints() << std::endl;

    // Test de la fiabilité
    std::cout << "Utilisateur fiable ? " << (user.isReliable() ? "Oui" : "Non") << std::endl;

    // Test de l'ajout de capteurs
    user.addSensor("sensor1");
    user.addSensor("sensor2");

    std::cout << "Capteurs ajoutés : ";
    for (const auto& id : user.getSensorsId()) {
        std::cout << id << " ";
    }
    std::cout << std::endl;

    // Test de la méthode d'authentification
    User* authenticated = user.authentificateUser("user123");
    std::cout << "Authentification : " << (authenticated != nullptr ? "Réussie" : "Échouée") << std::endl;

    return 0;
}