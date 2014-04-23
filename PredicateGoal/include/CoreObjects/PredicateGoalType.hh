/*  FILE     PredicateGoalType.hh
**  PACKAGE  PredicateGoal
**  AUTHOR   Edward S. Blurock
**
**  CONTENT
**    Class definitions for the "PredicateGoal" package.
**
**  OVERVIEW
**
**  IMPLEMENTATION
**
**  REFERENCES
**
**  COPYRIGHT (C) 1996 CoreObjects Project, RISC Linz
*/
 
#ifndef CoreObjects_PREDICATEGOALTYPE_HH
#define CoreObjects_PREDICATEGOALTYPE_HH

/*I  . . . INCLUDES  . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/
class BaseDataVariableEnvironment;
class BaseDataGoalPredicate;

/*C BaseDataSingleVariable  . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    SingleVariable contains the information defining a variable/constant
**    - Name: The name of the variable
**    - ClassName: The class (type) of the variable
**    - Level: The define level (in recursion) of the variable
**    - VConstant: whether it is a constant or not
**
**
**  REMARKS
**    Inheirits BaseDataObject
*/
class BaseDataSingleVariable : public BaseDataObject
{
  String VariableName;
  String ClassName;
  unsigned int Level;
  bool VConstant;

public:
  BaseDataSingleVariable();
  BaseDataSingleVariable(const BaseDataSingleVariable& data);
  BaseDataSingleVariable(const String name,
			 const String predname,
			 const String classname,
			 const unsigned int level,
			 const bool vconstant);

  String getClassName() const; 
  String getVariableName() const;
  unsigned int getLevel() const;
  void setClassName(String name);
  void setVariableName(String name);
  void setLevel(unsigned int level);

  bool operator==(const BaseDataSingleVariable &var);
  bool theSame(const String& var, const String& classname, 
	       const unsigned int level, const bool c);
  bool isConstant() const;
  void setAsConstant();
  void setAsVariable();

  BaseDataVariableEnvironment *Unify(BaseDataSingleVariable *var,
				     BaseDataVariableEnvironment *env,
				     unsigned int level);

  STANDARD_VIRTUAL_METHODS_OBJECT
};
/*C DataSingleVariableClass . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
**     Inheirits DataObjectClass
*/
class DataSingleVariableClass : public DataObjectClass
{
public:
  DataSingleVariableClass();
  DataSingleVariableClass(const DataSingleVariableClass& data);
  DataSingleVariableClass(const int id, 
		    const String& name,
		    const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS
};
/*C BaseDataVariableAssignment  . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    This is the VariableAssignment class definitions
**
**  REMARKS
**    Inheirits BaseDataSingleVariable
*/
class BaseDataVariableAssignment : public BaseDataSingleVariable
{
  BaseDataSingleVariable Assignment;

public:
  BaseDataVariableAssignment();
  BaseDataVariableAssignment(const BaseDataVariableAssignment& data);
  BaseDataVariableAssignment(const BaseDataSingleVariable& var,
			     const BaseDataSingleVariable& assign);
  BaseDataSingleVariable* getVariable();
  BaseDataSingleVariable* getAssignment();
  void setVariable(const BaseDataSingleVariable& var);
  void setAssignment(const BaseDataSingleVariable& ass);
  bool operator==(BaseDataVariableAssignment& assign);

  STANDARD_VIRTUAL_METHODS_OBJECT
};
/*C DataVariableAssignmentClass . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
**     Inheirits DataSingleVariableClass
*/
class DataVariableAssignmentClass : public DataSingleVariableClass
{
public:
  DataVariableAssignmentClass();
  DataVariableAssignmentClass(const DataVariableAssignmentClass& data);
  DataVariableAssignmentClass(const int id, 
		    const String& name,
		    const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS
};

/*C BaseDataVariableEnvironment  . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    This class holds the current variable assignment environment.
      A set of variable assignments are kept and accessed.
**
**  REMARKS
**    Inheirits BaseDataObject
*/
class BaseDataVariableEnvironment : public BaseDataObject
{
  BaseDataSetOfObjects Assignments;
  
public:
  BaseDataVariableEnvironment();
  BaseDataVariableEnvironment(const BaseDataVariableEnvironment& data);

