//---------- Interface de la classe <CSVLoader> (fichier CSVLoader.h) ----------------
#if ! defined ( CSVLOADER_H )
#define CSVLOADER_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "models/sensors/Sensor.h"
#include "models/sensors/AirCleaner.h"
#include "models/users/PrivateUser.h"
#include "models/users/AirCleanerProviderUser.h"
#include "models/sensors/Measurement.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
enum MeasurementType {
    O3,
    NO2,
    SO2,
    PM10
};

inline MeasurementType stringToMeasurementType(const std::string& str) {
    if (str == "O3") return O3;
    else if (str == "NO2") return NO2;
    else if (str == "SO2") return SO2;
    else if (str == "PM10") return PM10;
    else throw std::invalid_argument("Invalid measurement type: " + str);
}
//------------------------------------------------------------------------
// Rôle de la classe <CSVLoader>
//
//
//------------------------------------------------------------------------

class CSVLoader 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Instantiation publique et statique
    static CSVLoader& Instance();

//----------------------------------------------------- Méthodes publiques

    
    const vector<Sensor>& getSensors() const;
    const vector<AirCleaner>& getAirCleaners() const;
    const vector<PrivateUser>& getUsers() const;
    const vector<AirCleanerProviderUser>& getProviders() const;
    
//------------------------------------------------------------------ PRIVE
private:
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    CSVLoader ( );
    virtual ~CSVLoader ( );

//------------------------------------------------------------- Méthodes privées
    vector<AirCleaner> loadAirCleaners();
    vector<Sensor> loadSensors();
    map<string,vector<MeasurementGroup>> loadMeasurements();
    vector<vector<string>> loadAttributesInfo();
    vector<PrivateUser>  loadUsers(vector<Sensor> sensors);
    vector<AirCleanerProviderUser> loadProviders(vector<AirCleaner> airCleaners);

//---------------------------------------------- Attributs privés
    static CSVLoader instance;

    vector<Sensor> sensors;
    vector<AirCleaner> airCleaners;
    vector<PrivateUser> users;
    vector<AirCleanerProviderUser> providers;

};

//-------------------------------- Autres définitions dépendantes de <CSVLoader>

#endif // CSVLOADER_H

