#include "users/AirCleanerProviderUser.h"
#include <iostream>

// Constructeur par défaut
AirCleanerProviderUser::AirCleanerProviderUser()
    : User()
{
}

// Constructeur avec paramètres
AirCleanerProviderUser::AirCleanerProviderUser(std::string id, std::string login, std::string mdp)
    : User(id, login, mdp)
{
}

// Destructeur
AirCleanerProviderUser::~AirCleanerProviderUser()
{
}

// Implémentation de la méthode d'authentification
User* AirCleanerProviderUser::authentificateUser(std::string login, std::string mdp) const
{
    if (this->login == login && this->mdp == mdp)
    {
        return new AirCleanerProviderUser(*this);  // retourne une copie
    }
    return nullptr;
}

// Affichage des purificateurs d'air
void AirCleanerProviderUser::showAirCleaners() const
{
    std::cout << "Liste des purificateurs d'air :\n";
    // a voir les methodes de AirCleaner
}

// Calcul de l’impact total des purificateurs d’air
float AirCleanerProviderUser::calculateAirCleanerImpact() const
{
    // a voir les methodes de AirCleaner
}
