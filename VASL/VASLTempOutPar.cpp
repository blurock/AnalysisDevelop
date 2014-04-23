// VASLTempOutPar.cpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998
//--------------------------------------------------------------------------------
// history:
//   $Id: VASLTempOutPar.cpp,v 1.1 2008/02/17 12:15:08 blurock Exp $
//--------------------------------------------------------------------------------

#include "VASLTempOutPar.hpp"

METAIMPL(VASLTempOutPar, ROutParameter, (
  TS(VASLTempOutPar::temp), 0)
);


//--------------------------------------------------------------------------------
// constructor VASLTempOutPar
// description

VASLTempOutPar::VASLTempOutPar() : 
  ROutParameter() {
  temp = 0.0;
}


//--------------------------------------------------------------------------------
// destructor ~VASLTempOutPar
// description

VASLTempOutPar::~VASLTempOutPar() {
  
}


//--------------------------------------------------------------------------------
// method printOn
// description

void VASLTempOutPar::printOn(ostream &ostrm) {
	ROutParameter::printOn(ostrm);
	ostrm << endl;
	ostrm << "temp = " << this->temp;
	ostrm << endl;
	
}
