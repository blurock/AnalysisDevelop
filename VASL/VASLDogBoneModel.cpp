// VASLDogBoneModel.cpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1997
//--------------------------------------------------------------------------------
// history:
//   $Id: VASLDogBoneModel.cpp,v 1.1 2008/02/17 12:15:10 blurock Exp $
//--------------------------------------------------------------------------------

#include "VASLDogBoneModel.hpp"
#include "BClass.hpp"
#include "VASL.hpp"
#include "VASLCompositModel.hpp"

#include <math.h>
#include "VASLDogBoneInPar.hpp"
#include "VASLWidthOutPar.hpp"

METAIMPL(VASLDogBoneModel, RModel,(0));


//------------------------------------------------------------------------------
//

VASLDogBoneModel::VASLDogBoneModel() {
	diameterOfEdgerRolls = 1.0;
}

//------------------------------------------------------------------------------
//

VASLDogBoneModel::VASLDogBoneModel(BString aName,  
  RCompositModel * aCompositModel) :
  RModel(aName,aCompositModel) {
  
  diameterOfEdgerRolls = 1.0;
}

//------------------------------------------------------------------------------
//

VASLDogBoneModel::VASLDogBoneModel(BString aName,  
  RCompositModel * aCompositModel, float aDiameterOfEdgerRolls) :
  RModel(aName,aCompositModel) {
  
  this->diameterOfEdgerRolls = aDiameterOfEdgerRolls;
}



//------------------------------------------------------------------------------
//

VASLDogBoneModel::~VASLDogBoneModel() {

}

//------------------------------------------------------------------------------
// 

BObject * VASLDogBoneModel::deeperClone() {

	assert(false);
	return 0;

}

//------------------------------------------------------------------------------
// :bp: 
//  
// :ep:

void VASLDogBoneModel::init() {


}


//------------------------------------------------------------------------------
// 
void VASLDogBoneModel::calculate() {
	assert (false);
}

//------------------------------------------------------------------------------
// 
void VASLDogBoneModel::calculate(const VASLDogBoneInPar *in, VASLWidthOutPar *&out) {
	assert (in != 0);
	VASLWidthOutPar *tOut = new VASLWidthOutPar();
	float factor;
	factor = calculateDogBoneFactor(in);
	tOut->widthInc =	 factor * (in->widthBeforeEdger-in->widthAfterEdger);	
	
	out = tOut;

}

//------------------------------------------------------------------------------
// 

float VASLDogBoneModel::calculateDogBoneFactor(const VASLDogBoneInPar *in) {
		assert (in->widthBeforeEdger != 0.0);
		assert (this->diameterOfEdgerRolls != 0.0);
		assert (in->widthBeforeEdger != 0.0);
		assert (in->widthAfterEdger != 0.0);
		assert (in->widthBeforeEdger - in->widthAfterEdger >= 0.0);
		return 	exp(-1.877 * 
							pow( (in->widthBeforeEdger - in->widthAfterEdger) / in->widthBeforeEdger, 0.063) *
							pow(in->heightBeforeEdger / this->diameterOfEdgerRolls, 0.441) *
							pow(this->diameterOfEdgerRolls / in->widthBeforeEdger, 0.989) *
							pow(in->widthBeforeEdger / in->widthAfterEdger, 7.591));
}
