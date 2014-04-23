/*  FILE     DeFuzzy.cc
**  PACKAGE  DeFuzzy
**  AUTHOR   SCCH
**
**  CONTENT
**    Exported functions for the "DeFuzzy" package.
**
**  REFERENCES
**
**  COPYRIGHT (C) 1997 Edward S. Blurock
*/

 
/*I  . . . INCLUDES  . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/
#include "CoreDataObjects.hh"
#include "NumericObjects.hh"
#include "LogicalObjects.hh"
#include "FunctionReal1DObjects.hh"
#include "OperationObjects.hh"

#include "DeFuzzy.hh"

/*S BaseDataEvaluateRuleSystem
 */ 
/*F BaseDataEvaluateRuleSystem()  . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataEvaluateRuleSystem::BaseDataEvaluateRuleSystem()
{
  Identification = DEFUZZY_EVALUATERULESYSTEM_ID;
  NameTag = DEFUZZY_EVALUATERULESYSTEM_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;
} 
/*F BaseDataEvaluateRuleSystem(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataEvaluateRuleSystem::BaseDataEvaluateRuleSystem(const BaseDataEvaluateRuleSystem& data)
  : BaseDataOperation(data)
{
}
/*F Read(in,objc) . . . . . . . . . . . . . . . . . .  Read in BaseDataEvaluateRuleSystem
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataEvaluateRuleSystem::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . . . . . . . .  Read in BaseDataEvaluateRuleSystem
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataEvaluateRuleSystem::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = BaseDataOperation::Read(in,objc,name);
  
  return result;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . .  BaseDataEvaluateRuleSystem
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataEvaluateRuleSystem::print(ostream& out) const
{
  BaseDataOperation::print(out);
  //PointerPrint(out,"The List of Parameters: ","No Parameters",Parameters);
  // The rest

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . . . . .BaseDataEvaluateRuleSystem
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataEvaluateRuleSystem::Clone()
{
  BaseDataEvaluateRuleSystem *obj = new BaseDataEvaluateRuleSystem(*this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . . . . .BaseDataEvaluateRuleSystem
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataEvaluateRuleSystem::CopyClone(Identify * obj)
{
  BaseDataEvaluateRuleSystem *objfull = (BaseDataEvaluateRuleSystem *) obj;
  *this = *objfull;
  //Parameter = (BaseData... *) PointerClone(objfull->Parameter)
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataEvaluateRuleSystem
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataEvaluateRuleSystem::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataOperation::EncodeThis(buffer);
  //result = result && ---.EncodeThis(buffer);
  //result = result && Encode(buffer,---);
  //result = result && PointerEncode(buffer,Parameters);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataEvaluateRuleSystem
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataEvaluateRuleSystem::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataOperation::DecodeThis(buffer);
  // The rest

  return result;
}
 
 
/*S DataEvaluateRuleSystemClass
 */
