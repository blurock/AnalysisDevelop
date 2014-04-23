// VASLDogBoneInPar.cpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998
//--------------------------------------------------------------------------------
// history:
//   $Id: VASLDogBoneInPar.cpp,v 1.1 2008/02/17 12:15:09 blurock Exp $
//--------------------------------------------------------------------------------

#include "VASLDogBoneInPar.hpp"

METAIMPL(VASLDogBoneInPar, RInParameter, (
  TS(VASLDogBoneInPar::widthBeforeEdger), 
  TS(VASLDogBoneInPar::widthAfterEdger), 
  TS(VASLDogBoneInPar::heightBeforeEdger), 0)
);


//--------------------------------------------------------------------------------
// constructor VASLDogBoneInPar
// description

VASLDogBoneInPar::VASLDogBoneInPar() : 
  RInParameter() {
  widthBeforeEdger = 0.0;
	widthAfterEdger = 0.0 ; 
	heightBeforeEdger = 0.0;
}


//--------------------------------------------------------------------------------
// destructor ~VASLDogBoneInPar
// description

VASLDogBoneInPar::~VASLDogBoneInPar() {
  
}


//--------------------------------------------------------------------------------
// method printOn
// description

void VASLDogBoneInPar::printOn(ostream &ostrm) {
	RInParameter::printOn(ostrm);
	ostrm << endl;
	ostrm << "widthBeforeEdger = " << this->widthBeforeEdger;
	ostrm << " widthAfterEdger = " << this->widthAfterEdger;
	ostrm << " heightBeforeEdger = " << this->heightBeforeEdger;
	ostrm << endl;
}
