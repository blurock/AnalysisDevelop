// VASLRollingForceOutPar.hpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998

#ifndef VASLRollingForceOutPar_HPP
#define VASLRollingForceOutPar_HPP

#include "ROutParameter.hpp"

//--------------------------------------------------------------------------------
// class VASLRollingForceOutPar
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
//   $Id: VASLRollingForceOutPar.hpp,v 1.1 2008/02/17 12:15:09 blurock Exp $
//--------------------------------------------------------------------------------

class VASLRollingForceOutPar: public ROutParameter {
  METADEF;

  public:
    VASLRollingForceOutPar();
    virtual ~VASLRollingForceOutPar();
    
		// overiden methods
		virtual void printOn(ostream &ostrm=cout);
    
	public:
		float forceHG;
		float phim;
		float faer;
		float blm;
  
};

#endif
