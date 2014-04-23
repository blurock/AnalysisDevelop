// VASLQualityTable.cpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997
#include "VASLQualityTable.hpp"
#include "BCorbaCommunication.hpp"
#include "BClass.hpp"

METAIMPL(VASLQualityTable, BObject, (
	TOP (VASLQualityTable::theQualityElems), 0) 
);


//---- VASLQualityTable ------------------------------------------------------------------
//
//	Autor: Charly Artmann
//
//	File Info:
//
/* $Id: VASLQualityTable.cpp,v 1.1 2008/02/17 12:15:09 blurock Exp $ */
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

VASLQualityTable::VASLQualityTable() { //: VASLQualityTableIDLBOAImpl(name().c_str()) {
	//this->_marker("VASLQualityTable");
	this->theQualityElems = new QualityTableElemDictionary();
	cout << this->name() << " constructor called " << endl;
}

//------------------------------------------------------------------------------
// :bp: // also delete all entries!
//  
// :ep:
VASLQualityTable::~VASLQualityTable() {
	removeAll();	
	delete theQualityElems;
}

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

void VASLQualityTable::printOn(ostream &ostrm) {

	ostrm << "Quality table contains following entries:" << endl;
	ostrm << "BLTG" << ", " << "edgerAdjValue" << " " 
			<< "hStandAdjValue" << " " << "numOfPasses" << endl;

		theQualityElems->printOn(ostrm);
}

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

BObject * VASLQualityTable::deeperClone() {
		assert(false);
		return 0;
}

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

void VASLQualityTable::createEntry(BString *key) {
	if (! theQualityElems->contains(key) ) {
		VASLQualityTableElem *entry = new VASLQualityTableElem();
		theQualityElems->add(key, entry);
	}
}

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

bool VASLQualityTable::getEdgerAdjValue(BString *key, double &value) {
	VASLQualityTableElem *entry;
	if (theQualityElems->getValue(key, entry)) { 
		value = entry->edgerAdjValue;
		return true;
	} 
	return false;
}

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

void VASLQualityTable::setEdgerAdjValue(BString *key, double val) {
	createEntry (key);
	(*theQualityElems)[key]->edgerAdjValue = val;
}

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

bool VASLQualityTable::getHStandAdjValue(BString *key, double &value) {
	VASLQualityTableElem *entry;
	if (theQualityElems->getValue(key, entry)) { 
		value = entry->hStandAdjValue;
		return true;
	} 
	return false;
}

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

void VASLQualityTable::setHStandAdjValue(BString *key, double val) {
	createEntry (key);
	(*theQualityElems)[key]->hStandAdjValue = val;
}

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

bool VASLQualityTable::getNumOfPasses(BString *key, int16 &value) {
	VASLQualityTableElem *entry;
	if (theQualityElems->getValue(key, entry)) { 
		value = entry->numOfPasses;
		return true;
	} 
	return false;	
}

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

void VASLQualityTable::setNumOfPasses(BString *key, int16 val) {
	createEntry (key);
	(*theQualityElems)[key]->numOfPasses = val;
}

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

bool VASLQualityTable::getBBKWEG (BString *key, double &value) {
	VASLQualityTableElem *entry;
	if (theQualityElems->getValue(key, entry)) { 
		value = entry->bbkweg;
		return true;
	} 
	return false;
}

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

void VASLQualityTable::setBBKWEG(BString *key, double val) {
	createEntry (key);
	(*theQualityElems)[key]->bbkweg = val;
}
//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

void VASLQualityTable::remove(BString *key) {
	VASLQualityTableElem *elem = 0;
	if (theQualityElems->getValue(key, elem)) {	
		theQualityElems->remove (key,elem);
		delete elem;
	}
}

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

void VASLQualityTable::removeAll() {
	QualityTableElemDictionary::iterator pos;	
	for (pos = theQualityElems->begin(); pos != theQualityElems->end(); ++ pos ) {
		delete pos->second;
	}
	theQualityElems->clear();
}

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

BString VASLQualityTable::name() {
	return BString("VASLQualityTable");
}







