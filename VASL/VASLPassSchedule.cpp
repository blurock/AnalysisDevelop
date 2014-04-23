// VASLPassSchedule.cpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#include "VASLPassSchedule.hpp"
#include "BClass.hpp"
#include "BString.hpp"
#include "VASLPassScheduleElem.hpp"

METAIMPL(VASLPassSchedule, BObject, ( 
	TOP(VASLPassSchedule::thePassScheduleElems), 0)
);

//---- VASLPassSchedule ------------------------------------------------------------------
//
//	Autor: Charly Artmann
//
//	File Info:
//
/* $Id: VASLPassSchedule.cpp,v 1.1 2008/02/17 12:15:08 blurock Exp $ */
//
//------------------------------------------------------------------------------

VASLPassSchedule * VASLPassSchedule::instance = 0;

//constants for loading and saving
const char* NEW_SCHED = "Fixstichplan:"; 
const char* SEP = "\t";

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

VASLPassSchedule * VASLPassSchedule::getVASLPassSchedule() {

	if (instance == 0) {
		instance = new VASLPassSchedule();
	  //instance->createIt();		
		instance->loadFromASCII("fixpass.txt");
//		fstream f;
//		f.open("fixpass.txt", ios::in);
//		instance = (VASLPassSchedule*) BObject::loadFrom(f);
//		f.close()
	} 
	
	return instance; 

}

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

VASLPassSchedule::VASLPassSchedule() {
		this->thePassScheduleElems = new PassScheduleElemVector();
}

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

VASLPassSchedule::~VASLPassSchedule() {

		delete thePassScheduleElems;
}

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

void VASLPassSchedule::printOn(ostream &ostrm) {

		ostrm << "Fix Pass Schedule contains following entries:" << endl;
		ostrm << "passNr" << " " << "acceleration" << " " 
					<< "adjustmentHStand" << " " << "initialSpeed" << " " << "passSpeed" << endl;
		thePassScheduleElems->printOn(ostrm);
}

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

BObject * VASLPassSchedule::deeperClone() {

	assert(false);
	return 0;

}

//------------------------------------------------------------------------------
// method readFrom
// Overwritten when additional data has to be read.

//bool VASLPassSchedule::readFrom(istream &istrm) {
//
//		if (BObject::readFrom(istrm)) {
//				
//			thePassScheduleElems->readFrom(istrm);
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
//void VASLPassSchedule::writeTo(ostream &ostrm) {
//		
//		BObject::writeTo(ostrm);
//		
//		thePassScheduleElems->writeTo(ostrm);
//}



//------------------------------------------------------------------------------
// 

VASLPassScheduleElem * VASLPassSchedule::operator[] (int16 aPassScheduleNr) {

		return thePassScheduleElems->at(aPassScheduleNr);
}

// load pass schedule from a storage (e.g. file)
bool VASLPassSchedule::loadFromASCII(BString fileName) {
	//clear and delete? all entries
	this->thePassScheduleElems->removeAll();
	bool isLoaded = false;
	fstream f;
	f.open( fileName.c_str(), ios::in);	
	isLoaded = f.is_open();
	if (isLoaded) {
		//read first line == header info, just for comment
		char ch;
		while (!f.eof() && f.peek()!='\n') {
			f.get(ch);
		}
		if (!f.eof()) {f.get(ch);} //read new line
		//read data
		VASLPassScheduleElem* scheduleElem;
		bool nextSchedule = true;
		nextSchedule = ! f.eof() && (f.peek() == NEW_SCHED[0]);
		BString bStrBuff;
		while (! f.eof() && nextSchedule) {
			scheduleElem = new VASLPassScheduleElem();
			this->thePassScheduleElems->push_back(scheduleElem);
			f >> bStrBuff; // read mark NEW_SCHED
			f >> scheduleElem->fixPassNr;
			// read rows of passSchedule
			nextSchedule = false;
			VASLPassElem *passElem;
			int aBool = 0;
			while (! f.eof() && ! nextSchedule) {
				passElem = new VASLPassElem();
				scheduleElem->thePassElems->push_back(passElem);
				f >> passElem->passNr >> passElem->acceleration;
				f >> passElem->adjustmentHStand >> passElem->startupSpeed;
				f >> passElem->passSpeed >> passElem->minSpeed;
				f >> passElem->timePassToPass >> passElem->meanHeight;
				f >> aBool; passElem->hno = aBool;
				f >> aBool; passElem->hnu = aBool;
				f >> aBool; passElem->hso = aBool;
				f >> aBool; passElem->hsu = aBool;
				f >> aBool; passElem->last = aBool;
				f >> aBool; passElem->stau = aBool;
				f >> aBool; passElem->letzt = aBool;
				f >> passElem->direction;
				if (!f.eof()) { f.get(ch); } //read new line
				nextSchedule = !f.eof() && f.peek() == NEW_SCHED[0];
			}
		}
		
		f.close();
	}
	
	return isLoaded;
}

