#ifndef GOVERNMENTUSER_H
#define GOVERNMENTUSER_H

#include <string>
#include "User.h"

using namespace std;

// je suis pas sure de cette classe, à revoir

class GovernmentUser : public User
{
public:
    // Méthode statique pour accéder à l'instance unique
    static GovernmentUser* getInstance();

    // Surcharge de la méthode virtuelle d'authentification
    User* authentificateUser(std::string login) const override;

    // Méthodes spécifiques au gouvernement (exemple)
    void accessAllData() const;

    string getId() const;

private:
    // Constructeur privé (singleton)
    GovernmentUser();
    GovernmentUser(const GovernmentUser&) = delete;              
    GovernmentUser& operator=(const GovernmentUser&) = delete;   

    static GovernmentUser* instance;
};

#endif // GOVERNMENTUSER_H
