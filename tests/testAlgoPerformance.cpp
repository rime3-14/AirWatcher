#include <iostream>
#include <thread>    
#include <chrono>     
#include <cassert>
#include "services/AlgoPerformance.h"

using namespace std;

int main() {
    cout << "Réalisation des tests unitaires pour la classe <AlgoPerformance>" << endl;

    AlgoPerformance algoPerformance;

    // Test début / fin d'un algorithme simulé
    algoPerformance.begin("AlgorithmeTest1");
    this_thread::sleep_for(chrono::milliseconds(100)); 
    algoPerformance.end();

    vector<pair<string, duree_t>> perfList = algoPerformance.getPerformances();
    assert(perfList.size() == 1);
    assert(perfList[0].first == "AlgorithmeTest1");
    assert(perfList[0].second.count() >= 100); 

    cout << "Test 1 passé : début et fin enregistrés correctement." << endl;

    // Test displayLastPerformance()
    cout << "Affichage de la dernière performance : " << endl;
    algoPerformance.displayLastPerformance();

    // Test avec la simulation de l'exécution d’un second algorithme
    algoPerformance.begin("AlgorithmeTest2");
    this_thread::sleep_for(chrono::milliseconds(50));
    algoPerformance.end();

    assert(algoPerformance.getPerformances().size() == 2);
    cout << "Test 2 passé : deuxième algorithme enregistré correctement." << endl;

    // Test affichage de toutes les performances
    cout << "Affichage de toutes les performances : " << endl;
    algoPerformance.displayAllPerformances();

    // Test surcharge de l'opérateur <<
    cout << "Test de la surcharge opérateur << : " << endl;
    cout << algoPerformance;

    // Test displayLastPerformance() et displayAllPerformances() lorsqu'un algorithme est en cours d'exécution
    cout << "Tests dans le cas où un algorithme est en cours d'exécution : << : " << endl;
    algoPerformance.begin("AlgorithmeTest3"); 
    algoPerformance.displayAllPerformances();
    algoPerformance.displayLastPerformance();
    algoPerformance.begin("AlgorithmeTest4"); 
    algoPerformance.end(); 
    algoPerformance.end(); 

    cout << "\nTous les tests unitaires pour la classe <AlgoPerformance> ont été validés." << endl;
    return EXIT_SUCCESS;
}