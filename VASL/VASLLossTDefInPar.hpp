// VASLLossTDefInPar.hpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998

#ifndef VASLLossTDefInPar_HPP
#define VASLLossTDefInPar_HPP

#include "RInParameter.hpp"

//--------------------------------------------------------------------------------
// class VASLLossTDefInPar
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
//   $Id: VASLLossTDefInPar.hpp,v 1.1 2008/02/17 12:15:08 blurock Exp $
//--------------------------------------------------------------------------------

class VASLLossTDefInPar: public RInParameter {
  METADEF;

  public:
    VASLLossTDefInPar();
    virtual ~VASLLossTDefInPar();
    
    // overiden methods
		virtual void printOn(ostream &ostrm=cout);
    
	public:
		float faer;
		float phim;
		float curTemp;
		float smv;
  
};

#endif
