// VASLLossTDescInPar.hpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998

#ifndef VASLLossTDescInPar_HPP
#define VASLLossTDescInPar_HPP

#include "RInParameter.hpp"

//--------------------------------------------------------------------------------
// class VASLLossTDescInPar
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
//   $Id: VASLLossTDescInPar.hpp,v 1.1 2008/02/17 12:15:08 blurock Exp $
//--------------------------------------------------------------------------------

class VASLLossTDescInPar: public RInParameter {
  METADEF;

  public:
    VASLLossTDescInPar();
    virtual ~VASLLossTDescInPar();
    
    // overiden methods
		virtual void printOn(ostream &ostrm=cout);
    
	public:
		float speedOfSlab;
		float heightBeforePass;
		float tw;
		float curTemp;
};

#endif
