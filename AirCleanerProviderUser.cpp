/*************************************************************************
                           AirCleanerProviderUser  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <AirCleanerProviderUser> (fichier AirCleanerProviderUser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "AirCleanerProviderUser.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

    void AirCleanerProviderUser::showAirCleaners() {
        int i = 1; 
        for (AirCleaner elem : this.airCleaners) {
            cout << "Voici la liste des Air Cleaners fournis : \n"; 
            cout << "Air Cleaner " << i << "\n"; 
            cout << elem << "\n"; 
        }
    }
    
    float AirCleanerProviderUser::calculateAirCleanersImpact() {
        float somme = 0; 
        int nbAirCleaners; 
        for(AirCleaner elem : this.airCleaners) {
            some += elem.calculateImprovedAirLevel; 
        } return somme/(this.nbAirCleaners); 
    }


//------------------------------------------------- Surcharge d'opérateurs
AirCleanerProviderUser & AirCleanerProviderUser::operator = ( const AirCleanerProviderUser & unAirCleanerProviderUser )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
AirCleanerProviderUser::AirCleanerProviderUser ( const AirCleanerProviderUser & unAirCleanerProviderUser )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AirCleanerProviderUser>" << endl;
#endif
} 


AirCleanerProviderUser::AirCleanerProviderUser ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AirCleanerProviderUser>" << endl;
#endif
} 

AirCleanerProviderUser (string id, string login, string mdp) : User(id, login, mdp)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AirCleanerProviderUser>" << endl;
#endif
}


AirCleanerProviderUser::~AirCleanerProviderUser ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AirCleanerProviderUser>" << endl;
#endif
} 


//------------------------------------------------------------------ PRIVE


//----------------------------------------------------- Méthodes protégées

