// VASLLossTLeading.cpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#include "VASLLossTLeading.hpp"
#include "BClass.hpp"
#include "VASLCompositModel.hpp"

#include "VASLLossTLeadInPar.hpp"
#include "VASLTempOutPar.hpp"

#include <math.h>


METAIMPL(VASLLossTLeading, RModel,(0));

//---- VASLLossTLeading ------------------------------------------------------------------
//
//	Autor: Charly Artmann
//
//	File Info:
//
/* $Id: VASLLossTLeading.cpp,v 1.1 2008/02/17 12:15:08 blurock Exp $ */
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// 

VASLLossTLeading::VASLLossTLeading(BString aName,  RCompositModel * aCompositModel):
																						RModel(aName,  aCompositModel) {
}

//------------------------------------------------------------------------------
// 

VASLLossTLeading::~VASLLossTLeading() {

}


//------------------------------------------------------------------------------
// 

void VASLLossTLeading::init() {}


//------------------------------------------------------------------------------
// Calculates the loss of temperature through leading heat into the rolls.
//	The increase is calculated by using the formula of Andorfer.

void VASLLossTLeading::calculate() {
	assert(false);
//	
//		const double const1 = 0.00132248; // constant ?? = sqrt(kdiff/PI)
//		const double const2 = 1000.0;
//
//		this->getSharedParameters();
//
//	 	pars[eCurrentTemperature]->value = pars[eCurrentTemperature]->value -
//				const1 * (pars[eCurrentTemperature]->value - pars[eTofRoll]->value) * 
//				2/pars[eHeightAfterPass]->value * sqrt(pars[eBlm]->value/pars[eSpeedOfSlab]->value * const2);
//
//		this->setSharedParameters();
}

//------------------------------------------------------------------------------
// Calculates the loss of temperature through leading heat into the rolls.
//	The increase is calculated by using the formula of Andorfer.

void VASLLossTLeading::calculate(const VASLLossTLeadInPar *in, VASLTempOutPar *&out) {
	VASLTempOutPar *tOut = new VASLTempOutPar();	
	assert (in->heightAfterPass != 0.0);
	assert (in->speedOfSlab != 0.0);
	
	const float const1 = 0.00132248f; // constant ?? = sqrt(kdiff/PI)
	const float const2 = 1000.0f;
	const float tOfRoll = 50.0f;
	float div1, div2, result;
	div1 = in->speedOfSlab * const2;
	assert(div1 != 0.0);
	div2 = in->heightAfterPass  * sqrt( in->blm / div1);
	assert(div2 != 0.0);
	result = const1 * (in->curTemp - tOfRoll) * 2.0 / div2;
	tOut->temp = in->curTemp - result;
	out = tOut;
	TRACE3(cout << "VASLLossTLeading: -" << result << endl);
}
