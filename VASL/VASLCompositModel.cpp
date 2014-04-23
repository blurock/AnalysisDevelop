// VASLCompositModel.cpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#include "VASLCompositModel.hpp"
#include "BClass.hpp"


#include "VASLRollingForceModel.hpp"
#include "VASLEdgerModel.hpp"
#include "VASLLossTDeforming.hpp"
#include "VASLLossTDescaling.hpp"
#include "VASLLossTLeading.hpp"
#include "VASLLossTRadiation.hpp"
#include "VASLKashimaModel.hpp"
#include "VASLDogBoneModel.hpp"

#include "VASLRollingForceInPar.hpp"
#include "VASLEdgerInPar.hpp"
#include "VASLLossTDefInPar.hpp"
#include "VASLLossTDescInPar.hpp"
#include "VASLLossTLeadInPar.hpp"
#include "VASLLossTRadInPar.hpp"
#include "VASLKashimaInPar.hpp"
#include "VASLDogBoneInPar.hpp"
 
#include "VASLEdgerOutPar.hpp"
#include "VASLRollingForceOutPar.hpp"
#include "VASLTempOutPar.hpp"
#include "VASLWidthOutPar.hpp"
 
#include "VASL.hpp"
#include "VASLPassSchedule.hpp"
#include "VASLPassScheduleElem.hpp"
#include "VASLQualityTable.hpp"

#include "RModelData.hpp"
 
#include <math.h>
#include <time.h>
#include <fstream.h>
#include <cstdio>


#include "RModelFunctions.hpp"

#include "RCurrentValRequest.hpp"
#include "RStripHeadCondition.hpp"
#include "RStripAtAggregateCondition.hpp"
#include "RMeasuredValueCondition.hpp"

#include "BCorbaCommunication.hpp"
#include "RDispatcherIDL.hh"
#include "RFloat.hpp"
#include "BVector.hpp"

#include "RPrimaryData.hpp"

// singleton object colInfoInstance!
VASLColInfo *VASLCompositModel::colInfoInstance = 0;

METAIMPL(VASLCompositModel, RCompositModel,(0));


//---- VASLCompositModel ------------------------------------------------------------------
//
//	Autor: Charly Artmann
//
//	File Info:
//
/* $Id: VASLCompositModel.cpp,v 1.1 2008/02/17 12:15:09 blurock Exp $ */
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

VASLCompositModel::VASLCompositModel(BString aName, BString aStripID) :
  RCompositModel(aName,aStripID) {
	
}


//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

VASLCompositModel::~VASLCompositModel() {
	
	//delete theSchedule;
	delete theQualityTable;
	if (this->tempRequest != 0) delete tempRequest;
	if (this->widthRequest != 0) delete widthRequest;
}


//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

void VASLCompositModel::init(BString aName, BString aStripID, RCompositModel * aCompositModel) {
	
	RCompositModel::init(aName, aStripID, aCompositModel);
	
	if (colInfoInstance == 0) {
		colInfoInstance = new VASLColInfo();
	} 
	RPassDataTable * table = theData->getPassDataTable();
	table->getColumnIdx("forceHG", colInfoInstance->forceHGCol);
	table->getColumnIdx("forceLE", colInfoInstance->forceLECol);
	table->getColumnIdx("forceHE", colInfoInstance->forceHECol);
	table->getColumnIdx("wmo", colInfoInstance->wmoCol);
	table->getColumnIdx("korrWidth", colInfoInstance->korrWidthCol);
	table->getColumnIdx("korrForceHG", colInfoInstance->korrForceHGCol);
	table->getColumnIdx("korrWMO", colInfoInstance->korrWMOCol);
	table->getColumnIdx("adjHG", colInfoInstance->adjHGCol);
	table->getColumnIdx("adjEG", colInfoInstance->adjEGCol);
	table->getColumnIdx("adjVG", colInfoInstance->adjVGCol);
	table->getColumnIdx("rtv", colInfoInstance->rtvCol);
	table->getColumnIdx("temp", colInfoInstance->tempCol);
	table->getColumnIdx("speed", colInfoInstance->speedCol);
	table->getColumnIdx("stripLength", colInfoInstance->stripLengthCol);
	table->getColumnIdx("stripWidth", colInfoInstance->stripWidthCol);
	table->getColumnIdx("stripHeight", colInfoInstance->stripHeightCol);
	table->getColumnIdx("stripWidthAfterEdger", colInfoInstance->stripWidthAfterEdgerCol);

	theSchedule = VASLPassSchedule::getVASLPassSchedule();
	
	theQualityTable = new VASLQualityTable();
	this->tempRequest = 0;
	this->widthRequest = 0;
	this->curStripID = "";
		
	//the current qualitytable entry 
	//temporary hack!
	qualityKey = "XA45"; //should be "received"!
	theQualityTable->setEdgerAdjValue(&qualityKey, 1.0);
	
	// initialize parameters
	this->curWidth = 0.0;
	this->curHeight = 0.0;
	this->curTemp = 1200.0;
	this->curSpeed = 0.0;
	this->curLength = 0.0;
	this->forceHG = 0.0;
	this->finalWidth = 0.0;
	
}

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

