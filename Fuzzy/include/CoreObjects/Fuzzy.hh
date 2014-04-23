/*  FILE     Fuzzy.hh
**  PACKAGE  Fuzzy
**  AUTHOR   Harald Wahl
**
**  CONTENT
**    Prototypes for the "Fuzzy" package in the CoreObjects environment
**
**  COPYRIGHT (C) 1997 Edward S. Blurock
*/
 
#ifndef CoreObjects_FUZZY_HH
#define CoreObjects_FUZZY_HH

#define FUZZY_BASE_ID    65000
#define FUZZY_BASE_NAME  "Fuzzy"

/*I  . . . INCLUDES . . . . . . . . . . . . . . . . . . . . . . . . . . . .  
*/
#include "FuzzyType.hh"


/*P  . . . PROTOTYPES . . . . . . . . . . . . . . . . . . . . . . . . . . .  
*/
void AddFuzzyClasses(DataSetOfObjectsClass& set);
extern void InitialSetOfFuzzyEncodeDecodeRoutines();

#endif
