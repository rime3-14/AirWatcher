#ifndef AIRCLEANERSPROVIDERUSER_H
#define AIRCLEANERSPROVIDERUSER_H

#include <vector>
#include <string>
#include "User.h"
//#include "AirCleaner.h" 

class AirCleanersProviderUser : public User
{
public:
    // Constructeurs et destructeur
    AirCleanersProviderUser();
    AirCleanersProviderUser(std::string id, std::string login, std::string mdp);
    virtual ~AirCleanersProviderUser();

    // Méthode d'authentification
    User* authentificateUser(std::string login, std::string mdp) const override;

    // Méthodes spécifiques
    void showAirCleaners() const;
    float calculateAirCleanerImpact() const;

private:
    //std::vector<AirCleaner> airCleaners;
};

#endif // AIRCLEANERSPROVIDERUSER_H
