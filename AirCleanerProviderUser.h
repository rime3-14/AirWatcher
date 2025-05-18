/*************************************************************************
                           AirCleanerProviderUser  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <AirCleanerProviderUser> (fichier AirCleanerProviderUser.h) ----------------
#if ! defined ( AirCleanerProviderUser_H )
#define AirCleanerProviderUser_H

//--------------------------------------------------- Interfaces utilisées
#include "AirCleaner.h" 
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AirCleanerProviderUser>
//
//
//------------------------------------------------------------------------

class AirCleanerProviderUser : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void showAirCleaners(); 
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    float calculateAirCleanersImpact(); 
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    AirCleanerProviderUser & operator = ( const AirCleanerProviderUser & unAirCleanerProviderUser );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    AirCleanerProviderUser ( const AirCleanerProviderUser & unAirCleanerProviderUser );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    AirCleanerProviderUser ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    AirCleanerProviderUser (string id, string login, string mdp); 
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AirCleanerProviderUser ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
    vector<AirCleaner> airCleaners; 
//----------------------------------------------------- Attributs protégés
    
};

//-------------------------------- Autres définitions dépendantes de <AirCleanerProviderUser>

#endif // AirCleanerProviderUser_H

