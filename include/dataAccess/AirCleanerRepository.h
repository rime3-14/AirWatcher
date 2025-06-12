/*************************************************************************
                           AirCleanerRepository  
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par Ashley DUONG    
    e-mail               : ashley.duong@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <AirCleanerRepository> (fichier AirCleanerRepository.h) ----------------
#if ! defined ( AirCleanerRepository_H )
#define AirCleanerRepository_H

//--------------------------------------------------- Interfaces utilisées
#include <vector> 
#include "models/sensors/AirCleaner.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AirCleanerRepository>
// Fait office de DAO et récupère les informations voulues sur les AirCleaners
// pour les requêtes des AirCleanerProvider. 
//------------------------------------------------------------------------

class AirCleanerRepository  
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

AirCleaner getAirCleanerById(const string & airCleanerId);

vector<AirCleaner> getAll() const; 

//------------------------------------------------- Surcharge d'opérateurs

//------------------------------------------------- Getters - Setters

//-------------------------------------------- Constructeurs - destructeur

    AirCleanerRepository ( const AirCleanerRepository & unAirCleanerRepository );

    AirCleanerRepository ( );

    ~AirCleanerRepository ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <AirCleanerRepository>

#endif // AirCleanerRepository_H

