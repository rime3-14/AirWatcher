//---------- Interface de la classe <CSVLoader> (fichier CSVLoader.h) ----------------
#if ! defined ( CSVLOADER_H )
#define CSVOADER_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
#include <vector>
#include "Sensor.h"
#include "PrivateUser.h"
#include "AirCleanerProvider.h"
#include "Measurement.h"

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
    const vector<AirCleanerProvider>& getProviders() const;
    const vector<string>& getFiles() const;

    void setFiles(const vector<string>& files);
    void setSensors(const vector<Sensor>& sensors);
    void setUsers(const vector<PrivateUser>& users);
    void setProviders(const vector<AirCleanerProvider>& providers);
    
//------------------------------------------------------------------ PRIVE
private:
//------------------------------------------------- Surcharge d'opérateurs
    CSVLoader & operator = ( const CSVLoader & unEnsemble );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    CSVLoader ( const CSVLoader& );

    CSVLoader ( );

    virtual ~CSVLoader ( );

//------------------------------------------------------------- Méthodes privées
    void loadFiles(const vector<string>& files);
    vector<Sensor> loadSensors();
    vector<Measurement> loadMeasurements(vector<Sensor>& sensors);
    vector<vector<string>> loadAttributesInfo();

    void loadUsers();
    void loadProviders();
//---------------------------------------------- Attributs privés
    static CSVLoader instance;
    vector<string> files;
    vector<Sensor> sensors;
    vector<PrivateUser> users;
    vector<AirCleanerProvider> providers;
};

//-------------------------------- Autres définitions dépendantes de <CSVLoader>

#endif // CSVLOADER_H

