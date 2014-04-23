// VASLEdgerOutPar.hpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998

#ifndef VASLEdgerOutPar_HPP
#define VASLEdgerOutPar_HPP

#include "ROutParameter.hpp"

//--------------------------------------------------------------------------------
// class VASLEdgerOutPar
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
//   $Id: VASLEdgerOutPar.hpp,v 1.1 2008/02/17 12:15:10 blurock Exp $
//--------------------------------------------------------------------------------

class VASLEdgerMaxRedOutPar: public ROutParameter {
  METADEF;

  public:
    VASLEdgerMaxRedOutPar();
    virtual ~VASLEdgerMaxRedOutPar();
    
		// overiden methods
		virtual void printOn(ostream &ostrm=cout);
    
	public:
		float reduction;
  
};

class VASLEdgerForceOutPar: public ROutParameter {
  METADEF;

  public:
    VASLEdgerForceOutPar();
    virtual ~VASLEdgerForceOutPar();
    
		// overiden methods
		virtual void printOn(ostream &ostrm=cout);
    
	public:
		float force;
  
};
#endif
