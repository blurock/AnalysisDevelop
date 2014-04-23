// VASLRollingForceInPar.hpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998

#ifndef VASLRollingForceInPar_HPP
#define VASLRollingForceInPar_HPP

#include "RInParameter.hpp"

//--------------------------------------------------------------------------------
// class VASLRollingForceInPar
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
//   $Id: VASLRollingForceInPar.hpp,v 1.1 2008/02/17 12:15:08 blurock Exp $
//--------------------------------------------------------------------------------

class VASLRollingForceInPar: public RInParameter {
  METADEF;

  public:
    VASLRollingForceInPar();
    virtual ~VASLRollingForceInPar();
    
    // overiden methods
		virtual void printOn(ostream &ostrm=cout);
    
	public:
		float curTemp;	
		float heightBeforePass; 
		float heightAfterPass;
		float widthBeforeEdger; 
		float widthAfterEdger; 
		float widthAfterPass; 
		float speedOfSlab;
		float diameterOfRoughingRolls; 
		
};

#endif
