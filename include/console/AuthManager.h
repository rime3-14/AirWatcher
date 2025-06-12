//
// Created by Christopher Wilson on 27/05/2025.
//

#ifndef AUTHMANAGER_H
#define AUTHMANAGER_H

#include "models/users/User.h"

class AuthManager {
public:
    static User* login() ;
private:
    static UserType select_user_type();
};



#endif //AUTHMANAGER_H
