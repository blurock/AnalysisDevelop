// VASLLossTLeadInPar.cpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998
//--------------------------------------------------------------------------------
// history:
//   $Id: VASLLossTLeadInPar.cpp,v 1.1 2008/02/17 12:15:09 blurock Exp $
//--------------------------------------------------------------------------------

#include "VASLLossTLeadInPar.hpp"

METAIMPL(VASLLossTLeadInPar, RInParameter, (
  TS(VASLLossTLeadInPar::heightAfterPass), 
  TS(VASLLossTLeadInPar::speedOfSlab), 
  TS(VASLLossTLeadInPar::blm), 
  TS(VASLLossTLeadInPar::curTemp), 0)
);


//--------------------------------------------------------------------------------
// constructor VASLLossTLeadInPar
// description

VASLLossTLeadInPar::VASLLossTLeadInPar() : RInParameter() {

  heightAfterPass = 0.0;
	speedOfSlab = 0.0;
	blm = 0.0;
	curTemp = 0.0;
}


//--------------------------------------------------------------------------------
// destructor ~VASLLossTLeadInPar
// description

VASLLossTLeadInPar::~VASLLossTLeadInPar() {
  
}

//--------------------------------------------------------------------------------
// method printOn
// description

void VASLLossTLeadInPar::printOn(ostream &ostrm) {
	RInParameter::printOn(ostrm);
	ostrm << endl;
	ostrm << "heightAfterPass = " << this->heightAfterPass;
	ostrm << " speedOfSlab = " << this->speedOfSlab;
	ostrm << " blm = " << this->blm;
	ostrm << " curTemp = " << this->curTemp;
	ostrm << endl;
}

