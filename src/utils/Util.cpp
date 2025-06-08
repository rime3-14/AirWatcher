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
#include <iostream> 

//------------------------------------------------------ Include personnel
#include "utils/Util.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

float calculateDistance(float centerLat, float centerLong, float latitude, float longitude) {
// Retourne la distance entre un centre et un point en degrés (pour l'instant).
    float distanceEuclidienneDegre  = sqrt ((latitude-centerLat)*(latitude-centerLat) + (longitude - centerLong)*(longitude - centerLong)); 
    return distanceEuclidienneDegre; 
}

void displayDate(time_t timestamp)
{
    struct tm* timeinfo = localtime(&timestamp);

    std::cout
              << (timeinfo->tm_mday < 10 ? "0" : "") << timeinfo->tm_mday << "/"
              << (timeinfo->tm_mon + 1 < 10 ? "0" : "") << (timeinfo->tm_mon + 1) << "/"
              << (1900 + timeinfo->tm_year) << " "
              << (timeinfo->tm_hour < 10 ? "0" : "") << timeinfo->tm_hour << ":"
              << (timeinfo->tm_min < 10 ? "0" : "") << timeinfo->tm_min << ":"
              << (timeinfo->tm_sec < 10 ? "0" : "") << timeinfo->tm_sec
              << std::endl;
}