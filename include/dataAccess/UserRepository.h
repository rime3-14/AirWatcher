/*************************************************************************
                           UserRepository  
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par Ashley DUONG
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <UserRepository> (fichier UserRepository.h) ----------------
#if ! defined ( UserRepository_H )
#define UserRepository_H

//--------------------------------------------------- Interfaces utilisées
#include <vector> 
#include "models/sensors/Sensor.h"
#include "models/sensors/Measurement.h"
#include "models/users/PrivateUser.h"
#include "models/users/User.h"
#include "models/users/GovernmentUser.h"
#include "models/users/AirCleanerProviderUser.h"

// Rôle de la classe <UserRepository>
// Fait office de DAO et récupère les informations voulues sur les utilisateurs
// pour les requêtes.
//------------------------------------------------------------------------

class UserRepository 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    vector<PrivateUser> getAllPrivateUsers();

    vector<AirCleanerProviderUser> getAllAirCleanerProviderUsers();

    bool markPrivateUserAsUnreliable(PrivateUser privateUser); 
    // Contrat :
    // Set Reliability de privateUser à false. 
    // Retourne true si l'opération s'est bien réalisée, autrement dit si 
    // privateUser a bien été trouvé. 

//------------------------------------------------- Getters - Setters

//-------------------------------------------- Constructeurs - destructeur

    UserRepository ( const UserRepository & unUserRepository );

    UserRepository ( );

    ~UserRepository ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <UserRepository>


#endif // UserRepository_H

