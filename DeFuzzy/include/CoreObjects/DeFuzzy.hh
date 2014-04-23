/*  FILE     DeFuzzy.hh
**  PACKAGE  DeFuzzy
**  AUTHOR   SCCH
**
**  CONTENT
**    Prototypes for the "DeFuzzy" package in the CoreObjects environment
**
**  COPYRIGHT (C) 1997 Edward S. Blurock
*/
 
#ifndef CoreObjects_DEFUZZY_HH
#define CoreObjects_DEFUZZY_HH


#define DEFUZZY_BASE_ID 55000

#define DEFUZZY_EVALUATERULESYSTEM_ID     DEFUZZY_BASE_ID+10
#define DEFUZZY_CONDITIONVALUEPAIR_ID     DEFUZZY_BASE_ID+20
#define DEFUZZY_EVALUATEDRULESYSTEM_ID    DEFUZZY_BASE_ID+30

#define DEFUZZY_EVALUATERULESYSTEM_NAME   "EvaluateRuleSystem"
#define DEFUZZY_CONDITIONVALUEPAIR_NAME   "ConditionValuePair"
#define DEFUZZY_EVALUATEDRULESYSTEM_NAME  "EvaluatedRuleSystem"

#define DeFuzzy_CombineScaledDefuzzify_ID  DEFUZZY_BASE_ID+40


/*I  . . . INCLUDES . . . . . . . . . . . . . . . . . . . . . . . . . . . .  
*/
#include "DeFuzzyType.hh"

/*P  . . . PROTOTYPES . . . . . . . . . . . . . . . . . . . . . . . . . . .  
*/

extern void InitialDeFuzzyEncodeDecodeRoutines();
void AddDeFuzzyClasses(DataSetOfObjectsClass& set);

#endif
