/*  FILE     VASLModelOptimize.hh
**  PACKAGE  VASLModelOptimize
**  AUTHOR   
**
**  CONTENT
**    Definitions for the "VASLModelOptimize" package.
**
**  OVERVIEW
**
**  IMPLEMENTATION
**
**  REFERENCES
**
*/
 
#ifndef REACTION_VASLMODELOPTIMIZE_HH
#define REACTION_VASLMODELOPTIMIZE_HH


//  ALGORITHM_BASE_ID + 100 by REFORMBASISALG_PREDICATETEST_ID !! wh
#define WIDTHMODELALG_MATRIX_ID         ALGORITHM_BASE_ID + 150
#define WIDTHMODELALG_MATRIX_NAME       "WidthModelMatrixSetUp"

#define OPERATION_WIDTHMODELTOOPT_ID          OPERATION_ID_BASE + 120
#define OPERATION_WIDTHMODELTOOPT_NAME        "WidthModelOptimization"


#include "CoreDataObjects.hh"
#include "NumericObjects.hh"
#include "LogicalObjects.hh"
#include "FunctionReal1DObjects.hh"
#include "OperationObjects.hh"
#include "DataObjects.hh"
#include "InstanceObjects.hh"
#include "MenuObjects.hh"
//#include "PredicateObjects.hh"
#include "DirectedTreeObjects.hh"
#include "SelectObjects.hh"
#include "AlgorithmObjects.hh"
#include "SimulatedAnnealing.hh"


/*P  . . . PROTOTYPES  . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/
void AddVASLModelOptimizeClasses(DataSetOfObjectsClass& set);
extern void InitialVASLModelOptimizeEncodeDecodeRoutines();

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

#ifndef USER_ID
#define USER_ID \
"/* $Id: VASLModelOptimize.hh,v 1.1 2008/02/17 12:15:16 blurock Exp $ */"
#endif

#include "myUser.h"
#if MY_TEMPLATE			/* MY_TEMPLATE_includes */
  /* add your own include files as required */
#endif
#if COST_FILE
#include "myUser_cst.h"
#endif
#if ASA_LIB
static LONG_INT *asa_rand_seed;
#endif
#if ASA_TEMPLATE_SAVE		/* used to illustrate use of ASA_SAVE */
static double random_array[256];
#endif

#ifndef ASA_ID
#define ASA_ID \
"/* $Id: VASLModelOptimize.hh,v 1.1 2008/02/17 12:15:16 blurock Exp $ */"
#endif

#include "myASA.h"






/*P  . . . PROTOTYPES  . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/

/*I  . . . INCLUDES  . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/
#include "VASLModelOptimizeType.hh"




#endif
