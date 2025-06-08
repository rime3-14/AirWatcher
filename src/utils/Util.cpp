/*************************************************************************
                           Util  
                             -------------------
    début                : 16/05/2025
    copyright            : (C) $YEAR$ par Ashley DUONG
    e-mail               : ashley.duong@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Util> (fichier Util.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <math.h>

//------------------------------------------------------ Include personnel
#include "utils/Util.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

float calculateDistance(float centerLat, float centerLong, float latitude, float longitude) {
// Retourne la distance entre un centre et un point en degrés (pour l'instant).
    float distanceEuclidienneDegre  = sqrt ((latitude-centerLat)*(latitude-centerLat) + (longitude - centerLong)*(longitude - centerLong)); 
    return distanceEuclidienneDegre; 
}