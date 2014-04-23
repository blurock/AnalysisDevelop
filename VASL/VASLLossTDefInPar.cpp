// VASLLossTDefInPar.cpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998
//--------------------------------------------------------------------------------
// history:
//   $Id: VASLLossTDefInPar.cpp,v 1.1 2008/02/17 12:15:10 blurock Exp $
//--------------------------------------------------------------------------------

#include "VASLLossTDefInPar.hpp"

METAIMPL(VASLLossTDefInPar, RInParameter, (
  TS(VASLLossTDefInPar::faer), 
  TS(VASLLossTDefInPar::smv), 
  TS(VASLLossTDefInPar::curTemp), 
  TS(VASLLossTDefInPar::phim), 0)
);


//--------------------------------------------------------------------------------
// constructor VASLLossTDefInPar
// description

VASLLossTDefInPar::VASLLossTDefInPar() : 
  RInParameter() {
  faer = 0.0;
	phim = 0.0;
	curTemp = 0.0;
	smv=0.0;
}


//--------------------------------------------------------------------------------
// destructor ~VASLLossTDefInPar
// description

VASLLossTDefInPar::~VASLLossTDefInPar() {
  
}



//--------------------------------------------------------------------------------
// method printOn
// description

void VASLLossTDefInPar::printOn(ostream &ostrm) {
	RInParameter::printOn(ostrm);
	ostrm << endl;
	ostrm << "faer = " << this->faer;
	ostrm << " phim = " << this->phim;
	ostrm << " curTemp = " << this->curTemp;
	ostrm << " smv = " << this->smv;
	ostrm << endl;
}

