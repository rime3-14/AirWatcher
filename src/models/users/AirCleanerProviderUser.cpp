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

// Pas de override ici, c'est dans le .h uniquement
UserType AirCleanerProviderUser::getRole() const
{
    return UserType::AirCleanerProvider;
}

// Affichage des IDs des purificateurs d'air
void AirCleanerProviderUser::showAirCleaners() const
{
    cout << "Voici la liste des IDs des Air Cleaners fournis : \n";
    int i = 1;
    for (const auto& id : airCleanersId)
    {
        cout << "Air Cleaner " << i << " : " << id << "\n";
        ++i;
    }
}

// Calcul de l’impact total des purificateurs d’air (non applicable ici, donc retour neutre ou à définir)
float AirCleanerProviderUser::calculateAirCleanerImpact() const
{
    // Tu ne peux pas calculer un impact sans les objets AirCleaner
    // Ici on renvoie 0 ou on peut lever une exception ou loguer une alerte.
    cout << "Impossible de calculer l’impact : les objets AirCleaner ne sont pas disponibles.\n";
    return 0.0f;
}

string AirCleanerProviderUser::getId() const {
    return this->id;
}

// Ajout d’un ID de purificateur
void AirCleanerProviderUser::addAirCleaner(string airCleanerId)
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
