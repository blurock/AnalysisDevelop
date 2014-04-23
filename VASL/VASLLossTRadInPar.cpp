// VASLLossTRadInPar.cpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998
//--------------------------------------------------------------------------------
// history:
//   $Id: VASLLossTRadInPar.cpp,v 1.1 2008/02/17 12:15:08 blurock Exp $
//--------------------------------------------------------------------------------

#include "VASLLossTRadInPar.hpp"

METAIMPL(VASLLossTRadInPar, RInParameter, (
  TS(VASLLossTRadInPar::heightBeforePass), 
  TS(VASLLossTRadInPar::curTemp), 
  TS(VASLLossTRadInPar::timeToNext), 0)
);


//--------------------------------------------------------------------------------
// constructor VASLLossTRadInPar
// description

VASLLossTRadInPar::VASLLossTRadInPar() : RInParameter() {

  heightBeforePass = 0.0;
	timeToNext = 0.0;
	curTemp = 0.0;
}


//--------------------------------------------------------------------------------
// destructor ~VASLLossTRadInPar
// description

VASLLossTRadInPar::~VASLLossTRadInPar() {
  
}

//--------------------------------------------------------------------------------
// method printOn
// description

void VASLLossTRadInPar::printOn(ostream &ostrm) {
	RInParameter::printOn(ostrm);
	ostrm << endl;
	ostrm << "heightBeforePass = " << this->heightBeforePass;
	ostrm << " timeToNext = " << this->timeToNext;
	ostrm << " curTemp = " << this->curTemp;
	ostrm << endl;
}

