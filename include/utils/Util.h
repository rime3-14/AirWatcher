/*************************************************************************
                           Util  
                             -------------------
    début                : 06/06/2025
    copyright            : (C) 2025 par Ashley DUONG
    e-mail               : ashley.duong@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Util> (fichier Util.h) ----------------
#if ! defined ( Util_H )
#define Util_H

//--------------------------------------------------- Interfaces utilisées
#include <ctime>
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de <Util>
// Permet de définir des fonctions utilitaires qui peuvent être utilisées 
// dans plusieurs classes.
//------------------------------------------------------------------------

float calculateDistance(float centerLat, float centerLong, float latitude, float longitude);
// Calcule la distance entre un centre et un point en degrés.

void displayDate(time_t timestamp); 
//  Affiche la date au format JJ/MM/AAAA HH:MM:SS à partir d'un timestamp.

std::string dateToString(time_t timestamp);
// Convertit un timestamp en une chaîne de caractères au format JJ/MM/AAAA HH:MM:SS.

#endif // Util_H

