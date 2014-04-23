// VASLKashimaModel.hpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#ifndef VASLKASHIMAMODEL_HPP
#define VASLKASHIMAMODEL_HPP


#include "RModel.hpp"

class VASLKashimaInPar;
class VASLWidthOutPar;
 
//---- VASLKashimaModel -----------------------------------------------------------
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
/* $Id: VASLKashimaModel.hpp,v 1.1 2008/02/17 12:15:10 blurock Exp $ */
//
//-------------------------------------------------------------------------

class VASLKashimaModel : public RModel {
	METADEF;

public:
	// constructor, destructor
	VASLKashimaModel(void){}; 									
	VASLKashimaModel(BString aName,  RCompositModel * aCompositModel); 									
	VASLKashimaModel(BString aName,  RCompositModel * aCompositModel, float aDiameterOfEdgerRolls); 									
	virtual ~VASLKashimaModel();		
	
	virtual void init(void); 	// :bp: :ep:
	virtual void calculate(void); // :bp: :ep:
	virtual void calculate(const VASLKashimaInPar *in, VASLWidthOutPar *&out); 	
	float calculateWidthExponent(const VASLKashimaInPar *in); 
	
private:
	float diameterOfRoughingRolls;

};

#endif
