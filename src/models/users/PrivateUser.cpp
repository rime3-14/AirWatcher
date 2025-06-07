#include "models/users/PrivateUser.h"
#include <iostream>

using namespace std;

// Constructeur par défaut
PrivateUser::PrivateUser()
    : User(), points(0), reliability(true) {}

// Constructeur paramétré
PrivateUser::PrivateUser(string id, string login, string mdp)
    : User(id, login, mdp), points(0), reliability(true) {}

// Destructeur
PrivateUser::~PrivateUser() {}

// Ajoute un point si l'utilisateur est fiable
void PrivateUser::addPoint(bool reliable)
{
    if (reliable)
    {
        points++;
    }
}

// Affiche le nombre de points
void PrivateUser::showPoints() const
{
    cout << "Points: " << points << endl;
}


//void PrivateUser::addSensor()
//{
//    PrivateSensor sensor; 
//}

// Authentifie l'utilisateur
User* PrivateUser::authentificateUser(std::string login, std::string mdp) const
{
    if (this->login == login && this->mdp == mdp)
    {
        return new PrivateUser(*this);
    }
    return nullptr;
}



