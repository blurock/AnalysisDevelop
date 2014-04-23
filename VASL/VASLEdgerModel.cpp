// VASLEdgerModel.cpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#include "BClass.hpp"
#include "VASLCompositModel.hpp"
#include "VASLEdgerModel.hpp"
#include "VASL.hpp"

#include "VASLEdgerInPar.hpp"
#include "VASLEdgerOutPar.hpp"

#include <Math.h>

METAIMPL(VASLEdgerModel, RModel,(0));

//---- VASLEdgerModel ------------------------------------------------------------------
//
//	Autor: Charly Artmann
//
//	File Info:
//
/* $Id: VASLEdgerModel.cpp,v 1.1 2008/02/17 12:15:09 blurock Exp $ */
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// 

VASLEdgerModel::VASLEdgerModel(BString aName,  RCompositModel * aCompositModel) :
																RModel(aName,  aCompositModel) {
  
  //todo: bei plan request fuer E1-E6 schreiben!
  this->diameterOfEdgerRolls = 1.0;
  this->diameterOfEdgerRolls = 1.0;
  this->maxEdgerForce= 1.0; 
	this->maxMechEdgerReduction = 1.0;
	this->maxEdgerKW = 1.0;
}

//------------------------------------------------------------------------------
// 
VASLEdgerModel::VASLEdgerModel(BString aName,  RCompositModel * aCompositModel, 
															float aDiamOfEdgerRolls, float aMaxEdgerForce, 
															float aMaxMechEdgerReduction, float aMaxEdgerKW) :
																RModel(aName,  aCompositModel) {
  
  this->diameterOfEdgerRolls = aDiamOfEdgerRolls;
  this->maxEdgerForce= aMaxEdgerForce ; 
	this->maxMechEdgerReduction = aMaxMechEdgerReduction;
	this->maxEdgerKW = aMaxEdgerKW;
}


//------------------------------------------------------------------------------
// 

VASLEdgerModel::~VASLEdgerModel() {

}


//------------------------------------------------------------------------------
// 

void VASLEdgerModel::init() {
 
}

//------------------------------------------------------------------------------
// 

void VASLEdgerModel::calculate() {
	assert (false);
//
//	this->getSharedParameters();
//
//	/*
//	gegeben: fmax, pmax, sMaxMech, s=0; // s == eReduction!
//	gesucht: min von (s an der stelle fmax und s an der stelle pmax)
//	@optimize: beide while schleifen zu einer zusammenführen!
//	*/
//	
//	//set the parameters of the edger
//	float maxForce = pars[eMaxEdgerForce]->value; //max Stauchkraft - setzen!
//	float maxEdgerKW = pars[eMaxEdgerKW]->value; //max Leistung vom motor (in kw) - setzten !
//	float maxMechEdgerReduction = pars[eMaxMechEdgerReduction]->value; //wieweit man max. stauchen kann; in mm	-setzen!
//
//	//take half of the current reduction an see where we are!
//	float delta = 0.1; //Ungenauigkeit!
//	maxForce = maxForce - delta;
//
//	float lowRedF = 0.0;	//lower bound
//	float reductionF = maxMechEdgerReduction / 2; //the searched reduction
//	float upRedF = maxMechEdgerReduction;			//upper bound
//	float calcF =  0.0;
//	
//	//search the reduction with maxForce
//	pars[eReduction]->value = maxMechEdgerReduction;
//	calcF = f();
//	//check if maxForce can be reached - if not take maxMechReduction
//	if (calcF > maxForce) {
//		//search it !
//		bool redFound = false;
//		while ( ! redFound ) {
//			pars[eReduction]->value = reductionF;
//			calcF = f();
//			if (calcF < maxForce) {
//				lowRedF = reductionF;
//			} else if (calcF > maxForce) {
//				upRedF = reductionF;
//			}
//			redFound =	fabs(maxForce-calcF) < delta;	//(calcF > maxForce - delta) && (calcF < maxForce + delta) 
//			assert (reductionF < maxMechEdgerReduction && reductionF > 0.0);
//			reductionF = (lowRedF + upRedF) / 2.0;
//		}
//	} 
//	
//	//search the reduction with maxEdgerKW
//	delta = 0.1;
//	maxEdgerKW = maxEdgerKW - delta;
//	float calcEdgerKW = 0.0;
//	float reductionKW = 0.0;
//	lowRedF = 0.0;
//	reductionKW = maxMechEdgerReduction / 2.0;
//	upRedF = maxMechEdgerReduction;
//	
//	pars[eReduction]->value = maxMechEdgerReduction;
//	calcF = f();
//	calcEdgerKW = p(calcF);
//	//check if reduction with max edgerKW can be reached - if not take maxMechReduction
//	if (calcEdgerKW > maxEdgerKW) {
//		bool redFound = false;
//		//serach the reduction with maxMechEdgerReduction
//		while  (!redFound) {
//			pars[eReduction]->value = reductionKW;
//			calcF = f();
//			calcEdgerKW = p (calcF);
//			if (calcEdgerKW < maxEdgerKW) {
//				lowRedF = reductionKW;
//			} else if (calcEdgerKW > maxEdgerKW) {
//				upRedF = reductionKW;
//			}
//			redFound = fabs(calcEdgerKW - maxEdgerKW) < delta; 
//			assert (reductionKW < maxMechEdgerReduction && reductionKW > 0.0);
//			reductionKW = (lowRedF + upRedF) / 2.0;
//		}
//	}
//	reductionKW = pars[eReduction]->value;
//	
//	pars[eReduction]->value = min (reductionF, reductionKW);
//	this->setSharedParameters();
}

