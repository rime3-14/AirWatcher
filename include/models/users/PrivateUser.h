#ifndef PRIVATE_USER_H
#define PRIVATE_USER_H

#include "User.h"
#include <string>
#include <vector>
#include "models/sensors/PrivateSensor.h"  

using namespace std;

class PrivateUser : public User
{
public:
    // Constructeurs et destructeur
    PrivateUser();
    PrivateUser(string id, vector<string> sensors);
    virtual ~PrivateUser();

    // Méthodes publiques
    void addPoint(bool reliable);
    void showPoints() const;
    void addSensor(string sensorId);
    string getId() const;

    // Implémentation de la méthode abstraite
    User* authentificateUser(std::string login) const override;
    UserType getRole() const override;


protected:
    int points;
    vector<string> sensorsId;
    bool reliability;
};

#endif
