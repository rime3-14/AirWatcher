/*************************************************************************
                           AlgoPerformance  
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par Ashley DUONG    
    e-mail               : ashley.duong@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <AlgoPerformance> (fichier AlgoPerformance.h) ----------------
#if ! defined ( AlgoPerformance_H )
#define AlgoPerformance_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <vector> 
#include <ctime>
#include <string>
#include <chrono>
#include <optional>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
using duree_t = chrono::milliseconds;
using Clock = std::chrono::high_resolution_clock;
using TimePoint = Clock::time_point;
//------------------------------------------------------------------------
// Rôle de la classe <AlgoPerformance>
// Permet de stocker et d'afficher les performances de l'ensemble des algorithmes appelés
// Par l'utilisateur au cours de l'exécution de l'application. 
//------------------------------------------------------------------------

class AlgoPerformance  
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void displayAllPerformances(); 

    void displayLastPerformance(); 
    // Contrat : Affiche le dernier algorithme exécuté dans l'application et
    // son temps d'exécution. Si un algorithme est en cours d'exécution, 
    // affiche les informations de celui d'avant. Si aucun algorithme n'a 
    // encore été exécuté, affiche un message adapté.

    void begin(const string & algoName); 
    // Contrat : Permet de marquer le début de l'exécution de l'algorithme 
    // "algoName" exécuté juste après. On considérera le délai moindre.
    // Initialise le stockage de ces informations.
    // Pré-conditions : On suppose que les algorithmes sont exécutés successivement
    // l'un après l'autre. Impossibilité de calculer la performance de deux algorithmes
    // exécutés en simultané. Le premier doit être terminé avant.

    void end();
    // Contrat : Permet de marquer la fin de l'exécution de l'algorithme
    // en cours. Met à jour les informations sur le temps d'exécution dans 
    // vector<> performances.

//------------------------------------------------- Surcharge d'opérateurs

//------------------------------------------------- Getters - Setters
    vector<pair<string,duree_t>> getPerformances();
//-------------------------------------------- Constructeurs - destructeur

    AlgoPerformance ( const AlgoPerformance & unAlgoPerformance );

    AlgoPerformance ( );

    ~AlgoPerformance ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    vector<pair<string,duree_t>> performances;
    optional<TimePoint> onGoingAlgoStart; 

};

//-------------------------------- Autres définitions dépendantes de <AlgoPerformance>
// Surchage d'opérateurs
ostream & operator << ( ostream & out, AlgoPerformance & algoPerformance);

#endif // AlgoPerformance_H