  bool addVariableAssignment(BaseDataSingleVariable& var, 
			     BaseDataSingleVariable& assign);
  bool addVariableAssignment(BaseDataVariableAssignment& assign);
  bool isAssigned(BaseDataSingleVariable& var);
  BaseDataSingleVariable *getImmediateAssignment(BaseDataSingleVariable& var);
  BaseDataSingleVariable *getAssignment(BaseDataSingleVariable& var);
  bool Conflict(BaseDataVariableAssignment& assign);
  bool operator==(BaseDataGoalPredicate& pred);  
  bool operator<(BaseDataGoalPredicate& pred);  

  STANDARD_VIRTUAL_METHODS_OBJECT
};
/*C DataVariableEnvironmentClass . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
**     Inheirits DataObjectClass
*/
class DataVariableEnvironmentClass : public DataObjectClass
{
  DataSetOfObjectsClass *Classes;

public:
  DataVariableEnvironmentClass();
  DataVariableEnvironmentClass(const DataVariableEnvironmentClass& data);
  DataVariableEnvironmentClass(const int id, 
		    const String& name,
		    const String& descr);

  DataSetOfObjectsClass *getStandard();

  STANDARD_VIRTUAL_METHODS_CLASS
};
/*C BaseDataGoalPredicate  . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    This is the GoalPredicate class definitions
**
**  REMARKS
**    Inheirits BaseDataGoalSpec
*/
class BaseDataGoalPredicate : public BaseDataGoalSpec
{
  String PredicateName;
  bool PConstant;

public:
  BaseDataGoalPredicate();
  BaseDataGoalPredicate(const BaseDataGoalPredicate& data);
  bool operator==(BaseDataGoalPredicate& pred);
  bool operator<(BaseDataGoalPredicate& pred);

  bool Unifiable(BaseDataGoalPredicate *pred);
  BaseDataVariableEnvironment *Unify(BaseDataGoalPredicate *fact,
				     BaseDataVariableEnvironment *env,
				     unsigned int level);
  String getPredicateName() const;
  void setPredicateName(String name);

  bool isFact() const;
  void setAsFact();
  void setAsRule();

  STANDARD_VIRTUAL_METHODS_OBJECT
};
/*C DataGoalPredicateClass . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
**     Inheirits DataGoalSpecClass
*/
class DataGoalPredicateClass : public DataGoalSpecClass
{
public:
  DataGoalPredicateClass();
  DataGoalPredicateClass(const DataGoalPredicateClass& data);
  DataGoalPredicateClass(const int id, 
		    const String& name,
		    const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS
};
/*C BaseDataSetOfGoalPredicates  . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    This is the SetOfGoalPredicates class definitions
**
**  REMARKS
**    Inheirits BaseDataObject
*/
class BaseDataSetOfGoalPredicates : public BaseDataObject
{
  ObjectList<String> GoalPredicateNames;
  BaseDataSetOfObjects GoalPredicates;

public:
  BaseDataSetOfGoalPredicates();
  BaseDataSetOfGoalPredicates(const BaseDataSetOfGoalPredicates& data);

  BaseDataGoalPredicate *popPredicate();
  bool notEmpty();
  bool addGoalPredicateToFront(BaseDataGoalPredicate *pred);
  ObjectList<String> getGoalPredicateNames();
  STANDARD_VIRTUAL_METHODS_OBJECT
};
/*C DataSetOfGoalPredicatesClass . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
**     Inheirits DataObjectClass
*/
class DataSetOfGoalPredicatesClass : public DataObjectClass
{
  DataSetOfObjectsClass *Classes;
public:
  DataSetOfGoalPredicatesClass();
  DataSetOfGoalPredicatesClass(const DataSetOfGoalPredicatesClass& data);
  DataSetOfGoalPredicatesClass(const int id, 
		    const String& name,
		    const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS
  DataSetOfObjectsClass *getStandard();
};
/*C BaseDataFactPredicateEnvironment  . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    This is the FactPredicateEnvironment class definitions
**
**  REMARKS
**    Inheirits BaseDataObject
*/
class BaseDataFactPredicateEnvironment : public BaseDataObject
{
  ObjectList<String> FactList;
public:
  BaseDataFactPredicateEnvironment();
  BaseDataFactPredicateEnvironment(const BaseDataFactPredicateEnvironment& data);

  bool moreFacts();
  String popNextFact();
  void InitializeFacts(BaseDataSetOfGoalPredicates& facts);

