//---------- Réalisation de la classe <CSVLoader> (fichier CSVLoader.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
//------------------------------------------------------ Include personnel
#include "dataAccess/CSVLoader.h"
using namespace std;

//------------------------------------------------------------- Constantes
CSVLoader CSVLoader::instance=CSVLoader();
//----------------------------------------------------------------- PUBLIC

//--------------------------------------------------Méthodes
CSVLoader& CSVLoader::Instance() {
    static CSVLoader instance;
    return instance;
}

vector<vector<string>> CSVLoader::loadAttributesInfo() {
    vector<vector<string>> attributesInfo;
    
    ifstream ifsAttributes;
    ifsAttributes.open("data/attributes.csv");
    if(!ifsAttributes.is_open()){
        cout << "Erreur loadAttributesInfo() : erreur d'ouverture du fichier" << endl;
        return attributesInfo;
    }
    string line;
    getline(ifsAttributes, line); // Ignore la première ligne (en-tête)
    while(getline(ifsAttributes, line)){
        stringstream ss(line);
        string id, unit, description;
        getline(ss, id, ';');
        getline(ss, unit, ';');
        getline(ss, description, ';');
        
        vector<string> attributeInfo = {id, unit, description};
        attributesInfo.push_back(attributeInfo);
    }
    return attributesInfo;
}

map<string,vector<MeasurementGroup>> CSVLoader::loadMeasurements(){
    vector<vector<string>> attributesInfo = loadAttributesInfo();
    map<string,vector<MeasurementGroup>> measurementsBySensorId;
    
    ifstream ifsMeasurements;
    string fileName = "data/measurements.csv";
    ifsMeasurements.open(fileName);
    if(!ifsMeasurements.is_open()){
        cout << "Erreur loadMeasurements() : erreur d'ouverture du fichier" << endl;
        return measurementsBySensorId;
    }

    string line;
    MeasurementGroup currentGroup;
    while(getline(ifsMeasurements, line)){
        stringstream ss(line);
        string timestamp, sensorId, attributeId, stringValue;
        float value;
        getline(ss, timestamp, ';');
        getline(ss, sensorId, ';');
        getline(ss, attributeId, ';');
        getline(ss, stringValue, ';');

        // Convertir la valeur string en float
        try {
            value = stof(stringValue);
        } catch (const invalid_argument& e) {
            cout << "Erreur loadMeasurements() : erreur de conversion de la valeur : " << stringValue << endl;
            continue;
        }
        
        // Trouver l'attribut correspondant
        MeasurementType attributeIdEnum; ;
        string unit, description;
        bool found = false;
        for (const auto& attr : attributesInfo)
        {
            if (attr[0] == attributeId)
            {
                try {
                    attributeIdEnum = stringToMeasurementType(attr[0]);
                    unit = attr[1];
                    description = attr[2];
                    found = true;
                } catch (const std::invalid_argument& e) {
                    cout << "Erreur loadMeasurements() : erreur de type de mesure : " << attr[0] << endl;
                    found = false;
                }
                break;
            }
        }

        if (!found) {
            cout << "Attribut non trouvé ou invalide : " << attributeId << endl;
            continue;
        }

        Measurement measurement(unit, description, value);
        switch(attributeIdEnum) {
            case O3: currentGroup.measurementO3 = measurement; break;
            case NO2: currentGroup.measurementNO2 = measurement; break;
            case SO2: currentGroup.measurementSO2 = measurement; break;
            case PM10: currentGroup.measurementPM10 = measurement; measurementsBySensorId[sensorId].push_back(currentGroup); break;
        }
    }
    return measurementsBySensorId;
}

vector<Sensor> CSVLoader::loadSensors(){
    map<string,vector<MeasurementGroup>> allMeasurementsBySensorId = loadMeasurements();
    vector<Sensor> sensors;

    ifstream ifs;
    ifs.open("data/sensors.csv");
    if(!ifs.is_open()){
        cout << "Erreur loadSensors() : erreur d'ouverture du fichier" << endl;
        return sensors;
    }
    string line;
    while(getline(ifs, line)){
        stringstream ss(line);
        string id, latitudeString, longitudeString;
        getline(ss, id, ';');
        getline(ss, latitudeString, ';');
        getline(ss, longitudeString, ';');


        vector<MeasurementGroup> measurements;
        // Add measurements to the sensor
        if (allMeasurementsBySensorId.find(id) != allMeasurementsBySensorId.end()) {
            measurements = allMeasurementsBySensorId[id];
        }

        // Convert latitude and longitude strings to float
        float latitude = stof(latitudeString);
        float longitude = stof(longitudeString);

        Sensor sensor(id, latitude, longitude, true, measurements);
        sensors.push_back(sensor);
    }

    return sensors;
}

