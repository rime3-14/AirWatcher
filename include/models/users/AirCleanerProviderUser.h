#ifndef AIRCLEANERSPROVIDERUSER_H
#define AIRCLEANERSPROVIDERUSER_H

#include <vector>
#include <string>
#include "User.h"
//#include "AirCleaner.h" 

using namespace std;

class AirCleanerProviderUser : public User
{
public:
    // Constructeurs et destructeur
    AirCleanerProviderUser();
    AirCleanerProviderUser(std::string id, std::string login, std::string mdp);
    virtual ~AirCleanerProviderUser();

    // Méthode d'authentification
    User* authentificateUser(std::string login, std::string mdp) const override;

    // Méthodes spécifiques
    void showAirCleaners() const;
    float calculateAirCleanerImpact() const;

private:
    //std::vector<AirCleaner> airCleaners;
};

#endif // AIRCLEANERSPROVIDERUSER_H
