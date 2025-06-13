#ifndef USER_H
#define USER_H

#include <string>
#include "UserTypeEnum.h"

class User
{
public:

    // Méthode virtuelle pure : authentification par ID
    virtual User* authentificateUser(std::string login) const = 0;

    // Méthode virtuelle pure : retourne le rôle de l'utilisateur
    virtual UserType getRole() const = 0;

    // Constructeurs
    User();
    User(std::string id);

    // Destructeur virtuel
    virtual ~User();

protected:
    std::string id;
};

#endif