/*F DataEvaluateRuleSystemClass() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataEvaluateRuleSystemClass::DataEvaluateRuleSystemClass()
{
  Identification = DEFUZZY_EVALUATERULESYSTEM_ID;
  NameTag = DEFUZZY_EVALUATERULESYSTEM_NAME;
  SubClass = "Operation";
  EncodeDecodeClass = NameTag;
} 
/*F DataEvaluateRuleSystemClass(data) . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataEvaluateRuleSystemClass::DataEvaluateRuleSystemClass(const DataEvaluateRuleSystemClass& data)
  : DataOperationClass(data)
{
} 
 
/*F DataEvaluateRuleSystemClass(id,name,descr)  . . . . . . . . . . . . . . . constructor
**
**  DESCRIPTION
**    id: The ID of the object class
**    name: The name of the object class
**    descr: A text description of the object
**
**
**  REMARKS
**
*/
DataEvaluateRuleSystemClass::DataEvaluateRuleSystemClass(const int id, 
				 const String& name,
				 const String& descr)
  : DataOperationClass(id,name,descr)
{
  SubClass = "Operation";
  EncodeDecodeClass = "EvaluateRuleSystem";
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . . DataEvaluateRuleSystemClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataEvaluateRuleSystemClass::print(ostream& out) const
{
  DataOperationClass::print(out);
  //PointerPrint(out,"  The Class: "," No Class Defined ",Class);
  // the rest
       
       return out;
}
 
/*F in1 = Read(in)  . . . . . . . . . . . . . . . . . . . . . DataEvaluateRuleSystemClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataEvaluateRuleSystemClass, there is no further information.
**
**  REMARKS
**
*/
bool DataEvaluateRuleSystemClass::Read(istream& in, DataSetOfObjectsClass &set)
{
  bool result = DataOperationClass::Read(in,set);
  //result = result && PointerClassRead(in,(DataObjectClass *&) Class,
  //COREOBJECTS_BASE_NAME,
  //set," No Class ");
  return result;
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . . . DataEvaluateRuleSystemClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataEvaluateRuleSystemClass::CopyClone(Identify *  objc)
{
  DataEvaluateRuleSystemClass *objcfull = (DataEvaluateRuleSystemClass *) objc;
  *this = *objcfull;
  //ParameterClass = (DataSetOfObjectsClass *) PointerClone(objcfull->ParameterClass);
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . . . DataEvaluateRuleSystemClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataEvaluateRuleSystemClass::Clone()
    {
      DataEvaluateRuleSystemClass* id = new DataEvaluateRuleSystemClass(*this);
      return (Identify *) id;
    }
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . . DataEvaluateRuleSystemClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataEvaluateRuleSystemClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataOperationClass::EncodeThis(buffer);
  //result = result && PointerEncode(buffer,Class);
  // result = result && Encode(buffer,------);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . . DataEvaluateRuleSystemClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataEvaluateRuleSystemClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataOperationClass::DecodeThis(buffer);
  //result = result && PointerDecode(buffer,(BaseDataObject *&) Class);
  //result = result && Decode(buffer,-----);

  return result;
}
/*F obj = BaseDataObjectExample() . . . . . . . . . . . . .  create an object
**
**  DESCRIPTION
**    obj: The created object
**
**    This function is used to create an empty instance of a object 
**    given the class.  This is used so that the virtual functions
**    of the object can be used.
**
**  REMARKS
**
*/
BaseDataObject * DataEvaluateRuleSystemClass::BaseDataObjectExample()
{ 
  BaseDataObject *obj = new BaseDataEvaluateRuleSystem();
  obj->SetType(Identification);
  return obj;
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . DataEvaluateRuleSystemClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataEvaluateRuleSystemClass*& obj)
     {
     obj = new DataEvaluateRuleSystemClass;
     return obj->DecodeThis(buffer);
     }
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . BaseDataEvaluateRuleSystem
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataEvaluateRuleSystem*& obj)
     {
     obj = new BaseDataEvaluateRuleSystem;
     return obj->DecodeThis(buffer);
     }
//EncodeDecodeRegisterClass(DataEvaluateRuleSystemClass,BaseDataEvaluateRuleSystem,_NAME);
//String descr("The Class");
//DataEvaluateRuleSystemClass class(_ID,_NAME,descr);
//set.AddObjectClass(class);



/*F obj = operator()(x,y,xclass,yclass) . . . . . . . . . . BaseDataEvaluateRuleSystem
**
**  DESCRIPTION
**    x,y: The objects to be operated on
**    xclass,yclass: The object classes
**    obj: The result
**
**    This is a two-dimensional call.  An object is created.
**
**  REMARKS
**
*/
BaseDataObject *BaseDataEvaluateRuleSystem::operator()(BaseDataObject *x, BaseDataObject *y,
					     DataObjectClass *xc, DataObjectClass *yc)
{
  BaseDataSetOfRules *rules = (BaseDataSetOfRules *) x; 
  BaseDataParameterSet *set = (BaseDataParameterSet *) y;
  DataParameterSetClass *setcls = (DataParameterSetClass *) yc;

  cout << "BaseDataEvaluateRuleSystem::operator()   The Parameter Set" << endl;
  set->print(cout);
  cout << endl;

  cout << "EvaluateRules(rules, set, setcls);" << endl;
  rules->print(cout);
  return EvaluateRules(rules, set, setcls);
}
/*F obj = operator()(x,xclass)  . . . . . . . . . . . . . . BaseDataEvaluateRuleSystem
**
**  DESCRIPTION
**    x: The object to be operated on
**    xclass: The class of the object
**    obj: The result
**
**    This is a one-dimensional call.  An object is created.
**
**  REMARKS
**
*/
BaseDataObject *BaseDataEvaluateRuleSystem::operator()(BaseDataObject *x,
					     DataObjectClass *xc)
{
  cout << x->NameTag << " " << x->GetType() << endl;
  return (BaseDataObject *) x->Clone();
}
/*F obj = operator()(cls,x,y,xclass,yclass) . . . . . . . . . . BaseDataEvaluateRuleSystem
**
**  DESCRIPTION
**    x,y: The objects to be operated on
**    xclass,yclass: The object classes
**    obj: The result
**
**    This is a two-dimensional call.  An object is created.
**    The cls is used (among other things) to check the input types
**
**  REMARKS
**
*/
BaseDataObject *BaseDataEvaluateRuleSystem::operator()(DataObjectClass *cls,
						       BaseDataObject *x, BaseDataObject *y,
						       DataObjectClass *xc, DataObjectClass *yc)
                                              
{
  return operator()(x, y, xc, yc);
}
/*F EvaluateRule()  . . . . . . . . . . . . . . BaseDataEvaluateRuleSystem
**
**  DESCRIPTION
**
**  REMARKS
**
*/
BaseDataEvaluatedRuleSystem *BaseDataEvaluateRuleSystem::EvaluateRules(BaseDataSetOfRules *rules,
								       BaseDataParameterSet *set,
								       DataParameterSetClass *setclass) 
{
  DataInstanceClass *instcls = (DataInstanceClass *)setclass->PointerToAllowedClasses()->GetObjectClass("Instance");
  BaseDataInstance *instance = (BaseDataInstance *)instcls->BaseDataObjectExample();
  BaseDataEvaluatedRuleSystem *ev = new BaseDataEvaluatedRuleSystem();

  ObjectList<String> rulenames = rules->OrderedListOfParameterNames();
  ObjectList<String>::iterator rulename;
  for(rulename = rulenames.begin(); rulename != rulenames.end() ; rulename++) 
    {
      cout << "Run Rule: '" << *rulename << "'" << endl;
    BaseDataActionRule *rule = (BaseDataActionRule *) rules->GetObject(*rulename);
    DataActionRuleClass *rulecls = (DataActionRuleClass *)setclass->PointerToAllowedClasses()->GetObjectClass(rule->GetType());

    BaseDataConditionValuePair *condValPair = CreateConditionValuePair(rule, rulecls,
								       instance, instcls,
								       set, setclass);
    ev->AddObject(condValPair);
  }
  return ev;
}
/*F ans = InsertOrderedParameterSet(objects) . . . .  set up parameters for function
**
**  DESCRIPTION
**    objects: The set of parameters
**    ans: true if successful
**
**  REMARKS
**
*/
BaseDataParameterSet *BaseDataEvaluateRuleSystem::TranslateOrderedParameterSet(BaseDataActionRule *rule, 
									       BaseDataParameterSet *objects,
									       DataParameterSetClass *setclass)
{
  bool result = true;
  bool addobject = true;
  addobject = false;
  BaseDataParameterSet *newset = (BaseDataParameterSet *) setclass->BaseDataObjectExample();
      ObjectList<String> objnames = objects->OrderedListOfParameterNames();
      ObjectList<String> names    = rule->getParameterSet()->OrderedListOfParameterNames();
      ObjectList<String>::iterator name;
      ObjectList<String>::iterator objname = objnames.begin();
      for(name = names.begin();name != names.end();name++)
	{
	  if(objname != objnames.end()) {
	    cout << "Parameter: '" << *objname << "' inserted as '" << *name << "'" << endl;
	  BaseDataObject *obj = objects->GetObject(*objname);
	  obj->NameTag = *name;
	  result = result && newset->AddObject(obj);
	  obj->NameTag = *objname;
	  objname++;
	  }
	}
  return newset;
}
/*F CreateConditionValuePair()  . . . . . . . . . . . . . . BaseDataEvaluateRuleSystem
**
**  DESCRIPTION
**
**  REMARKS
**
*/
BaseDataConditionValuePair *BaseDataEvaluateRuleSystem::CreateConditionValuePair(BaseDataActionRule *rule,
										 DataActionRuleClass *rulecls,
										 BaseDataInstance *instance,
										 DataInstanceClass *instcls,
										 BaseDataParameterSet *set,
										 DataParameterSetClass *setclass)
										 
{
  cout << "Insert Parameters" << endl;
  BaseDataParameterSet *newset = TranslateOrderedParameterSet(rule,set,setclass);
  cout << "Evaluate Condition" << endl;
  BaseDataLogical *logical = rule->EvaluateCondition(rulecls,newset,instance,setclass,instcls);
  cout << "Logical Value: " << endl;
  logical->print(cout);
  cout << endl;
  cout << "Evaluate Rules" << endl;
  rule->EvaluateAllActions(rulecls,newset,instance,setclass,instcls);
    
  BaseDataObject *cost;
  String costS("Cost");
  if(instance->IsInList(costS))
  {
    cout << "Cost" << endl;
    cost = (BaseDataObject *) instance->GetObject(costS)->Clone();
    cost->print(cout);
  }
  else
  {
    cost = new BaseDataReal();
    BaseDataReal *rcost = (BaseDataReal *) cost;
    rcost->SetValue(10000000.0);
    cout << "Fake Cost" << endl;
    cost->print(cout);
  }
  BaseDataConditionValuePair *condValPair = new BaseDataConditionValuePair(logical, cost);
  delete logical;
  delete cost;
  return condValPair;
}

/*F obj = operator()(cls,x,xclass)  . . . . . . . . . . . . . . BaseDataEvaluateRuleSystem
**
**  DESCRIPTION
**    cls: The class of the operation
**    x: The object to be operated on
**    xclass: The class of the object
**    obj: The result
**
**    This is a dummy one-dimensional call.  An empty object is created.
**
**  REMARKS
**
*/
BaseDataObject *BaseDataEvaluateRuleSystem::operator()(DataObjectClass *cls,
						  BaseDataObject *x,
						  DataObjectClass *xclass)
{
  /*
    DataSetOfObjectsClass *set = (BaseDataSetOfObjects *) cls->PointerToAllowedClasses();
    bool result = true;
    result = result && set->IsOfClass(xc,_NAME);
    result = result && (x->GetType() == xc->GetType());
  */
  return operator()(x,xclass);
}









/*S BaseDataConditionValuePair
 */ 
/*F BaseDataConditionValuePair()  . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataConditionValuePair::BaseDataConditionValuePair()
  : Logical(NULL),
    Object(NULL)
{
  Identification = DEFUZZY_CONDITIONVALUEPAIR_ID;
  NameTag = DEFUZZY_CONDITIONVALUEPAIR_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;
} 
/*F BaseDataConditionValuePair(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataConditionValuePair::BaseDataConditionValuePair(BaseDataLogical *logical,
						       BaseDataObject *object)
  : Logical(NULL),
    Object(NULL)
{
  Identification = DEFUZZY_CONDITIONVALUEPAIR_ID;
  NameTag = DEFUZZY_CONDITIONVALUEPAIR_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;

  Logical = (BaseDataLogical *) PointerClone(logical);
  Object = (BaseDataObject *) PointerClone(object);
  
}
/*F BaseDataConditionValuePair(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataConditionValuePair::BaseDataConditionValuePair(const BaseDataConditionValuePair& data)
  : BaseDataObject(data)
{
  Logical = (BaseDataLogical *) PointerClone(data.Logical);
  Object = (BaseDataObject *) PointerClone(data.Object);
}
/*F ~BaseDataConditionValuePair() . . . . . . . . . . . . . . . . . . . .  destructor
**
**  DESCRIPTION
**    
**  REMARKS
** 
*/
BaseDataConditionValuePair::~BaseDataConditionValuePair()
{
  if(Logical != NULL)
    delete Logical;
  if(Object != NULL)
    delete Object;
}
/*F Read(in,objc) . . . . . . . . . . . . . . . . . .  Read in BaseDataConditionValuePair
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataConditionValuePair::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . . . . . . . .  Read in BaseDataConditionValuePair
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataConditionValuePair::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = true;
  result = result && BaseDataObject::Read(in,objc,name);

  DataConditionValuePairClass *pairClass = (DataConditionValuePairClass *) objc;

  String logical("Logical:");
  result = result && CheckReadKeyWord(in,logical);
  String notdefinedl("Logical Not Defined");
  result = result && PointerObjectRead(in, (BaseDataObject *&) Logical,
                pairClass->getLogicalClass(),
		            notdefinedl);

  String objs("Object:");
  result = result && CheckReadKeyWord(in,objs);
  String notdefinedo("Object Not Defined");
  result = result && PointerObjectRead(in, (BaseDataObject *&) Object,
                pairClass->getObjectClass(),
		            notdefinedo);
  return result;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . .  BaseDataConditionValuePair
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataConditionValuePair::print(ostream& out) const
{
  BaseDataObject::print(out);
  
  PointerPrint(out,"The Logical: ","Logical Not Defined",Logical);
  PointerPrint(out,"The Object: ","Object Not Defined",Object);

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . . . . .BaseDataConditionValuePair
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataConditionValuePair::Clone()
{
  BaseDataConditionValuePair *obj = new BaseDataConditionValuePair(*this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . . . . .BaseDataConditionValuePair
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataConditionValuePair::CopyClone(Identify * obj)
{
  BaseDataConditionValuePair *objfull = (BaseDataConditionValuePair *) obj;
  *this = *objfull;
  //Parameter = (BaseData... *) PointerClone(objfull->Parameter)
  Logical = (BaseDataLogical *) PointerClone(objfull->Logical);
  Object = (BaseDataObject *) PointerClone(objfull->Object);
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataConditionValuePair
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataConditionValuePair::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataObject::EncodeThis(buffer);
  //result = result && ---.EncodeThis(buffer);
  //result = result && Encode(buffer,---);
  //result = result && PointerEncode(buffer,Parameters);
  result = result && PointerEncode(buffer,(BaseDataObject *&) Logical);
  result = result && PointerEncode(buffer,(BaseDataObject *&) Object);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataConditionValuePair
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataConditionValuePair::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataObject::DecodeThis(buffer);
  // The rest
  result = result && PointerDecode(buffer,(BaseDataObject *&) Logical);
  result = result && PointerDecode(buffer,(BaseDataObject *&) Object);

  return result;
}
/*F setLogical(Logical)  . . . . . . . . . . . . . . .  BaseDataConditionValuePair
**
**  DESCRIPTION
**    logical: The logical to be inserted
**
**  REMARKS
**
*/
void BaseDataConditionValuePair::setLogical(BaseDataLogical *logical)
{
  if (Logical != NULL)
    delete Logical;
  Logical = (BaseDataLogical *) PointerClone(logical);
}
/*F setObject(object)  . . . . . . . . . . . . . . .  BaseDataConditionValuePair
**
**  DESCRIPTION
**    object: The object to be inserted (no copy made)
**
**  REMARKS
**
*/
void BaseDataConditionValuePair::setObject(BaseDataObject *object)
{
  if(Object != NULL)
    delete Object;
  Object = (BaseDataObject *) PointerClone(object);
}
 
 
/*S DataConditionValuePairClass
 */
/*F DataConditionValuePairClass() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataConditionValuePairClass::DataConditionValuePairClass()
  : LogicalClass(NULL),
    ObjectClass(NULL)
{
  Identification = DEFUZZY_CONDITIONVALUEPAIR_ID;
  NameTag = DEFUZZY_CONDITIONVALUEPAIR_NAME;
  SubClass = "Object";
  EncodeDecodeClass = NameTag;
} 
/*F DataConditionValuePairClass(data) . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataConditionValuePairClass::DataConditionValuePairClass(const DataConditionValuePairClass& data)
  : DataObjectClass(data)
{
  LogicalClass = (DataLogicalClass *) PointerClone(data.LogicalClass);
  ObjectClass = (DataObjectClass *) PointerClone(data.ObjectClass);
} 
 
/*F DataConditionValuePairClass(id,name,descr)  . . . . . . . . . . . . . . . constructor
**
**  DESCRIPTION
**    id: The ID of the object class
**    name: The name of the object class
**    descr: A text description of the object
**
**
**  REMARKS
**
*/
DataConditionValuePairClass::DataConditionValuePairClass(const int id, 
				 const String& name,
				 const String& descr)
  : DataObjectClass(id,name,descr),
    LogicalClass(NULL),
    ObjectClass(NULL)
{
  SubClass = "Object";
  EncodeDecodeClass = "ConditionValuePair";
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . . DataConditionValuePairClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataConditionValuePairClass::print(ostream& out) const
{
  DataObjectClass::print(out);
  //PointerPrint(out,"  The Class: "," No Class Defined ",Class);
  // the rest
  out << endl;
  PointerPrint(out,"Logical Class:","No Logical Class defined",LogicalClass);       
  out << endl;
  PointerPrint(out,"Object Class:","No Object Class defined",ObjectClass);       
       
       return out;
}
 
/*F in1 = Read(in)  . . . . . . . . . . . . . . . . . . . . . DataConditionValuePairClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataConditionValuePairClass, there is no further information.
**
**  REMARKS
**
*/
bool DataConditionValuePairClass::Read(istream& in, DataSetOfObjectsClass &set)
{
  bool result = DataObjectClass::Read(in,set);
  String noClassL = "No Logical Class";   
  String noClassO = "No Object Class"; 
  result = result && PointerClassRead(in,(DataObjectClass *&) LogicalClass,
				      LOGICAL_BASE_NAME,
				      set,noClassL);
  result = result && PointerClassRead(in,(DataObjectClass *&) ObjectClass,
				      COREOBJECTS_BASE_NAME,
				      set,noClassO);
  return result;
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . . . DataConditionValuePairClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataConditionValuePairClass::CopyClone(Identify *  objc)
{
  DataConditionValuePairClass *objcfull = (DataConditionValuePairClass *) objc;
  *this = *objcfull;
  //ParameterClass = (DataSetOfObjectsClass *) PointerClone(objcfull->ParameterClass);
  LogicalClass = (DataLogicalClass *) PointerClone(objcfull->LogicalClass);
  ObjectClass = (DataObjectClass *) PointerClone(objcfull->ObjectClass);
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . . . DataConditionValuePairClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataConditionValuePairClass::Clone()
    {
      DataConditionValuePairClass* id = new DataConditionValuePairClass(*this);
      return (Identify *) id;
    }
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . . DataConditionValuePairClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataConditionValuePairClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataObjectClass::EncodeThis(buffer);
  //result = result && PointerEncode(buffer,Class);
  // result = result && Encode(buffer,------);
  result = result && PointerEncode(buffer,(BaseDataObject *&) LogicalClass);
  result = result && PointerEncode(buffer,(BaseDataObject *&) ObjectClass);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . . DataConditionValuePairClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataConditionValuePairClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataObjectClass::DecodeThis(buffer);
  //result = result && PointerDecode(buffer,(BaseDataObject *&) Class);
  //result = result && Decode(buffer,-----);
  result = result && PointerDecode(buffer,(BaseDataObject *&) LogicalClass);
  result = result && PointerDecode(buffer,(BaseDataObject *&) ObjectClass);

  return result;
}
/*F obj = BaseDataObjectExample() . . . . . . . . . . . . .  create an object
**
**  DESCRIPTION
**    obj: The created object
**
**    This function is used to create an empty instance of a object 
**    given the class.  This is used so that the virtual functions
**    of the object can be used.
**
**  REMARKS
**
*/
BaseDataObject * DataConditionValuePairClass::BaseDataObjectExample()
{ 
  BaseDataObject *obj = new BaseDataConditionValuePair();
  obj->SetType(Identification);
  return obj;
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . DataConditionValuePairClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataConditionValuePairClass*& obj)
     {
     obj = new DataConditionValuePairClass;
     return obj->DecodeThis(buffer);
     }
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . BaseDataConditionValuePair
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataConditionValuePair*& obj)
     {
     obj = new BaseDataConditionValuePair;
     return obj->DecodeThis(buffer);
     }
/*F logicalclass = getLogicalClass() . . . . . . . . . . . DataLogicalClass
**
**  DESCRIPTION
**    logicallass: The current logical class
**
**  REMARKS
**
*/
DataLogicalClass *DataConditionValuePairClass::getLogicalClass()
{
  return LogicalClass;
}
/*F objectclass = getObjectClass() . . . . . . . . . . . . . DataObjectClass
**
**  DESCRIPTION
**    objectclass: The object class
**
**  REMARKS
**
*/
DataObjectClass *DataConditionValuePairClass::getObjectClass()
{
  return ObjectClass;
}


//EncodeDecodeRegisterClass(DataConditionValuePairClass,BaseDataConditionValuePair,_NAME);
//String descr("The Class");
//DataConditionValuePairClass class(_ID,_NAME,descr);
//set.AddObjectClass(class);







/*S BaseDataEvaluatedRuleSystem
 */ 
/*F BaseDataEvaluatedRuleSystem()  . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataEvaluatedRuleSystem::BaseDataEvaluatedRuleSystem()
{
  Identification = DEFUZZY_EVALUATEDRULESYSTEM_ID;
  NameTag = DEFUZZY_EVALUATEDRULESYSTEM_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;
} 
/*F BaseDataEvaluatedRuleSystem(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataEvaluatedRuleSystem::BaseDataEvaluatedRuleSystem(const BaseDataEvaluatedRuleSystem& data)
  : BaseDataParameterSet(data)
{
}
/*F Read(in,objc) . . . . . . . . . . . . . . . . . .  Read in BaseDataEvaluatedRuleSystem
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataEvaluatedRuleSystem::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . . . . . . . .  Read in BaseDataEvaluatedRuleSystem
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataEvaluatedRuleSystem::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = BaseDataParameterSet::Read(in,objc,name);
  
  return result;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . .  BaseDataEvaluatedRuleSystem
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataEvaluatedRuleSystem::print(ostream& out) const
{
  BaseDataParameterSet::print(out);
  //PointerPrint(out,"The List of Parameters: ","No Parameters",Parameters);
  // The rest

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . . . . .BaseDataEvaluatedRuleSystem
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataEvaluatedRuleSystem::Clone()
{
  BaseDataEvaluatedRuleSystem *obj = new BaseDataEvaluatedRuleSystem(*this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . . . . .BaseDataEvaluatedRuleSystem
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataEvaluatedRuleSystem::CopyClone(Identify * obj)
{
  BaseDataEvaluatedRuleSystem *objfull = (BaseDataEvaluatedRuleSystem *) obj;
  *this = *objfull;
  //Parameter = (BaseData... *) PointerClone(objfull->Parameter)
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataEvaluatedRuleSystem
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataEvaluatedRuleSystem::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataParameterSet::EncodeThis(buffer);
  //result = result && ---.EncodeThis(buffer);
  //result = result && Encode(buffer,---);
  //result = result && PointerEncode(buffer,Parameters);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataEvaluatedRuleSystem
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataEvaluatedRuleSystem::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataParameterSet::DecodeThis(buffer);
  // The rest

  return result;
}
 
/*S DataEvaluatedRuleSystemClass
 */
/*F DataEvaluatedRuleSystemClass() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataEvaluatedRuleSystemClass::DataEvaluatedRuleSystemClass()
{
  Identification = DEFUZZY_EVALUATEDRULESYSTEM_ID;
  NameTag = DEFUZZY_EVALUATEDRULESYSTEM_NAME;
  SubClass = "ParameterSet";
  EncodeDecodeClass = NameTag;
} 
/*F DataEvaluatedRuleSystemClass(data) . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataEvaluatedRuleSystemClass::DataEvaluatedRuleSystemClass(const DataEvaluatedRuleSystemClass& data)
  : DataParameterSetClass(data)
{
} 
 
/*F DataEvaluatedRuleSystemClass(id,name,descr)  . . . . . . . . . . . . . . . constructor
**
**  DESCRIPTION
**    id: The ID of the object class
**    name: The name of the object class
**    descr: A text description of the object
**
**
**  REMARKS
**
*/
DataEvaluatedRuleSystemClass::DataEvaluatedRuleSystemClass(const int id, 
				 const String& name,
				 const String& descr)
  : DataParameterSetClass(id,name,descr)
{
  SubClass = "ParameterSet";
  EncodeDecodeClass = "EvaluatedRuleSystem";
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . . DataEvaluatedRuleSystemClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataEvaluatedRuleSystemClass::print(ostream& out) const
{
  DataParameterSetClass::print(out);
  //PointerPrint(out,"  The Class: "," No Class Defined ",Class);
  // the rest
       
       return out;
}
 
/*F in1 = Read(in)  . . . . . . . . . . . . . . . . . . . . . DataEvaluatedRuleSystemClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataEvaluatedRuleSystemClass, there is no further information.
**
**  REMARKS
**
*/
bool DataEvaluatedRuleSystemClass::Read(istream& in, DataSetOfObjectsClass &set)
{
  bool result = DataParameterSetClass::Read(in,set);
  //result = result && PointerClassRead(in,(DataObjectClass *&) Class,
  //COREOBJECTS_BASE_NAME,
  //set," No Class ");
  return result;
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . . . DataEvaluatedRuleSystemClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataEvaluatedRuleSystemClass::CopyClone(Identify *  objc)
{
  DataEvaluatedRuleSystemClass *objcfull = (DataEvaluatedRuleSystemClass *) objc;
  *this = *objcfull;
  //ParameterClass = (DataSetOfObjectsClass *) PointerClone(objcfull->ParameterClass);
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . . . DataEvaluatedRuleSystemClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataEvaluatedRuleSystemClass::Clone()
    {
      DataEvaluatedRuleSystemClass* id = new DataEvaluatedRuleSystemClass(*this);
      return (Identify *) id;
    }
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . . DataEvaluatedRuleSystemClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataEvaluatedRuleSystemClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataParameterSetClass::EncodeThis(buffer);
  //result = result && PointerEncode(buffer,Class);
  // result = result && Encode(buffer,------);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . . DataEvaluatedRuleSystemClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataEvaluatedRuleSystemClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataParameterSetClass::DecodeThis(buffer);
  //result = result && PointerDecode(buffer,(BaseDataObject *&) Class);
  //result = result && Decode(buffer,-----);

  return result;
}
/*F obj = BaseDataObjectExample() . . . . . . . . . . . . .  create an object
**
**  DESCRIPTION
**    obj: The created object
**
**    This function is used to create an empty instance of a object 
**    given the class.  This is used so that the virtual functions
**    of the object can be used.
**
**  REMARKS
**
*/
BaseDataObject * DataEvaluatedRuleSystemClass::BaseDataObjectExample()
{ 
  BaseDataObject *obj = new BaseDataEvaluatedRuleSystem();
  obj->SetType(Identification);
  return obj;
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . DataEvaluatedRuleSystemClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataEvaluatedRuleSystemClass*& obj)
     {
     obj = new DataEvaluatedRuleSystemClass;
     return obj->DecodeThis(buffer);
     }
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . BaseDataEvaluatedRuleSystem
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataEvaluatedRuleSystem*& obj)
     {
     obj = new BaseDataEvaluatedRuleSystem;
     return obj->DecodeThis(buffer);
     }
//EncodeDecodeRegisterClass(DataEvaluatedRuleSystemClass,BaseDataEvaluatedRuleSystem,_NAME);
//String descr("The Class");
//DataEvaluatedRuleSystemClass class(_ID,_NAME,descr);
//set.AddObjectClass(class);

/*S
 */
BaseDataCombineScaledDefuzzify::BaseDataCombineScaledDefuzzify()
     : BaseDataOperation(),
       CombineOp(NULL),
       CoerceOp(NULL),
       ScaleOp(NULL)
{
       Identification = DeFuzzy_CombineScaledDefuzzify_ID;
       NameTag = "CombineScaledDefuzzify";
       EncodeDecodeClass = "Object.CombineScaledDefuzzify";

       Initialization();
}
DataCombineScaledDefuzzifyClass::DataCombineScaledDefuzzifyClass()
     : DataOperationClass(),
       CombineOpClass(NULL),
       CoerceOpClass(NULL),
       ScaleOpClass(NULL)
{
       Identification = DeFuzzy_CombineScaledDefuzzify_ID;
       NameTag = "CombineScaledDefuzzify";
       EncodeDecodeClass = NameTag;
       SubClass = "Operation";

       Initialization();
}
BaseDataCombineScaledDefuzzify::BaseDataCombineScaledDefuzzify(const BaseDataCombineScaledDefuzzify& data)
     : BaseDataOperation(data)
{
       CombineOp = (BaseDataOperation *) PointerClone(data.CombineOp);
       CoerceOp = (BaseDataOperation *) PointerClone(data.CombineOp);
       ScaleOp = (BaseDataOperation *) PointerClone(data.ScaleOp);
}
DataCombineScaledDefuzzifyClass::DataCombineScaledDefuzzifyClass(const DataCombineScaledDefuzzifyClass& data)
     : DataOperationClass(data)
{
       CombineOpClass = (DataOperationClass *) PointerClone(data.CombineOpClass);
       CoerceOpClass = (DataOperationClass *) PointerClone(data.CombineOpClass);
       ScaleOpClass = (DataOperationClass *) PointerClone(data.ScaleOpClass);
}
DataCombineScaledDefuzzifyClass::DataCombineScaledDefuzzifyClass(const int id, const String& name, const String& descr)
     : DataOperationClass(id,name,descr),
       CombineOpClass(NULL),
       CoerceOpClass(NULL),
       ScaleOpClass(NULL)
{
       EncodeDecodeClass = "CombineScaledDefuzzify";
       SubClass = "Operation";
       Initialization();
}

BaseDataCombineScaledDefuzzify::~BaseDataCombineScaledDefuzzify()
{
if(CombineOp != NULL)
     {
     delete CombineOp;
     CombineOp = NULL;
     }
if(CoerceOp != NULL)
     {
     delete CombineOp;
     CoerceOp = NULL;
     }
if(ScaleOp != NULL)
     {
     delete ScaleOp;
     ScaleOp = NULL;
     }

}
DataCombineScaledDefuzzifyClass::~DataCombineScaledDefuzzifyClass()
{
if(CombineOpClass != NULL)
     {
     delete CombineOpClass;
     CombineOpClass = NULL;
     }
if(CoerceOpClass != NULL)
     {
     delete CombineOpClass;
     CombineOpClass = NULL;
     }
if(ScaleOpClass != NULL)
     {
     delete ScaleOpClass;
     ScaleOpClass = NULL;
     }

}
void BaseDataCombineScaledDefuzzify::Initialization()
{
}
void DataCombineScaledDefuzzifyClass::Initialization()
{
}
ostream& BaseDataCombineScaledDefuzzify::print(ostream& out) const
{
       BaseDataOperation::print(out);
       PointerPrint(out, "CombineOp:  ","No Object",(BaseDataObject *) CombineOp);
       PointerPrint(out, "CoerceOp:  ","No Object",(BaseDataObject *) CoerceOp);
       PointerPrint(out, "ScaleOp:  ","No Object",(BaseDataObject *) ScaleOp);

       return out;
}
ostream& DataCombineScaledDefuzzifyClass::print(ostream& out) const
{
       DataOperationClass::print(out);
       PointerPrint(out, "CombineOpClass:  ","No Object",(BaseDataObject *) CombineOpClass);
       PointerPrint(out, "CoerceOpClass:  ","No Object",(BaseDataObject *) CoerceOpClass);
       PointerPrint(out, "ScaleOpClass:  ","No Object",(BaseDataObject *) ScaleOpClass);

       return out;
}
void BaseDataCombineScaledDefuzzify::CopyClone(Identify *obj)
{
       BaseDataCombineScaledDefuzzify *objfull = (BaseDataCombineScaledDefuzzify *) obj;
       *this = *objfull;
       BaseDataOperation::CopyClone(obj);
       CombineOp = (BaseDataOperation *) PointerClone(objfull->CombineOp);
       CoerceOp = (BaseDataOperation *) PointerClone(objfull->CoerceOp);
       ScaleOp = (BaseDataOperation *) PointerClone(objfull->ScaleOp);
}
void DataCombineScaledDefuzzifyClass::CopyClone(Identify *obj)
{
       DataCombineScaledDefuzzifyClass *objfull = (DataCombineScaledDefuzzifyClass *) obj;
       *this = *objfull;
       DataOperationClass::CopyClone(obj);
       CombineOpClass = (DataOperationClass *) PointerClone(objfull->CombineOpClass);
       CoerceOpClass = (DataOperationClass *) PointerClone(objfull->CoerceOpClass);
       ScaleOpClass = (DataOperationClass *) PointerClone(objfull->ScaleOpClass);
}
Identify *BaseDataCombineScaledDefuzzify::Clone()
{
       Identify *id = (Identify *) new BaseDataCombineScaledDefuzzify(*this);
       return id;
}
Identify *DataCombineScaledDefuzzifyClass::Clone()
{
       Identify *id = (Identify *) new DataCombineScaledDefuzzifyClass(*this);
       return id;
}
bool TopDecode(CommBuffer& buffer, BaseDataCombineScaledDefuzzify*& obj)
{
       obj = new BaseDataCombineScaledDefuzzify;
       return obj->DecodeThis(buffer);
}
bool TopDecode(CommBuffer& buffer, DataCombineScaledDefuzzifyClass*& obj)
{
       obj = new DataCombineScaledDefuzzifyClass;
       return obj->DecodeThis(buffer);
}
bool BaseDataCombineScaledDefuzzify::EncodeThis(CommBuffer& buffer)
{
       bool result = BaseDataOperation::EncodeThis(buffer);
       result = result  & PointerEncode(buffer, (BaseDataObject *&) CombineOp);
       result = result  & PointerEncode(buffer, (BaseDataObject *&) CoerceOp);
       result = result  & PointerEncode(buffer, (BaseDataObject *&) ScaleOp);

       return(result);
}
bool DataCombineScaledDefuzzifyClass::EncodeThis(CommBuffer& buffer)
{
       bool result = DataOperationClass::EncodeThis(buffer);
       result = result  & PointerEncode(buffer, (BaseDataObject *&) CombineOpClass);
       result = result  & PointerEncode(buffer, (BaseDataObject *&) CoerceOpClass);
       result = result  & PointerEncode(buffer, (BaseDataObject *&) ScaleOpClass);

       return(result);
}
bool BaseDataCombineScaledDefuzzify::DecodeThis(CommBuffer& buffer)
{
       bool result = BaseDataOperation::DecodeThis(buffer);
       result = result  & PointerDecode(buffer, (BaseDataObject *&) CombineOp);
       result = result  & PointerDecode(buffer, (BaseDataObject *&) CoerceOp);
       result = result  & PointerDecode(buffer, (BaseDataObject *&) ScaleOp);

       return(result);
}
bool DataCombineScaledDefuzzifyClass::DecodeThis(CommBuffer& buffer)
{
       bool result = DataOperationClass::DecodeThis(buffer);
       result = result  & PointerDecode(buffer, (BaseDataObject *&) CombineOpClass);
       result = result  & PointerDecode(buffer, (BaseDataObject *&) CoerceOpClass);
       result = result  & PointerDecode(buffer, (BaseDataObject *&) ScaleOpClass);

       return(result);
}
bool BaseDataCombineScaledDefuzzify::Read(istream& in, DataObjectClass* objc)
{
       StreamObjectInput str(in,' ');
       NameTag = str.ReadNext();
       return Read(in,objc,NameTag);
}
bool BaseDataCombineScaledDefuzzify::Read(istream& in, DataObjectClass *objc, const String& name)
{
       DataCombineScaledDefuzzifyClass *objcfull = (DataCombineScaledDefuzzifyClass *) objc;
       bool result = BaseDataOperation::Read(in,objcfull, name);
       String notdefined("Not Defined");
       result = result  & PointerObjectRead(in,(BaseDataObject *&) CombineOp,objcfull->GetClassCombineOpClass(),notdefined);
       result = result  & PointerObjectRead(in,(BaseDataObject *&) CoerceOp,objcfull->GetClassCoerceOpClass(),notdefined);
       result = result  & PointerObjectRead(in,(BaseDataObject *&) ScaleOp,objcfull->GetClassScaleOpClass(),notdefined);

       return(result);
}
bool DataCombineScaledDefuzzifyClass::Read(istream& in, DataSetOfObjectsClass& set)
{
       bool result = DataOperationClass::Read(in,set);
       String notdefined("Not Defined");
       result = result  & PointerClassRead(in,(DataObjectClass *&) CombineOpClass,"Operation",set,notdefined);
       result = result  & PointerClassRead(in,(DataObjectClass *&) CoerceOpClass,"Operation",set,notdefined);
       result = result  & PointerClassRead(in,(DataObjectClass *&) ScaleOpClass,"Operation",set,notdefined);

       return(result);
}
bool BaseDataCombineScaledDefuzzify::Write(ostream& out, DataObjectClass *objc)
{
  //DataCombineScaledDefuzzifyClass *objcfull = (DataCombineScaledDefuzzifyClass *) objc;
  bool result = true;
  //bool result = BaseDataOperation::Write(out,objcfull);
       //result = result  & PointerObjectWrite(out,&CombineOp,objcfull->GetClassCombineOpClass(),notdefined);
       //result = result  & PointerObjectWrite(out,&ScaleOp,objcfull->GetClassScaleOpClass(),notdefined);

       return(result);
}
bool DataCombineScaledDefuzzifyClass::Write(ostream& out, DataSetOfObjectsClass& set)
{
  bool result = true;
  //bool result = DataOperationClass::Write(out,set);
       //result = result  & PointerClassWrite(out,&CombineOpClass,"CombineOpClass",set,notdefined);
       //result = result  & PointerClassWrite(out,&ScaleOpClass,"ScaleOpClass",set,notdefined);

       return(result);
}
BaseDataObject *DataCombineScaledDefuzzifyClass::BaseDataObjectExample()
{
       BaseDataObject *obj = (BaseDataObject *) new BaseDataCombineScaledDefuzzify();
       obj->SetType(Identification);
       return obj;
}
BaseDataObject *BaseDataCombineScaledDefuzzify::GetObjectCombineOp()

{
      return (BaseDataObject *) CombineOp;
}
BaseDataObject *BaseDataCombineScaledDefuzzify::GetObjectCoerceOp()

{
      return (BaseDataObject *) CombineOp;
}
BaseDataObject *BaseDataCombineScaledDefuzzify::GetObjectScaleOp()

{
      return (BaseDataObject *) ScaleOp;
}
DataObjectClass *DataCombineScaledDefuzzifyClass::GetClassCombineOpClass()

{
      return (DataObjectClass *) CombineOpClass;
}
DataObjectClass *DataCombineScaledDefuzzifyClass::GetClassCoerceOpClass()

{
      return (DataObjectClass *) CombineOpClass;
}
DataObjectClass *DataCombineScaledDefuzzifyClass::GetClassScaleOpClass()

{
      return (DataObjectClass *) ScaleOpClass;
}

/*F obj = operator()(x,y,xclass,yclass) . . . . . . . . . . BaseDataCombineScaledDefuzzify
**
**  DESCRIPTION
**    x,y: The objects to be operated on
**    xclass,yclass: The object classes
**    obj: The result
**
**    This is a two-dimensional call.  An object is created.
**
**  REMARKS
**
*/
BaseDataObject *BaseDataCombineScaledDefuzzify::operator()(BaseDataObject *x, BaseDataObject *y,
							   DataObjectClass *xc, DataObjectClass *yc)
{
  return operator()(x,xc);
}
/*F obj = operator()(x,xclass)  . . . . . . . . . . . . . . BaseDataCombineScaledDefuzzify
**
**  DESCRIPTION
**    x: The object to be operated on
**    xclass: The class of the object
**    obj: The result
**
**    This is a one-dimensional call.  An object is created.
**
**  REMARKS
**
*/
BaseDataObject *BaseDataCombineScaledDefuzzify::operator()(BaseDataObject *x,
					                   DataObjectClass *xc)
{
  BaseDataSetOfInstances *instances = (BaseDataSetOfInstances *) x;
  DataSetOfInstancesClass *instclass = (DataSetOfInstancesClass *) xc;
  
    
  BaseDataEvaluatedRuleSystem *evaluated = ( BaseDataEvaluatedRuleSystem *) instances->GetObject("Pairs");
  //DataEvaluatedRuleSystemClass *evalclass = (DataEvaluatedRuleSystemClass *) xc;

  BaseDataObject *combined = NULL;

  cout << "BaseDataCombineScaledDefuzzify::operator()" << endl;
  evaluated->print(cout);
  cout << endl << "------------------------------------------" << endl;
  ObjectList<String> names = evaluated->OrderedListOfParameterNames();
  cout << "Rule Evaluated Names: " << endl;
  names.print(cout);
  cout << endl;

  ObjectList<String>::iterator name;
  for(name=names.begin();name != names.end(); name++) 
    {
      cout << "First Evaluation"  << *name << endl;

      BaseDataConditionValuePair *pair = (BaseDataConditionValuePair *) evaluated->GetObject(*name);
      cout << "First Result: " << endl;
      pair->print(cout);
      cout << endl;

      BaseDataLogical *log = (BaseDataLogical *) pair->Logical;
      BaseDataObject *obj  = pair->Object;
      cout << "Logical Value: " << endl;
      log->print(cout);
      cout << endl << "Object Value";
      obj->print(cout);
      cout << endl;

      DataObjectClass *logcls = instclass->PointerToAllowedClasses()->GetObjectClass(log->GetType());
      DataObjectClass *objcls = instclass->PointerToAllowedClasses()->GetObjectClass(obj->GetType());
      
      
      BaseDataObject *scaled = ScaleOp->operator()(log,obj,logcls,objcls);
      cout << "Scaled Result: " << endl;
      scaled->print(cout);
      cout << endl;
      if(combined == NULL) {
	cout << "First combined";
	combined = scaled;
      } else {
	cout << "Replace Combined" << endl;
	DataObjectClass *scaledclass = instclass->PointerToAllowedClasses()->GetObjectClass(scaled->GetType());
	DataObjectClass *combinedclass = instclass->PointerToAllowedClasses()->GetObjectClass(combined->GetType());
	BaseDataObject *newcombined = CombineOp->operator()(combined,scaled,combinedclass,scaledclass);
	delete combined;
	combined = newcombined;
      }
    }
  return combined;
}
/*F obj = operator()(cls,x,y,xclass,yclass) . . . . . . . . . . BaseDataCombineScaledDefuzzify
**
**  DESCRIPTION
**    x,y: The objects to be operated on
**    xclass,yclass: The object classes
**    obj: The result
**
**    This is a two-dimensional call.  An object is created.
**    The cls is used (among other things) to check the input types
**
**  REMARKS
**
*/
BaseDataObject *BaseDataCombineScaledDefuzzify::operator()(DataObjectClass *cls,
						  BaseDataObject *x, BaseDataObject *y,
						  DataObjectClass *xc, DataObjectClass *yc)
                                              
{
  /*
    DataSetOfObjectsClass *set = (BaseDataSetOfObjects *) cls->PointerToAllowedClasses();
    bool result = true;
    result = result && set->IsOfClass(xc,_NAME);
    result = result && set->IsOfClass(yc,_NAME);
    result = result && (x->GetType() == xc->GetType());
    result = result && (y->GetType() == yc->GetType());
  */
  return operator()(x,y,xc,yc);
}
/*F obj = operator()(cls,x,xclass)  . . . . . . . . . . . . . . BaseDataCombineScaledDefuzzify
**
**  DESCRIPTION
**    cls: The class of the operation
**    x: The object to be operated on
**    xclass: The class of the object
**    obj: The result
**
**    This is a dummy one-dimensional call.  An empty object is created.
**
**  REMARKS
**
*/
BaseDataObject *BaseDataCombineScaledDefuzzify::operator()(DataObjectClass *cls,
						  BaseDataObject *x,
						  DataObjectClass *xclass)
{
  /*
    DataSetOfObjectsClass *set = (BaseDataSetOfObjects *) cls->PointerToAllowedClasses();
    bool result = true;
    result = result && set->IsOfClass(xc,_NAME);
    result = result && (x->GetType() == xc->GetType());
  */
  return operator()(x,xclass);
}
 

/*S Utilities
 */
/*F InitialDeFuzzyEncodeDecodeRoutines() . . parameterized classes
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
extern void InitialDeFuzzyEncodeDecodeRoutines()
{
  EncodeDecodeRegisterClass(DataEvaluateRuleSystemClass,BaseDataEvaluateRuleSystem,DEFUZZY_EVALUATERULESYSTEM_NAME);
  EncodeDecodeRegisterClass(DataConditionValuePairClass,BaseDataConditionValuePair,DEFUZZY_CONDITIONVALUEPAIR_NAME);
  EncodeDecodeRegisterClass(DataEvaluatedRuleSystemClass,BaseDataEvaluatedRuleSystem,DEFUZZY_EVALUATEDRULESYSTEM_NAME);
  EncodeDecodeRegisterClass(DataCombineScaledDefuzzifyClass, BaseDataCombineScaledDefuzzify,"CombineScaledDefuzzify");
}
 
/*F AddDeFuzzyClasses(set)
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
void AddDeFuzzyClasses(DataSetOfObjectsClass& set)
{
  String erdescr("The Evaluate Rule System Class");
  DataEvaluateRuleSystemClass erclass(DEFUZZY_EVALUATERULESYSTEM_ID,DEFUZZY_EVALUATERULESYSTEM_NAME,erdescr);
  set.AddObjectClass(erclass);

  String cdescr("The Condition Value Class");
  DataConditionValuePairClass cclass(DEFUZZY_CONDITIONVALUEPAIR_ID,DEFUZZY_CONDITIONVALUEPAIR_NAME,cdescr);
  set.AddObjectClass(cclass);

  String eddescr("The Evaluated Rule System Class");
  DataEvaluatedRuleSystemClass edclass(DEFUZZY_EVALUATEDRULESYSTEM_ID,DEFUZZY_EVALUATEDRULESYSTEM_NAME,eddescr);
  set.AddObjectClass(edclass);

  String descrDataCombineScaledDefuzzifyClass("CombineScaledDefuzzify of CoreObjects");
  DataCombineScaledDefuzzifyClass  defDataCombineScaledDefuzzifyClass(DeFuzzy_CombineScaledDefuzzify_ID,"CombineScaledDefuzzify",descrDataCombineScaledDefuzzifyClass);
  set.AddObjectClass(defDataCombineScaledDefuzzifyClass);

}
