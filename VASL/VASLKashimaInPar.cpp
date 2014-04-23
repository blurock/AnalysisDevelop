// VASLKashimaInPar.cpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998
//--------------------------------------------------------------------------------
// history:
//   $Id: VASLKashimaInPar.cpp,v 1.1 2008/02/17 12:15:09 blurock Exp $
//--------------------------------------------------------------------------------

#include "VASLKashimaInPar.hpp"

METAIMPL(VASLKashimaInPar, RInParameter, (
  TS(VASLKashimaInPar::widthBeforePass), 
  TS(VASLKashimaInPar::heightBeforePass), 
  TS(VASLKashimaInPar::diameterOfRoughingRolls),
  TS(VASLKashimaInPar::heightAfterPass), 0)
);


//--------------------------------------------------------------------------------
// constructor VASLKashimaInPar
// description

VASLKashimaInPar::VASLKashimaInPar() : 
  RInParameter() {
  
  widthBeforePass = 0.0;
	heightBeforePass = 0.0;
	heightAfterPass = 0.0;
	diameterOfRoughingRolls = 0.0;
}


//--------------------------------------------------------------------------------
// destructor ~VASLKashimaInPar
// description

VASLKashimaInPar::~VASLKashimaInPar() {
  
}


//--------------------------------------------------------------------------------
// method printOn
// description

void VASLKashimaInPar::printOn(ostream &ostrm) {
	RInParameter::printOn(ostrm);
	ostrm << endl;
	ostrm << "widthBeforePass = " << this->widthBeforePass;
	ostrm << " heightBeforePass = " << this->heightBeforePass;
	ostrm << " diameterOfRoughingRolls = " << this->diameterOfRoughingRolls;
	ostrm << " heightAfterPass = " << this->heightAfterPass;
	ostrm << endl;
}
