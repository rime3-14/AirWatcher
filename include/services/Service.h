/*************************************************************************
                           Service  -  classe abstraite
                             -------------------
    début                : 26/05/2025
    copyright            : (C) 2025 par Bindech Rida
    e-mail               : rida.bindech@gmail.com
*************************************************************************/

//---------- Réalisation de la classe <Service> (fichier Service.h) ------------
#if ! defined ( SERVICE_H )
#define SERVICE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Service>
//
// Classe abstraite servant de base aux différents services disponibles
// dans l'application. Toute classe dérivant de Service devra implémenter
// les méthodes virtuelles pures définies ici.
//------------------------------------------------------------------------

class Service
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual void Executer() = 0;
    // Mode d'emploi :
    //  Méthode pure virtuelle que les classes dérivées doivent implémenter.
    // Contrat :
    //  Doit être surchargée dans toute classe héritant de Service.

//-------------------------------------------- Constructeurs - destructeur
    Service ( );
    // Mode d'emploi :
    //  Constructeur par défaut

    virtual ~Service ( );
    // Mode d'emploi :
    //  Destructeur virtuel

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//------------------------------- Autres définitions dépendantes de <Service.h>

#endif // SERVICE_H