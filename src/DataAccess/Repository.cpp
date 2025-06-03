/*************************************************************************
                           Repository  -  description
                             -------------------
    début                : 27/05/2025
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Repository> (fichier Repository.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
#include "include/dataAccess/Repository.h"

//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs
Repository & Repository::operator = ( const Repository & unRepository )
// Algorithme :
//
{

} 

//------------------------------------------------- Getters - Setters

//-------------------------------------------- Constructeurs - destructeur
Repository::Repository ( const Repository & unRepository )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Repository>" << endl;
#endif
} 

Repository::Repository ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Repository>" << endl;
#endif
} 

Repository::~Repository ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Repository>" << endl;
#endif
} 
