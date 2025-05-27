#if ! defined ( SERVICE_H )
#define SERVICE_H 

//--------------------------------------------------- Interfaces utilisées
// (Aucune interface externe n'est utilisée.)

using namespace std;

//------------------------------------------------------------- Constantes
// (Aucune constante n'est définie dans ce fichier.)

//------------------------------------------------------------------ Types
// (Aucun type supplémentaire n'est défini en dehors de la classe.)

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
// La classe <Service> est une classe abstraite qui sert de base pour
// représenter un service. Elle définit des méthodes virtuelles que les
// classes dérivées doivent implémenter pour gérer différents types de services.
//
//------------------------------------------------------------------------
class Service
{
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


    // Méthodes virtuelles pures à définir dans les classes filles 
};



#endif
