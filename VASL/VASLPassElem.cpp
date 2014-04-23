// VASLPassElem.cpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1997
//--------------------------------------------------------------------------------
// history:
//   $Id: VASLPassElem.cpp,v 1.1 2008/02/17 12:15:10 blurock Exp $
//--------------------------------------------------------------------------------

#include "VASLPassElem.hpp"
#include "BClass.hpp"

METAIMPL(VASLPassElem, BObject,( TS (VASLPassElem::passNr) , TS (VASLPassElem::acceleration) , 
																TS (VASLPassElem::adjustmentHStand) , TS (VASLPassElem::startupSpeed) , 
																TS (VASLPassElem::passSpeed) , TS (VASLPassElem::minSpeed) , 
																TS (VASLPassElem::timePassToPass) , TS (VASLPassElem::meanHeight) , 
																TS (VASLPassElem::hno) , TS (VASLPassElem::hnu) , 
																TS (VASLPassElem::hso) , TS (VASLPassElem::hsu) , 
																TS (VASLPassElem::last) , TS (VASLPassElem::stau) , 
																TS (VASLPassElem::letzt) , TS (VASLPassElem::direction) , 																
																0))

//------------------------------------------------------------------------------
//

VASLPassElem::VASLPassElem() {
	//init - db
	acceleration = 0;
	minSpeed = 0;
	adjustmentHStand = 0;
	startupSpeed = 0;
	passSpeed = 0;
	timePassToPass = 0;
	meanHeight = 0;
	hno = false;
	hnu = false;
	hso = false;
	hsu = false;
	last = false;
	stau = false;
	letzt = false;
	direction = eForward;

}

//------------------------------------------------------------------------------
//

VASLPassElem::~VASLPassElem() {

}

//------------------------------------------------------------------------------
//

void VASLPassElem::printOn(ostream &ostrm) {

		ostrm << endl << passNr << " " << acceleration << " " 
					<< adjustmentHStand << " " << startupSpeed << " " << passSpeed;

}

//------------------------------------------------------------------------------
// 

BObject * VASLPassElem::deeperClone() {

	assert(false);
	return 0;

}

//------------------------------------------------------------------------------
// method readFrom
// Overwritten when additional data has to be read.

//bool VASLPassElem::readFrom(istream &istrm) {
//
//		if (BObject::readFrom(istrm)) {
//		
//				istrm >> passNr;
//				istrm >> acceleration;
//				istrm >> adjustmentHStand;
//				istrm >> startupSpeed;
//				istrm >> passSpeed;
//				
//				return true;
//		} else {
//				return false;
//		}
//
//}
//
////------------------------------------------------------------------------------
//// method writeTo
//// Write all the components of object this on stream ostrm.
//
//void VASLPassElem::writeTo(ostream &ostrm) {
//		
//		BObject::writeTo(ostrm);
//		
//		ostrm << passNr;
//		ostrm << acceleration;
//		ostrm << adjustmentHStand;
//		ostrm << startupSpeed;
//		ostrm << passSpeed;
//
//}
