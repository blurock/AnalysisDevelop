// VASLCompositModel.hpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#ifndef VASLCOMPOSITMODEL_HPP
#define VASLCOMPOSITMODEL_HPP

#include "RCompositModel.hpp"

#include "VASL.hpp"
#include "RModelData.hpp" 

class VASLRollingForceModel;
class VASLLossTDeforming;
class VASLLossTDescaling;
class VASLLossTLeading;
class VASLLossTRadiation;
class VASLKashimaModel;
class VASLDogBoneModel;
class VASLEdgerModel;
class VASLPassSchedule;
class VASLPassScheduleElem;
class VASLQualityTable;
class VASLColInfo;

class RDispatcherIDL;
class RCurrentValRequest;

class VASLEdgerInPar;
class VASLColInfo;

//---- VASLCompositModel -----------------------------------------------------------
//
//	Autor: Charly Artmann
//
//	Purpose: 	
//		:bp:
//		
//		:ep:
//
//	Associations to other Classes:
//		:ba:
//		None.
//		:ea:
//
//	Usage:
//		:bu:
//		No special usage advices.
//  	:eu:
//
// 	Important hints for subclasses:
//		:bh:
//		No special hints.
//		:eh:
//
//	File Info:
//
//  $Id: VASLCompositModel.hpp,v 1.1 2008/02/17 12:15:08 blurock Exp $ 
//
//-------------------------------------------------------------------------


class VASLCompositModel : public RCompositModel {
	METADEF;

friend VASLRollingForceModel;
friend VASLLossTDeforming;
friend VASLLossTDescaling;
friend VASLLossTLeading;
friend VASLLossTRadiation;
friend VASLEdgerModel;
friend VASLKashimaModel;
friend VASLDogBoneModel;

public:
	// constructor, destructor
	VASLCompositModel(BString aName= "", BString aStripID=""); 									
	virtual ~VASLCompositModel();							

	// overiden methods
	virtual void init(BString aName, BString aStripID, RCompositModel * aCompositModel); 		// :bp: :ep:
	virtual void calculate(BString &reason); 	// :bp: :ep:
	virtual void calculate(); 	// :bp: :ep:
	virtual void postCalculate(void); 	// :bp: :ep:
	
	virtual void resetNonPrimaryData(void);
	virtual void getPrimaryData(void);
	virtual void setPassData(int16 passNr);  
	virtual void getPassData(int16 passNr);					
	virtual RModelData* getModelData() { return reinterpret_cast<RModelData*>(theData); };
		
private:

		// internal methods for calculating submodels
		void calculateWidth(int pass);
		void calculateTempAndForce(int pass);
		float getLength(void);
		void setVolume(void);
		float calculatePassSpeed(int16 pass);
		float bounceFactor(float aForce);
		float rollBend(float aWidth, float aForce);

		
		
		VASLPassSchedule * theSchedule;
		VASLPassScheduleElem * currentSchedule;
				
		int16 theScheduleNr;
		
		// local parameters
		float reductionLEdger;
		float reductionHEdger;
		float maxReductionHEdger;
		float maxReductionLEdger;
		
		float volume;
		float adjVG;
		float adjEG;
		float adjHG;
		
		RCurrentValRequest *tempRequest;
		RCurrentValRequest *widthRequest;
		RCurrentValRequest *qualityClassRequest; // sets qualityKey
		RCurrentValRequest *scheduleNoRequest; // sets theScheduleNr
		BString curStripID; //the current id of the "received strip - data"

		BString qualityKey; //current key of the quality table!
		VASLQualityTable *theQualityTable;
		
		RDispatcherIDL *theDispatcher;
		
private:
	//values of the strip:
	float curWidth;
	float curHeight;
	float curTemp;
	float curSpeed;
	float curLength;
	float widthBeforeEdger;
	float widthAfterEdger;
	float widthAfterPass;
	
	float forceHG;
	float forceLE;
	float forceHE;
	
	float finalWidth;		

	static VASLColInfo *colInfoInstance;
	
};

class VASLColInfo {
	public:
		//column index of the pass data -- see RPassDataTable
		int16 forceHGCol;
		int16 forceLECol;
		int16 forceHECol;
		int16 wmoCol;
		int16 korrWidthCol;
		int16 korrForceHGCol;
		int16 korrWMOCol;
		int16 adjHGCol;
		int16 adjEGCol;
		int16 adjVGCol;
		int16 rtvCol;
		int16 tempCol;
		int16 speedCol;
		int16 stripLengthCol;
		int16 stripWidthCol;
		int16 stripHeightCol;
		int16 stripWidthAfterEdgerCol;
};

#endif
