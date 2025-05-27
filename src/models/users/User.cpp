using namespace std;
#include <iostream>    
#include <cstring>     

#include "models/users/User.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs
// Aucun opérateur n'est surchargé dans cette implémentation.

//-------------------------------------------- Constructeurs - destructeur
// Constructeur par défaut
User::User()
    : id(""), login(""), mdp("") 
{

}

User::User(string id, string login, string mdp)
    : id(id), login(login), mdp(mdp)
{
    // Affectation directe via l'initialisation
}

// Destructeur
User::~User()
{

}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
// Pas de méthodes protégées dans cette implémentation.

