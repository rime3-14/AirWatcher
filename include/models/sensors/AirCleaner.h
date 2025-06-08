/*************************************************************************
                           AirCleaner  
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par Ashley DUONG
    e-mail               : ashley.duong@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <AirCleaner> (fichier AirCleaner.h) ----------------
#if ! defined ( AirCleaner_H )
#define AirCleaner_H

//--------------------------------------------------- Interfaces utilisées
#include <vector> 
#include <string>
using namespace std;
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
    // Contrat :
    // Calcule le rayon d'impact d'un AirCleaner en fonction de la qualité 
    // de l'air mesurée par les capteurs situés autour de lui 
    // (sur un rayon qu'on aura arbitrairement défini) 
    // avant et après sa période d'activité signalée par les attributs debut et fin.
    // Retourne le rayon d'impact en radius ?
    
    float calculateImprovedAirLevel(); 
    // Contrat :
    // Calcule le niveau d'amélioration de la qualité de l'air
    // en fonction de la qualité de l'air mesurée par les capteurs situés
    // autour de lui avant et après sa période d'activité signalée par les
    // attributs debut et fin.

//------------------------------------------------- Surcharge d'opérateurs
    AirCleaner & operator = ( const AirCleaner & unAirCleaner );

//------------------------------------------------- Getters - Setters
    string getId() const; 

    float getLatitude() const; 

    float getLongitude() const; 

    float getRadius() const; 
//-------------------------------------------- Constructeurs - destructeur
    AirCleaner ( const AirCleaner & unAirCleaner );

    AirCleaner ( );

    AirCleaner (string anId, float lat , float lon, time_t debut, time_t fin);

    virtual ~AirCleaner ( );
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
// Surchage d'opérateurs
ostream & operator << ( ostream & out, const AirCleaner & aC) {
    out << "Informations concernant le Air Cleaner " << aC.getId() << " : \n"; 
    out << "ID Fournisseur : "; 
    out << "Latitude : " << aC.getLatitude() << " :\n "; 
    out << "Longitude : " << aC.getLongitude() << " : \n"; 
    return out;   
}

#endif // AirCleaner_H

