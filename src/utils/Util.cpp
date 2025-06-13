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
#include <cmath>
#include <iostream> 
#include <iomanip>
#include <sstream>

//------------------------------------------------------ Include personnel
#include "utils/Util.h"
//------------------------------------------------------------- Constantes
const double RAYON_TERRE = 6371000.0; // en mètres
//----------------------------------------------------------------- PUBLIC

float calculateDistanceEuclidienne(float centerLat, float centerLong, float latitude, float longitude) {
// Retourne la distance entre un centre et un point en degrés (pour l'instant).
    float distanceEuclidienneDegre  = sqrt ((latitude-centerLat)*(latitude-centerLat) + (longitude - centerLong)*(longitude - centerLong)); 
    return distanceEuclidienneDegre; 

}

// Convertit des degrés en radians
float deg2rad(float deg) {
    return deg * M_PI / 180.0;
}

float calculateDistance(float lat1, float lon1, float lat2, float lon2) {
    // Calcule la distance entre deux points (lat1, lon1) et (lat2, lon2) en mètres
    lat1 = deg2rad(lat1);
    lon1 = deg2rad(lon1);
    lat2 = deg2rad(lat2);
    lon2 = deg2rad(lon2);

    float dlat = lat2 - lat1;
    float dlon = lon2 - lon1;

    float a = sin(dlat/2) * sin(dlat/2) +
               cos(lat1) * cos(lat2) * sin(dlon/2) * sin(dlon/2);

    float c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return RAYON_TERRE * c;
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


std::string dateToString(time_t timestamp) {
    struct tm* timeinfo = localtime(&timestamp);
    std::ostringstream oss;
    oss << std::setfill('0')
        << std::setw(2) << timeinfo->tm_mday << "/"
        << std::setw(2) << (timeinfo->tm_mon + 1) << "/"
        << (1900 + timeinfo->tm_year) << " "
        << std::setw(2) << timeinfo->tm_hour << ":"
        << std::setw(2) << timeinfo->tm_min << ":"
        << std::setw(2) << timeinfo->tm_sec;
    return oss.str();
}

time_t stringToDate(const std::string& input) {
    std::tm tm = {};
    std::istringstream ss(input);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    if (ss.fail()) {
        throw std::runtime_error("Failed to parse date/time");
    }
    tm.tm_isdst = -1; 
    return std::mktime(&tm);
}
