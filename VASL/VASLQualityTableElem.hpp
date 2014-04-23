// VASLQualityTableElem.hpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#ifndef VASLQUALITYTABLEELEM_HPP
#define VASLQUALITYTABLEELEM_HPP

#include "BObject.hpp"

 
//---- VASLQualityTableElem ----------------------------------------------------
//
//	Autor: Dietrich Birngruber
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
//* $Id: VASLQualityTableElem.hpp,v 1.1 2008/02/17 12:15:08 blurock Exp $ */
//
//-------------------------------------------------------------------------


class VASLQualityTableElem : public BObject  {
	METADEF;

	public:
		VASLQualityTableElem();
		virtual ~VASLQualityTableElem();

		// overiden methods
		virtual void printOn(ostream &ostrm=cout);												 
		virtual BObject* deeperClone();

		//instance variables
		double	edgerAdjValue;		//Korrekturfaktor Staucher (BBKWST)
		double	hStandAdjValue;		//Korrekturfaktor Horizontalgerüst-Anstellung (BBKWHG)
		double 	bbkweg;					//Korrekturfaktor Egalisiergerüst (BBKWEG)
		int16		numOfPasses;		//Anzahl der Walzungen dieser Qualität (BBANZ)

};

#endif // !defined(VASLQUALITYTABLEELEM_HPP)
