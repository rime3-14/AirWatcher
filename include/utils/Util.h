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
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de <Util>
// Permet de définir des fonctions utilitaires comme le calcul de distance
// entre deux points géographiques qui peuvent être utilisées dans plusieurs classes.
//------------------------------------------------------------------------


float calculateDistance(float centerLat, float centerLong, float latitude, float longitude); 

#endif // Util_H

