/*  FILE     VASLModelOperation.hh
**  PACKAGE  VASLModelOperation
**  AUTHOR   
**
**  CONTENT
**    Definitions for the VASL Models as operaton classes
**
**  OVERVIEW
**
**  IMPLEMENTATION
**
**  REFERENCES
**
*/
 
#ifndef REACTION_VASLMODELOPERATION_HH
#define REACTION_VASLMODELOPERATION_HH

//--------------------
// VGL. VASL.hpp
const double cDiameterOfHGRolls = 800.0; // diameter of horizontal rolls
const double cDiameterOfLERolls = 800.0; // diameter of light edger rolls
const double cDiameterOfHERolls = 1100.0; // diameter of heavy edger rolls

const double cCorrHEdger = 0.852;
const double cCorrRollingForce = 1.141;
const double cCorrKashima = 1.0;	//Korrekturfaktor Kashimaformel
const double cCorrDogBone = 1.0;	// Korrekturfaktor DogBoneModel

const double cCorrEdgerMean = 0.75;

const	double cReductionLEdger = 20.0;
const	double cReductionHEdger = 50.0;
const	double cMaxReductionHEdger = 100.0; // sollte mit Edger model ausgerechnet werden: für schweren und für leichten fixwert
const double cMaxReductionLEdger = 30.0;

//  ALGORITHM_BASE_ID + 100 by REFORMBASISALG_PREDICATETEST_ID !! wh
#define VASLMODEL_ID_BASE                            30800
#define OPERATION_VASLMODEL_ID                       VASLMODEL_ID_BASE + 1
#define OPERATION_VASLDOGBONEMODEL_ID                VASLMODEL_ID_BASE + 2
#define OPERATION_VASLKASHIMAMODEL_ID                VASLMODEL_ID_BASE + 3
#define OPERATION_VASLWIDTHMODEL_ID                  VASLMODEL_ID_BASE + 4


#define OPERATION_VASLMODEL_NAME                     "VASLModelOperation"
#define OPERATION_VASLDOGBONEMODEL_NAME              "VASLDogBoneModelOperation"
#define OPERATION_VASLKASHIMAMODEL_NAME              "VASLKashimaModelOperation"
#define OPERATION_VASLWIDTHMODEL_NAME                "VASLWidthModelOperation"


#include "CoreDataObjects.hh"
#include "NumericObjects.hh"
#include "LogicalObjects.hh"
#include "FunctionReal1DObjects.hh"
#include "OperationObjects.hh"
#include "DataObjects.hh"
#include "InstanceObjects.hh"
//#include "MenuObjects.hh"
//#include "PredicateObjects.hh"
//#include "DirectedTreeObjects.hh"
//#include "SelectObjects.hh"
//#include "AlgorithmObjects.hh"

/*P  . . . PROTOTYPES  . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/
void AddVASLModelOperationClasses(DataSetOfObjectsClass& set);
extern void InitialVASLModelOperationEncodeDecodeRoutines();

/*I  . . . INCLUDES  . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/
#ifdef _msdos_stl
#include <iostream>
#include <list>
#include <map>
using namespace std;
#pragma warning(disable:4786)
#endif

#ifdef _unix
#include "STL.h"
#endif

#include "defines.hh"





/*P  . . . PROTOTYPES  . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/
#define STANDARD_VIRTUAL_VASLMODELOPERATIONMETHODS_OBJECT         \
  virtual BaseDataReal calculate();                               \
  virtual void initTheInputParameters();                          \
  virtual void initTheCoefficients();                             \
  virtual void fillCoefficients(BaseDataDoubleVector *parToOpt);  \
  virtual void fillInputParameters(VectorNumeric *dataVec);  




/*I  . . . INCLUDES  . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/
#include "VASLModelsType.hh"




#endif
