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
#include "models/users/PrivateUser.h"
#include "models/users/AirCleanerProviderUser.h"
#include "models/sensors/Measurement.h"

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

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
    const vector<PrivateUser>& getUsers() const;
    const vector<AirCleanerProviderUser>& getProviders() const;
    const vector<string>& getFiles() const;

    void setFiles(const vector<string>& files);
    void setSensors(const vector<Sensor>& sensors);
    void setUsers(const vector<PrivateUser>& users);
    void setProviders(const vector<AirCleanerProviderUser>& providers);
    
//------------------------------------------------------------------ PRIVE
private:
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    CSVLoader ( );
    virtual ~CSVLoader ( );

//------------------------------------------------------------- Méthodes privées
    vector<Sensor> loadSensors();
    map<string,vector<Measurement>> loadMeasurements(vector<Sensor>& sensors);
    vector<vector<string>> loadAttributesInfo();

    void loadUsers();
    void loadProviders();
//---------------------------------------------- Attributs privés
    static CSVLoader instance;
    vector<string> files;
    vector<Sensor> sensors;
    vector<PrivateUser> users;
    vector<AirCleanerProviderUser> providers;
};

//-------------------------------- Autres définitions dépendantes de <CSVLoader>

#endif // CSVLOADER_H

