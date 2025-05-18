//---------- Interface de la classe <AirCleanerProviderUser> (fichier AirCleanerProviderUser.h) ----------------
#if ! defined ( AirCleanerProviderUser_H )
#define AirCleanerProviderUser_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>
#include "User.h"
#include "models/sensors/AirCleaner.h" 

using namespace std;

class AirCleanerProviderUser : public User
{
public:
    // Constructeurs et destructeur
    AirCleanerProviderUser();
    AirCleanerProviderUser(string id, string login, string mdp);
    virtual ~AirCleanerProviderUser();

    // Méthode d'authentification
    User* authentificateUser(string login, string mdp) const override;

    // Méthodes spécifiques
    void showAirCleaners() const;
    float calculateAirCleanerImpact() const;

protected:
    vector<AirCleaner> airCleaners;
};

#endif // AIRCLEANERSPROVIDERUSER_H