vector<PrivateUser> CSVLoader::loadUsers(vector<Sensor> sensors){
    vector<PrivateUser> users;

    ifstream ifs;
    ifs.open("data/users.csv");
    if(!ifs.is_open()){
        cout << "Erreur loadUsers() : erreur d'ouverture du fichier" << endl;
        return users;
    }
    string line;
    while(getline(ifs, line)){
        stringstream ss(line);
        string id, sensorId;
        getline(ss, id, ';');
        getline(ss, sensorId, ';');

        // Check if the sensorId is valid
        bool sensorFound = false;
        for (const auto& sensor : sensors) {
            if (sensor.getId() == sensorId) {
                sensorFound = true;
                break; 
            }
        }
        if(!sensorFound){
            cout << "Erreur loadUsers() : le capteur avec l'ID " << sensorId << " n'existe pas." << endl;
            continue; // Skip this user if the sensor does not exist
        }
        else {
            bool userFound = false;
            // Check if the user already exists
            for (auto& user : users) {
                if (user.getId() == id) {
                    userFound = true;
                    user.addSensor(sensorId);
                    break; 
                }
            }

            // If the user does not exist, create a new one
            if (!userFound) {
                PrivateUser user(id);
                user.addSensor(sensorId);
                users.push_back(user);
            }
        }
    }
    return users;
}

vector<AirCleaner> CSVLoader::loadAirCleaners(){
    vector<AirCleaner> airCleaners;

    ifstream ifs;
    ifs.open("data/cleaners.csv");
    if(!ifs.is_open()){
        cout << "Erreur loadAirCleaners() : erreur d'ouverture du fichier" << endl;
        return airCleaners;
    }
    string line;
    while(getline(ifs, line)){
        stringstream ss(line);
        string id, latitudeString, longitudeString, debut, fin;
        getline(ss, id, ';');
        getline(ss, latitudeString, ';');
        getline(ss, longitudeString, ';');
        getline(ss, debut, ';');
        getline(ss, fin, ';');
 
        // Convert latitude and longitude strings to float
        float latitude = stof(latitudeString);
        float longitude = stof(longitudeString);

        // Convert debut and fin to time_t
        struct tm tmDebut = {};
        struct tm tmFin = {};
        strptime(debut.c_str(), "%Y-%m-%d %H:%M:%S", &tmDebut);
        strptime(fin.c_str(), "%Y-%m-%d %H:%M:%S", &tmFin);
        time_t debutTime = mktime(&tmDebut);
        time_t finTime = mktime(&tmFin);

        AirCleaner airCleaner(id, latitude, longitude, debutTime, finTime);
        airCleaners.push_back(airCleaner);
    }
    return airCleaners;
}

vector<AirCleanerProviderUser> CSVLoader::loadProviders(vector<AirCleaner> airCleaners){

    vector<AirCleanerProviderUser> providers;

    ifstream ifs;
    ifs.open("data/providers.csv");
    if(!ifs.is_open()){
        cout << "Erreur loadProviders() : erreur d'ouverture du fichier" << endl;
        return providers;
    }
    string line;
    while(getline(ifs, line)){
        stringstream ss(line);
        string id, airCleanerId;
        getline(ss, id, ';');
        getline(ss, airCleanerId, ';');

        // Check if the airCleanerId is valid
        bool airCleanerFound = false;
        for (const auto& airCleaner : airCleaners) {
            if (airCleaner.getId() == airCleanerId) {
                airCleanerFound = true;
                break; 
            }
        }
        if(!airCleanerFound){
            cout << "Erreur loadProviders() : le capteur avec l'ID " << airCleanerId << " n'existe pas." << endl;
            continue;
        }
        else {
            bool providerFound = false;
            // Check if the provider already exists
            for (auto& provider : providers) {
                if (provider.getId() == id) {
                    providerFound = true;
                    provider.addAirCleaner(airCleanerId);
                    break; 
                }
            }

            // If the provider does not exist, create a new one
            if (!providerFound) {
                vector<string> providerSensors;
                providerSensors.push_back(airCleanerId);
                AirCleanerProviderUser provider(id, providerSensors);
                providers.push_back(provider);
            }
        }
    }
    return providers;
}

const vector<Sensor>& CSVLoader::getSensors() const{
    return sensors;
}
const vector<PrivateUser>& CSVLoader::getUsers() const{
    return users;
}
const vector<AirCleanerProviderUser>& CSVLoader::getProviders() const{
    return providers;
}
const vector<AirCleaner>& CSVLoader::getAirCleaners() const{
    return airCleaners;
}
//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

CSVLoader::CSVLoader ( )
{
    sensors = loadSensors();
    users = loadUsers(sensors);
    airCleaners = loadAirCleaners();
    providers = loadProviders(airCleaners);
#ifdef MAP
    cout << "Appel au constructeur de <CSVLoader>" << endl;
#endif
}


CSVLoader::~CSVLoader ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <CSVLoader>" << endl;
#endif
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

