// VASLModelData.hpp
//--------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University of Linz, 1998

#ifndef VASLModelData_HPP
#define VASLModelData_HPP

#include "RModelData.hpp"

class VASLColInfo;

//--------------------------------------------------------------------------------
// class VASLModelData
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
//   $Id: VASLModelData.hpp,v 1.1 2008/02/17 12:15:09 blurock Exp $
//--------------------------------------------------------------------------------

class VASLModelData: public RModelData {
  METADEF;

  public:
		//TODO: implement as class factory!
    VASLModelData();
		VASLModelData(RPrimaryData * aPrim);
    virtual ~VASLModelData();
    virtual VASLColInfo* getColInfo();
    
	private:
		static VASLColInfo *colInfoInstance;
		
};

class VASLColInfo {
	public:
		//column index of the pass data -- see RPassDataTable
		int16 forceHGCol;
		int16 forceLECol;
		int16 forceHECol;
		int16 wmoCol;
		int16 korrWidthCol;
		int16 korrForceHGCol;
		int16 korrWMOCol;
		int16 adjHGCol;
		int16 adjEGCol;
		int16 adjVGCol;
		int16 rtvCol;
		int16 tempCol;
		int16 speedCol;
		int16 stripLengthCol;
		int16 stripWidthCol;
		int16 stripHeightCol;
		int16 stripWidthAfterEdgerCol;
};

#endif
