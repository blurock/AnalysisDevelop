// VASLLossTDescInPar.cpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998
//--------------------------------------------------------------------------------
// history:
//   $Id: VASLLossTDescInPar.cpp,v 1.1 2008/02/17 12:15:10 blurock Exp $
//--------------------------------------------------------------------------------

#include "VASLLossTDescInPar.hpp"

METAIMPL(VASLLossTDescInPar, RInParameter, (
  TS(VASLLossTDescInPar::speedOfSlab), 
  TS(VASLLossTDescInPar::heightBeforePass), 
  TS(VASLLossTDescInPar::curTemp), 
  TS(VASLLossTDescInPar::tw), 0)
);


//--------------------------------------------------------------------------------
// constructor VASLLossTDescInPar
// description

VASLLossTDescInPar::VASLLossTDescInPar() : 
  RInParameter() {
  speedOfSlab = 0.0;
	heightBeforePass = 0.0;
	curTemp = 0.0;
	tw = 0.0;
}


//--------------------------------------------------------------------------------
// destructor ~VASLLossTDescInPar
// description

VASLLossTDescInPar::~VASLLossTDescInPar() {
  
}

//--------------------------------------------------------------------------------
// method printOn
// description

void VASLLossTDescInPar::printOn(ostream &ostrm) {
	RInParameter::printOn(ostrm);
	ostrm << endl;
	ostrm << "speedOfSlab = " << this->speedOfSlab;
	ostrm << " heightBeforePass = " << this->heightBeforePass;
	ostrm << " tw = " << this->tw;
	ostrm << endl;
}

