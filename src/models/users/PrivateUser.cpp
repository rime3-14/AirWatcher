/************************************************************************* 
                           PrivateUser  -  description
                             -------------------
    début                : 27/05/2025
    copyright            : (C) 2025 par Bindech Rida
    e-mail               : rida.bindech@gmail.com
*************************************************************************/

//---------- Réalisation de la classe <PrivateUser> (fichier PrivateUser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;
//------------------------------------------------------ Include personnel
#include "models/users/PrivateUser.h"

//------------------------------------------------------------- Constantes (si besoin)

//----------------------------------------------------------------- PUBLIC

void PrivateUser::setReliability(bool unReliability) {
    reliability = unReliability; 
}

//-------------------------------------------- Surcharges d'opérateurs 

bool PrivateUser::operator==(const PrivateUser& unPrivateUser)
{
    return id == unPrivateUser.id; 
}

//-------------------------------------------- Constructeurs - destructeur

PrivateUser::PrivateUser()
    : User(), points(0), reliability(false)
{
#ifdef MAP
    std::cout << "Appel au constructeur par défaut de PrivateUser" << std::endl;
#endif
}

PrivateUser::PrivateUser(std::string id)
    : User(id), points(0), reliability(false)
{
    sensorsId = vector<string>();
#ifdef MAP
    std::cout << "Appel au constructeur paramétré de PrivateUser" << std::endl;
#endif
}

PrivateUser::~PrivateUser()
{
#ifdef MAP
    std::cout << "Appel au destructeur de PrivateUser" << std::endl;
#endif
}

//----------------------------------------------------- Méthodes publiques

// Méthodes héritées abstraites

User* PrivateUser::authentificateUser(std::string login) const
{
    // Simple exemple, retourne nullptr (non implémenté ici)
    return nullptr;
}

UserType PrivateUser::getRole() const
{
    return UserType::Private;
}

// Méthodes existantes

void PrivateUser::addPoint(bool reliable)
{
    if (reliable) points++;
    reliability = reliable;
}

void PrivateUser::showPoints() const
{
    std::cout << "Points: " << points << std::endl;
}

void PrivateUser::addSensor(const std::string& sensorId)
{
    sensorsId.push_back(sensorId);
}

int PrivateUser::getPoints() const
{
    return points;
}

// Méthodes ajoutées

std::string PrivateUser::getId() const
{
    return id;
}

bool PrivateUser::isReliable() const
{
    return reliability;
}

std::vector<std::string> PrivateUser::getSensorsId() const
{
    return sensorsId;
}

//------------------------------------------------- Surcharge d'opérateurs

std::ostream& operator<<(std::ostream& os, const PrivateUser& user)
{
    os << "User ID: " << user.getId() << "\n";
    os << "Points: " << user.points << "\n";
    os << "Reliability: " << (user.reliability ? "true" : "false") << "\n";
    os << "Sensors: ";
    for (const auto& sensor : user.sensorsId)
    {
        os << sensor << " ";
    }
    os << "\n";
    return os;
}
