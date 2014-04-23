/*  FILE     DeFuzzyType.hh
**  PACKAGE  DeFuzzy
**  AUTHOR   SCCH
**
**  CONTENT
**    Class definitions for the "DeFuzzy" package.
**
**  OVERVIEW
**
**  IMPLEMENTATION
**
**  REFERENCES
**
**  COPYRIGHT (C) 1996 CoreObjects Project, RISC Linz
*/
 
#ifndef CoreObjects_DEFUZZYTYPE_HH
#define CoreObjects_DEFUZZYTYPE_HH

//class BaseDataSetOfRules;
//class BaseDataActionRule;
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
#include "RuleSystem.hh"




/*C BaseDataEvaluatedRuleSystem  . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    This is the EvaluatedRuleSystem class definitions
**
**  REMARKS
**    Inheirits BaseDataParameterSet
*/
class BaseDataEvaluatedRuleSystem : public BaseDataParameterSet
{
public:
  BaseDataEvaluatedRuleSystem();
  BaseDataEvaluatedRuleSystem(const BaseDataEvaluatedRuleSystem& data);

  STANDARD_VIRTUAL_METHODS_OBJECT
};
/*C DataEvaluatedRuleSystemClass . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
**     Inheirits DataParameterSetClass
*/
class DataEvaluatedRuleSystemClass : public DataParameterSetClass
{
public:
  DataEvaluatedRuleSystemClass();
  DataEvaluatedRuleSystemClass(const DataEvaluatedRuleSystemClass& data);
  DataEvaluatedRuleSystemClass(const int id, 
		    const String& name,
		    const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS
};




/*C BaseDataConditionValuePair  . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    This is the ConditionValuePair class definitions
**
**  REMARKS
**    Inheirits BaseDataObject
*/
class BaseDataConditionValuePair : public BaseDataObject
{
public:
  BaseDataLogical *Logical;
  BaseDataObject *Object;

  BaseDataConditionValuePair();
  BaseDataConditionValuePair(const BaseDataConditionValuePair& data);
  BaseDataConditionValuePair(BaseDataLogical *logical,
			     BaseDataObject *object);
  ~BaseDataConditionValuePair();

  void setLogical(BaseDataLogical *logical);
  void setObject(BaseDataObject *object);

  STANDARD_VIRTUAL_METHODS_OBJECT
};
/*C DataConditionValuePairClass . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
**     Inheirits DataObjectClass
*/
class DataConditionValuePairClass : public DataObjectClass
{
  DataLogicalClass *LogicalClass;
  DataObjectClass *ObjectClass;

public:
  DataConditionValuePairClass();
  DataConditionValuePairClass(const DataConditionValuePairClass& data);
  DataConditionValuePairClass(const int id, 
		    const String& name,
		    const String& descr);
  
  DataLogicalClass *getLogicalClass();
  DataObjectClass *getObjectClass();

  STANDARD_VIRTUAL_METHODS_CLASS
};





/*C BaseDataEvaluateRuleSystem  . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    This is the EvaluateRuleSystem class definitions
**
**  REMARKS
**    Inheirits BaseDataOperation
*/
class BaseDataEvaluateRuleSystem : public BaseDataOperation
{
public:
  BaseDataEvaluateRuleSystem();
  BaseDataEvaluateRuleSystem(const BaseDataEvaluateRuleSystem& data);

  BaseDataEvaluatedRuleSystem *EvaluateRules(BaseDataSetOfRules *rules,
					     BaseDataParameterSet *set,
					     DataParameterSetClass *setclass); 
  BaseDataConditionValuePair *CreateConditionValuePair(BaseDataActionRule *rule,
						       DataActionRuleClass *rulecls,
						       BaseDataInstance *instance,
						       DataInstanceClass *instcls,
						       BaseDataParameterSet *set,
						       DataParameterSetClass *setclass);

  STANDARD_VIRTUAL_METHODS_OBJECT;
  STANDARD_VIRTUAL_OPERATION_METHODS;
  BaseDataParameterSet *BaseDataEvaluateRuleSystem::TranslateOrderedParameterSet(BaseDataActionRule *rule, 
										 BaseDataParameterSet *objects,
										 DataParameterSetClass *setclass);
};
/*C DataEvaluateRuleSystemClass . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
**     Inheirits DataOperationClass
*/
class DataEvaluateRuleSystemClass : public DataOperationClass
{
public:
  DataEvaluateRuleSystemClass();
  DataEvaluateRuleSystemClass(const DataEvaluateRuleSystemClass& data);
  DataEvaluateRuleSystemClass(const int id, 
		    const String& name,
		    const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS
};

class BaseDataCombineScaledDefuzzify : public BaseDataOperation
    {
    public:
      BaseDataOperation  *CombineOp;  
      BaseDataOperation  *CoerceOp;  
      BaseDataOperation  *ScaleOp;  
      
      BaseDataCombineScaledDefuzzify();
      BaseDataCombineScaledDefuzzify(const BaseDataCombineScaledDefuzzify& data);
      ~BaseDataCombineScaledDefuzzify();
      
      virtual void Initialization();
      virtual ostream& print(ostream& out) const;
      virtual void CopyClone(Identify *obj);
      virtual Identify *Clone();
      virtual bool EncodeThis(CommBuffer& buffer);
      virtual bool DecodeThis(CommBuffer& buffer);
      
      virtual bool Read(istream& in, DataObjectClass* objc);
      virtual bool Write(ostream& out, DataObjectClass* objc);
      virtual bool Read(istream& in, DataObjectClass *objc, const String& name);
      BaseDataObject *GetObjectCombineOp();
      BaseDataObject *GetObjectCoerceOp();
      BaseDataObject *GetObjectScaleOp();     
      STANDARD_VIRTUAL_OPERATION_METHODS;
    };
class DataCombineScaledDefuzzifyClass : public DataOperationClass
    {
       public:
        DataOperationClass  *CombineOpClass;  
        DataOperationClass  *CoerceOpClass;  
        DataOperationClass  *ScaleOpClass;  

        DataCombineScaledDefuzzifyClass();
        DataCombineScaledDefuzzifyClass(const DataCombineScaledDefuzzifyClass& data);
        DataCombineScaledDefuzzifyClass(const int id, const String& name, const String& descr);
        ~DataCombineScaledDefuzzifyClass();

        virtual void Initialization();
        virtual ostream& print(ostream& out) const;
        virtual void CopyClone(Identify *obj);
        virtual Identify *Clone();
        virtual bool EncodeThis(CommBuffer& buffer);
        virtual bool DecodeThis(CommBuffer& buffer);

        virtual bool Read(istream& in, DataSetOfObjectsClass& set);
        virtual bool Write(ostream& out, DataSetOfObjectsClass& set);
        virtual BaseDataObject *BaseDataObjectExample();
        DataObjectClass *GetClassCombineOpClass();
        DataObjectClass *GetClassCoerceOpClass();
        DataObjectClass *GetClassScaleOpClass();
    };






#endif
