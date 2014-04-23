// VASLWidthOutPar.cpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998
//--------------------------------------------------------------------------------
// history:
//   $Id: VASLWidthOutPar.cpp,v 1.1 2008/02/17 12:15:08 blurock Exp $
//--------------------------------------------------------------------------------

#include "VASLWidthOutPar.hpp"

METAIMPL(VASLWidthOutPar, ROutParameter, (
  TS(VASLWidthOutPar::widthInc), 0)
);


//--------------------------------------------------------------------------------
// constructor VASLWidthOutPar
// description

VASLWidthOutPar::VASLWidthOutPar() : 
  ROutParameter() {
  widthInc = 0.0;
}


//--------------------------------------------------------------------------------
// destructor ~VASLWidthOutPar
// description

VASLWidthOutPar::~VASLWidthOutPar() {
  
}


//--------------------------------------------------------------------------------
// method printOn
// description

void VASLWidthOutPar::printOn(ostream &ostrm) {
	ROutParameter::printOn(ostrm);
	ostrm << endl;
	ostrm << "widthInc = " << this->widthInc;
	ostrm << endl;
	
}
