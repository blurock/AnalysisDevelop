// VASLRollingForceModel.hpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#ifndef VASLROLLINGFORCEMODEL_H
#define VASLROLLINGFORCEMODEL_H

#include "RModel.hpp"
class VASLRollingForceInPar;
class VASLRollingForceOutPar;

const int i = 5;

const float whk1 = 6.9f;
const float whk2=0.005f;
const float whk3=0.58f;
const float whk4=0.7f;

const float wbk1=1.2f;
const float wbk2=0.77f;
const float wbk3=0.2f;

const float fsw = 0.99f; // Füllfaktor Stauchwulst

const float a1 = 1.5724f;
const float a2 = 1.2012f;
const float a3 = 0.819f;
const float m1 = 0.00083f;
const float m2 = 0.04f;
const float m3 = 0.125f;

const float ffk1 = 100.0f; // Constant Formaenderungsfestigkeit

const float reibk = 0.32f; // Reibungskoeffizient

const float kcp = 0.0781f;		// spezifisches Gewicht
const float kgamma = 0.118f; // spezifische Waerme
//const float smv = 1.0;	//stichspez. Vererbungsf. fuer Walzmomente
		
//---- VASLRollingForceModel -----------------------------------------------------------
//
//	Autor: Charly Artmann
//
//	Purpose: 	
//		:bp:
//		
//		:ep:
//
//	Associations to other Classes:
//		:ba:
//		None.
//		:ea:
//
//	Usage:
//		:bu:
//		No special usage advices.
//  	:eu:
//
// 	Important hints for subclasses:
//		:bh:
//		No special hints.
//		:eh:
//
//	File Info:
//
/* $Id: VASLRollingForceModel.hpp,v 1.1 2008/02/17 12:15:08 blurock Exp $ */
//
//-------------------------------------------------------------------------

class VASLRollingForceModel : public RModel {
	METADEF;

public:
    VASLRollingForceModel(){};
    VASLRollingForceModel(BString aName,  RCompositModel * aCompositModel);
    virtual ~VASLRollingForceModel(void);
        
    virtual void init();
    virtual void calculate();
		void calculatewkh();
		virtual void calculate (const VASLRollingForceInPar *in, VASLRollingForceOutPar *&out);
    
    
//-------------------------------------------------------------------------
//
//	Calculation "Walzkraftmodell"
//
//-------------------------------------------------------------------------

		float wh(); 	 	// Wulsthoehe
		float wb();	 	// Wulstbreite
		float de();	 	// Dickenerhoehung durch Wulst
		float blm();	 	// gedrueckte Laenge in Brammenmitte
		float wlb();		// gedrueckte Länge im Wulstbereich
		float aowb();	// gedrueckte Flaechen ausserhalb des Wulstbereiches
		float aiwb();	// geddrueckte Flaechen im Wulstbereich
		float adges();	// gesamt gedrueckte Flaeche
		float mug();		// mittlerer Umformungsgrad
		float dhm();		// mittlere Hoehenabnahme
		float mah();		// mittlere Eintrittsdicke
		float phim();	// logarithmischer Umformungsgrad
		float phimv();	// mittlere logarithmische Unformungsgeschwindigkeit
		float teinf();	// Temperatureinfluss
		float phie();	// Formaenderungseinfluss
		float phiv();	// Einfluss der Formaenderungsgeschwindigkeit
		float ffk();		// Formaenderungsfestigkeit
		float abreib();// Faktor fuer aeussere Reibung	
		float ngamma();// Faktor fuer innere Schiebung
		float faer();	// Formaenderungswiderstand

//-------------------------------------------------------------------------
//
//	Offline Calculation "Temperaturmodell"
//
//-------------------------------------------------------------------------

		float tfor();	// Formaenderungswiderstand
    
private:
		
		float db; //Abnahme durch Stauchen
		float dh; //Gesamtabnahme
		float thewh; // Vorberechnung Wulsthoehe
		
		const VASLRollingForceInPar *inPar; // input parameter of the calculation
		VASLRollingForceOutPar *tOut; //the output parameter see calculate
		
		
};


#endif
