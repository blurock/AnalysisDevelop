/*  FILE     PredicateGoal.hh
**  PACKAGE  PredicateGoal
**  AUTHOR   Edward S. Blurock
**
**  CONTENT
**    Prototypes for the "PredicateGoal" package in the CoreObjects environment
**
**  COPYRIGHT (C) 1997 Edward S. Blurock
*/
 
#ifndef CoreObjects_PREDICATEGOAL_HH
#define CoreObjects_PREDICATEGOAL_HH

#define PREDICATEGOAL_SINGLEVARIABLE_NAME      "SingleVariable"
#define PREDICATEGOAL_SINGLEVARIABLE_ID        PREDICATEGOAL_BASE + 10
#define PREDICATEGOAL_VARIABLEASSIGNMENT_NAME "VariableAssignment"
#define PREDICATEGOAL_VARIABLEASSIGNMENT_ID    PREDICATEGOAL_BASE + 20
#define PREDICATEGOAL_VARIABLEENVIRONMENT_NAME "VariableEnvironment"
#define PREDICATEGOAL_VARIABLEENVIRONMENT_ID   PREDICATEGOAL_BASE + 30
#define PREDICATEGOAL_GOALPREDICATE_NAME      "GoalPredicate"
#define PREDICATEGOAL_GOALPREDICATE_ID         PREDICATEGOAL_BASE + 40
#define PREDICATEGOAL_SETOFGOALS_NAME          "SetOfGoalPredicates"
#define PREDICATEGOAL_SETOFGOALS_ID            PREDICATEGOAL_BASE + 50
#define PREDICATEGOAL_GOALENV_NAME             "GoalPredicateEnvironment"
#define PREDICATEGOAL_GOALENV_ID               PREDICATEGOAL_BASE + 60
#define PREDICATEGOAL_FACTENV_NAME             "FactPredicateEnvironment"
#define PREDICATEGOAL_FACTENV_ID               PREDICATEGOAL_BASE + 70
#define PREDICATEGOAL_CURRENTENV_NAME          "CurrentEnvironment"
#define PREDICATEGOAL_CURRENTENV_ID            PREDICATEGOAL_BASE + 80
#define PREDICATEGOAL_TOPLEVEL_NAME            "TopLevelEnvironment"
#define PREDICATEGOAL_TOPLEVEL_ID              PREDICATEGOAL_BASE + 90

/*I  . . . INCLUDES . . . . . . . . . . . . . . . . . . . . . . . . . . . .  
*/
#include "CoreObjects/PredicateGoalType.hh"


/*P  . . . PROTOTYPES . . . . . . . . . . . . . . . . . . . . . . . . . . .  
*/
extern void InitialPredicateGoalObjectsEncodeDecodeRoutines();
void AddPredicateObjectsClasses(DataSetOfObjectsClass& set);


#endif
