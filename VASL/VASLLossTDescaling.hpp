// VASLLossTDescaling.hpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#ifndef VASLLOSSTDESCALING_HPP
#define VASLLOSSTDESCALING_HPP


#include "RModel.hpp"

class RCompositModel;
class VASLLossTDescInPar;
class VASLTempOutPar;
 

//---- VASLLossTDescaling -----------------------------------------------------------
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
/* $Id: VASLLossTDescaling.hpp,v 1.1 2008/02/17 12:15:08 blurock Exp $ */
//
//-------------------------------------------------------------------------

class VASLLossTDescaling : public RModel {
	METADEF;

public:
		// constructor, destructor
		VASLLossTDescaling(void){}; 									
		VASLLossTDescaling(BString aName,  RCompositModel * aCompositModel); 									
		virtual ~VASLLossTDescaling();							

		virtual void init(void); 	// :bp: :ep:
		virtual void calculate(void); 	// :bp: :ep:
		virtual void calculate(const VASLLossTDescInPar *in, VASLTempOutPar *&out);

};

#endif
