/*************************************************************************
                           Measurement  -  description
                             -------------------
    début                : 16/05/2025
    copyright            : (C) 2025 par Bindech Rida
    e-mail               : rida.bindech@gmail.com
*************************************************************************/

//---------- Réalisation de la classe <Measurement> (fichier Measurement.h) ------------
#if ! defined ( MEASUREMENT_H )
#define MEASUREMENT_H

//--------------------------------------------------- Interfaces utilisées
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
// Rôle de la classe <Measurement>
// Permet de regrouper les caractéristiques d'une mesure d'un seul type (O3, NO2, SO2 ou P10)
// parmi les 4 qui permettent de calculer la qualité de l'air mesurée par 
// un capteur à une date précise. Est un élément de Struct<MeasurementGroup>.
//
//------------------------------------------------------------------------

class Measurement
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    // Getters
    string getUnit() const;
    string getDescription() const;
    float getValue() const;

    // Setters
    void setUnit(const string& newunit);
    void setDescription(const string& newDescription);
    void setValue(float newvalue);

//------------------------------------------------- Surcharge d'opérateurs
    Measurement & operator = ( const Measurement & unMeasurement );


//-------------------------------------------- Constructeurs - destructeur
    Measurement ( const Measurement & unMeasurement );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Measurement (string ununit, string unDescription, float unvalue);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Measurement ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Measurement ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string unit;
    string description;
    float value;
};

//-------------------------------- Autres définitions dépendantes de <Measurement.h>
// ------------------------------- Struct <MeasurementGroup>
// Rôle du Struct <MeasurementGroup>
// Permet de regrouper les 4 types de mesures de type <Measurement>
//  recueillies par un capteur à une date précise 
// qui sont nécessaires pour calculer la qualité de l'air.

struct MeasurementGroup {
    time_t timestamp;
    Measurement measurementO3; 
    Measurement measurementNO2; 
    Measurement measurementSO2; 
    Measurement measurementPM10; 
    
};

ostream& operator<<(ostream& os, const Measurement& m);
ostream& operator<<(ostream& os, const MeasurementGroup& group);

#endif // MEASUREMENT_H


