// VASLPassScheduleElem.hpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#ifndef VASLPASSSCHEDULEELEM_HPP
#define VASLPASSSCHEDULEELEM_HPP


#include "BObject.hpp"
#include "BTypes.hpp"
#include "BVector.hpp"
#include "BIterator.hpp"

#include "VASLPassElem.hpp"
 
typedef BVector<VASLPassElem * > PassElemVector;
typedef BIterator<VASLPassElem * > PassElemIterator;
//---- VASLPassScheduleElem -----------------------------------------------------------
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
// $Id: VASLPassScheduleElem.hpp,v 1.1 2008/02/17 12:15:09 blurock Exp $ 
//
//-------------------------------------------------------------------------

class VASLPassScheduleElem : public BObject {
	METADEF;

public:
		// constructor, destructor
		VASLPassScheduleElem(); 									
		virtual ~VASLPassScheduleElem();							

		// overiden methods
		virtual void printOn(ostream &ostrm=cout);												 
		virtual BObject* deeperClone();
		void createIt(void);

//		virtual void writeTo(ostream &ostrm);
//		virtual bool readFrom(istream &istrm);
		
		// operators
		VASLPassElem * operator[] (int16 aPassNr);
		
		virtual int16 getNrOfPasses(void); 

		int16 fixPassNr;

		PassElemVector * thePassElems;
				 
};

#endif
