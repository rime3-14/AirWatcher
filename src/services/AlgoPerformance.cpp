/*************************************************************************
                           AlgoPerformance  
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par Ashley DUONG
    e-mail               : ashley.duong@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <AlgoPerformance> (fichier AlgoPerformance.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include "services/AlgoPerformance.h"


//------------------------------------------------------ Include personnel

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

    void AlgoPerformance::begin(const string & algoName) {
        if (onGoingAlgoStart.has_value()) {
            cout << "Un algorithme est déjà en cours d'exécution : Impossible de débuter l'exécution d'un autre algorithme avant d'avoir terminé celui-ci." << endl;
        } else {
            pair<string, duree_t> p; 
            p.first = algoName; 
            p.second = duree_t::zero(); 
            performances.push_back(p); 
            onGoingAlgoStart = Clock::now();
        }
    }

    void AlgoPerformance::end() {
        if (onGoingAlgoStart.has_value()) {
            TimePoint onGoingAlgoEnd = Clock::now();
            performances.back().second = chrono::duration_cast<duree_t>(onGoingAlgoEnd - onGoingAlgoStart.value());
            onGoingAlgoStart.reset();
        } else {
            cout << "Aucun algorithme en cours d'exécution à terminer." << endl;
        }
    }


    void AlgoPerformance::displayAllPerformances() {
        cout << *this; 
    }

    void AlgoPerformance::displayLastPerformance() {
        if(!performances.empty()) {
            pair<string, duree_t> p = performances.back();
            cout << " Performances du dernier algorithme exécuté : " << endl;  
            cout << "   - Algorithme : " << p.first << endl; 
            if(p.second == duree_t::zero()) {
                cout << "L'algorithme est en cours d'exécution." << endl; 
            } else {
                cout << "   - Temps d'exécution " << (p.second).count() << " ms"<< endl; 
            }
        } else {
            cout << "   Aucun algorithme exécuté depuis le lancement de l'application." << endl; 
        } 
    }

//------------------------------------------------- Surcharge d'opérateurs

//------------------------------------------------- Getters - Setters

vector<pair<string,duree_t>> AlgoPerformance::getPerformances() {
        return performances; 
    }


//-------------------------------------------- Constructeurs - destructeur

AlgoPerformance::AlgoPerformance(const AlgoPerformance & unAlgoPerformance)
    : performances(unAlgoPerformance.performances),
      onGoingAlgoStart(unAlgoPerformance.onGoingAlgoStart)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AlgoPerformance>" << endl;
#endif
} 

AlgoPerformance::AlgoPerformance ()
{
#ifdef MAP
    cout << "Appel au constructeur de <AlgoPerformance>" << endl;
#endif
} 

AlgoPerformance::~AlgoPerformance ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <AlgoPerformance>" << endl;
#endif
} 


//-------------------------------------------- Surcharges d'opérateur
ostream & operator << (ostream & out, AlgoPerformance & algoPerformance) {
    out << "Performances de l'ensemble des algorithmes exécutés jusqu'à présent : " << endl;
    vector<pair<string,duree_t>> allPerformances = algoPerformance.getPerformances(); 

    if(allPerformances.empty()) {
        out << "   Aucun algorithme exécuté depuis le lancement de l'application." << endl; 
    } else {
        for (size_t i = 0; i<allPerformances.size(); i++) {
            pair<string,duree_t> p = allPerformances[i]; 
            out << "    - Algorithme " << i+1 << " | " << p.first << endl; 
            if(p.second == duree_t::zero()) {
                out << "        L'algorithme est en cours d'exécution." << endl; 
            } else {
                out << "        Temps d'exécution : " << p.second.count() << " ms"<< endl;
            }
        } cout << endl; 
    }
    



    return out;   
}
