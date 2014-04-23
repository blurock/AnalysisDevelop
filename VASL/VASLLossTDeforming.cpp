// VASLLossTDeforming.cpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#include "VASLLossTDeforming.hpp"
#include "BClass.hpp"
#include "VASLCompositModel.hpp"

#include "VASLTempOutPar.hpp"
#include "VASLLossTDefInPar.hpp"

#include <math.h>

METAIMPL(VASLLossTDeforming, RModel,(0));

//---- VASLLossTDeforming ------------------------------------------------------------------
//
//	Autor: Charly Artmann
//
//	File Info:
//
/* $Id: VASLLossTDeforming.cpp,v 1.1 2008/02/17 12:15:09 blurock Exp $ */
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// 

VASLLossTDeforming::VASLLossTDeforming(BString aName,  RCompositModel * aCompositModel) 
		: RModel(aName,  aCompositModel) {

}

//------------------------------------------------------------------------------
 

VASLLossTDeforming::~VASLLossTDeforming() {

}


//------------------------------------------------------------------------------
// 

void VASLLossTDeforming::init() {
}

//------------------------------------------------------------------------------
// Calculates the increase of temperature through deforming.
//		The increase is calculated by using the formula of SIEMENS.


void VASLLossTDeforming::calculate() {
	assert(false);
//		this->getSharedParameters();
//
//		const double kcp = 0.0781;
//		const double kgamma = 0.118;
//		
//		pars[eCurrentTemperature]->value = pars[eCurrentTemperature]->value +
//				(pars[eFaer]->value * pars[eSmv]->value
//				 * pars[ePhim]->value)/(kgamma*kcp);
//
//		this->setSharedParameters();
		
}

//------------------------------------------------------------------------------
// Calculates the increase of temperature through deforming.
//		The increase is calculated by using the formula of SIEMENS.

void VASLLossTDeforming::calculate(const VASLLossTDefInPar *in, VASLTempOutPar *&out) {
	VASLTempOutPar *tOut = new VASLTempOutPar();
	const float kcp = 0.0781f;
	const float kgamma = 0.118f;
	float div, result;
	div = kgamma * kcp;
	assert(div != 0.0);
	result = (in->faer * in->smv * in->phim) / div;
	tOut->temp = 	in->curTemp + result;
	out = tOut;
	TRACE3(cout << "VASLLossTDeforming: +" << result << endl);

}

