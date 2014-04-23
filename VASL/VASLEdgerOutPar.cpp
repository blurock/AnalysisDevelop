// VASLEdgerOutPar.cpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998
//--------------------------------------------------------------------------------
// history:
//   $Id: VASLEdgerOutPar.cpp,v 1.1 2008/02/17 12:15:09 blurock Exp $
//--------------------------------------------------------------------------------

#include "VASLEdgerOutPar.hpp"

METAIMPL(VASLEdgerMaxRedOutPar, ROutParameter, (
  TS(VASLEdgerMaxRedOutPar::reduction), 0)
);


//--------------------------------------------------------------------------------
// constructor VASLEdgerMaxRedOutPar
// description

VASLEdgerMaxRedOutPar::VASLEdgerMaxRedOutPar() : ROutParameter() {
  reduction = 0.0;
}


//--------------------------------------------------------------------------------
// destructor ~VASLEdgerMaxRedOutPar
// description

VASLEdgerMaxRedOutPar::~VASLEdgerMaxRedOutPar() {
  
}


//--------------------------------------------------------------------------------
// method printOn
// description

void VASLEdgerMaxRedOutPar::printOn(ostream &ostrm) {
	ROutParameter::printOn(ostrm);
	ostrm << endl;
	ostrm << "reduction = " << this->reduction;
	ostrm << endl;
	
}

METAIMPL(VASLEdgerForceOutPar, ROutParameter, (
  TS(VASLEdgerForceOutPar::force), 0)
);


//--------------------------------------------------------------------------------
// constructor VASLEdgerForceOutPar
// description

VASLEdgerForceOutPar::VASLEdgerForceOutPar() : ROutParameter() {
  force = 0.0;
}


//--------------------------------------------------------------------------------
// destructor ~VASLEdgerForceOutPar
// description

VASLEdgerForceOutPar::~VASLEdgerForceOutPar() {
  
}


//--------------------------------------------------------------------------------
// method printOn
// description

void VASLEdgerForceOutPar::printOn(ostream &ostrm) {
	ROutParameter::printOn(ostrm);
	ostrm << endl;
	ostrm << "force = " << this->force;
	ostrm << endl;
	
}