void VASLEdgerModel::calculateMaxReduction (const VASLEdgerInPar *in, VASLEdgerMaxRedOutPar *&out) {
	VASLEdgerMaxRedOutPar * tOut = new VASLEdgerMaxRedOutPar();
	this->inPar = in;	
	/*
	gegeben: fmax, pmax, sMaxMech, s=0; // s == eReduction!
	gesucht: min von (s an der stelle fmax und s an der stelle pmax)
	@optimize: beide while schleifen zu einer zusammenführen!
	*/
	
	//set the parameters of the edger
	float maxForce = this->maxEdgerForce; //max Stauchkraft - setzen!
	float maxEdgerKW = this->maxEdgerKW; //max Leistung vom motor (in kw) - setzten !
	float maxMechEdgerReduction = this->maxMechEdgerReduction; //wieweit man max. stauchen kann; in mm	-setzen!

	//take half of the current reduction an see where we are!
	float delta = 0.1f; //Ungenauigkeit!
	maxForce = maxForce - delta;

	float lowRedF = 0.0f;	//lower bound
	float reductionF = maxMechEdgerReduction / 2; //the searched reduction
	float upRedF = maxMechEdgerReduction;			//upper bound
	float calcF =  0.0f;
	
	//search the reduction with maxForce
	this->reduction = maxMechEdgerReduction;
	calcF = f();
	//check if maxForce can be reached - if not take maxMechReduction
	if (calcF > maxForce) {
		//search it !
		bool redFound = false;
		while ( ! redFound ) {
			this->reduction = reductionF;
			calcF = f();
			if (calcF < maxForce) {
				lowRedF = reductionF;
			} else if (calcF > maxForce) {
				upRedF = reductionF;
			}
			redFound =	fabs(maxForce-calcF) < delta;	//(calcF > maxForce - delta) && (calcF < maxForce + delta) 
			assert (reductionF < maxMechEdgerReduction && reductionF > 0.0);
			reductionF = (lowRedF + upRedF) / 2.0;
		}
	} 
	
	//search the reduction with maxEdgerKW
	delta = 0.1f;
	maxEdgerKW = maxEdgerKW - delta;
	float calcEdgerKW = 0.0f;
	float reductionKW = 0.0f;
	lowRedF = 0.0f;
	reductionKW = maxMechEdgerReduction / 2.0;
	upRedF = maxMechEdgerReduction;
	
	this->reduction = maxMechEdgerReduction;
	calcF = f();
	calcEdgerKW = p(calcF);
	//check if reduction with max edgerKW can be reached - if not take maxMechReduction
	if (calcEdgerKW > maxEdgerKW) {
		bool redFound = false;
		//serach the reduction with maxMechEdgerReduction
		while  (!redFound) {
			this->reduction = reductionKW;
			calcF = f();
			calcEdgerKW = p (calcF);
			if (calcEdgerKW < maxEdgerKW) {
				lowRedF = reductionKW;
			} else if (calcEdgerKW > maxEdgerKW) {
				upRedF = reductionKW;
			}
			redFound = fabs(calcEdgerKW - maxEdgerKW) < delta; 
			assert (reductionKW < maxMechEdgerReduction && reductionKW > 0.0);
			reductionKW = (lowRedF + upRedF) / 2.0;
		}
	}
	reductionKW = this->reduction;
	
	tOut->reduction = min (reductionF, reductionKW);
	
	out = tOut;
}

