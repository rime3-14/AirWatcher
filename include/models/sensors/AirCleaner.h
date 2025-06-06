/*************************************************************************
                           AirCleaner  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <AirCleaner> (fichier AirCleaner.h) ----------------
#if ! defined ( AirCleaner_H )
#define AirCleaner_H

//--------------------------------------------------- Interfaces utilisées
#include <vector> 
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AirCleaner>
// Répertorie toutes les informations concernant un AirCleaner fourni par 
// un AirCleanerProviderUser.
//------------------------------------------------------------------------

class AirCleaner 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    float calculateRadiusPurifiedAir(); 
    // Mode d'emploi :
    // 
    // Contrat :
    //
    
    float calculateImprovedAirLevel(); 
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    AirCleaner & operator = ( const AirCleaner & unAirCleaner );
    // Mode d'emploi :
    //
    // Contrat :

//------------------------------------------------- Getters - Setters

    string getId() const; 

    float getLatitude() const; 

    float getLongitude() const; 

    float getRadius() const; 

//-------------------------------------------- Constructeurs - destructeur
    AirCleaner ( const AirCleaner & unAirCleaner );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    AirCleaner ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    AirCleaner (string anId, float lat , float lon, time_t debut, time_t fin);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AirCleaner ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    string id; 
    float latitude; 
    float longitude; 
    float radius;
    time_t debut;
    time_t fin;
};

//-------------------------------- Autres définitions dépendantes de <AirCleaner>

ostream & operator << ( ostream & out, const AirCleaner & aC) {
    out << "Informations concernant le Air Cleaner " << aC.getId() << " : \n"; 
    out << "ID Fournisseur : "; 
    out << "Latitude : " << aC.getLatitude() << " :\n "; 
    out << "Longitude : " << aC.getLongitude() << " : \n"; 
    return out;   
}

#endif // AirCleaner_H

