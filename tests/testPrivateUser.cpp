#include <iostream>
#include <vector>
#include <string>
#include "../include/models/users/PrivateUser.h"  // adapte le chemin selon ton arborescence

int main() {
    std::cout << "Début des tests unitaires pour la classe <PrivateUser>" << std::endl;

    // Création d’un utilisateur privé
    PrivateUser user("user123");

    // Vérification de l'ID
    if (user.getId() == "user123") {
        std::cout << "🟢 Test ID utilisateur réussi" << std::endl;
    } else {
        std::cout << "🔴 Test ID utilisateur échoué" << std::endl;
    }

    // Test ajout de points
    user.addPoint(true);
    user.addPoint(true);
    user.addPoint(false);

    if (user.getPoints() == 2) {
        std::cout << "🟢 Test ajout de points réussi" << std::endl;
    } else {
        std::cout << "🔴 Test ajout de points échoué (valeur : " << user.getPoints() << ")" << std::endl;
    }

    // Test de la fiabilité
    if (user.isReliable()) {
        std::cout << "🟢 Test fiabilité utilisateur réussi" << std::endl;
    } else {
        std::cout << "🔴 Test fiabilité utilisateur échoué" << std::endl;
    }

    // Test de l'ajout de capteurs
    user.addSensor("sensor1");
    user.addSensor("sensor2");
    std::vector<std::string> expectedSensors = {"sensor1", "sensor2"};
    if (user.getSensorsId() == expectedSensors) {
        std::cout << "🟢 Test ajout de capteurs réussi" << std::endl;
    } else {
        std::cout << "🔴 Test ajout de capteurs échoué" << std::endl;
    }

    // Test de la méthode d'authentification
    User* authenticated = user.authentificateUser("user123");
    if (authenticated != nullptr) {
        std::cout << "🟢 Test authentification réussi" << std::endl;
    } else {
        std::cout << "🔴 Test authentification échoué" << std::endl;
    }

    std::cout << "Fin des tests unitaires pour la classe <PrivateUser>" << std::endl;
    return 0;
}
