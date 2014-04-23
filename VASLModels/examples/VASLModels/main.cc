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
#include "Vector.hh"
#include "PrimitiveStats.hh"
#include "MatrixNumeric.hh"
#include "BasicLaTeXTable.hh"
#include "MatrixOut.hh"
#include "NumericObjects.hh"
#include "LogicalObjects.hh"
#include "FunctionReal1DObjects.hh"
#include "OperationObjects.hh"
#include "LogicalOperations.hh"
#include "DataObjects.hh"
#include "InstanceObjects.hh"
#include "MenuObjects.hh"
#include "DirectedTreeObjects.hh"
#include "DataObjects.hh"
#include "InstanceObjects.hh"
#include "SelectObjects.hh"
#include "AlgorithmObjects.hh"
#include "ExpressionTree.hh"
#include "InstanceAlgorithms.hh"
#include "DistributionAlgorithm.hh"
#include "NumericOperations.hh"
#include "ParameterizedFunction.hh"
#include "PredicateObjects.hh"
#include "PredicateGen.hh"
#include "RuleSystem.hh"
#include "Optimize.hh"
#include "PopulationBasedOptimization.hh"
#include "ParameterizedFunction.hh"
#include "GeneticOperations.hh"
#include "VectorOperations.hh"
#include "EvaluationTree.hh"
#include "EntropyObjects.hh"
#include "DecisionTreeAlgorithms.hh"
#include "VASLModels.hh"
#include "VerifyEnvironment.hh"
#include "SimulatedAnnealing.hh"
#include "VASLModelOptimize.hh"

static int ExpressionReadIn(ReactionSystemBase *level1);

 
class SystemCoreObjectTest : public AlgorithmSystemSave
{
public:
  SystemCoreObjectTest(int argc, char *argv[])
    : AlgorithmSystemSave(argc,argv)
    {
    }
  void EncodeDecodeObjectsSetUp()
    {
      AlgorithmSystemSave::EncodeDecodeObjectsSetUp();
      InitialInstanceAlgorithmsEncodeDecodeRoutines();
      InitialDistributionObjectsEncodeDecodeRoutines();
      InitialSetOfExpressionTreeEncodeDecodeRoutines();
      InitialSetOfNumericOperationEncodeDecodeRoutines();
      InitialSetOfLogicalOperationEncodeDecodeRoutines();
      InitialParameterizedEncodeDecodeRoutines();
      InitialSetOfPredicateEncodeDecodeRoutines();
      InitialSetOfRuleSystemEncodeDecodeRoutines();

      InitialPredicateGenEncodeDecodeRoutines();
      InitialEntropyAlgorithmEncodeDecodeRoutines();
      DecisionTreeEncodeDecodeRoutines();

      InitialSetOfOptimizeEncodeDecodeRoutines();
      InitialSetOfPopulationEncodeDecodeRoutines();
      InitialGeneticEncodeDecodeRoutines();

      InitialVASLModelOperationEncodeDecodeRoutines();
      InitialSimAnnAlgorithmsEncodeDecodeRoutines();
      InitialVASLModelOptimizeEncodeDecodeRoutines();

      VerifyEncodeDecodeRoutines();
    }
    void StandardObjectsSetUp()
    {
      AlgorithmSystemSave::StandardObjectsSetUp();
      AddInstanceAlgorithmsClasses(getStandard());
      AddBaseDistributionClasses(getStandard());
      AddBaseExpressionTreeClasses(getStandard());
      AddNumericOperationClasses(getStandard());
      AddParameterizedClasses(getStandard());
      AddLogicalOperationClasses(getStandard());
      AddParameterizedClasses(getStandard());
      AddPredicateClasses(getStandard());
      AddRuleSystemClasses(getStandard());

      AddPredicateGenAlgorithmClasses(getStandard());
      AddEntropyAlgorithmClasses(getStandard());
      AddDecisionTreeClasses(getStandard());

      AddOptimizeClasses(getStandard());
      AddPopulationClasses(getStandard());
      AddGeneticClasses(getStandard());

      AddVASLModelOperationClasses(getStandard());
      AddSimAnnAlgorithmsClasses(getStandard());
      AddVASLModelOptimizeClasses(getStandard());

      AddBaseVerifyClasses(getStandard());
    }
    
  void CommandSetUp()
    {     
      AlgorithmSystemSave::CommandSetUp();

      SingleSystemCommand readit("TestRead",
				"Simple Read in Test",
				&ExpressionReadIn);
      Commands.AddObject("TestRead",readit);
    }
};
/*F main(argc,argv) . . . . . . . . . . . . . . . . . . . . . . . . . .  main
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
int main(int argc, char *argv[])
{
  SystemCoreObjectTest test(argc,argv);
  
  test.Initialization();
  test.Run();
  test.Exit();
  
}
/*F ans = AlgorithmReadIn(level1)
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
static int ExpressionReadIn(ReactionSystemBase *level1)
{
  SystemCoreObjectTest *test = (SystemCoreObjectTest *) level1;

  if(test->Inputs.size() < 1)
    {
      cout << "Input:\n";
      cout << "Filename: Expression Class\n";
      cout << "Filename: Expression \n";
      
      return 1;
    }

  String algorithmClassS = test->Inputs.front();
  test->Inputs.pop_front();
  String algorithmS = test->Inputs.front();
  test->Inputs.pop_front();

  
  BaseDataExpressionTree tree;
  DataExpressionTreeClass *ctree = (DataExpressionTreeClass *)
    test->InstanceClasses.PointerToAllowedClasses()->GetObjectClass(EXPRESSIONTREE_TREE_NAME);
  
  
  OpenInputFile inclass(algorithmClassS);
  OpenInputFile inexp(algorithmS);

  cout << "-------------------------------------------" << endl;
  cout << "        Read in Tree Class" << endl;
  cout << "-------------------------------------------" << endl;
  ctree->Read(inclass.Stream,*(test->InstanceClasses.PointerToAllowedClasses()));
  cout << endl << "-------------------------------------------" << endl;
  ctree->print(cout);
  DataExpressionTreeClass *ctree1 = (DataExpressionTreeClass *)
    test->InstanceClasses.PointerToAllowedClasses()->GetObjectClass(EXPRESSIONTREE_TREE_NAME);
  cout << endl << "=============================================" << endl;
  ctree1->print(cout);
  cout << endl << "=============================================" << endl;
  
  
  cout << "-------------------------------------------" << endl;
  cout << "        Read in Tree" << endl;
  cout << "-------------------------------------------" << endl;
  tree.Read(inexp.Stream,ctree);
  cout << endl << "-------------------------------------------" << endl;
  tree.print(cout);
  cout << "\n-------------------------------------------" << endl;
  cout << "        Value of Tree" << endl;
  cout << "-------------------------------------------" << endl;
  BaseDataObject *ans = tree.operator()(&(test->Instances),&(test->InstanceClasses));
  cout << "\n-------------------------------------------" << endl;
  ans->print(cout);
  cout << endl;
  
  return 1;
}

