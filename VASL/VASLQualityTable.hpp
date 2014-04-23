// VASLQualityTable.hpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#ifndef VASLQUALITYTABLE_HPP
#define VASLQUALITYTABLE_HPP

#include "BObject.hpp"
#include "BString.hpp"
#include "BDictionary.hpp"

#include "VASLQualityTableElem.hpp"


typedef BDictionary<BString*, VASLQualityTableElem*> QualityTableElemDictionary; 

 
//---- VASLQualityTable -----------------------------------------------------------
//
//	Autor: Charly Artmann
//
//	Purpose: 	
//		:bp:
//		represents the "Leitgütentabelle"
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
//* $Id: VASLQualityTable.hpp,v 1.1 2008/02/17 12:15:08 blurock Exp $ */
//
//-------------------------------------------------------------------------

class VASLQualityTable : public BObject {
	METADEF;

	public:
		// constructor, destructor
		VASLQualityTable(); 									
		virtual ~VASLQualityTable();							

		// overiden methods
		virtual void printOn(ostream &ostrm=cout);												 
		virtual BObject* deeperClone();
		
		bool getEdgerAdjValue(BString *key, double &value); 	// :bp: :ep: //Korrekturfaktor Staucher (BBKWST)
		bool getHStandAdjValue(BString *key, double &value); 	// :bp: :ep: //Korrekturfaktor Horizontalgerüst-Anstellung (BBKWHG)
		bool getNumOfPasses(BString *key, int16 &value); 	// :bp: :ep:  //Anzahl der Walzungen dieser Qualität (BBANZ)
		bool getBBKWEG (BString *key, double &value); 	// :bp: :ep: //Korrekturfaktor Egalisiergerüst (BBKWEG)
																											
		void setEdgerAdjValue(BString *key, double val); 	// :bp: :ep:
		void setHStandAdjValue(BString *key, double val); 	// :bp: :ep:
		void setNumOfPasses(BString *key, int16 val); 	// :bp: :ep:
		void setBBKWEG(BString *key, double val); 	// :bp: :ep:
		
		void remove (BString *key); //deletes the entry with the specified key
		void removeAll();		//removes all entrys of the quality table
		
		BString name();
		
	private:
		void createEntry (BString *key); //if the key does not exist an entry will be created

		// instance variable - the entries
		QualityTableElemDictionary* theQualityElems;
		// name - used in conjunction with CORBA
		BString theName;
				 
};

#endif
