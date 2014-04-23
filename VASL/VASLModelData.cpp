// VASLModelData.cpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998
//--------------------------------------------------------------------------------
// history:
//   $Id: VASLModelData.cpp,v 1.1 2008/02/17 12:15:09 blurock Exp $
//--------------------------------------------------------------------------------

#include "VASLModelData.hpp"
#include "RPassDataFloat.hpp"
#include "BString.hpp"


METAIMPL(VASLModelData, RModelData,(0));

//init singleton static variable
VASLColInfo* VASLModelData::colInfoInstance = 0;

//--------------------------------------------------------------------------------
// constructor VASLModelData
// description

VASLModelData::VASLModelData() : 
  RModelData() {
  
}


//--------------------------------------------------------------------------------
// constructor RModelData
// description

VASLModelData::VASLModelData(RPrimaryData * aPrim) : 
  RModelData(aPrim) {
	
	if (colInfoInstance == 0) {
		colInfoInstance = new VASLColInfo();
	} 
	colInfoInstance->forceHGCol=theData->addPassData(BString("forceHG"), new RPassDataFloat());
	colInfoInstance->forceLECol=theData->addPassData(BString("forceLE"), new RPassDataFloat());
	colInfoInstance->forceHECol=theData->addPassData(BString("forceHE"), new RPassDataFloat());
	colInfoInstance->wmoCol=theData->addPassData(BString("wmo"), new RPassDataFloat());
	colInfoInstance->korrWidthCol=theData->addPassData(BString("korrWidth"), new RPassDataFloat());
	colInfoInstance->korrForceHGCol=theData->addPassData(BString("korrForceHG"), new RPassDataFloat());
	colInfoInstance->korrWMOCol=theData->addPassData(BString("korrWMO"), new RPassDataFloat());
	colInfoInstance->adjHGCol=theData->addPassData(BString("adjHG"), new RPassDataFloat());
	colInfoInstance->adjEGCol=theData->addPassData(BString("adjEG"), new RPassDataFloat());
	colInfoInstance->adjVGCol=theData->addPassData(BString("adjVG"), new RPassDataFloat());
	colInfoInstance->rtvCol=theData->addPassData(BString("rtv"), new RPassDataFloat());
	colInfoInstance->tempCol=theData->addPassData(BString("temp"), BString("tempBeforeRoughingStand"), new RPassDataFloat());
	colInfoInstance->speedCol=theData->addPassData(BString("speed"), new RPassDataFloat());
//	theData->addPassData(BString("passTime"), new RPassDataTime());
//	theData->addPassData(BString("timeBeforePass"), new RPassDataTime());
	colInfoInstance->stripLengthCol=theData->addPassData(BString("stripLength"), new RPassDataFloat());
	colInfoInstance->stripWidthCol=theData->addPassData(BString("stripWidth"), new RPassDataFloat());
	colInfoInstance->stripHeightCol=theData->addPassData(BString("stripHeight"), new RPassDataFloat());
	colInfoInstance->stripWidthAfterEdgerCol=theData->addPassData(BString("widthAfterEdger"), new RPassDataFloat());
	
//--------------- copy	
//	colInfoInstance->forceHGCol=theData->addPassData(BString("forceHG"),BString("rollingForceRoughingStand"), new RPassDataFloat());
//	colInfoInstance->forceLECol=theData->addPassData(BString("forceLE"), new RPassDataFloat());
//	colInfoInstance->forceHECol=theData->addPassData(BString("forceHE"), BString("rollingForceHeavyEdger"), new RPassDataFloat());
//	colInfoInstance->wmoCol=theData->addPassData(BString("wmo"), new RPassDataFloat());
//	colInfoInstance->korrWidthCol=theData->addPassData(BString("korrWidth"), new RPassDataFloat());
//	colInfoInstance->korrForceHGCol=theData->addPassData(BString("korrForceHG"), new RPassDataFloat());
//	colInfoInstance->korrWMOCol=theData->addPassData(BString("korrWMO"), new RPassDataFloat());
//	colInfoInstance->adjHGCol=theData->addPassData(BString("adjHG"), BString("heightRoughingStand"), new RPassDataFloat());
//	colInfoInstance->adjEGCol=theData->addPassData(BString("adjEG"), BString("widthLightEdger"), new RPassDataFloat());
//	colInfoInstance->adjVGCol=theData->addPassData(BString("adjVG"), BString("widthHeavyEdger"), new RPassDataFloat());
//	colInfoInstance->rtvCol=theData->addPassData(BString("rtv"), new RPassDataFloat());
//	colInfoInstance->tempCol=theData->addPassData(BString("temp"), BString("tempBeforeRoughingStand"), new RPassDataFloat());
//	colInfoInstance->speedCol=theData->addPassData(BString("speed"), new RPassDataFloat());
////	theData->addPassData(BString("passTime"), new RPassDataTime());
////	theData->addPassData(BString("timeBeforePass"), new RPassDataTime());
//	colInfoInstance->stripLengthCol=theData->addPassData(BString("stripLength"), new RPassDataFloat());
//	colInfoInstance->stripWidthCol=theData->addPassData(BString("stripWidth"), new RPassDataFloat());
//	colInfoInstance->stripHeightCol=theData->addPassData(BString("stripHeight"), new RPassDataFloat());
//	colInfoInstance->stripWidthAfterEdgerCol=theData->addPassData(BString("widthAfterEdger"), new RPassDataFloat());
 
}

//--------------------------------------------------------------------------------
// destructor ~VASLModelData
// description

VASLModelData::~VASLModelData() {
  
}


VASLColInfo* VASLModelData::getColInfo() {
	return colInfoInstance;
}









