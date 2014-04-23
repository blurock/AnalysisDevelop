// VASLRollingForceModel.cpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997


#include "VASLRollingForceModel.hpp"
#include "BClass.hpp"
#include "VASLCompositModel.hpp"
#include <math.h>

#include "VASLRollingForceInPar.hpp"
#include "VASLRollingForceOutPar.hpp"

METAIMPL(VASLRollingForceModel, RModel,(0));


//---- VASLRollingForceModel -----------------------------------------------------------
//
//	Autor: Charly Artmann
//
//	File Info:
//
/* $Id: VASLRollingForceModel.cpp,v 1.1 2008/02/17 12:15:08 blurock Exp $ */
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// 

VASLRollingForceModel::VASLRollingForceModel(BString aName,  RCompositModel * aCompositModel):
																						RModel (aName,  aCompositModel) {
		tOut = 0;
}

//------------------------------------------------------------------------------
// 

VASLRollingForceModel::~VASLRollingForceModel(void) {

}

//------------------------------------------------------------------------------
// 

void VASLRollingForceModel::init() {
}


//------------------------------------------------------------------------------
// 

void VASLRollingForceModel::calculate() {
	assert(false);
//	
//		this->getSharedParameters();
//
//		db = pars[eWidthBeforeEdger]->value-pars[eWidthAfterEdger]->value;
//		dh = pars[eHeightBeforePass]->value - pars[eHeightAfterPass]->value;
//		thewh = whk1*whk2*pow(pars[eHeightBeforePass]->value, whk3)*pow(db,whk4);
//		calculatewkh();
//
//		this->setSharedParameters();
//		

}

//------------------------------------------------------------------------------
// 

void VASLRollingForceModel::calculate (const 	VASLRollingForceInPar *in, 
																							VASLRollingForceOutPar *&out) {

	assert (in != 0);
	tOut = new VASLRollingForceOutPar();
	this->inPar = in;
	
	db = inPar->widthBeforeEdger - inPar->widthAfterEdger;
	dh = inPar->heightBeforePass - inPar->heightAfterPass;
	assert (db >= 0.0);
	thewh = whk1*whk2*pow(inPar->heightBeforePass, whk3) * pow(db,whk4);
	calculatewkh();

	out = tOut;																							
}

//-------------------------------------------------------------------------
//
//	Offline Calculation "Walzkraftmodell"
//
//-------------------------------------------------------------------------


//------------------------------------------------------------------------------
// 

inline float VASLRollingForceModel::wh() {


	return whk1*whk2*pow(inPar->heightBeforePass, whk3)*pow(db,whk4);
}

//------------------------------------------------------------------------------
// 

inline float VASLRollingForceModel::wb() {

		return wbk1 * pow(inPar->heightBeforePass,wbk2) * pow(inPar->widthAfterEdger,wbk3);
}

//------------------------------------------------------------------------------
// 

inline float VASLRollingForceModel::de() {

		assert(inPar->widthAfterEdger);
		return (thewh*wb())/ inPar->widthAfterEdger;
}

//------------------------------------------------------------------------------
// 
inline float VASLRollingForceModel::blm() {
	float blm = sqrt( inPar->diameterOfRoughingRolls * (dh + de()) );
	if (tOut != 0) {	tOut->blm = blm; }
	return blm;
}

//------------------------------------------------------------------------------
// 

inline float VASLRollingForceModel::wlb() {
	return sqrt(inPar->diameterOfRoughingRolls * (dh + fsw*thewh));
}

//------------------------------------------------------------------------------
// 

inline float VASLRollingForceModel::aowb() {

	return blm()*(inPar->widthAfterPass - 2.0*wb());
}

//------------------------------------------------------------------------------
// 

inline float VASLRollingForceModel::aiwb() {

	return wlb()*2*wb();
}

//------------------------------------------------------------------------------
// 

inline float VASLRollingForceModel::adges() {

	return aowb() + aiwb();
}

//------------------------------------------------------------------------------
// 

inline float VASLRollingForceModel::mug() {

	assert(inPar->widthAfterPass != 0.0);
	return adges() / inPar->widthAfterPass;
}

//------------------------------------------------------------------------------
// 

inline float VASLRollingForceModel::dhm() {

	assert(inPar->diameterOfRoughingRolls != 0.0);
	return mug() * mug()/ inPar->diameterOfRoughingRolls;
}

//------------------------------------------------------------------------------
// 

inline float VASLRollingForceModel::mah() {

	return inPar->heightAfterPass + dhm();
}

//------------------------------------------------------------------------------
// 

inline float VASLRollingForceModel::phim() {

	assert ( inPar->heightAfterPass != 0.0);
	float phim = log(mah()/ inPar->heightAfterPass);
	if (tOut != 0) { tOut->phim = phim; }
	return phim;
}

//------------------------------------------------------------------------------
// 

inline float VASLRollingForceModel::phimv() {
	
	float div;
	div = mug();
	assert (div != 0.0);
	return inPar->speedOfSlab * phim() / div; // speed in mm/s! factor 1000 skipped!
}

//------------------------------------------------------------------------------
// 

inline float VASLRollingForceModel::teinf() {

	return a1*exp(-inPar->curTemp * m1);
}

//------------------------------------------------------------------------------
// 

inline float VASLRollingForceModel::phie() {

	return a2*pow(phim(),m2);
}

//------------------------------------------------------------------------------
// 

inline float VASLRollingForceModel::phiv() {

	return a3*pow(phimv(),m3);
}

//------------------------------------------------------------------------------
// 

inline float VASLRollingForceModel::ffk() {

	return ffk1*teinf()*phie()*phiv();
}

//------------------------------------------------------------------------------
// 

inline float VASLRollingForceModel::abreib() {

	float div;
	div = mah() + inPar->heightAfterPass;
	assert (div !=0.0);
	return (2.0*mug()) / div;
}

//------------------------------------------------------------------------------
// 

inline float VASLRollingForceModel::ngamma() {

	float div;
	div = reibk*abreib();
	assert (div != 0.0);
	return (exp(reibk*abreib()) - 1)/div;
}

//------------------------------------------------------------------------------
// 

inline float VASLRollingForceModel::faer() {

	float faer = ffk()*ngamma()/1000.0;
	if (tOut != 0) {tOut->faer = faer;}
	return faer;
}

//------------------------------------------------------------------------------
// 

inline void VASLRollingForceModel::calculatewkh() {

	if (tOut != 0) {
		tOut->forceHG = faer()*adges();
	}
}

//-------------------------------------------------------------------------
//
//	Offline Calculation "Temperaturmodell"
//
//-------------------------------------------------------------------------

//------------------------------------------------------------------------------
// 

inline float VASLRollingForceModel::tfor() {

	float div;
	div = kgamma*kcp;
	assert(div != 0.0);
	return (faer()*smv*phim())/ div;
}

