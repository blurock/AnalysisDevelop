// VASLLossTDeforming.hpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#ifndef VASLLOSSTDEFORMING_HPP
#define VASLLOSSTDEFORMING_HPP


#include "RModel.hpp"

class RCompositModel;
class VASLLossTDefInPar;
class VASLTempOutPar;


//---- VASLLossTDeforming -----------------------------------------------------------
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
/* $Id: VASLLossTDeforming.hpp,v 1.1 2008/02/17 12:15:09 blurock Exp $ */
//
//-------------------------------------------------------------------------

class VASLLossTDeforming : public RModel {
	METADEF;

public:
		// constructor, destructor
		VASLLossTDeforming(void){}; 									
		VASLLossTDeforming(BString aName,  RCompositModel * aCompositModel=NULL); 									
		virtual ~VASLLossTDeforming();							

		// overiden methods

		virtual void init(void); 	// :bp: :ep:
		virtual void calculate(void); 	// :bp: :ep:
		virtual void calculate(const VASLLossTDefInPar *in, VASLTempOutPar *&out);
		
};


#endif
