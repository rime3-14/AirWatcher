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

vector<vector<string>> CSVLoader::loadAttributesInfo(){
    vector<vector<string>> attributesInfo;
    
    ifstream ifsAttributes;
    ifsAttributes.open("data/attributes.csv");
    if(!ifsAttributes.is_open()){
        cout << "Erreur d'ouverture du fichier" << endl;
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



map<string,vector<Measurement>> CSVLoader::loadMeasurements(vector<Sensor>& sensors){
    vector<vector<string>> attributesInfo = loadAttributesInfo();
    map<string,vector<Measurement>> measurementsBySensorId;
    
    ifstream ifsMeasurements;
    string fileName = "data/measurements.csv";
    ifsMeasurements.open(fileName);
    if(!ifsMeasurements.is_open()){
        cout << "Erreur d'ouverture du fichier" << endl;
        return measurementsBySensorId;
    }

    string line;
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
            cout << "Erreur de conversion de la valeur : " << stringValue << endl;
            continue;
        }
        
        // Trouver l'attribut correspondant
        string unit, description;
        for (std::vector<vector<string>>::iterator i = attributesInfo.begin() ; i != attributesInfo.end(); i++)
        {
            if ((*i)[0] == attributeId)
            {
                unit = (*i)[1];
                description = (*i)[2];
                break;
            }
        }

        Measurement measurement(attributeId, unit, description, value, timestamp);  
        measurementsBySensorId[sensorId].push_back(measurement);
    }
    return measurementsBySensorId;
}

vector<Sensor> CSVLoader::loadSensors(){
    map<string,vector<Measurement>> allMeasurementsBySensorId = loadMeasurements(sensors);
    vector<Sensor> sensors;

    ifstream ifs;
    ifs.open("data/sensors.csv");
    if(!ifs.is_open()){
        cout << "Erreur d'ouverture du fichier" << endl;
        return sensors;
    }
    string line;
    while(getline(ifs, line)){
        stringstream ss(line);
        string id, latitudeString, longitudeString;
        getline(ss, id, ';');
        getline(ss, latitudeString, ';');
        getline(ss, longitudeString, ';');


        vector<Measurement> measurements;
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
void CSVLoader::loadUsers(){

}
void CSVLoader::loadProviders(){

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
const vector<string>& CSVLoader::getFiles() const{
    return files;
}

void CSVLoader::setFiles(const vector<string>& files){
    // TODO : créer un vector contenant les noms des fichiers CSV
    this->files = files;
}
void CSVLoader::setSensors(const vector<Sensor>& sensors){
    // TODO : appeler la méthode de loadSensors
    this->sensors = sensors;
}
void CSVLoader::setUsers(const vector<PrivateUser>& users){
    this->users = users;
}
void CSVLoader::setProviders(const vector<AirCleanerProviderUser>& providers){
    this->providers = providers;
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

CSVLoader::CSVLoader ( )
{
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

