/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par Bindech Rida
    e-mail               : rida.bindech@gmail.com
*************************************************************************/

//---------- Réalisation de la classe <Sensor> (fichier Sensor.h) ------------
#if !defined(SENSOR_H)
#define SENSOR_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Measurement.h"

//------------------------------------------------------------------------
// Rôle de la classe <Sensor>
// Représente un capteur avec un identifiant, des coordonnées géographiques,
// un indicateur de fiabilité et une collection de mesures.
//------------------------------------------------------------------------

class Sensor
{
//----------------------------------------------------------------- PUBLIC
public:
    //----------------------------------------------------- Méthodes publiques

    // Getters
    std::string GetId() const;
    float GetLatitude() const;
    float GetLongitude() const;
    bool GetReliability() const;
    Measurement* GetMeasurements() const;

    // Setters
    void SetId(const std::string& newId);
    void SetLatitude(float newLatitude);
    void SetLongitude(float newLongitude);
    void SetReliability(bool newReliability);
    void SetMeasurements(Measurement* newMeasurements);

    //------------------------------------------------- Surcharge d'opérateurs
    Sensor& operator=(const Sensor& unSensor);

    //-------------------------------------------- Constructeurs - destructeur
    Sensor(); // Constructeur par défaut
    Sensor(const Sensor& unSensor); // Constructeur de copie
    Sensor(std::string unId, float unLatitude, float unLongitude, bool unReliability, Measurement* unMeasurements);
    virtual ~Sensor();

//------------------------------------------------------------------ PRIVE
protected:
    //----------------------------------------------------- Attributs protégés
    std::string id;
    float latitude;
    float longitude;
    bool reliability;
    Measurement* measurements;
};

#endif // SENSOR_H