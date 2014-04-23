// VASLLossTRadInPar.hpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998

#ifndef VASLLossTRadInPar_HPP
#define VASLLossTRadInPar_HPP

#include "RInParameter.hpp"

//--------------------------------------------------------------------------------
// class VASLLossTRadInPar
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
//   $Id: VASLLossTRadInPar.hpp,v 1.1 2008/02/17 12:15:09 blurock Exp $
//--------------------------------------------------------------------------------

class VASLLossTRadInPar: public RInParameter {
  METADEF;

  public:
    VASLLossTRadInPar();
    virtual ~VASLLossTRadInPar();
    
    // overiden methods
		virtual void printOn(ostream &ostrm=cout);
    
	public:
		float heightBeforePass;
		float timeToNext;
		float curTemp;
};

#endif
