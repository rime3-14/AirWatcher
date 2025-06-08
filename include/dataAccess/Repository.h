/*************************************************************************
                           Repository  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Repository> (fichier Repository.h) ----------------
#if ! defined ( Repository_H )
#define Repository_H

//--------------------------------------------------- Interfaces utilisées
#include <vector> 
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Repository>
// Classe abstraite qui regroupe l'ensemble des divers Repository qu'il y a, 
// autrement dit SensorRepository, UserRepository et MeasurementRepository.
// Les Repository font office de DAO et permettent de récupérer certaines
// données souhaitées dans les requêtes appelant les services.
//------------------------------------------------------------------------

template <typename T>
class Repository 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
virtual vector<T> getAll() const = 0;
// Méthode qui permet de déclarer la classe comme abstraite.

//------------------------------------------------- Surcharge d'opérateurs
    Repository & operator = ( const Repository & unRepository );
    // Mode d'emploi :
    //
    // Contrat :

//------------------------------------------------- Getters - Setters

//-------------------------------------------- Constructeurs - destructeur

    Repository ( const Repository & unRepository );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Repository ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Repository ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Repository>


#endif // Repository_H

