#include "AirCleanerProviderUser.h"
#include <iostream>

// Constructeur par défaut
AirCleanersProviderUser::AirCleanersProviderUser()
    : User()
{
}

// Constructeur avec paramètres
AirCleanersProviderUser::AirCleanersProviderUser(std::string id, std::string login, std::string mdp)
    : User(id, login, mdp)
{
}

// Destructeur
AirCleanersProviderUser::~AirCleanersProviderUser()
{
}

// Implémentation de la méthode d'authentification
User* AirCleanersProviderUser::authentificateUser(std::string login, std::string mdp) const
{
    if (this->login == login && this->mdp == mdp)
    {
        return new AirCleanersProviderUser(*this);  // retourne une copie
    }
    return nullptr;
}

// Affichage des purificateurs d'air
void AirCleanersProviderUser::showAirCleaners() const
{
    std::cout << "Liste des purificateurs d'air :\n";
    // a voir les methodes de AirCleaner
}

// Calcul de l’impact total des purificateurs d’air
float AirCleanersProviderUser::calculateAirCleanerImpact() const
{
    // a voir les methodes de AirCleaner
}
