//---------- Réalisation de la classe <AirCleanerProviderUser> (fichier AirCleanerProviderUser.cpp) ------------

//---------------------------------------------------------------- INCLUDE
#include "models/users/AirCleanerProviderUser.h"
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
AirCleanerProviderUser::AirCleanerProviderUser(std::string id, vector<string> airCleanersId)
    : User(id), airCleanersId(airCleanersId)
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
User* AirCleanerProviderUser::authentificateUser(std::string login) const
{
    if (this->id == login)
    {
        return new AirCleanerProviderUser(*this);  // retourne une copie
    }
    return nullptr;
}

UserType AirCleanerProviderUser::getRole() const override
{
    return UserType::AirCleanerProvider;
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

string AirCleanerProviderUser::getId() const{
    return this->id;
}

void addAirCleaner(string airCleanerId)
{
    for (const auto& airCleaner : airCleanersId)
    {
        if (airCleaner == airCleanerId)
        {
            cout << "Le purificateur d'air est déjà ajouté." << endl;
            return; 
        }
    }
    
    airCleanersId.push_back(airCleanerId);
}