// VASLLossTRadiation.cpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#include "VASLLossTRadiation.hpp"
#include "BClass.hpp"
#include "BString.hpp"
#include "VASLCompositModel.hpp"

#include "VASLTempOutPar.hpp"
#include "VASLLossTRadInPar.hpp"

#include <math.h>


METAIMPL(VASLLossTRadiation, RModel,(0));

//---- VASLLossTRadiation ------------------------------------------------------------------
//
//	Autor: Charly Artmann
//
//	File Info:
//
/* $Id: VASLLossTRadiation.cpp,v 1.1 2008/02/17 12:15:10 blurock Exp $ */
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// 

VASLLossTRadiation::VASLLossTRadiation(BString aName,  RCompositModel * aCompositModel):
																						RModel(aName,  aCompositModel) {
}

//------------------------------------------------------------------------------
// 

VASLLossTRadiation::~VASLLossTRadiation() {

}


//------------------------------------------------------------------------------
// 

void VASLLossTRadiation::init() {}

//------------------------------------------------------------------------------
// 	Calculates the loss of temperature through radiation 
//	during a certain time period.
// 	The decrease is caclulated by using the formula of Andorfer.

void VASLLossTRadiation::calculate() {
	assert(false);
//	
//		const double ks = 1.723076923E-14; 	// constant = eps*rhob/(Cs*rho)*2
//																				// with eps=0.8 ("Emmissionsfaktor")
//																				// 			rhob = 5.88E-8 ("Boltzmann Constant")
//
//		this->getSharedParameters();
//
//		pars[eCurrentTemperature]->value = pars[eCurrentTemperature]->value -
//				ks* pow((pars[eCurrentTemperature]->value + 273.0), 4) / 
//				(pars[eHeightBeforePass]->value*0.001) * pars[eTimeToNext]->value;
//
//		this->setSharedParameters();
}

void VASLLossTRadiation::calculate (const VASLLossTRadInPar *in, VASLTempOutPar *&out) {
	VASLTempOutPar *tOut = new VASLTempOutPar();
	const float ks = 1.723076923E-14f; 	// constant = eps*rhob/(Cs*rho)*2
																			// with eps=0.8 ("Emmissionsfaktor")
																			//			rhob = 5.88E-8 ("Boltzmann Constant")
	float div, result;
	div = (in->heightBeforePass * 0.001) ;
	assert(div != 0.0);
	result = ks * pow((in->curTemp + 273.0), 4) / div * in->timeToNext;
	tOut->temp = in->curTemp - result;
			
	out = tOut;
	TRACE3(cout << "VASLLossTRadiation: " << result << endl);
}
