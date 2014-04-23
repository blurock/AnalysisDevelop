// VASLDogBoneInPar.hpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998

#ifndef VASLDogBoneInPar_HPP
#define VASLDogBoneInPar_HPP

#include "RInParameter.hpp"

//--------------------------------------------------------------------------------
// class VASLDogBoneInPar
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
//   $Id: VASLDogBoneInPar.hpp,v 1.1 2008/02/17 12:15:09 blurock Exp $
//--------------------------------------------------------------------------------

class VASLDogBoneInPar: public RInParameter {
  METADEF;

  public:
    VASLDogBoneInPar();
    virtual ~VASLDogBoneInPar();
  
		// overiden methods
		virtual void printOn(ostream &ostrm=cout);												 

	  
	public:
		float widthBeforeEdger;
		float widthAfterEdger; 
		float heightBeforeEdger;
		//float diameterOfEdgerRolls;	
	
  
};

#endif