void VASLCompositModel::resetNonPrimaryData() {
	this->forceHG = 0.0f;
	this->forceLE = 0.0f;
	this->forceHE = 0.0f;
	//this->wmo = 0.0f;
	//this->korrWidth = 0.0f;
	//this->korrForceHG = 0.0f;
	//this->korrWMO = 0.0f;
	this->adjHG = 0.0f;
	this->adjEG = 0.0f;
	this->adjVG = 0.0f;
	this->widthAfterEdger = 0.0f;
	this->curSpeed = 0.0f;

}
//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

void VASLCompositModel::getPrimaryData() {
 
	RPrimaryData * pData = theData->getPrimaryData();

//	pData->getPrimaryData(BString("width"))->setVal(1295.0);
//	pData->getPrimaryData(BString("length"))->setVal(10100.0);
//	pData->getPrimaryData(BString("height"))->setVal(211.0);
//	pData->getPrimaryData(BString("startTemp"))->setVal(1200.0);
//	pData->getPrimaryData(BString("finalWidth"))->setVal(1308.0);
//	pData->getPrimaryData(BString("scheduleNr"))->setVal(1.0);

	pData->getPrimaryData(BString("width"))->getVal(this->curWidth);
	this->curWidth = this->curWidth*corrMM;
	pData->getPrimaryData(BString("length"))->getVal(this->curLength);
	this->curLength = this->curLength*corrMM;
	pData->getPrimaryData(BString("height"))->getVal(this->curHeight);
	this->curHeight = this->curHeight*corrMM;
	pData->getPrimaryData(BString("startTemp"))->getVal(this->curTemp);
	pData->getPrimaryData(BString("finalWidth"))->getVal(this->finalWidth);
	this->finalWidth = this->finalWidth * corrMM;
	this->setPassData(0);

	float aValue;
	pData->getPrimaryData(BString("scheduleNr"))->getVal(aValue);
	this->theScheduleNr = aValue;
	
	// for offline testing 
	this->curWidth = 1295.0;
	this->curLength = 10100.0;
	this->curHeight = 211.0;
	this->finalWidth = 1308.0;
	this->curTemp = 1200.0;
	this->setPassData(0);

	this->theScheduleNr = 1;
	
}

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:
	
void VASLCompositModel::setPassData(int16 passNr) {
	RPassDataTable* passDataTable= this->theData->getPassDataTable();
	passDataTable->getPassData(passNr, this->colInfoInstance->forceHGCol)->setVal(this->forceHG);
	passDataTable->getPassData(passNr, this->colInfoInstance->forceLECol)->setVal(this->forceLE);
	passDataTable->getPassData(passNr, this->colInfoInstance->forceHECol)->setVal(this->forceHE);
	//passDataTable->getPassData(passNr, this->colInfoInstance->wmoCol)->setVal(this->wmo);
	//passDataTable->getPassData(passNr, this->colInfoInstance->korrWidthCol)->setVal(this->korrWidth);
	//passDataTable->getPassData(passNr, this->colInfoInstance->korrForceHGCol)->setVal(this->korrForceHG);
	//passDataTable->getPassData(passNr, this->colInfoInstance->korrWMOCol)->setVal(this->korrWMO);
	passDataTable->getPassData(passNr, this->colInfoInstance->adjHGCol)->setVal(this->adjHG);
	passDataTable->getPassData(passNr, this->colInfoInstance->adjEGCol)->setVal(this->adjEG);
	passDataTable->getPassData(passNr, this->colInfoInstance->adjVGCol)->setVal(this->adjVG);
	//passDataTable->getPassData(passNr, this->colInfoInstance->rtvCol)->setVal(this->curTemp);
	passDataTable->getPassData(passNr, this->colInfoInstance->tempCol)->setVal(this->curTemp);
	passDataTable->getPassData(passNr, this->colInfoInstance->speedCol)->setVal(this->curSpeed);
	passDataTable->getPassData(passNr, this->colInfoInstance->stripLengthCol)->setVal(this->curLength);
	passDataTable->getPassData(passNr, this->colInfoInstance->stripWidthCol)->setVal(this->curWidth);
	passDataTable->getPassData(passNr, this->colInfoInstance->stripHeightCol)->setVal(this->curHeight);
	passDataTable->getPassData(passNr, this->colInfoInstance->stripWidthAfterEdgerCol)->setVal(this->widthAfterEdger);
}
 
