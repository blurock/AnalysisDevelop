// VASLEdgerModel.hpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#ifndef VASLEDGERMODEL_HPP
#define VASLEDGERMODEL_HPP

class VASLEdgerInPar;
class VASLEdgerMaxRedOutPar;
class VASLEdgerForceOutPar;

#include "RModel.hpp"
 
//---- VASLEdgerModel -----------------------------------------------------------
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
/* $Id: VASLEdgerModel.hpp,v 1.1 2008/02/17 12:15:09 blurock Exp $ */
//
//-------------------------------------------------------------------------


class VASLEdgerModel : public RModel {
	METADEF;

public:
	// constructor, destructor
	VASLEdgerModel(void){}; 									
	VASLEdgerModel(BString aName,  RCompositModel * aCompositModel); 
	VASLEdgerModel(BString aName,  RCompositModel * aCompositModel, 
								float aDiamOfEdgerRolls, float aMaxEdgerForce, 
								float aMaxMechEdgerReduction, float aMaxEdgerKW); 
	virtual ~VASLEdgerModel();							

	virtual void init(void); 	// :bp: :ep:
	virtual void calculate(void); 	// :bp: :ep:
	virtual void calculateMaxReduction(const VASLEdgerInPar *in, VASLEdgerMaxRedOutPar *&out);
	virtual void calculateForce(const VASLEdgerInPar *in, VASLEdgerForceOutPar *&out);
	
	//functions of the edger model 3 "Stauchkraftmodell 3"
	float se();    //durch SMC zugeführte Energiedichte [10kJ / cm3]
	float ts();    //Temperatur beim Stauchen
	float rho();
	float rhoP();
	float tn();    //bezogene Temperatur
	float kw();    //??
	float ld();    //gedrückte Länge
	float f();     //Kraft
	float p( float force);    //erforderliche Leistung in kw
	
	float aproximateS (float maxForce);
	
	
	float kws; //Korrekturfaktor Walzkraft in Abhängigkeit der Qualität - löschen!

private:
//		float tempZ; //Ziehtemperatur [Celsius]
//		float timeZS; //Zeit zw. Austragen und Anstich [Sekunden]
//		float timeH;  //Zeit in d. Ausgleichszone [Minuten]
//		float e1, e2, e3, e4, e5, e6;    //je Spule durch SMC zugeführte Energie [10kJ]
		float diameterOfEdgerRolls; 
		float maxEdgerForce; //the max. allowed pressure force
		float maxMechEdgerReduction; //in mm; the max. reduction
		float maxEdgerKW; //max kw of the engine
		const VASLEdgerInPar *inPar; 
		float reduction;
				 
};

#endif
