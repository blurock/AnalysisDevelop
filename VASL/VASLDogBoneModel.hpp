// VASLDogBoneModel.hpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#ifndef VASLDOGBONE_HPP
#define VASLDOGBONE_HPP


#include "RModel.hpp"

class VASLDogBoneInPar;
class VASLWidthOutPar;
 
//---- VASLDogBoneModel -----------------------------------------------------------
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
// $Id: VASLDogBoneModel.hpp,v 1.1 2008/02/17 12:15:09 blurock Exp $ 
//
//-------------------------------------------------------------------------

class VASLDogBoneModel : public RModel {
	METADEF;

public:
	// constructor, destructor 
	VASLDogBoneModel(); 									
	VASLDogBoneModel(BString aName,  RCompositModel * aCompositModel); 									
	VASLDogBoneModel(BString aName,  RCompositModel * aCompositModel, float aDiameterOfEdgerRolls);
	virtual ~VASLDogBoneModel();							

	// overiden methods										 
	virtual BObject* deeperClone();

	virtual void init(void); 	// :bp: :ep:
	virtual void calculate();
	virtual void calculate (const VASLDogBoneInPar *in, VASLWidthOutPar *&out);
	float calculateDogBoneFactor (const VASLDogBoneInPar *in); 

	private:
		float diameterOfEdgerRolls;

};

#endif
