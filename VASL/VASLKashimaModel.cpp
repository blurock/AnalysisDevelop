// VASLKashimaModel.cpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#include "VASLKashimaModel.hpp"
#include "BClass.hpp"
#include "VASL.hpp"
#include "VASLCompositModel.hpp"

#include <math.h>
#include "VASLKashimaInPar.hpp"
#include "VASLWidthOutPar.hpp"

METAIMPL(VASLKashimaModel, RModel,(0));

//---- VASLKashimaModel ------------------------------------------------------------------
//
//	Autor: Charly Artmann
//
//	File Info:
//
/* $Id: VASLKashimaModel.cpp,v 1.1 2008/02/17 12:15:09 blurock Exp $ */
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// 

VASLKashimaModel::VASLKashimaModel(BString aName,  RCompositModel * aCompositModel):
  RModel(aName,  aCompositModel) {
}

//------------------------------------------------------------------------------
// 

VASLKashimaModel::VASLKashimaModel(BString aName,  
				   RCompositModel * aCompositModel, 
				   float aDiameterOfRoughingRolls):
  RModel(aName,  aCompositModel) {
  this->diameterOfRoughingRolls = aDiameterOfRoughingRolls;
}

//------------------------------------------------------------------------------
// 

VASLKashimaModel::~VASLKashimaModel() {
  
}



//------------------------------------------------------------------------------
// 

void VASLKashimaModel::init() {
}


//------------------------------------------------------------------------------
// 
void VASLKashimaModel::calculate() {
 assert (false);
//		this->getSharedParameters();
//		
//		pars[eWidthIncrease]->value = (
//				pow	(	(pars[eHeightBeforePass]->value/pars[eHeightAfterPass]->value), 
//						 	calculateWidthExponent()
//						) - 1.0
//					)	
//				* pars[eWidthBeforePass]->value;
//
//		this->setSharedParameters();
}

//------------------------------------------------------------------------------
// 
void VASLKashimaModel::calculate(const VASLKashimaInPar *in, VASLWidthOutPar *&out) {
  assert (in != 0);
  out = 0;
  VASLWidthOutPar *tOut = new VASLWidthOutPar ();
  assert(in->heightAfterPass);
  tOut->widthInc = (
		    pow	(	(in->heightBeforePass / in->heightAfterPass),
				calculateWidthExponent(in)) - 1.0 
		    )	
    * in->widthBeforePass;
  
  out = tOut;			
  assert (out != 0);
}


//------------------------------------------------------------------------------
// 

float VASLKashimaModel::calculateWidthExponent(const VASLKashimaInPar *in ) {
  
  // precalculate factor widthBefore/heightBefore
  assert(in->heightBeforePass);
  float widthTHeigth = in->widthBeforePass / in->heightBeforePass;
  // precalculate factor "ldi"
  float ldi = sqrt( this->diameterOfRoughingRolls * 
		    ( in->heightBeforePass - in->heightAfterPass));
  assert(ldi != 0.0);
  assert(this->diameterOfRoughingRolls != 0.0);
  
  return 	exp (	-1.64 
			* pow(widthTHeigth, 0.376) 
			* pow( (in->widthBeforePass / ldi), (0.016 * widthTHeigth) ) 
			* pow( (in->heightBeforePass / this->diameterOfRoughingRolls), (0.015 * widthTHeigth) )
			);
}
