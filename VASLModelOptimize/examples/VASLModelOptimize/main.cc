/*  FILE     main.cpp
**  PACKAGE  SimulatedAnnealing    
**  AUTHOR   
**
**  CONTENT
**    test program for SimulatedAnnealing package
**
**  REFERENCES
**
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
#include "VASLModelOptimize.hh"


//#define TEMPLATE_INSTANTIATION
////#include "CommBuffer.hh"
////#include "String.hh"
////#include "Objects.hh"
////#include "Vector.hh"
//
//#include "CoreDataObjects.hh"
//#include "NumericObjects.hh"
//#include "LogicalObjects.hh"
//#include "FunctionReal1DObjects.hh"
//#include "OperationObjects.hh"
//#include "DataObjects.hh"
//#include "InstanceObjects.hh"
//#include "MenuObjects.hh"
////#include "PredicateObjects.hh"
//#include "DirectedTreeObjects.hh"
//#include "SelectObjects.hh"
//#include "AlgorithmObjects.hh"
//
//#include "InstanceAlgorithms.hh"
//// #include "PredicateObjects.hh"
//
////#include "CommBuffer.hh"
////#include "String.hh"
////#include "Vector.hh"
////
////#include "System.hh"
////#include "MatrixNumeric.hh"
////#include "BasicLaTeXTable.hh"
////#include "MatrixOut.hh"
////#include "PrimitiveStats.hh"
//
////#include "ReadData.hh"

#include <string>


#ifdef _unix
//#include "unix.hh"
#endif

#include "SimulatedAnnealing.hh"
#include "VASLModels.hh"


//#include "VObject.hpp"
#include "PrimitiveStats.hh"
#include "DistributionAlgorithm.hh"

int TransferAttributes(ReactionSystemBase* sys);
int T(ReactionSystemBase* sys);
static int ExpressionReadIn(ReactionSystemBase *level1);



class VASLModelOptimizeTest : public AlgorithmSystemSave
{
public:

// Constructor
	VASLModelOptimizeTest(int argc, char *argv[]) 
	: AlgorithmSystemSave(argc, argv)
	{
//		cout << endl;
//		PrintCommandList(this);
//		cout << endl << endl;
	}
  void CommandSetUp()
    {
      AlgorithmSystemSave::CommandSetUp();

      SingleSystemCommand readit("TestRead",
				"Simple Read in Test",
				&ExpressionReadIn);

      String trans("TransferAttributes");
      SingleSystemCommand transfer(trans,
				    "Transfer Attributes",
				    &TransferAttributes);

      String t("T");
      SingleSystemCommand tr(t,
				    "T",
				    &T);

      Commands.AddObject("TestRead",readit);
      Commands.AddObject(trans,transfer);
      Commands.AddObject(t,tr);
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

//      InitialDistributionObjectsEncodeDecodeRoutines();
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

//      AddBaseDistributionClasses(getStandard());
    }
}; // SimulatedAnnealingTest



int main(int argc, char *argv[])
{
	cout << "\n================= VASL Model Optimize ===============\n";
//	VObject::listOfClasses = new vector<VClass *>();
	VASLModelOptimizeTest test(argc, argv);
  test.Initialization();
  test.Run();
  test.Exit();
  
	return 0;
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
  VASLModelOptimizeTest *test = (VASLModelOptimizeTest *) level1;

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



int T(ReactionSystemBase* sys)
{
  InstanceSystem* system = (InstanceSystem *) sys;

// SetOfObjects
//  BaseDataObject *baseObj = new BaseDataObject();
//  BaseDataObject *baseObj2 = new BaseDataObject();
//  BaseDataObject *baseObj3 = new BaseDataObject();
//  DataObjectClass *baseObj = new DataObjectClass(1, "Name1", "D1");
  DataObjectClass *baseObj2 = new DataObjectClass(2, "Name2", "D2");
  DataObjectClass *baseObj3 = new DataObjectClass(3, "Name3", "D3");
//  baseObj->NameTag = "Name1";
//  baseObj2->NameTag = "Name2";
//  baseObj3->NameTag = "Name1";
//  BaseDataSetOfObjects sObj;
//  BaseDataObject *sObj = new BaseDataObject();
  BaseDataSetOfObjects *sObj = new BaseDataSetOfObjects();
//  ObjectNameClassPairs *sObj = new ObjectNameClassPairs();
//  DataSetOfObjectsClass *sObj = new DataSetOfObjectsClass();
//  String *sObj = new String("Str");
  DataNumericClass *baseObj = new DataNumericClass();
  
//  sObj->AddObject("Str0", "Str1");
  sObj->AddObject(baseObj2);
  sObj->AddObject(baseObj3);
//  sObj->AddObjectClass(*baseObj);
//  sObj->AddObjectClass(*baseObj2);
//  sObj->AddObjectClass(*baseObj3);
  delete baseObj;
  delete baseObj2;
  delete baseObj3;

  CommBuffer buffer(COMM_BUFF_ENCODE,200000,2000);
  sObj->EncodeThis(buffer);
cout << "And now print:" << endl;
  sObj->print(cout);
//cout << "---" << endl;
//  ido->print(cout);
cout << "\nEnd Info" << endl;  

  BaseDataSetOfObjects *sObj2 = new BaseDataSetOfObjects();
  CommBuffer buffer1(buffer.GetBuffer(), buffer.GetBufferSize());

  sObj2->DecodeThis(buffer1);
cout << "2 And now print:" << endl;
  sObj2->print(cout);
//cout << "---" << endl;
//  ido->print(cout);
cout << "\nEnd Info" << endl;  
  
  
//  SearchableListOfMixedObjects<Identify,Identify> sObj;
//  Identify id1(baseObj.Identification,0);
//  bool added = sObj.AddObject(id1,&baseObj,baseObj.EncodeDecodeClass);
  
  Identify id(baseObj->Identification,0);
  
//  SearchableObjectListFull< Identify, PntrMixed< Identify, Identify > > sObj;
//  PntrMixed<Identify,Identify> *ido = new PntrMixed<Identify,Identify>(id,&baseObj,baseObj.EncodeDecodeClass);
//  bool result = sObj.AddObject(id,*ido);
//  delete ido;

//  SearchableObjectListFull< Identify, PntrMixed< Identify, Identify > > sObj;
//  pair< map< Identify , PntrMixed< Identify, Identify > , less<Identify> >::iterator, bool> p;
//  pair< const Identify, PntrMixed< Identify, Identify > > *p1 = new pair< const Identify, PntrMixed< Identify, Identify > >(id,*ido);
//  p = sObj.insert( *p1 );
//  if(p.second == false)
//    cout << "AddObject failed\n";
//cout << "And now print:" << endl;
//  sObj->print(cout);
////cout << "---" << endl;
////  ido->print(cout);
//cout << "End Info" << endl;  



//  InstanceSystem* system = (InstanceSystem *) sys;
//
//  CommBuffer buffer(COMM_BUFF_ENCODE,200000,2000);
//cout << "before ICLP " << endl;
//system->InstanceClasses.print(cout);
//  system->InstanceClasses.EncodeThis(buffer);
//  
//  DataSetOfInstancesClass cls;
//cout << "before decode " << endl;
//  cls.DecodeThis(buffer);
//  
//  cls.print(cout);
  
  return 0;
}

/*F ans = TransferAttributes(system)
**
**  DESCRIPTION
**    system: The system structure
**    ans: Zero if successful
**
**  REMARKS
**
*/
int TransferAttributes(ReactionSystemBase* sys)
{
  InstanceSystem* system = (InstanceSystem *) sys;
  
  int result = SYSTEM_NORMAL_RETURN;
  BaseDataSetOfInstances instances = system->Instances;
  cout << "Number of Inputs: " << system->Inputs.size() << endl;
  while(system->Inputs.size() > 1)
    {
      String source = system->GetNextInput();
      String destination = system->GetNextInput();
      cout << "Transfer: '" << source << "' to  '" << destination << "'" << endl;
      if(system->Instances.IsInList(source))
	{
	  BaseDataObject *obj = system->Instances.GetObject(source);
	  obj->NameTag = destination;
	  system->Instances.AddObject(obj);
	}
      else
	{
	  cerr << "Source Attribute Not found: '" << source << "'" << endl;
	  result = SYSTEM_ERROR_RETURN;
	}
    }
  return result;
}
