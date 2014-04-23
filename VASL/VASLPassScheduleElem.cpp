// VASLPassScheduleElem.cpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1997
//--------------------------------------------------------------------------------
// history:
//   $Id: VASLPassScheduleElem.cpp,v 1.1 2008/02/17 12:15:08 blurock Exp $
//--------------------------------------------------------------------------------

#include "VASLPassScheduleElem.hpp"
#include "BClass.hpp"

#include "VASLPassElem.hpp"
#include "BVector.hpp"
#include "BCollectionIterator.hpp"

METAIMPL(VASLPassScheduleElem, BObject, (TOP (VASLPassScheduleElem::thePassElems), 0) )

//------------------------------------------------------------------------------
//

VASLPassScheduleElem::VASLPassScheduleElem() {

		thePassElems = new PassElemVector();
}

//------------------------------------------------------------------------------
//

VASLPassScheduleElem::~VASLPassScheduleElem() {
		
		delete thePassElems;
}

//------------------------------------------------------------------------------
//

void VASLPassScheduleElem::printOn(ostream &ostrm) {

//		BIterator<VASLPassElem *> * it;
//		VASLPassElem * obj;
//
//  it = theFixPassElems->iteratorObject();
//  while (it->next(obj)) {
//    obj->printOn();
//  }
//  
//  delete it;
//  

		ostrm << "Pass Schedule Elems:" << endl;
		thePassElems->printOn(ostrm);
		ostrm << endl;
		
}

//------------------------------------------------------------------------------
// 

BObject * VASLPassScheduleElem::deeperClone() {

	assert(false);
	return 0;

}

//------------------------------------------------------------------------------
// method readFrom
// Overwritten when additional data has to be read.

//bool VASLPassScheduleElem::readFrom(istream &istrm) {
//
//		if (BObject::readFrom(istrm)) {
//				
//				istrm >> fixPassNr;
//				thePassElems->readFrom(istrm);
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
//void VASLPassScheduleElem::writeTo(ostream &ostrm) {
//		
//		BObject::writeTo(ostrm);
//		
//		ostrm << fixPassNr;
//		thePassElems->writeTo(ostrm);
//}

//------------------------------------------------------------------------------
// 

VASLPassElem * VASLPassScheduleElem::operator[] (int16 aPassNr) {

		return thePassElems->at(aPassNr);
}

//------------------------------------------------------------------------------
// 

int16 VASLPassScheduleElem::getNrOfPasses(void) {

		return thePassElems->nrOfElems();
}

//------------------------------------------------------------------------------
// 

void VASLPassScheduleElem::createIt(void) {

		VASLPassElem * anElem;

		anElem = new VASLPassElem;
		anElem->passNr=0;
		anElem->acceleration=0;	 
		anElem->adjustmentHStand=0;
		anElem->startupSpeed =0;
		anElem->passSpeed=0;
		anElem->hno = false;
		anElem->hnu = false;
		anElem->hso = false;
		anElem->hsu = false;
		anElem->direction = VASLPassElem::eForward;

		thePassElems->add(anElem);

		
		anElem = new VASLPassElem;
		anElem->passNr=1;
		anElem->acceleration=9999;	 
		anElem->adjustmentHStand=185;
		anElem->startupSpeed =2300;
		anElem->passSpeed=2500;
		anElem->hno = true;
		anElem->hnu = true;
		anElem->hso = false;
		anElem->hsu = false;
		anElem->direction = VASLPassElem::eForward;

		
		thePassElems->add(anElem);

		anElem = new VASLPassElem;
		anElem->passNr=2;
		anElem->acceleration=0;	 
		anElem->adjustmentHStand=160;
		anElem->startupSpeed =2800;
		anElem->passSpeed=3000;
		anElem->hno = false;
		anElem->hnu = false;
		anElem->hso = true;
		anElem->hsu = true;
		anElem->direction = VASLPassElem::eBackward;
		
		thePassElems->add(anElem);		
		
		anElem = new VASLPassElem;
		anElem->passNr=3;
		anElem->acceleration=9999;	 
		anElem->adjustmentHStand=134;
		anElem->startupSpeed =3500;
		anElem->passSpeed=4000;
		anElem->hno = false;
		anElem->hnu = false;
		anElem->hso = false;
		anElem->hsu = false;
		anElem->direction = VASLPassElem::eForward;
		
		thePassElems->add(anElem);		
		
		anElem = new VASLPassElem;
		anElem->passNr=4;
		anElem->acceleration=0;	 
		anElem->adjustmentHStand=108;
		anElem->startupSpeed =3200;
		anElem->passSpeed=3700;
		anElem->hno = false;
		anElem->hnu = false;
		anElem->hso = true;
		anElem->hsu = true;
		anElem->direction = VASLPassElem::eBackward;
		
		thePassElems->add(anElem);		
		
		anElem = new VASLPassElem;
		anElem->passNr=5;
		anElem->acceleration=9999;	 
		anElem->adjustmentHStand=82;
		anElem->startupSpeed =3500;
		anElem->passSpeed=4000;
		anElem->hno = false;
		anElem->hnu = false;
		anElem->hso = false;
		anElem->hsu = false;
		anElem->direction = VASLPassElem::eForward;
		
		thePassElems->add(anElem);		
		
		anElem = new VASLPassElem;
		anElem->passNr=6;
		anElem->acceleration=-400;	 
		anElem->adjustmentHStand=56;
		anElem->startupSpeed =3200;
		anElem->passSpeed=3700;
		anElem->hno = false;
		anElem->hnu = false;
		anElem->hso = true;
		anElem->hsu = true;
		anElem->direction = VASLPassElem::eBackward;
		
		thePassElems->add(anElem);
		
		anElem = new VASLPassElem;
		anElem->passNr=7;
		anElem->acceleration=300;	 
		anElem->adjustmentHStand=27;
		anElem->startupSpeed =3700;
		anElem->passSpeed=4700;
		anElem->hno = true;
		anElem->hnu = true;
		anElem->hso = false;
		anElem->hsu = false;
		anElem->direction = VASLPassElem::eForward;

		
		thePassElems->add(anElem);
}
