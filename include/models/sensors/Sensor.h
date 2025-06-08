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
#include <vector>
#include <iostream>
#include <optional>
#include "models/users/PrivateUser.h"
#include "models/sensors/Measurement.h"

using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <Sensor>
// Représente un capteur avec un identifiant, des coordonnées géographiques,
// un indicateur de fiabilité, un fournisseur et une collection de mesures groupées.
//------------------------------------------------------------------------

class Sensor
{
//----------------------------------------------------------------- PUBLIC
public:
    //----------------------------------------------------- Méthodes publiques

    // Getters
    std::string getId() const;
    float getLatitude() const;
    float getLongitude() const;
    bool getReliability() const;
    vector<MeasurementGroup> getMeasurements() const;

    // Setters
    void setId(const std::string& newId);
    void setLatitude(float newLatitude);
    void setLongitude(float newLongitude);
    void setReliability(bool newReliability);
    void setProvider(const PrivateUser& newProvider);
    void setMeasurements(const vector<MeasurementGroup>& newMeasurements);

    //------------------------------------------------- Surcharge d'opérateurs
    Sensor& operator=(const Sensor& unSensor);
    bool operator==(const Sensor& unSensor);

    //-------------------------------------------- Constructeurs - destructeur
    Sensor(); // Constructeur par défaut
    Sensor(const Sensor& unSensor); // Constructeur de copie
    Sensor(const std::string& unId, float unLatitude, float unLongitude, bool unReliability, const std::vector<MeasurementGroup>& unMeasurements);
    virtual ~Sensor();

//------------------------------------------------------------------ PRIVE
protected:
    //----------------------------------------------------- Attributs protégés
    std::string id;
    float latitude;
    float longitude;
    bool reliability;
    optional<PrivateUser> provider; // Optional to allow for sensors without a provider
    vector<MeasurementGroup> measurements;
};

#endif // SENSOR_H

std::ostream& operator<<(std::ostream& os, const Sensor& sensor);