#include "models/users/GovernmentUser.h"
#include <iostream>

// Initialisation du pointeur statique
GovernmentUser* GovernmentUser::instance = nullptr;

// Constructeur privé
GovernmentUser::GovernmentUser()
    : User("gov_id", "admin", "admin123") // Identifiants d'exemple
{
}

// Accès à l’instance unique
GovernmentUser* GovernmentUser::getInstance()
{
    if (instance == nullptr)
    {
        instance = new GovernmentUser();
    }
    return instance;
}

// Authentification
User* GovernmentUser::authentificateUser(std::string login, std::string mdp) const
{
    if (this->login == login && this->mdp == mdp)
    {
        return instance;
    }
    return nullptr;
}

UserType GovernmentUser::getRole() const override
{
    return UserType::Government;
}

// Méthode spécifique
void GovernmentUser::accessAllData() const
{
    std::cout << "[GovernmentUser] accès à toutes les données du système." << std::endl;
}
