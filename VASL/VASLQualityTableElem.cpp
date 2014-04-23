// VASLQualityTableElem.cpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#include "VASLQualityTableElem.hpp"
#include "BClass.hpp"


METAIMPL(VASLQualityTableElem,  BObject , ( 
	TS (VASLQualityTableElem::edgerAdjValue) , 
	TS (VASLQualityTableElem::hStandAdjValue), 
	TS (VASLQualityTableElem::bbkweg), 
	TS (VASLQualityTableElem::numOfPasses), 0) );

//---- VASLQualityTableElem ------------------------------------------------------------------
//
//	Autor: Dietrich Birngruber
//
//	File Info:
//
/* $Id: VASLQualityTableElem.cpp,v 1.1 2008/02/17 12:15:09 blurock Exp $ */
//
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

VASLQualityTableElem::VASLQualityTableElem() : BObject() {
	edgerAdjValue = 1.0;
	hStandAdjValue = 1.0;		
	bbkweg = 1.0;
	numOfPasses = 0;		
}


VASLQualityTableElem::~VASLQualityTableElem()
{

}


//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

void VASLQualityTableElem::printOn(ostream &ostrm) {

	ostrm << edgerAdjValue << " " << hStandAdjValue << " " << bbkweg << " " << numOfPasses;

}

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

BObject * VASLQualityTableElem::deeperClone() {

	assert(false);
	return 0;

}
