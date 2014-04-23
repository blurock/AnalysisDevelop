// VASL.hpp
//------------------------------------------------------------------------------
// Copyright ESPRIT Project Group, University Linz, 1997

#ifndef VASL_HPP
#define VASL_HPP


//---- VASL -----------------------------------------------------------
//
//	Purpose: 	
//		:bp:
//		
//		:ep:
//
//	Associations to other Classes:
//		:ba:
//		None.
//		:ea:
//
//	Usage:
//		:bu:
//		No special usage advices.
//  	:eu:
//
// 	Important hints for subclasses:
//		:bh:
//		No special hints.
//		:eh:
//
//	File Info:
//
// $Id: VASL.hpp,v 1.1 2008/02/17 12:15:08 blurock Exp $ 
//
//-------------------------------------------------------------------------


const float diameterOfHGRolls = 450.0f; // diameter of horizontal rolls
const float diameterOfLERolls = 800.0f; // diameter of light edger rolls
const float diameterOfHERolls = 1200.0f; // diameter of heavy edger rolls
const float maxDeviation = 0.5f;	//the max. allowed deviation of the calculated width and the final width
const float maxHEdgerForce = 300.0f; //the max pressure force of the heavy edger in tonns
const float maxLEdgerForce = 100.0f; //the max pressure force of the light edger in tonns
const float maxLEdgerKW = 600.0f; //the max. performance of the light edger motors in KW
const float maxHEdgerKW = 1500.0f; //the max. performance of the light edger motors in KW
const float maxMechHEReduction = 100.0f; // the max. achievable reduction of the heavy edger in mm
const float maxMechLEReduction = 30.0f; // the max. achievable reduction of the light edger in mm
const float tempOfWater = 20.0f; //temperature of cooling water; wird bei radiation-temp-modell verwendet
const float timeOvenToHE = 30.0f; // time between oven and heavy edger in seconds
const float timeHEdgerToHG = 30.0f;			// time heavy edger and roughing stand in seconds
const float turnAroundTime = 8.0f; // time for turning around in seconds
const float smv = 1.0f; //stichspez. Vererbungsf. für Walzmoment
const float speedAtHeavyEdger = 1000.0f; // Durchlaufgeschwindigkeit beim staucher [mm/second]
const float maxAcceleration = 800.0f; //max. acceleration of HG [mm/second]

const float corrMM = 1000.0;
#endif
