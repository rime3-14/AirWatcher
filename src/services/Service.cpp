/*************************************************************************
                           Service  -  Interface abstraite
                             -------------------
    début                : 26/05/2025
    copyright            : (C) 2025 par Bindech Rida
    e-mail               : rida.bindech@gmail.com
*************************************************************************/

//---------- Réalisation de la classe <Service> (fichier Service.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "services/Service.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur
Service::Service ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de Service (abstraite)" << endl;
#endif
} //----- Fin de Service

Service::~Service ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de Service (abstraite)" << endl;
#endif
} //----- Fin de ~Service

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées