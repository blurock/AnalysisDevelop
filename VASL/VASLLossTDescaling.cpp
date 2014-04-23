// VASLLossTDescaling.cpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#include "VASLLossTDescaling.hpp"
#include "BClass.hpp"
#include "VASLCompositModel.hpp"

#include "VASLTempOutPar.hpp"
#include "VASLLossTDescInPar.hpp"

#include <math.h>


METAIMPL(VASLLossTDescaling, RModel,(0));

//---- VASLLossTDescaling ------------------------------------------------------------------
//
//	Autor: Charly Artmann
//
//	File Info:
//
/* $Id: VASLLossTDescaling.cpp,v 1.1 2008/02/17 12:15:08 blurock Exp $ */
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// 

VASLLossTDescaling::VASLLossTDescaling(BString aName,  RCompositModel * aCompositModel):
																						RModel(aName,  aCompositModel) {
}

//------------------------------------------------------------------------------
// 

VASLLossTDescaling::~VASLLossTDescaling() {

}



//------------------------------------------------------------------------------
// 

void VASLLossTDescaling::init() {
}

//------------------------------------------------------------------------------
// Calculates the loss of temperature through descaling.

void VASLLossTDescaling::calculate() {
	assert(false);
//		this->getSharedParameters();
//
//		const double kZU = 7.326E-4;	// constant = alphzu*2*lzu/(Cs*RHO)
//		
////		double curTemp = pars[eCurrentTemperature]->value; //just for debug purposes
////		double height = pars[eHeightBeforePass]->value;
////		double speed = pars[eSpeedOfSlab]->value;
//		
//		assert (pars[eSpeedOfSlab]->value != 0.0);
//		
//		pars[eCurrentTemperature]->value = pars[eCurrentTemperature]->value - kZU * 
//				(pars[eCurrentTemperature]->value - pars[eTw]->value)/
//				(pars[eHeightBeforePass]->value * pars[eSpeedOfSlab]->value)*1000.0;
//		
////		curTemp = pars[eCurrentTemperature]->value; //debug
//		
//		this->setSharedParameters();
}

//------------------------------------------------------------------------------
// Calculates the loss of temperature through descaling.
void VASLLossTDescaling::calculate(const VASLLossTDescInPar *in, VASLTempOutPar *&out) {
	VASLTempOutPar *tOut = new VASLTempOutPar();	
	assert (in->speedOfSlab != 0.0); 
	assert (in->heightBeforePass != 0.0);
	
	const double kZU = 7.326E-4;	// constant = alphzu*2*lzu/(Cs*RHO)	
	float div, result;
	div = (in->heightBeforePass * in->speedOfSlab / 1000.0); // speedOfSlab in mm/sec; m/s needed!!
	assert(div != 0.0);
	result = kZU * (in->curTemp - in->tw) / div*1000.0;
	tOut->temp = in->curTemp - result;
	out = tOut;
	TRACE3(cout << "VASLLossTDescaling: -" << result << endl);
}
