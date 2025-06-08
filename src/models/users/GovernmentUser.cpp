#include "models/users/GovernmentUser.h"
#include <iostream>

// Initialisation du pointeur statique
GovernmentUser* GovernmentUser::instance = nullptr;

// Constructeur privé
GovernmentUser::GovernmentUser()
    : User("gov_id") // Identifiants d'exemple
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
User* GovernmentUser::authentificateUser(std::string login) const
{
    if (this->id == login)
    {
        return instance;
    }
    return nullptr;
}

UserType GovernmentUser::getRole() const
{
    return UserType::Government;
}

// Méthode spécifique
void GovernmentUser::accessAllData() const
{
    std::cout << "[GovernmentUser] accès à toutes les données du système." << std::endl;
}


string GovernmentUser::getId() const{
    return this->id;
}