  STANDARD_VIRTUAL_METHODS_OBJECT
};
/*C DataFactPredicateEnvironmentClass . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
**     Inheirits DataObjectClass
*/
class DataFactPredicateEnvironmentClass : public DataObjectClass
{
public:
  DataFactPredicateEnvironmentClass();
  DataFactPredicateEnvironmentClass(const DataFactPredicateEnvironmentClass& data);
  DataFactPredicateEnvironmentClass(const int id, 
		    const String& name,
		    const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS
};
/*C BaseDataGoalPredicateEnvironment  . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    This is the GoalPredicateEnvironment class definitions
**
**  REMARKS
**    Inheirits BaseDataSetOfGoalPredicates
*/
class BaseDataGoalPredicateEnvironment : public BaseDataSetOfGoalPredicates
{
public:
  BaseDataGoalPredicateEnvironment();
  BaseDataGoalPredicateEnvironment(const BaseDataGoalPredicateEnvironment& data);

  STANDARD_VIRTUAL_METHODS_OBJECT
};
/*C DataGoalPredicateEnvironmentClass . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
**     Inheirits DataSetOfGoalPredicatesClass
*/
class DataGoalPredicateEnvironmentClass : public DataSetOfGoalPredicatesClass
{
public:
  DataGoalPredicateEnvironmentClass();
  DataGoalPredicateEnvironmentClass(const DataGoalPredicateEnvironmentClass& data);
  DataGoalPredicateEnvironmentClass(const int id, 
		    const String& name,
		    const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS
};
/*C BaseDataCurrentEnvironment  . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    This is the CurrentEnvironment class definitions
**
**  REMARKS
**    Inheirits BaseDataObject
*/
class BaseDataCurrentEnvironment : public BaseDataObject
{
  BaseDataVariableEnvironment VarEnv;
  BaseDataGoalPredicateEnvironment Goals;
  BaseDataFactPredicateEnvironment Facts;

public:
  BaseDataCurrentEnvironment();
  BaseDataCurrentEnvironment(const BaseDataCurrentEnvironment& data);
  BaseDataCurrentEnvironment(const BaseDataFactPredicateEnvironment& facts,
			     BaseDataGoalPredicate *goal);
  BaseDataCurrentEnvironment(const BaseDataFactPredicateEnvironment& facts,
			     const BaseDataGoalPredicateEnvironment& goals);
  
  BaseDataVariableEnvironment *getVariableEnvironment();
  BaseDataGoalPredicate *popGoal();
  String popFactName();
  
  STANDARD_VIRTUAL_METHODS_OBJECT
};
/*C DataCurrentEnvironmentClass . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
**     Inheirits DataObjectClass
*/
class DataCurrentEnvironmentClass : public DataObjectClass
{
  DataVariableEnvironmentClass VarEnvClass;
  DataGoalPredicateEnvironmentClass GoalEnvClass;
  DataFactPredicateEnvironmentClass FactEnvClass;

public:
  DataCurrentEnvironmentClass();
  DataCurrentEnvironmentClass(const DataCurrentEnvironmentClass& data);
  DataCurrentEnvironmentClass(const int id, 
		    const String& name,
		    const String& descr);

  DataVariableEnvironmentClass *getVarEnvClass();
  DataGoalPredicateEnvironmentClass *getGoalEnvClass();
  DataFactPredicateEnvironmentClass *getFactEnvClass();

  
  STANDARD_VIRTUAL_METHODS_CLASS
};
/*C BaseDataTopLevelEnvironment  . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    This is the TopLevelEnvironment class definitions
**
**  REMARKS
**    Inheirits BaseDataObject
*/
class BaseDataTopLevelEnvironment : public BaseDataObject
{
  BaseDataSetOfGoalPredicates Facts;
public:
  BaseDataTopLevelEnvironment();
  BaseDataTopLevelEnvironment(const BaseDataTopLevelEnvironment& data);

  STANDARD_VIRTUAL_METHODS_OBJECT
};
/*C DataTopLevelEnvironmentClass . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
**     Inheirits DataObjectClass
*/
class DataTopLevelEnvironmentClass : public DataObjectClass
{
  DataSetOfGoalPredicatesClass FactClasses;
public:
  DataTopLevelEnvironmentClass();
  DataTopLevelEnvironmentClass(const DataTopLevelEnvironmentClass& data);
  DataTopLevelEnvironmentClass(const int id, 
		    const String& name,
		    const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS

  DataFactPredicateEnvironmentClass *getFactClass();
};

#endif
