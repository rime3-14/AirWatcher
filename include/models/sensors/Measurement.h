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


//------------------------------------------------------------------------
// Rôle de la classe <Measurement>
// Permet de lister les caractéristiques d'une mesure d'un seul type (O3, NO2, SO2 ou P10)
// d'un capteur à une date précise. 
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
    // Mode d'emploi :
    //
    // Contrat :
    //


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
// Permet de regrouper les 4 types de mesures recueillies par un capteur à une date précise 
// qui sont nécessaires pour calculer la qualité de l'air.
struct MeasurementGroup {
    time_t timestamp;
    Measurement measurementO3;
    Measurement measurementNO2; 
    Measurement measurementSO2; 
    Measurement measurementP10; 
};

#endif // MEASUREMENT_H

