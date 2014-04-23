// VASLPassSchedule.hpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#ifndef VASLPASSSCHEDULE_HPP
#define VASLPASSSCHEDULE_HPP


#include "BObject.hpp"
 
#include "BVector.hpp"

#include "VASLPassScheduleElem.hpp"

class BString;


typedef BVector<VASLPassScheduleElem *> PassScheduleElemVector;

//---- VASLPassSchedule -----------------------------------------------------------
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
/* $Id: VASLPassSchedule.hpp,v 1.1 2008/02/17 12:15:08 blurock Exp $ */
//
//-------------------------------------------------------------------------

class VASLPassSchedule : public BObject {
	METADEF;

public:
		// constructor, destructor
		
		static VASLPassSchedule * getVASLPassSchedule(void);

protected:
		
		VASLPassSchedule(); 									
		virtual ~VASLPassSchedule();							

public:
		// overiden methods
		virtual void printOn(ostream &ostrm=cout);												 
		virtual BObject* deeperClone();
		
		// load pass schedule from a storage (e.g. file)
		virtual bool loadFromASCII(BString fileName);
		// save pass schedule on a storage (e.g. file)
		virtual bool saveToASCII(BString fileName);
		
		// operators
		VASLPassScheduleElem * operator[] (int16 passScheduleNr);
		
		virtual int16 getNrOfPassSchedules(void); 
		
		void createIt(void); 	// :bp: :ep: 
				 
private:
		PassScheduleElemVector * thePassScheduleElems;
		
		static VASLPassSchedule * instance;
		
};

#endif
