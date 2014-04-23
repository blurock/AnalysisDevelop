/*  FILE     main.cc
**  PACKAGE     REACTION    
**  AUTHOR   Edward S. Blurock
**
**  CONTENT
**    
**
**  REFERENCES
**
**  COPYRIGHT (C) 1995  REACTION Project / Edward S. Blurock 
*/
 
/*I  . . . INCLUDES  . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/
#include "CoreDataObjects.hh"
#include "NumericObjects.hh"
#include "LogicalObjects.hh"
#include "FunctionReal1DObjects.hh"
#include "OperationObjects.hh"
#include "DataObjects.hh"
#include "InstanceObjects.hh"
#include "DirectedTreeObjects.hh"
#include "SelectObjects.hh"
#include "AlgorithmObjects.hh"
#include "InstanceAlgorithms.hh"
#include "GoalObjects.hh"
#include "PredicateGoal.hh"

static int SimpleVariableTest(ReactionSystemBase *level1);
static int SimpleVariableUnifyTest(ReactionSystemBase *level1);
static int GoalPredicateUnifyTest(ReactionSystemBase *level1);


class SystemGoalPredicateTest : public GoalSystemSave
{
public:
  SystemGoalPredicateTest(int argc, char *argv[])
    : GoalSystemSave(argc,argv)
    {
    }
  void EncodeDecodeObjectsSetUp()
    {
      GoalSystemSave::EncodeDecodeObjectsSetUp();
      InitialInstanceAlgorithmsEncodeDecodeRoutines();
      InitialPredicateGoalObjectsEncodeDecodeRoutines();
    }
  void StandardObjectsSetUp()
    {
      GoalSystemSave::StandardObjectsSetUp();
      AddPredicateObjectsClasses(getStandard());
    }
  
  void CommandSetUp()
    {
      GoalSystemSave::CommandSetUp();
      
      SingleSystemCommand variable("VariableTest",
				"Simple variable and variable assignment test",
				&SimpleVariableTest);
      Commands.AddObject("VariableTest",variable);

      SingleSystemCommand simpunify("SimpleVariableUnify",
				"Variable Unify test",
				&SimpleVariableUnifyTest);
      Commands.AddObject("SimpleVariableUnify",simpunify);

      SingleSystemCommand predunify("GoalPredicateUnify",
				"Goal Predicate Unify test",
				&GoalPredicateUnifyTest);
      Commands.AddObject("GoalPredicateUnify",predunify);
    }
};
/*F
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
int main(int argc, char *argv[])
{
  SystemGoalPredicateTest test(argc,argv);
  
  test.Initialization();
  StandardAllowedClasses = &(test.InstanceClasses);
  test.Run();
  test.Exit();
  
}
  
/*F ans = SimpleVariableTest(level1)  . . . . . . . . . . .  simple variable test
**
**  DESCRIPTION
**    This reads in three goal specs from one file and checks for equality of the
**    first against the second and third
**
**  REMARKS
**
*/
static int SimpleVariableTest(ReactionSystemBase *level1)
{
  SystemGoalPredicateTest *test = (SystemGoalPredicateTest *) level1;

  if(test->Inputs.size() < 1)
    {
      cout << "Input:\n";
      cout << "Filename: Three Variable Assignments \n";
      
      return 1;
    }
  
  String filename = test->Inputs.front();
  test->Inputs.pop_front();
  OpenInputFile file(filename);
  
  cout << "----------------------------------------------------------------------------\n";
  cout << " Assignment: Simple Read and Print Test\n";
  cout << "----------------------------------------------------------------------------\n";
  DataVariableAssignmentClass sclass(555,"VariableAssignment", "Variable Assignment Class");

  cout << "Read in 3 Variable Assignment instances\n";
  BaseDataVariableAssignment assign1,assign2,assign3;
  assign1.Read(file.Stream,&sclass);
  assign1.print(cout);
  cout << "\n";
  assign2.Read(file.Stream,&sclass);
  assign2.print(cout);
  cout << "\n";
  assign3.Read(file.Stream,&sclass);
  assign3.print(cout);
  cout << "\n";
  cout.flush();

  cout << "----------------------------------------------------------------------------\n";
  cout << " Assignment: Simple Equality Tests\n";
  cout << "----------------------------------------------------------------------------\n";
  cout << "Compare Variable 1 and Variable 2\n";
  if(assign1.operator==(assign2))
    cout << "Equal\n";
  else
    cout << "Not Equal\n";
  
  cout << "Compare Variable 1 and Variable 3\n";
  if(assign1.operator==(assign3))
    cout << "Equal\n";
  else
    cout << "Not Equal\n";
  
  cout << "----------------------------------------------------------------------------\n";
  cout << " Environment: Simple Tests\n";
  cout << "----------------------------------------------------------------------------\n";

  cout << "Add to environment\n";
  BaseDataVariableEnvironment env;
  env.NameTag = "Environment";

  cout << "Adding Assignment 1\n";
  if(env.Conflict(assign1))
      cout << "Conflict with environment\n";
  else
      cout << "No Conflict With environment\n";

  env.addVariableAssignment(assign1);
  cout << "Adding Assignment 2\n";
  if(env.Conflict(assign2))
      cout << "Conflict with environment\n";
  else
      cout << "No Conflict With environment\n";

  env.addVariableAssignment(assign2);
  cout << "Adding Assignment 3\n";
  if(env.Conflict(assign3))
      cout << "Conflict with environment\n";
  else
      cout << "No Conflict With environment\n";

  env.addVariableAssignment(assign3);

  env.print(cout);
  cout << endl;
  
  cout << "----------------------------------------------------------------------------\n";
  cout << " Environment: Add to Set of Attributes\n";
  cout << "----------------------------------------------------------------------------\n";

  test->Instances.AddObject(&assign1);
  test->Instances.AddObject(&env);
  test->Instances.print(cout);

  return 0;
}
/*F ans = SimpleVariableTest(level1)  . . . . . . . . . . .  simple variable test
**
**  DESCRIPTION
**    This reads in three goal specs from one file and checks for equality of the
**    first against the second and third
**
**  REMARKS
**
*/
static int SimpleVariableUnifyTest(ReactionSystemBase *level1)
{
  SystemGoalPredicateTest *test = (SystemGoalPredicateTest *) level1;

  if(test->Inputs.size() < 1)
    {
      cout << "Input:\n";
      cout << "Filename: Three Variable Assignments \n";
      
      return 1;
    }
  
  String filename = test->Inputs.front();
  test->Inputs.pop_front();
  OpenInputFile file(filename);
  
  cout << "----------------------------------------------------------------------------\n";
  cout << " Variable: Simple Unify Test\n";
  cout << "----------------------------------------------------------------------------\n";
  
  DataSingleVariableClass varclass(555,"SingleVariable", "Single Variable Class");
  BaseDataVariableEnvironment *env = new BaseDataVariableEnvironment;;
  
  BaseDataSingleVariable var1,var2,var3;
  var1.Read(file.Stream,&varclass);
  var2.Read(file.Stream,&varclass);
  var3.Read(file.Stream,&varclass);

  cout << "----------------------------------------------------------------------------\n";
  cout << "  Unify Variable 1 and Variable 2\n";
  cout << "----------------------------------------------------------------------------\n";
  BaseDataVariableEnvironment *newenv = var1.Unify(&var2,env,1);
  if(newenv != NULL)
    {
      cout << "----------------------------------------------------------------------------\n";
      cout << "The environment after unification\n";
      cout << "----------------------------------------------------------------------------\n";
      newenv->print(cout);
      cout << "----------------------------------------------------------------------------\n";
    }
  else
    {
      cout << " Unsuccessful unification\n";
    }

  if(newenv != NULL)
    {
      cout << "----------------------------------------------------------------------------\n";
      cout << "  Unify Variable 2 and Variable 3\n";
      cout << "----------------------------------------------------------------------------\n";
      newenv = var2.Unify(&var3,newenv,1);
      if(newenv != NULL)
	{
	  cout << "----------------------------------------------------------------------------\n";
	  cout << "The environment after unification\n";
	  cout << "----------------------------------------------------------------------------\n";
	  newenv->print(cout);
	  cout << "----------------------------------------------------------------------------\n";
	}
      else
	{
	  cout << " Unsuccessful unification\n";
	}
      
    }
  return 0;
}
/*F ans = SimpleVariableTest(level1)  . . . . . . . . . . .  simple variable test
**
**  DESCRIPTION
**    This reads in three goal specs from one file and checks for equality of the
**    first against the second and third
**
**  REMARKS
**
*/
static int GoalPredicateUnifyTest(ReactionSystemBase *level1)
{
  SystemGoalPredicateTest *test = (SystemGoalPredicateTest *) level1;

  if(test->Inputs.size() < 1)
    {
      cout << "Input:\n";
      cout << "Filename: Three Variable Assignments \n";
      
      return 1;
    }
  
  String filename = test->Inputs.front();
  test->Inputs.pop_front();
  OpenInputFile file(filename);
  
  cout << "----------------------------------------------------------------------------\n";
  cout << " GoalPredicate: Simple Unify Test\n";
  cout << "----------------------------------------------------------------------------\n";
  
  BaseDataGoalPredicate pred1,pred2,pred3;
  DataGoalPredicateClass predcls(555,"GoalPredicate","Goal Predicate Class");
  
  cout << "\n Read in 2 Goal Predicates\n";
  pred1.Read(file.Stream,&predcls);
  cout << "\n -------------- First Predicate -------------------\n";
  pred1.print(cout);
  cout << "\n -------------- First Predicate -------------------\n";
  pred2.Read(file.Stream,&predcls);
  cout << "\n -------------- Second Predicate -------------------\n";
  pred2.print(cout);
  cout << "\n -------------- Second Predicate -------------------\n";
  
  cout << "\nUnify the predicates\n";
  BaseDataVariableEnvironment *env = new BaseDataVariableEnvironment;
  
  BaseDataVariableEnvironment *newenv = pred1.Unify(&pred2,env,1);
  if(newenv != NULL)
    {
      cout << "----------------------------------------------------------------------------\n";
      cout << "The environment after unification\n";
      cout << "----------------------------------------------------------------------------\n";
      newenv->print(cout);
      cout << "----------------------------------------------------------------------------\n";
    }
  else
    {
      cout << " Unsuccessful unification\n";
    }  
  return 0;
}
