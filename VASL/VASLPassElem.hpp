// VASLPassElem.hpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#ifndef VASLPASSELEM_HPP
#define VASLPASSELEM_HPP


#include "BObject.hpp"
 
//---- VASLPassElem -----------------------------------------------------------
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
// $Id: VASLPassElem.hpp,v 1.1 2008/02/17 12:15:08 blurock Exp $ 
//
//-------------------------------------------------------------------------

class VASLPassElem : public BObject {
	METADEF;
	
public:
	// constructor, destructor
	VASLPassElem(); 									
	virtual ~VASLPassElem();							
	
	// overiden methods
	virtual void printOn(ostream &ostrm=cout);												 
	virtual BObject* deeperClone();
	
//	virtual void writeTo(ostream &ostrm);
//    virtual bool readFrom(istream &istrm);

public:
	double passNr;			//st
	double acceleration;	//B-Fakt [mm/s2]
	double adjustmentHStand;//HG-AN [mm]
	double startupSpeed;	//V-ANST [mm/s]
	double passSpeed;		//V-DUR [mm/s]
	double minSpeed;		//V-MIN [mm/s]
	double timePassToPass;	//Anstich-Anstich Zeit [s]
	double meanHeight;		//MITTL.H. [mm]
	bool hno;			// HD Entzunderung Nord oben
	bool hnu;			// HD Entzunderung Nord unten
	bool hso;			// HD Entzunderung Sued oben
	bool hsu;			// HD Entzunderung Sued unten
	bool last;			// Last-Stich
	bool stau;			// Stauchstich
	bool letzt;			// letzter Stich
	int16 direction;	// Richtung - enum typ
	//directon
	enum {
		eForward = 0,
		eBackward
	};

};

#endif
