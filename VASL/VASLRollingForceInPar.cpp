// VASLRollingForceInPar.cpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998
//--------------------------------------------------------------------------------
// history:
//   $Id: VASLRollingForceInPar.cpp,v 1.1 2008/02/17 12:15:09 blurock Exp $
//--------------------------------------------------------------------------------

#include "VASLRollingForceInPar.hpp"

METAIMPL(VASLRollingForceInPar, RInParameter, (
  TS(VASLRollingForceInPar::heightAfterPass), 
  TS(VASLRollingForceInPar::heightBeforePass), 
  TS(VASLRollingForceInPar::speedOfSlab), 
  TS(VASLRollingForceInPar::curTemp), 
  TS(VASLRollingForceInPar::widthBeforeEdger), 
  TS(VASLRollingForceInPar::widthAfterEdger), 
  TS(VASLRollingForceInPar::widthAfterPass), 
  TS(VASLRollingForceInPar::diameterOfRoughingRolls), 0)
);


//--------------------------------------------------------------------------------
// constructor VASLRollingForceInPar
// description

VASLRollingForceInPar::VASLRollingForceInPar() : RInParameter() {

  heightAfterPass = 0.0;
  heightBeforePass = 0.0; 
	speedOfSlab = 0.0;
	curTemp = 0.0;	
	widthBeforeEdger = 0.0; 
	widthAfterEdger = 0.0; 
	widthAfterPass = 0.0; 
	diameterOfRoughingRolls = 0.0;
}


//--------------------------------------------------------------------------------
// destructor ~VASLRollingForceInPar
// description

VASLRollingForceInPar::~VASLRollingForceInPar() {
  
}

//--------------------------------------------------------------------------------
// method printOn
// description

void VASLRollingForceInPar::printOn(ostream &ostrm) {
	RInParameter::printOn(ostrm);
	ostrm << endl;
	ostrm << "heightAfterPass = " << this->heightAfterPass;
	ostrm << " heightBeforePass = " << this->heightBeforePass;
	ostrm << " speedOfSlab = " << this->speedOfSlab;
	ostrm << " curTemp = " << this->curTemp;
	ostrm << " widthBeforeEdger = " << this->widthBeforeEdger;
	ostrm << " widthAfterEdger = " << this->widthAfterEdger;
	ostrm << " widthAfterPass = " << this->widthAfterPass;
	ostrm << " diameterOfRoughingRolls = " << this->diameterOfRoughingRolls;
	ostrm << endl;
}

