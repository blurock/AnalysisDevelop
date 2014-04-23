// VASLLossTRadiation.hpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#ifndef VASLLOSSTRADIATION_HPP
#define VASLLOSSTRADIATION_HPP


#include "RModel.hpp"

class RCompositModel;
class VASLLossTRadInPar;
class VASLTempOutPar;
 

//---- VASLLossTRadiation -----------------------------------------------------------
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
/* $Id: VASLLossTRadiation.hpp,v 1.1 2008/02/17 12:15:08 blurock Exp $ */
//
//-------------------------------------------------------------------------

class VASLLossTRadiation : public RModel {
	METADEF;

public:
		// constructor, destructor
		VASLLossTRadiation(void){}; 									
		VASLLossTRadiation(BString aName,  RCompositModel * aCompositModel); 									
		virtual ~VASLLossTRadiation();							

		virtual void init(void); 	// :bp: :ep:
		virtual void calculate(void); 	// :bp: :ep:
		virtual void calculate (const VASLLossTRadInPar *in, VASLTempOutPar *&out);

};

#endif
