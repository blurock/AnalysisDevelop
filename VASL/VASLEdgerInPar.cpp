// VASLEdgerInPar.cpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998
//--------------------------------------------------------------------------------
// history:
//   $Id: VASLEdgerInPar.cpp,v 1.1 2008/02/17 12:15:09 blurock Exp $
//--------------------------------------------------------------------------------

#include "VASLEdgerInPar.hpp"

METAIMPL(VASLEdgerInPar, RInParameter, (
  TS(VASLEdgerInPar::tempZ), 
  TS(VASLEdgerInPar::timeZS), 
  TS(VASLEdgerInPar::timeH), 
  TS(VASLEdgerInPar::kws), 
  TS(VASLEdgerInPar::speedOfSlab), 
  TS(VASLEdgerInPar::reduction), 
  TS(VASLEdgerInPar::curLength), 
  TS(VASLEdgerInPar::widthBeforeEdger), 
  TS(VASLEdgerInPar::heightBeforeEdger), 
  TS(VASLEdgerInPar::e), 0)
);


//--------------------------------------------------------------------------------
// constructor VASLEdgerInPar
// description

VASLEdgerInPar::VASLEdgerInPar() : RInParameter() {

		tempZ = 0.0; //Ziehtemperatur
		timeZS = 0.0; //Zeit zw. Austragen und Anstich in sec. - minimum is 30. sec
		timeH = 0.0; 	//min. is 20 minutes
		kws = 0.0;	//from the "quality table"
		speedOfSlab = 0.0;
		reduction = 0.0;
		curLength = 0.0; 
		widthBeforeEdger = 0.0;
		heightBeforeEdger = 0.0;

		assert (sizeof (float) != 0);
		int size = sizeof(this->e) / sizeof (float);
		for (int i = 0; i < size; i ++) {
			e[i] = 0.0;
		}
}


//--------------------------------------------------------------------------------
// destructor ~VASLEdgerInPar
// description

VASLEdgerInPar::~VASLEdgerInPar() {
  
}

//--------------------------------------------------------------------------------
// method printOn
// description

void VASLEdgerInPar::printOn(ostream &ostrm) {
	RInParameter::printOn(ostrm);
	ostrm << endl;
	ostrm << "tempZ = " << this->tempZ;
	ostrm << " timeZS = " << this->timeZS;
	ostrm << " ...";
	ostrm << endl;
}
