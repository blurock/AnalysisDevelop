// VASLLossTLeading.hpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#ifndef VASLLOSSTLEADING_HPP
#define VASLLOSSTLEADING_HPP


#include "RModel.hpp"

class RCompositModel;
class VASLLossTLeadInPar;
class VASLTempOutPar;

 

//---- VASLLossTLeading -----------------------------------------------------------
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
/* $Id: VASLLossTLeading.hpp,v 1.1 2008/02/17 12:15:08 blurock Exp $ */
//
//-------------------------------------------------------------------------

class VASLLossTLeading : public RModel {
	METADEF;

public:
		// constructor, destructor
		VASLLossTLeading(void){}; 									
		VASLLossTLeading(BString aName,  RCompositModel * aCompositModel); 									
		virtual ~VASLLossTLeading();							

		virtual void init(void); 	// :bp: :ep:
		virtual void calculate(void); 	// :bp: :ep:
		virtual void calculate(const VASLLossTLeadInPar *in, VASLTempOutPar *&out);
	
				
};

#endif