// save pass schedule on a storage (e.g. file)
bool VASLPassSchedule::saveToASCII(BString fileName) {
	bool isSaved = false;
	fstream f;
	f.open( fileName.c_str(), ios::out);	
	isSaved = f.is_open();
	if (isSaved) {
		//write header info - just for information
		f << "passNr" << SEP << "acceleration" << SEP;
		f << "adjustmentHStand" << SEP << "startupSpeed" << SEP;
		f << "passSpeed" << SEP << "minSpeed" << SEP;
		f << "timePassToPass" << SEP << "meanHeight" << SEP;
		f << "hno" << SEP << "hnu" << SEP;
		f << "hso" << SEP << "hsu" << SEP;
		f << "last" << SEP << "stau" << SEP;
		f << "letzt" << SEP << "direction";
		
		//write data
		VASLPassScheduleElem* scheduleElem;
		BIterator<VASLPassScheduleElem*> *scheduleElemIt;
		scheduleElemIt = this->thePassScheduleElems->iteratorObject();
		while (scheduleElemIt->next(scheduleElem)) {
			f << endl << NEW_SCHED << SEP << scheduleElem->fixPassNr;
			// save rows of passSchedule
			VASLPassElem *passElem;
			PassElemIterator *passElemIt;
			passElemIt = scheduleElem->thePassElems->iteratorObject();
			while (passElemIt->next(passElem)) {
				f << endl;
				f << passElem->passNr << SEP << passElem->acceleration << SEP;
				f << passElem->adjustmentHStand << SEP << passElem->startupSpeed << SEP;
				f << passElem->passSpeed << SEP << passElem->minSpeed << SEP;
				f << passElem->timePassToPass << SEP << passElem->meanHeight << SEP;
				f << passElem->hno << SEP << passElem->hnu << SEP;
				f << passElem->hso << SEP << passElem->hsu << SEP;
				f << passElem->last << SEP << passElem->stau << SEP;
				f << passElem->letzt << SEP << passElem->direction;
			}
		}
		
		f.close();
	}
	return isSaved;
}

//------------------------------------------------------------------------------
// 

int16 VASLPassSchedule::getNrOfPassSchedules(void) {

		return thePassScheduleElems->nrOfElems();
}

//------------------------------------------------------------------------------
// creates a pass Schedule

void VASLPassSchedule::createIt(void) {
	
	VASLPassScheduleElem * anElem;
	assert(this->thePassScheduleElems != NULL);
	for (int16 i=1; i<=2;i++) {
		anElem = new VASLPassScheduleElem;
		anElem->createIt();
		anElem->fixPassNr=i;
		this->thePassScheduleElems->add(anElem);
	}
}

//------------------------------------------------------------------------------
// returns the pass Schedule with the ID passScheduleNr

VASLPassElem * getPassScheduleElem(int16 passScheduleNr) {
		// not yet implemented
		assert(false);
		return NULL;
}

