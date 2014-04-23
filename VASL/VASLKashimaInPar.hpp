// VASLKashimaInPar.hpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998

#ifndef VASLKashimaInPar_HPP
#define VASLKashimaInPar_HPP

#include "RInParameter.hpp"

//--------------------------------------------------------------------------------
// class VASLKashimaInPar
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
//   $Id: VASLKashimaInPar.hpp,v 1.1 2008/02/17 12:15:08 blurock Exp $
//--------------------------------------------------------------------------------

class VASLKashimaInPar: public RInParameter {
  METADEF;

  public:
    VASLKashimaInPar();
    virtual ~VASLKashimaInPar();
    
    // overiden methods
		virtual void printOn(ostream &ostrm=cout);
		
  public:
		float widthBeforePass;
		float heightBeforePass;
		float heightAfterPass;
		float diameterOfRoughingRolls;
		
};

#endif
