/************************************************************************* 
                           PrivateUser  -  description
                             -------------------
    début                : 27/05/2025
    copyright            : (C) 2025 par Bindech Rida
    e-mail               : rida.bindech@gmail.com
*************************************************************************/

//---------- Réalisation de la classe <PrivateUser> (fichier PrivateUser.h) ------------
#ifndef PRIVATEUSER_H
#define PRIVATEUSER_H

//--------------------------------------------------- Interfaces utilisées
#include "User.h"
#include <vector>
#include <string>
#include <iostream>

//------------------------------------------------------------------------
// Rôle de la classe <PrivateUser>
// Hérite de User. Représente un utilisateur privé avec un identifiant,
// un nombre de points accumulés, une fiabilité, et une liste d'ID de capteurs.
//------------------------------------------------------------------------

class PrivateUser : public User
{
//----------------------------------------------------------------- PUBLIC
public:
     //-------------------------------------------- Surcharges d'opérateurs
    bool operator==(const PrivateUser& unPrivateUser);
    //-------------------------------------------- Constructeurs - destructeur
    PrivateUser();
    explicit PrivateUser(const std::string id);
    virtual ~PrivateUser();

    //----------------------------------------------------- Méthodes publiques
    User* authentificateUser(const std::string login) const override;
    UserType getRole() const override;

    void addPoint(bool reliable);
    void showPoints() const;
    void addSensor(const std::string& sensorId);

    //----------------------------------------------------- Setters - Getters
    int getPoints() const;
    std::string getId() const;
    bool isReliable() const;
    std::vector<std::string> getSensorsId() const;

    void setReliability(bool unReliability); 

    //-------------------------------------------- Surcharge opérateur <<
    friend std::ostream& operator<<(std::ostream& os, const PrivateUser& user);

//------------------------------------------------------------------ PRIVE
private:
    int points;
    std::vector<std::string> sensorsId;
    bool reliability;
};

#endif // PRIVATEUSER_H

// Déclaration hors classe pour la surcharge opérateur <<
std::ostream& operator<<(std::ostream& os, const PrivateUser& user);
