#include <iostream>
#include <string>
#include "../include/models/users/GovernmentUser.h"

using namespace std;

int main() {
    cout << "=== Test GovernmentUser ===" << endl;

    // Récupération de l'instance singleton
    GovernmentUser* user = GovernmentUser::getInstance();

    // Vérification de l'ID
    string id = user->getId();
    if (!id.empty()) {
        cout << "✅ ID utilisateur récupéré : " << id << endl;
    } else {
        cout << "❌ ID utilisateur vide ou invalide." << endl;
    }

    // Vérification du rôle
    if (user->getRole() == UserType::Government) {
        cout << "✅ Rôle : Government" << endl;
    } else {
        cout << "❌ Erreur : rôle inattendu." << endl;
    }

    // Accès aux données
    cout << "Accès aux données gouvernementales : " << endl;
    user->accessAllData();

    // Test de la méthode d'authentification
    User* authenticated = user->authentificateUser(user->getId());
    if (authenticated != nullptr) {
        cout << "✅ Authentification réussie." << endl;
        delete authenticated; // nettoyage si une copie a été créée
    } else {
        cout << "❌ Authentification échouée." << endl;
    }

    cout << "=== Fin du test GovernmentUser ===" << endl;
    return 0;
}
