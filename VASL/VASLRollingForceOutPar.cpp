// VASLRollingForceOutPar.cpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998
//--------------------------------------------------------------------------------
// history:
//   $Id: VASLRollingForceOutPar.cpp,v 1.1 2008/02/17 12:15:10 blurock Exp $
//--------------------------------------------------------------------------------

#include "VASLRollingForceOutPar.hpp"

METAIMPL(VASLRollingForceOutPar, ROutParameter, (
  TS(VASLRollingForceOutPar::forceHG),
  TS(VASLRollingForceOutPar::phim),
  TS(VASLRollingForceOutPar::faer),
  TS(VASLRollingForceOutPar::blm), 0)
);


//--------------------------------------------------------------------------------
// constructor VASLRollingForceOutPar
// description

VASLRollingForceOutPar::VASLRollingForceOutPar() : ROutParameter() {
  forceHG = 0.0;
	phim = 0.0;
	faer = 0.0;
	blm = 0.0; 
}


//--------------------------------------------------------------------------------
// destructor ~VASLRollingForceOutPar
// description

VASLRollingForceOutPar::~VASLRollingForceOutPar() {
  
}


//--------------------------------------------------------------------------------
// method printOn
// description

void VASLRollingForceOutPar::printOn(ostream &ostrm) {
	ROutParameter::printOn(ostrm);
	ostrm << endl;
	ostrm << "forceHG = " << this->forceHG;
	ostrm << " phim  = " << this->phim ;
	ostrm << " faer = " << this->faer;
	ostrm << " blm = " << this->blm;
	ostrm << endl;
	
}
