/*************************************************************************
                           AirCleanerRepository  
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par Ashley DUONG
    e-mail               : ashley.duong@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <AirCleanerRepository> (fichier AirCleanerRepository.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include "dataAccess/AirCleanerRepository.h"
#include "dataAccess/CSVLoader.h"
using namespace std;

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

AirCleaner AirCleanerRepository::getAirCleanerById(const string & AirCleanerId) {
    CSVLoader& csvLoader = CSVLoader::Instance();
    vector<AirCleaner> allAirCleaners = csvLoader.getAirCleaners(); 
    for (AirCleaner & aC : allAirCleaners) {
        if(aC.getId() == AirCleanerId) {
            return aC; 
        }
    }
    cout << "Aucun AirCleaner trouvé avec l'ID : " << AirCleanerId << endl;
    return AirCleaner(); 
}


vector<AirCleaner> AirCleanerRepository::getAll() const {
    CSVLoader& csvLoader = CSVLoader::Instance();
    return csvLoader.getAirCleaners();
}



//------------------------------------------------- Surcharge d'opérateurs

//------------------------------------------------- Getters - Setters

//-------------------------------------------- Constructeurs - destructeur
AirCleanerRepository::AirCleanerRepository ( const AirCleanerRepository & unAirCleanerRepository )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AirCleanerRepository>" << endl;
#endif
} 

AirCleanerRepository::AirCleanerRepository ()
{
#ifdef MAP
    cout << "Appel au constructeur de <AirCleanerRepository>" << endl;
#endif
} 

AirCleanerRepository::~AirCleanerRepository ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <AirCleanerRepository>" << endl;
#endif
} 
