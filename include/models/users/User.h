#if ! defined ( USER_H )
#define USER_H 

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
// La classe <User> est une classe abstraite qui sert de base pour
// représenter un utilisateur. Elle définit des méthodes virtuelles que les
// classes dérivées doivent implémenter pour gérer différents types d'utilisateurs.
//
//------------------------------------------------------------------------
class User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual User* authentificateUser(string login) const = 0;
    // Mode d'emploi :
    // Méthode virtuelle pure qui permet d'authentifier un utilisateur.
    // Les classes dérivées doivent fournir leur propre implémentation.
    //
    // Contrat : Aucun.

//------------------------------------------------- Surcharge d'opérateurs
// (Aucune surcharge d'opérateurs définie dans ce fichier.)

//-------------------------------------------- Constructeurs - destructeur
    User();
    // Mode d'emploi :
    // Constructeur par défaut qui initialise un utilisateur
    // par défaut ou vides.
    //
    // Contrat : Aucun.

    User(string id); 

    virtual ~User();
    // Mode d'emploi :
    // Destructeur virtuel pour permettre une destruction correcte des
    // objets dérivés et pour libérer la mémoire allouée dynamiquement.
    //
    // Contrat : Aucun.

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
// (Aucune méthode protégée n'est définie.)

//----------------------------------------------------- Attributs protégés
 
string id;

};

#endif
