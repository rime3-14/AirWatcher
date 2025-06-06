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
    AirCleanerProviderUser(string id, vector<string> airCleanersId);
    virtual ~AirCleanerProviderUser();

    // Méthode d'authentification
    User* authentificateUser(string login) const override;
    UserType getRole() const override;

    // Méthodes spécifiques
    void showAirCleaners() const;
    float calculateAirCleanerImpact() const;
    void addAirCleaner(string airCleanerId);

    string getId() const;

protected:
    vector<string> airCleanersId;
};

#endif // AIRCLEANERSPROVIDERUSER_H
