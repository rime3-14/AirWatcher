//---------- Réalisation de la classe <AirCleanerProviderUser> (fichier AirCleanerProviderUser.cpp) ------------

//---------------------------------------------------------------- INCLUDE
#include "users/AirCleanerProviderUser.h"
#include <iostream>

using namespace std;

// Constructeur par défaut
AirCleanerProviderUser::AirCleanerProviderUser()
    : User()
{
    #ifdef MAP
        cout << "Appel au constructeur de <AirCleanerProviderUser>" << endl;
    #endif
}

// Constructeur avec paramètres
AirCleanerProviderUser::AirCleanerProviderUser(std::string id, std::string login, std::string mdp)
    : User(id, login, mdp)
{
    #ifdef MAP
        cout << "Appel au constructeur de <AirCleanerProviderUser>" << endl;
    #endif
}

// Destructeur
AirCleanerProviderUser::~AirCleanerProviderUser()
{
    #ifdef MAP
        cout << "Appel au destructeur de <AirCleanerProviderUser>" << endl;
    #endif
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
    int i = 1; 
    for (AirCleaner elem : this.airCleaners) {
        cout << "Voici la liste des Air Cleaners fournis : \n"; 
        cout << "Air Cleaner " << i << "\n"; 
        cout << elem << "\n"; 
    }
}

// Calcul de l’impact total des purificateurs d’air
float AirCleanerProviderUser::calculateAirCleanerImpact() const
{
    float somme = 0; 
    int nbAirCleaners; 
    for(AirCleaner elem : this.airCleaners) {
        some += elem.calculateImprovedAirLevel; 
    } return somme/(this.nbAirCleaners); 
}
