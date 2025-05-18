#ifndef PRIVATE_USER_H
#define PRIVATE_USER_H

#include "User.h"
#include <string>
#include <vector>
//#include "PrivateSensor.h"  

using namespace std;

class PrivateUser : public User
{
public:
    // Constructeurs et destructeur
    PrivateUser();
    PrivateUser(string id, string login, string mdp);
    virtual ~PrivateUser();

    // Méthodes publiques
    void addPoint(bool reliable);
    void showPoints() const;
    void addSensor();

    // Implémentation de la méthode abstraite
    User* authentificateUser(std::string login, std::string mdp) const override;


protected:
    int points;
    //vector<PrivateSensor> sensors;
    bool reliability;
};

#endif
