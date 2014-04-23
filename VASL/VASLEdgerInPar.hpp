// VASLEdgerInPar.hpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998

#ifndef VASLEdgerInPar_HPP
#define VASLEdgerInPar_HPP

#include "RInParameter.hpp"

//--------------------------------------------------------------------------------
// class VASLEdgerInPar
//
// purpose:                                                                   :bp:
//   none                                                                     :ep:	
// associations to other classes:                                             :ba:
//   none                                                                     :ea:	
// usage:                                                                     :bu:
//   none                                                                     :eu:	
// important hints for subclasses:                                            :bh:
//   none                                                                     :uh:
//	
// history:
//   $Id: VASLEdgerInPar.hpp,v 1.1 2008/02/17 12:15:09 blurock Exp $
//--------------------------------------------------------------------------------

class VASLEdgerInPar: public RInParameter {
  METADEF;

  public:
    VASLEdgerInPar();
    virtual ~VASLEdgerInPar();
    
    // overiden methods
		virtual void printOn(ostream &ostrm=cout);
    
	public:
		float e[6]; //durch SMC zugeführte Energie in [10 kJ]
		float tempZ; //Ziehtemperatur
		float timeZS; //Zeit zw. Austragen und Anstich in sec. - minimum is 30. sec
		float timeH; 	//min. is 20 minutes
		float kws;	//from the "quality table"
		float speedOfSlab;
		float reduction;
		float curLength; 
		float widthBeforeEdger;
		float heightBeforeEdger;
//		float diameterOfEdgerRolls;
//		float maxEdgerForce;
//		float maxEdgerKW; 
//		float maxMechEdgerReduction;
		
};

#endif
