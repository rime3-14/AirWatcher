#include "users/PrivateUser.h"
#include <iostream>

using namespace std;


// Constructeur par défaut
PrivateUser::PrivateUser()
    : User(), points(0), reliability(true) {}

// Constructeur paramétré
PrivateUser::PrivateUser(string id, vector<string> sensors)
    : User(id), points(0), reliability(true), sensorsId(sensors) {}

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


void PrivateUser::addSensor(string sensorId)
{
    // Vérifie si le capteur n'est pas déjà dans la liste
    for (const auto& sensor : sensors)
    {
        if (sensor.getId() == sensorId)
        {
            cout << "Le capteur est déjà ajouté." << endl;
            return; // Le capteur est déjà présent, on ne l'ajoute pas
        }
    }
    
    // Ajoute le capteur à la liste
    sensors.push_back(sensorId);
    cout << "Capteur ajouté avec succès." << endl;
}


string PrivateUser::getId() const{
    return this->id;
}

// Authentifie l'utilisateur
User* PrivateUser::authentificateUser(std::string login) const
{
    if (this->id == login)
    {
        return new PrivateUser(*this);
    }
    return nullptr;
}





