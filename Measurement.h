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

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Measurement>
//
//
//------------------------------------------------------------------------

class Measurement
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    // Getters
    std::string GetId() const;
    std::string Getunit() const;
    std::string GetDescription() const;
    float Getvalue() const;
    std::string GetTimestamp() const;

    // Setters
    void SetId(const std::string& newId);
    void Setunit(const std::string& newunit);
    void SetDescription(const std::string& newDescription);
    void Setvalue(float newvalue);
    void SetTimestamp(const std::string& newTimestamp);


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

    Measurement (std::string unId, std::string ununit, std::string unDescription, float unvalue, std::string unTimestamp);
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
std::string id;
std::string unit;
std::string description;
float value;
std::string timestamp;
};

//-------------------------------- Autres définitions dépendantes de <Measurement.h>

#endif // MEASUREMENT_H