//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:
void VASLCompositModel::getPassData(int16 passNr) {
	RPassDataTable* passDataTable= this->theData->getPassDataTable();
	passDataTable->getPassData(passNr, this->colInfoInstance->forceHGCol)->getVal(this->forceHG);
	passDataTable->getPassData(passNr, this->colInfoInstance->forceLECol)->getVal(this->forceLE);
	passDataTable->getPassData(passNr, this->colInfoInstance->forceHECol)->getVal(this->forceHE);
//	this->forceHG = 0.0;
//	this->forceLE = 0.0;
//	this->forceHE = 0.0;
	//passDataTable->getPassData(passNr, this->colInfoInstance->wmoCol)->getVal(this->wmo);
	//passDataTable->getPassData(passNr, this->colInfoInstance->korrWidthCol)->getVal(this->korrWidth);
	//passDataTable->getPassData(passNr, this->colInfoInstance->korrForceHGCol)->getVal(this->korrForceHG);
	//passDataTable->getPassData(passNr, this->colInfoInstance->korrWMOCol)->getVal(this->korrWMO);
	passDataTable->getPassData(passNr, this->colInfoInstance->adjHGCol)->getVal(this->adjHG);
	passDataTable->getPassData(passNr, this->colInfoInstance->adjEGCol)->getVal(this->adjEG);
	passDataTable->getPassData(passNr, this->colInfoInstance->adjVGCol)->getVal(this->adjVG);
//	this->adjHG = 0.0;
//	this->adjEG = 0.0;
//	this->adjVG = 0.0;
	//passDataTable->getPassData(passNr, this->colInfoInstance->rtvCol)->getVal(this->curTemp);
	passDataTable->getPassData(passNr, this->colInfoInstance->tempCol)->getVal(this->curTemp);
	passDataTable->getPassData(passNr, this->colInfoInstance->speedCol)->getVal(this->curSpeed);
	passDataTable->getPassData(passNr, this->colInfoInstance->stripLengthCol)->getVal(this->curLength);
	passDataTable->getPassData(passNr, this->colInfoInstance->stripWidthCol)->getVal(this->curWidth);
	passDataTable->getPassData(passNr, this->colInfoInstance->stripHeightCol)->getVal(this->curHeight);
}
 
 
void VASLCompositModel::calculate(BString &reason) { 

	clock_t start, finish;
	start = clock();
	if (reason == "precalculate") {
		//calculate();
	} else if (reason == "calculate") {
		calculate();
	} else {
		    BMessageSender::curSender->send(BMessageTypes::eWarning | BMessageTypes::eDeveloper, 
																				"Unknown calculate reason");
	}
	finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	char buffer[32];
	sprintf(buffer, "%2.1f seconds\n", duration );
	#ifndef NDEBUG
		ostrstream *debugStream= new ostrstream;                                                
		(*debugStream) << "VASLCompositModel::calculate: duration = " << buffer << endl;                                                   
		(*debugStream) << "reason was " << reason << endl;
		(*debugStream) << this  << ends;		
		BMessageSender::curSender->send(BMessageTypes::eModel | BMessageTypes::eDebugInfo,debugStream->str());  
		delete debugStream;                                                                     
	#endif
}

void VASLCompositModel::postCalculate(void) { 
	this->curSpeed = (*currentSchedule)[curPass]->passSpeed; // ?? via Kernel
	this->getPassData(curPass-1);
	calculateTempAndForce(curPass);
	calculateWidth(curPass);
	this->curHeight = this->adjHG + bounceFactor(this->forceHG) + rollBend(this->widthAfterEdger, this->forceHG);
	this->curLength = getLength();
	setPassData(curPass);

}


