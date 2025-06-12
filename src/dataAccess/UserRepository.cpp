/*************************************************************************
                           UserRepository  
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par Ashley DUONG
    e-mail               : ashley.duong@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <UserRepository> (fichier UserRepository.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <math.h>
#include "dataAccess/UserRepository.h" 
#include "dataAccess/CSVLoader.h" 
using namespace std;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

vector<PrivateUser> UserRepository::getAllPrivateUsers() {
    CSVLoader& csvLoader = CSVLoader::Instance();
    return csvLoader.getUsers();  
}

PrivateUser UserRepository::getPrivateUserById(const string & privateUserId) {
    CSVLoader& csvLoader = CSVLoader::Instance();
    vector<PrivateUser> & allPrivateUsers = csvLoader.getUsers(); 

    for(const PrivateUser & privateU : allPrivateUsers) {
        if(privateU.getId() == privateUserId) {
            return privateU; 
        }
    }

    return PrivateUser(); 
}

vector<AirCleanerProviderUser> UserRepository::getAllAirCleanerProviderUsers() {
    CSVLoader& csvLoader = CSVLoader::Instance();
    return csvLoader.getProviders();
}

AirCleanerProviderUser UserRepository::getAirCleanerProviderUserById(const string & airCleanerProviderId) {
    CSVLoader& csvLoader = CSVLoader::Instance();
    vector<AirCleanerProviderUser> allProviders = csvLoader.getProviders(); 

    for(const AirCleanerProviderUser & provider : allProviders) {
        if(provider.getId() == airCleanerProviderId) {
            return provider; 
        }
    }

    return AirCleanerProviderUser(); 
}

bool UserRepository::markPrivateUserAsUnreliable(PrivateUser privateUser) {
    CSVLoader& csvLoader = CSVLoader::Instance();
    vector<PrivateUser> & allPrivateUsers = csvLoader.getUsers(); 

    for(PrivateUser & privateU : allPrivateUsers) {
        if(privateU == privateUser) {
            privateU.setReliability(false); 
            return true; 
        }
    }

    return false; 
}


//------------------------------------------------- Surcharge d'opérateurs

//------------------------------------------------- Getters - Setters

//-------------------------------------------- Constructeurs - destructeur
UserRepository::UserRepository ( const UserRepository & unUserRepository )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <UserRepository>" << endl;
#endif
} 

UserRepository::UserRepository ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <UserRepository>" << endl;
#endif
} 

UserRepository::~UserRepository ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <UserRepository>" << endl;
#endif
} 
