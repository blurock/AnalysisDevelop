// VASLWidthOutPar.hpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998

#ifndef VASLWidthOutPar_HPP
#define VASLWidthOutPar_HPP

#include "ROutParameter.hpp"

//--------------------------------------------------------------------------------
// class VASLWidthOutPar
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
//   $Id: VASLWidthOutPar.hpp,v 1.1 2008/02/17 12:15:08 blurock Exp $
//--------------------------------------------------------------------------------

class VASLWidthOutPar: public ROutParameter {
  METADEF;

  public:
    VASLWidthOutPar();
    virtual ~VASLWidthOutPar();
    
		// overiden methods
		virtual void printOn(ostream &ostrm=cout);
    
	public:
		float widthInc;
  
};

#endif
