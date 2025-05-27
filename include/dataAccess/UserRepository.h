#if ! defined ( UserRepository_H )
#define UserRepository_H

//--------------------------------------------------- Interfaces utilisées
#include <vector> 
#include "include/dataAccess/Repository.h"
#include "include/models/sensors/Sensor.h"
#include "include/models/sensors/Measurement.h"
#include "include/models/users/PrivateUser.h"

class UserRepository : public Repository
{
public :
    bool getUserFiability(const PrivateUser& user) const;
    void addUser(PrivateUser& user, bool reliable); 
    //associe un capteur à l'utilisateur 
    void addSensor(PrivateUser& user, const Sensor& sensor);

    // Constructeurs et opérateurs
    UserRepository();
    UserRepository(const UserRepository& other);
    virtual ~UserRepository();

    UserRepository& operator=(const UserRepository& other);

};


#endif