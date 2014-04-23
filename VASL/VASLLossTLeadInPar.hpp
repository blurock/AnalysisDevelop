// VASLLossTLeadInPar.hpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998

#ifndef VASLLossTLeadInPar_HPP
#define VASLLossTLeadInPar_HPP

#include "RInParameter.hpp"

//--------------------------------------------------------------------------------
// class VASLLossTLeadInPar
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
//   $Id: VASLLossTLeadInPar.hpp,v 1.1 2008/02/17 12:15:10 blurock Exp $
//--------------------------------------------------------------------------------

class VASLLossTLeadInPar: public RInParameter {
  METADEF;

  public:
    VASLLossTLeadInPar();
    virtual ~VASLLossTLeadInPar();
    
    // overiden methods
		virtual void printOn(ostream &ostrm=cout);
    
	public:
		float heightAfterPass;
		float speedOfSlab;
		float blm;
		float curTemp;
  
};

#endif
