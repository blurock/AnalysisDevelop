// VASLTempOutPar.hpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998

#ifndef VASLTempOutPar_HPP
#define VASLTempOutPar_HPP

#include "ROutParameter.hpp"

//--------------------------------------------------------------------------------
// class VASLTempOutPar
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
//   $Id: VASLTempOutPar.hpp,v 1.1 2008/02/17 12:15:08 blurock Exp $
//--------------------------------------------------------------------------------

class VASLTempOutPar: public ROutParameter {
  METADEF;

  public:
    VASLTempOutPar();
    virtual ~VASLTempOutPar();
    
		// overiden methods
		virtual void printOn(ostream &ostrm=cout);
    
	public:
		float temp;
  
};

#endif
