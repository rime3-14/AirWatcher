/*************************************************************************
                           UserRepository  
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par Ashley DUONG
    e-mail               : ashley.duong@insa-lyon.fr
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
    // Contrat :
    // Retourne tous les PrivateUsers présents dans le fichier CSV.
    // Si aucun PrivateUser n'est trouvé, retourne un vecteur vide.

    PrivateUser getPrivateUserById(const string & privateUserId);
    // Contrat :
    // Retourne le PrivateUser dont l'ID est privateUserId.
    // Si aucun PrivateUser n'est trouvé, retourne un PrivateUser vide.

    vector<AirCleanerProviderUser> getAllAirCleanerProviderUsers();
    // Contrat :
    // Retourne tous les AirCleanerProviderUsers présents dans le fichier CSV.
    // Si aucun AirCleanerProviderUser n'est trouvé, retourne un vecteur vide.

    AirCleanerProviderUser getAirCleanerProviderUserById(const string & airCleanerProviderId);
    // Contrat :
    // Retourne le AirCleanerProviderUser dont l'ID est airCleanerProviderId.
    // Si aucun AirCleanerProviderUser n'est trouvé, retourne un AirCleanerProviderUser vide.

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