void VASLCompositModel::calculate(void) { 

	if (curPass < 1) {
		ostrstream *debugStream= new ostrstream;                                                
		(*debugStream) << "VASLCompositModel::calculate aborted: invalid passNumber = " << curPass << ends;                                                   
		BMessageSender::curSender->send(BMessageTypes::eModel | BMessageTypes::eWarning,debugStream->str());  
		delete debugStream;                                    
		return;                                 	
	}
	theScheduleNr=1;
	currentSchedule = (*theSchedule)[theScheduleNr];

	if (curPass == 1) {	
		// initialize model
		resetNonPrimaryData();
		getPrimaryData();
		currentSchedule = (*theSchedule)[theScheduleNr];
		setVolume();
		setPassData(0);
	}
		
	ofstream outFile("passprot.txt");

	
	// ----- create model -----
	VASLEdgerModel *hEdgerModel = new VASLEdgerModel ( BString("HeavyEdgerModel"),  this,
																											diameterOfHERolls, maxHEdgerForce, maxMechHEReduction, maxHEdgerKW);
	
	
	//initial values
	int nrOfPasses=currentSchedule->getNrOfPasses();
	reductionLEdger = 15.0;
	reductionHEdger = 50.0;
	maxReductionHEdger = 100.0; // sollte mit Edger model ausgerechnet werden: für schweren und für leichten fixwert
	maxReductionLEdger = 30.0;
	
	adjVG=1900.0;
	adjEG=1900.0;
	adjHG=300.0;
	
	//conditions to stop the calculation:
	float widthPrecision, delta;
	float devWidth;
	delta = 0.1f; 
	widthPrecision = 0.1f;
	
	bool maxLEdger, minLEdger, maxHEdger, minHEdger, widthReached;
	maxLEdger = false;	
	maxHEdger = false;	
	minLEdger = false;	
	minHEdger = false;	
	widthReached = false;
 

	TRACE1(cout << "*** Start calculation; initial values are: ***" << endl);
	TRACE1(cout << "*** end initial values; now calculate " << nrOfPasses << " passes: "  << endl << endl);
	int i = 0;
	
	
	if (curPass == 1) {

		//-----------------------------------------------------------
		// calculate limits of heavy edger
		// use VASLEdgerModel

		VASLEdgerInPar *edgerMaxRedIn = new VASLEdgerInPar();
		VASLEdgerMaxRedOutPar *edgerMaxRedOut=0;
		// ------ set parameters ----- 	
		edgerMaxRedIn->widthBeforeEdger = this->curWidth;
		edgerMaxRedIn->heightBeforeEdger = this->curHeight;
		//durch SMC zugeführte Energie in [10 kJ]
		edgerMaxRedIn->e[0] = 2200.0; 	edgerMaxRedIn->e[1] = 2200.0;
		edgerMaxRedIn->e[2] = 2200.0; 	edgerMaxRedIn->e[3] = 2200.0;
		edgerMaxRedIn->e[4] = 2200.0; 	edgerMaxRedIn->e[5] = 2200.0;
		edgerMaxRedIn->tempZ = this->curTemp;
		edgerMaxRedIn->timeZS = 30.0; //Zeit zw. Austragen und Anstich in sec. - minimum is 30. sec
		edgerMaxRedIn->timeH =20.0; //min. is 20 minutes
		edgerMaxRedIn->kws = 1.0;		//from the "quality table"
		edgerMaxRedIn->speedOfSlab = speedAtHeavyEdger; // constant speed 1000.0 mm/s at heavy edger
		edgerMaxRedIn->curLength = this->curLength; 
		// ----- calculate -----
		hEdgerModel->calculateMaxReduction (edgerMaxRedIn, edgerMaxRedOut);
		assert (edgerMaxRedOut != 0);
		maxReductionHEdger = edgerMaxRedOut->reduction;
		delete edgerMaxRedOut;
		delete edgerMaxRedIn;
	}

	
	//der walzprozeß -> mehrmals durchrechnen, bis width reached!
#ifdef DIAGRAMM
	reductionHEdger=0.0f;
	reductionLEdger = 0.0f;
	minHEdger = true;
	minLEdger = true;
#endif
	
#ifndef DIAGRAMM
	while (!widthReached  && ! (maxHEdger && maxLEdger) && !(minHEdger && minLEdger)) {
#else
	while (!(maxHEdger && maxLEdger)) {
#endif
//		if (curPass == 1) {
//			getPrimaryData(); //reset parameters of the slab		
//		}	else {
//			getPassData(curPass);
//		}

		getPassData(curPass - 1); // initialize values with pass data of previous pass
		for (int counter=curPass; counter < nrOfPasses; counter++) {
		
			resetNonPrimaryData();	
			this->curSpeed = (*currentSchedule)[counter]->passSpeed;
			
			//-----------------------------------------------------------
			// calculate force of heavy edger
			// use VASLEdgerModel

			if (counter == 1 && reductionHEdger > 0.0f) {
				VASLEdgerInPar *edgerForceIn = new VASLEdgerInPar();
				VASLEdgerForceOutPar *edgerForceOut=0;
				// ------ set parameters ----- 	
				edgerForceIn->widthBeforeEdger = this->curWidth;
				edgerForceIn->heightBeforeEdger = this->curHeight;
				edgerForceIn->reduction = reductionHEdger;
				//durch SMC zugeführte Energie in [10 kJ]
				edgerForceIn->e[0] = 2200.0; 	edgerForceIn->e[1] = 2200.0;
				edgerForceIn->e[2] = 2200.0; 	edgerForceIn->e[3] = 2200.0;
				edgerForceIn->e[4] = 2200.0; 	edgerForceIn->e[5] = 2200.0;
				edgerForceIn->tempZ = this->curTemp;
				edgerForceIn->timeZS = 30.0; //Zeit zw. Austragen und Anstich in sec. - minimum is 30. sec
				edgerForceIn->timeH =20.0; //min. is 20 minutes
				edgerForceIn->kws = 1.0;		//from the "quality table"
				edgerForceIn->speedOfSlab = speedAtHeavyEdger; 		// constant speed 1000.0 mm/s at heavy edger
				edgerForceIn->curLength = this->curLength; 
				// ----- calculate -----
				hEdgerModel->calculateForce (edgerForceIn, edgerForceOut);
				assert (edgerForceOut != 0);
				this->forceHE = edgerForceOut->force;
				delete edgerForceOut;
				delete edgerForceIn;
			}
			//Annahme: für ungerade Stiche edger model rechnen -> f() 
			//für leichten staucher ausrechnen und nicht reduction (=calculate())! - in der vorausberechnung nicht nötig
			
			calculateTempAndForce(counter);
			calculateWidth(counter);
			this->adjHG=(*currentSchedule)[counter]->adjustmentHStand;
			this->curHeight=(*currentSchedule)[counter]->adjustmentHStand;
			this->adjHG = this->curHeight - bounceFactor(this->forceHG) - rollBend(this->widthAfterEdger, this->forceHG);
			this->curLength = getLength();
			setPassData(counter);
			TRACE3(cout << endl << "------------------ end of pass " << counter << endl);
		}

#ifndef DIAGRAM
		TRACE1(theData->toASCII(outFile));
		devWidth = this->curWidth - this->finalWidth;
		 if ( fabs (devWidth) > widthPrecision) {
       //abs (diffHEdger) >= delta 
       if (! maxHEdger && ! minHEdger) {
				 if ((devWidth < 0.0) && (reductionHEdger - fabs(devWidth)/2.0 < 0.0)) {
					 // avoid a negativ reduction
					 reductionHEdger = reductionHEdger/2;
				 } else {
					reductionHEdger = reductionHEdger + devWidth / 2.0;
				 }
				 assert(reductionHEdger >= 0.0);
         if (reductionHEdger >= maxReductionHEdger) {
           reductionHEdger = maxReductionHEdger;
           maxHEdger = true;
         }
         if (reductionHEdger < widthPrecision) {
           reductionHEdger = 0.0;
					 minHEdger = true;
         }

       } else {
          //use light edger
				 if ((devWidth < 0.0) && (reductionLEdger - fabs(devWidth)/2.0 < 0.0)) {
					 // avoid a negativ reduction
					 reductionLEdger = reductionLEdger/2;
				 } else {
           reductionLEdger = reductionLEdger + devWidth / 2; 
				 }
				 assert(reductionLEdger >= 0.0);
         if (reductionLEdger >= maxReductionLEdger) {
           reductionLEdger = maxReductionLEdger;
           maxLEdger = true;
         }
         if (reductionLEdger < widthPrecision) { 
					 if (maxHEdger) {
						 reductionHEdger = 10.0f;
						 maxHEdger = false;
					 }
					 reductionLEdger = 0.0;
           minLEdger = true;
					 //TODO: notify width cannot be reached
					}
         }
			 
		 } else {
       widthReached = true;
		 }
#else
		 outFile << reductionLEdger << "\t" << reductionHEdger << "\t" << this->curWidth << endl;
		 maxHEdger = reductionHEdger > maxReductionHEdger;
		 maxLEdger = reductionLEdger > maxReductionLEdger;
		 if (minHEdger || maxHEdger) {
			 reductionLEdger++;
		 }
		 minHEdger = reductionLEdger < 15.0;
			if (!minHEdger && !maxHEdger) {
			 reductionHEdger++;
			}
#endif
		 
		 
	} //end while
	
	delete hEdgerModel;
	
	TRACE1(cout << "------------calculation ended, because " << endl);
	TRACE1(cout << "maxLEdger = " << maxLEdger << endl);
	TRACE1(cout << "maxHEdger = " << maxLEdger << endl);
	TRACE1(cout << "widthReached = " << widthReached << endl);
	TRACE1(cout << "reductionHEdger = " << reductionHEdger << endl);
	TRACE1(cout << "reductionLEdger = " << reductionLEdger << endl);
	TRACE1(cout << "maxReductionHEdger = " << maxReductionHEdger << endl);
	TRACE1(cout << "maxReductionLEdger = " << maxReductionLEdger << endl);
	TRACE1(cout << "devWidth = " << devWidth << endl);	
}
 
//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:
 
void VASLCompositModel::calculateWidth(int pass) {
	
	this->widthBeforeEdger = this->curWidth;
	if (isOdd(pass)) {
		//calculate width increase according to dogbone model after LIGHT edger 
		//light edger is only used in odd passes, except pass 1

		
		if (pass == 1) {
			VASLDogBoneModel *dogHModel = new VASLDogBoneModel (BString("DogBone(HeavyEdger)Model"), this,	diameterOfHERolls);
			VASLDogBoneInPar *dogIn = new VASLDogBoneInPar();
			dogIn->widthBeforeEdger = this->curWidth;
			dogIn->heightBeforeEdger = this->curHeight;
			VASLWidthOutPar *widthOut = 0;
			widthOut = 0;
			dogIn->widthAfterEdger = this->curWidth - reductionHEdger;
			dogHModel->calculate(dogIn, widthOut);
			assert (widthOut != 0);
			this->adjVG = this->curWidth - this->reductionLEdger;
			this->curWidth = this->adjVG + widthOut->widthInc;
			this->adjEG = this->curWidth + 40.0;
			delete dogHModel;
			delete dogIn;
			delete widthOut;
		} else  {
			VASLDogBoneInPar *dogIn = new VASLDogBoneInPar();
			dogIn->widthBeforeEdger = this->curWidth;
			dogIn->heightBeforeEdger = this->curHeight;
			VASLWidthOutPar *widthOut = 0;
			widthOut = 0;
			dogIn->widthAfterEdger = this->curWidth - reductionLEdger;
			VASLDogBoneModel *dogLModel = new VASLDogBoneModel (BString("DogBone(HeavyEdger)Model2"), this,	diameterOfLERolls);
			dogLModel->calculate(dogIn, widthOut);
			assert (widthOut != 0);
			this->adjEG = this->curWidth - this->reductionLEdger;
			this->curWidth = this->adjEG + widthOut->widthInc;
			delete dogLModel;
			delete dogIn;
			delete widthOut;
		}
	} else {
		this->adjEG = this->curWidth + 400.0;
	}
	
	this->widthAfterEdger = this->curWidth;	
	assert(pass < currentSchedule->getNrOfPasses() & pass > 0);
			
	VASLKashimaInPar *kashIn = new 	VASLKashimaInPar();
	VASLKashimaModel *kashModel = new VASLKashimaModel(BString("DogBone(HeavyEdger)Model2"), this, diameterOfHGRolls);
	
	kashIn->heightBeforePass = this->curHeight;
	kashIn->heightAfterPass = (*currentSchedule)[pass]->adjustmentHStand;
	kashIn->widthBeforePass = this->widthAfterEdger;
	VASLWidthOutPar *kashimaWidthOut = 0;
	kashimaWidthOut = 0;
	kashModel->calculate(kashIn, kashimaWidthOut);
	assert(kashimaWidthOut != 0);
	this->curWidth = this->curWidth + kashimaWidthOut->widthInc;
	this->widthAfterPass = this->curWidth;
	delete kashModel;
	delete kashimaWidthOut;
	delete kashIn;
}
 
//------------------------------------------------------------------------------
// 
 
void VASLCompositModel::calculateTempAndForce(int pass) {
	//create models needed to calculate the temperature loss
	VASLTempOutPar *tempOut = 0;
	VASLRollingForceOutPar *forceOut = 0;
	 
	VASLLossTRadiation *radModel = new VASLLossTRadiation ( BString ("VASLLossTRadiation2"), this);
	VASLLossTRadInPar *radIn = new VASLLossTRadInPar();																													
 
	VASLLossTDescaling *descModel	= new VASLLossTDescaling (BString ("VASLLossTDescaling2"),  this);
	VASLLossTDescInPar *descIn = new VASLLossTDescInPar();													
 
	VASLRollingForceModel *forceModel	= new VASLRollingForceModel (BString ("VASLRollingForceModel2"), this);
	VASLRollingForceInPar *forceIn = new 	VASLRollingForceInPar();
	
	VASLLossTDeforming *defModel = new VASLLossTDeforming (BString ("VASLLossTDeforming2"),  this);
	VASLLossTDefInPar *defIn = new 	VASLLossTDefInPar;
	
	VASLLossTLeading *leadModel = new VASLLossTLeading (BString ("VASLLossTLeading2"),  this);
	VASLLossTLeadInPar *leadIn = new 	VASLLossTLeadInPar;
	float heightAfterPass = (*currentSchedule)[pass]->adjustmentHStand;
	
	// set widthBeforeEdger, widthAfterEdger and widthAfterPass
	this->widthBeforeEdger=this->curWidth;
	if (pass == 1) {
		this->widthAfterEdger = this->curWidth - reductionHEdger;
	} else {
		this->widthAfterEdger = this->curWidth - reductionLEdger;
	}
	// precalculate the width after the pass
	// curWidth is not modified; this has to be done after rolling!
	VASLKashimaInPar *kashIn = new 	VASLKashimaInPar();
	VASLKashimaModel *kashModel = new VASLKashimaModel(BString("DogBone(HeavyEdger)Model2"),  this, diameterOfHGRolls);

	kashIn->heightBeforePass = this->curHeight;
	kashIn->heightAfterPass = (*currentSchedule)[pass]->adjustmentHStand;
	kashIn->widthBeforePass = this->widthAfterEdger;
	VASLWidthOutPar *kashimaWidthOut = 0;
	kashimaWidthOut = 0;
	kashModel->calculate(kashIn, kashimaWidthOut);
	assert(kashimaWidthOut != 0);
	this->widthAfterPass = this->curWidth + kashimaWidthOut->widthInc;
	delete kashModel;
	delete kashimaWidthOut;
	delete kashIn;
	
	if (isOdd(pass)) {	// odd number
		if (pass == 1) {
			// loss of temperature between oven and heavy edger
			radIn->heightBeforePass = this->curHeight;
			radIn->timeToNext = timeOvenToHE; // time between oven and heavy edger in seconds
			radIn->curTemp = this->curTemp;
			radModel->calculate(radIn, tempOut);
			this->curTemp = tempOut->temp;	delete tempOut; 
						
			// loss of temperature through descaling
			descIn->speedOfSlab = this->curSpeed;
			descIn->heightBeforePass = this->curHeight;
			descIn->tw = tempOfWater; //temp of cooling water
			descIn->curTemp = this->curTemp;		
			descModel->calculate(descIn, tempOut);
			this->curTemp = tempOut->temp;	delete tempOut;
			
			// loss of temperature between heavy edger and roughing stand
			radIn->heightBeforePass = this->curHeight;			
			radIn->timeToNext = timeHEdgerToHG;			// time heavy edger and roughing stand		
			radIn->curTemp = this->curTemp;
			radModel->calculate(radIn, tempOut);
			this->curTemp = tempOut->temp;	delete tempOut;	
	
		} else { // all other passes
			// loss of temperature through reversion
			radIn->heightBeforePass = this->curHeight;
			radIn->timeToNext = turnAroundTime; // time for reversion
			radIn->curTemp = this->curTemp;
			radModel->calculate(radIn, tempOut);
			this->curTemp = tempOut->temp;	delete tempOut; 		
 
			// loss of temperature through descaling
			descIn->speedOfSlab = this->curSpeed;
			descIn->heightBeforePass = this->curHeight;
			descIn->tw = tempOfWater; 
			if ( (*currentSchedule)[pass]->hno) {
				descIn->curTemp = this->curTemp;		
				descModel->calculate(descIn, tempOut);
				this->curTemp = tempOut->temp;	delete tempOut;
			}
			if ((*currentSchedule)[pass]->hnu) {
				descIn->curTemp = this->curTemp;		
				descModel->calculate(descIn, tempOut);
				this->curTemp = tempOut->temp;	delete tempOut;
			}
		}
		
		// calculate the pressure
		forceIn->curTemp = this->curTemp;
		forceIn->heightBeforePass = this->curHeight;
		forceIn->heightAfterPass = heightAfterPass; 
		forceIn->widthBeforeEdger = this->widthBeforeEdger;
		forceIn->widthAfterEdger = this->widthAfterEdger;
		forceIn->widthAfterPass = this->widthAfterPass;
		forceIn->speedOfSlab = (*currentSchedule)[pass]->passSpeed;
		forceIn->diameterOfRoughingRolls = diameterOfHGRolls; 
		forceModel->calculate(forceIn, forceOut);
		this->forceHG = forceOut->forceHG;

		// increase of temperature through deformation
		defIn->faer = forceOut->faer;
		defIn->phim = forceOut->phim;
		defIn->curTemp = this->curTemp; 
		defIn->smv = smv; 
		defModel->calculate(defIn, tempOut);
		this->curTemp = tempOut->temp; delete tempOut;

		// loss of temperature through leading
		leadIn->heightAfterPass = heightAfterPass; 
		leadIn->speedOfSlab = this->curSpeed;
		leadIn->blm = forceOut->blm;
		delete forceOut;
		leadIn->curTemp = this->curTemp;
		leadModel->calculate (leadIn, tempOut);
		this->curTemp = tempOut->temp; delete tempOut;
// MARK			
		// loss of temperature through time for roughing = "Stichzeit"
		radIn->heightBeforePass = this->curHeight;			
		radIn->timeToNext = calculatePassSpeed(pass);			// time for roughing		
		radIn->curTemp = this->curTemp;
		radModel->calculate(radIn, tempOut);
		this->curTemp = tempOut->temp;	delete tempOut;	
		
	} else { //calculate even pass
		// loss of temperature through reversion
		radIn->heightBeforePass = this->curHeight;			
		radIn->timeToNext = turnAroundTime;			// time for reversion		
		radIn->curTemp = this->curTemp;
		radModel->calculate(radIn, tempOut);
		this->curTemp = tempOut->temp;	delete tempOut;	
		
		// loss of temperature through descaling
		descIn->speedOfSlab = this->curSpeed;
		descIn->heightBeforePass = this->curHeight;
		descIn->tw = tempOfWater; 
		if ( (*currentSchedule)[pass]->hso) {
			descIn->curTemp = this->curTemp;		
			descModel->calculate(descIn, tempOut);
			this->curTemp = tempOut->temp;	delete tempOut;
		}
		if ((*currentSchedule)[pass]->hsu) {
			descIn->curTemp = this->curTemp;		
			descModel->calculate(descIn, tempOut);
			this->curTemp = tempOut->temp;	delete tempOut;
		}

		// loss of temperature through time for roughing = "Stichzeit"
		radIn->heightBeforePass = this->curHeight;
		radIn->timeToNext = calculatePassSpeed(pass);			// time for roughing		
		radIn->curTemp = this->curTemp;
		radModel->calculate(radIn, tempOut);
		this->curTemp = tempOut->temp;	delete tempOut;	

		// calculate the pressure
		forceIn->curTemp = this->curTemp;
		forceIn->heightBeforePass = this->curHeight;
		forceIn->heightAfterPass = heightAfterPass; 
		forceIn->widthBeforeEdger = this->widthBeforeEdger;
		forceIn->widthAfterEdger = this->widthAfterEdger;
		forceIn->widthAfterPass = this->widthAfterPass;
		forceIn->speedOfSlab = this->curSpeed;
		forceIn->diameterOfRoughingRolls = diameterOfHGRolls; //of "hg"
		forceModel->calculate(forceIn, forceOut);
		this->forceHG = forceOut->forceHG;

		// increase of temperature through deformation
		defIn->faer = forceOut->faer;
		defIn->phim = forceOut->phim;
		defIn->curTemp = this->curTemp;
		defIn->smv = smv;
		defModel->calculate(defIn, tempOut);
		this->curTemp = tempOut->temp; delete tempOut;	
		
		// loss of temperature through leading
		leadIn->heightAfterPass = heightAfterPass; 
		leadIn->speedOfSlab = this->curSpeed;
		leadIn->blm = forceOut->blm;
		delete forceOut;
		leadIn->curTemp = this->curTemp;
		leadModel->calculate (leadIn, tempOut);
		this->curTemp = tempOut->temp; delete tempOut;
	}
	
	//free all dynamical created models + input parameters!
	delete radModel;		delete radIn;
	delete descModel;		delete descIn;
	delete forceModel;	delete forceIn; 
	delete defModel;		delete defIn;
	delete leadModel; 	delete leadIn;
 
}
 

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

float VASLCompositModel::getLength(void) {
	float div;
	div = this->curWidth * this->curHeight;
	assert(div != 0.0);
	return this->volume / div;
//	return volume/(pars[eCurrentWidth]->value * pars[eCurrentHeight]->value);
}

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

void VASLCompositModel::setVolume(void) {
	volume = this->curWidth * this->curLength * this->curHeight;
}

float VASLCompositModel::calculatePassSpeed(int16 pass) {

 float t1, t2, t3, tges;
 float s1, s2, s3;
 float dv;
 float a1, a3;
 float v1, v2;
 float l;
 
 v1 = (*currentSchedule)[pass]->minSpeed;
 v2 = (*currentSchedule)[pass]->passSpeed;
 dv = v2 - v1;
 assert(dv > 0.0);
 l = curLength;

 if (isOdd(pass)) {
  a1 = min(maxAcceleration, (*currentSchedule)[pass]->acceleration);
  t1 = dv/a1;
	assert(a1 > 0.0);
  s1 = dv/2.0 * t1;
  s2= l - s1;
  t2 = s2/v2;
  tges = t1 + t2;
 } else {
  a1 = maxAcceleration;
  t1 = dv/a1;
  s1 = dv/2.0 * t1;

  a3 = min(maxAcceleration, (*currentSchedule)[pass]->acceleration);
	if (a3 != 0.0) {
		t3 = dv/a3;
	} else {
		t3 =0.0;
	}
  s3 = dv/2.0*t3;
  s2 = l - s1 - s3;
  assert(v2 != 0.0);
  t2 = s2 / v2;
  tges = t1 + t2 + t3;
 }
 return tges;
}


float VASLCompositModel::bounceFactor(float aForce) {
	assert(aForce != 0.0f);
	float result;
	result = 0.8f/5000.0f*aForce;
	return result;

}
 
float VASLCompositModel::rollBend(float aWidth, float aForce) {

	float result;
	result = 0.6E-04f + aWidth* -2.4E-09f + aWidth*aWidth*2.5E-12f + pow(aWidth,3.0f)*2.75E-16;
	result = result * aForce;
	return result;
}