void VASLEdgerModel::calculateForce (const VASLEdgerInPar *in, VASLEdgerForceOutPar *&out) {
	this->inPar = in;	
	this->reduction = in->reduction;
	out = new VASLEdgerForceOutPar();
	out->force=f();
}

//functions of the edger model 3 "Stauchkraftmodell 3"

//------------------------------------------------------------------------------
//
float VASLEdgerModel::se() { //durch SMC zugeführte Energiedichte [10kJ / cm3] 

  float res = 0.0;
  //e1 .. je Spule zugeführte Engergie [10kJ]
  assert (this->inPar != 0);
  assert(inPar->curLength != 0.0);
  assert(inPar->heightBeforeEdger != 0.0);
  assert(inPar->widthBeforeEdger != 0.0);
  
  res = (inPar->e[0] + inPar->e[1] + inPar->e[2] + inPar->e[3] + inPar->e[4] + inPar->e[5]) * 1000 
        / (inPar->widthBeforeEdger * inPar->heightBeforeEdger * inPar->curLength) ;
 
  return res;
}
	
//------------------------------------------------------------------------------
//
float VASLEdgerModel::ts() {    //Temperatur beim Stauchen
  float res = 0.0;
  assert (this->inPar != 0 && this->inPar->timeH != 0.0);
  res = inPar->tempZ * (1.0 - 6.5954E-5 * inPar->timeZS - 0.31549 / inPar->timeH) + 856.537 * se();
  return res;
}

//------------------------------------------------------------------------------
//
float VASLEdgerModel::rho() {
  float res = 0.0;
  assert (this->inPar != 0 && inPar->widthBeforeEdger != 0.0);
  res = this->reduction / inPar->widthBeforeEdger;
  return res;
}

//------------------------------------------------------------------------------
//
float VASLEdgerModel::rhoP() {
	assert(this->diameterOfEdgerRolls != 0.0);
	assert(inPar->widthBeforeEdger != 0.0);
  float res = 0.0;
  res = (pow ( this->reduction / (this->diameterOfEdgerRolls / 2), 0.5 ) )
				* (inPar->speedOfSlab / inPar->widthBeforeEdger) ;
  return res;
}

//------------------------------------------------------------------------------
//
float VASLEdgerModel::tn() {    //bezogene Temperatur
  float res = 0.0;
  res = ts() / 1000.0 - 1.1;
  return res;
}

//------------------------------------------------------------------------------
//
float VASLEdgerModel::kw() {
  float res = 0.0;
  float aTn = tn();
  float aRhoP = rhoP();
  float aRho = rho();
  
  res =   1 - 2.37741 * aTn      	- 0.87666 * aRhoP      	+ 1.54686 * aRho;
  res = res + 0.76829 * aTn*aTn   + 0.22736 * aRhoP*aRhoP + 0.51532 * aRho * aRho;
  res = res + 1.62624 * aTn*aRhoP + 0.45073 * aTn * aRho  + 0.45969 * aRho * aRhoP;
  res = res * 102.596;
  return res;
}

//------------------------------------------------------------------------------
//
float VASLEdgerModel::ld() {   //gedrückte Länge in [mm]
	assert(this->diameterOfEdgerRolls != 0.0);
  float res = 0.0;
  assert (this->reduction > 0.0);
  res = pow ( this->reduction * (this->diameterOfEdgerRolls / 2), 0.5 ) ;
  return res;
}

//------------------------------------------------------------------------------
//
float VASLEdgerModel::f() {     //Walzkraft in Tonnen
	float res = 0.0;
	assert (this->inPar != 0 && inPar->kws > 0.0);
  res = (kw() * ld() * inPar->heightBeforeEdger * inPar->kws) / 9810.0;
  return res;
}

//------------------------------------------------------------------------------
//
float VASLEdgerModel::p( float force) {    //erforderliche Leistung in kw
	assert(this->diameterOfEdgerRolls != 0.0);
	float res = 0.0;
	res = force * ld() / 1000.0; 		//Drehmoment "M"
	res = (res * inPar->speedOfSlab * 9.81) / ( (this->diameterOfEdgerRolls / 2) * 0.85);
	return res;
}
