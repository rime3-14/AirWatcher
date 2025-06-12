#include "models/users/AirCleanerProviderUser.h"
#include "dataAccess/AirCleanerRepository.h"
#include "models/sensors/AirCleaner.h"
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
        return new AirCleanerProviderUser(*this);  
    }
    return nullptr;
}

UserType AirCleanerProviderUser::getRole() const
{
    return UserType::AirCleanerProvider;
}

// Affichage des IDs des purificateurs d'air
void AirCleanerProviderUser::showAirCleaners() const
{
    cout << "Liste des Air Cleaners fournis par : " << this->id << "\n";
    int i = 1;
    if (airCleanersId.empty()) {
        cout << "Aucun purificateur d'air n'est associé à cet utilisateur.\n";
    } else {
        AirCleanerRepository airCleanerRepo;
        cout << "Nombre de purificateurs d'air associés : " << airCleanersId.size() << endl;
        for (const string & airCleanerId : airCleanersId) {
            AirCleaner airCleaner = airCleanerRepo.getAirCleanerById(airCleanerId);
            if (airCleaner.getId() == "") {
                cout << "Purificateur d'air [" << i << "] : ID invalide ou inexistant." << endl;
                continue;
            }
            cout << "Purificateur d'air " << i << " : " << endl; 
            cout << airCleaner << endl;  
        }
    }
}

// Calcul de l’impact total des purificateurs d’air (non applicable ici, donc retour neutre ou à définir)
float AirCleanerProviderUser::calculateAirCleanerImpact() const
{
    if (!airCleanersId.empty())
    {
        float totalImpact = 0.0f;
        for (const auto& airCleanerId : airCleanersId)
        {
            AirCleanerRepository airCleanerRepo;
            AirCleaner airCleaner = airCleanerRepo.getAirCleanerById(airCleanerId);
            if (airCleaner.getId() != "")
            {
                totalImpact += airCleaner.calculateRadiusPurifiedAir();
            }
        }
        return totalImpact;
    }
    cout << "Impossible de calculer l’impact : les objets AirCleaner ne sont pas disponibles.\n";
    return 0.0f;
}


// Setters et Getters
string AirCleanerProviderUser::getId() const {
    return this->id;
}

vector<string> AirCleanerProviderUser::getAirCleanersId() const {
    return this->airCleanersId;
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

vector<string> AirCleanerProviderUser::getAirCleanersId() const { return airCleanersId; };