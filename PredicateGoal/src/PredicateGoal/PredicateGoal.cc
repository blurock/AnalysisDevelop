/*  FILE     PredicateGoal.cc
**  PACKAGE  PredicateGoal
**  AUTHOR   Edward S. Blurock
**
**  CONTENT
**    Exported functions for the "PredicateGoal" package.
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
#include "DataObjects.hh"
#include "InstanceObjects.hh"
#include "DirectedTreeObjects.hh"
#include "SelectObjects.hh"
#include "AlgorithmObjects.hh"
#include "GoalObjects.hh"
#include "PredicateGoal.hh"

/*S BaseDataSingleVariable
 */ 
/*F BaseDataSingleVariable()  . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataSingleVariable::BaseDataSingleVariable()
{
  Identification = PREDICATEGOAL_SINGLEVARIABLE_ID;
  NameTag = PREDICATEGOAL_SINGLEVARIABLE_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;
} 
/*F BaseDataSingleVariable(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataSingleVariable::BaseDataSingleVariable(const BaseDataSingleVariable& data)
  : BaseDataObject(data),
    VariableName(data.VariableName),
    ClassName(data.ClassName),
    Level(data.Level),
    VConstant(data.VConstant)
{
}
/*F BaseDataSingleVariable(name,classname,level)  . . . . . . . . . . . . . . . . .  constructor
**
**  DESCRIPTION
**    name: Name of variable
**    classname: The classname of the variable
**    level: the level of this instance of the variable
**
**  REMARKS
**
*/
BaseDataSingleVariable::BaseDataSingleVariable(const String name,
					       const String varname,
					       const String classname,
					       const unsigned int level,
					       const bool vconstant)
  : VariableName(varname),
    ClassName(classname),
    Level(level),
    VConstant(vconstant)
{
  NameTag = name;
}
/*F Read(in,objc) . . . . . . . . . . . . . . . . . .  Read in BaseDataSingleVariable
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataSingleVariable::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . . . . . . . .  Read in BaseDataSingleVariable
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataSingleVariable::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = BaseDataObject::Read(in,objc,name);
  
  StreamObjectInput str(in,' ');
  VariableName = str.ReadNext();
  ClassName = str.ReadNext();
  String LevelS = str.ReadNext();
  String VConstantS= str.ReadNext();

  Level = LevelS.ToInteger();
  VConstant = false;
  if(VConstantS == "T")
    VConstant = true;

  return result;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . .  BaseDataSingleVariable
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataSingleVariable::print(ostream& out) const
{
  BaseDataObject::print(out);

  out << "Variable Name: ";
  out << VariableName;
  out << "    ClassName: ";
  out << ClassName;
  out << " ( Level=" << Level << ") ";
  if(VConstant == true)
    out << " [A Constant]";
  out << endl;

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . . . . .BaseDataSingleVariable
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataSingleVariable::Clone()
{
  BaseDataSingleVariable *obj = new BaseDataSingleVariable;
  obj->CopyClone(this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . . . . .BaseDataSingleVariable
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataSingleVariable::CopyClone(Identify * obj)
{
  BaseDataSingleVariable *objfull = (BaseDataSingleVariable *) obj;
  
  *this = *objfull;
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataSingleVariable
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataSingleVariable::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataObject::EncodeThis(buffer);
  result = result && Encode(buffer,VariableName);
  result = result && Encode(buffer,ClassName);
  result = result && Encode(buffer,Level);
  result = result && BoolEncode(buffer,VConstant);
    
  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataSingleVariable
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataSingleVariable::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataObject::DecodeThis(buffer);
  result = result && Decode(buffer,VariableName);
  result = result && Decode(buffer,ClassName);
  result = result && Decode(buffer,Level);
  result = result && BoolDecode(buffer,VConstant);

    
  return result;
}
/*F name = getVariableName()  . . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    name: The name of the variable
**
**  REMARKS
**
*/
String BaseDataSingleVariable::getVariableName() const
{
  return VariableName;
}
/*F name = getClassName()  . . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
String BaseDataSingleVariable::getClassName() const
{
  return ClassName;
}
/*F level = getClassLevel() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
unsigned int BaseDataSingleVariable::getLevel() const
{
  return Level;
}
/*F setVariableName(name) . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataSingleVariable::setVariableName(String name)
{
  VariableName = name;
}
/*F setClassName(name)  . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataSingleVariable::setClassName(String name)
{
  ClassName = name;
}
/*F setLevel(unsigned int level() . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataSingleVariable::setLevel(unsigned int level)
{
  Level = level;
}
/*F ans = operator==(var) . . . . . . . . . . . . . .  BaseDataSingleVariable
**
**  DESCRIPTION
**
**  REMARKS
**
*/
bool BaseDataSingleVariable::operator==(const BaseDataSingleVariable& var)
{
  
  cout << "Check if equal\n";
  bool result = (getVariableName() == var.getVariableName());
  result = result && (getClassName() == var.getClassName());
  result = result && (getLevel() == var.getLevel());
  result = result && ( (!isConstant() && !var.isConstant()) ||
		       (isConstant() && var.isConstant()) );
  return result;
}
/*F ans = theSame(var,classname,level,c) . . . . .  BaseDataSingleVariable
**
**  DESCRIPTION
**    var: The variable name
**    classname: The name of the variable class (type)
**    level: The assignment level
**    c: true if a constant
**    ans: true if the same
**
**  REMARKS
**
*/
bool BaseDataSingleVariable::theSame(const String& var,
				     const String& classname,
				     const unsigned int level,
				     const bool c)
{
  bool result = (var == getVariableName());
  result = result && (classname == getClassName());
  result = result && (level == getLevel());
  result = result && (c == isConstant());
  return result;
}
/*F ans = isConstant()  . . . . . . . . . . . . . . .  BaseDataSingleVariable
**
**  DESCRIPTION
**    ans: true if the constant is a variable
**
**  REMARKS
**
*/
bool BaseDataSingleVariable::isConstant() const
{
  return VConstant;
}
/*F setAsConstant() . . . . . . . . . . . . . . . BaseDataSingleVariable
**
**  DESCRIPTION
**     Defines the variable as a constant
**
**  REMARKS
**
*/
void BaseDataSingleVariable::setAsConstant()
{
  VConstant = true;
}
/*F setAsVariable() . . . . . . . . . . . . . . . BaseDataSingleVariable
**
**  DESCRIPTION
**     Defines the variable as a variable
**
**  REMARKS
**
*/
void BaseDataSingleVariable::setAsVariable()
{
  VConstant = false;
}
/*F newenv = Unify(var,env,level) . . . . . . . . . .  BaseDataSingleVariable
**
**  DESCRIPTION
**     var: The fact variable
**     env: The current variable environment
**     level: The current level
**     newen: The new variable environment (NULL if not unifiable)
**
**     This routine unifies a goal and fact variable.  The bottom of 
**     both the goal and the fact variable are found and are checked 
**     against the assignments within the environment.
**
**  REMARKS
**
*/
BaseDataVariableEnvironment *BaseDataSingleVariable::Unify(BaseDataSingleVariable *var,
							   BaseDataVariableEnvironment *env,
							   unsigned int level)
{
  BaseDataVariableEnvironment *newenv = env;
  bool result = true;
  BaseDataSingleVariable *bottomvar;
  if(env->isAssigned(*var))
      bottomvar = env->getAssignment(*var);
  else
      bottomvar = var;
  BaseDataSingleVariable *bottomgoal;
  if(env->isAssigned(*this))
      bottomgoal = env->getAssignment(*this);
  else
      bottomgoal = this;

  if(!(bottomgoal->operator==(*bottomvar)))
    {
      if(bottomvar->isConstant() && bottomgoal->isConstant())
	{
	  result = false;
	}
      else
	{
	  result = bottomvar->getClassName() == bottomgoal->getClassName();
	  if(result)
	    {
	      BaseDataVariableAssignment *assign;
	      if(bottomgoal->isConstant())
		assign = new BaseDataVariableAssignment(*bottomvar,*bottomgoal);
	      else
		assign = new BaseDataVariableAssignment(*bottomgoal,*bottomvar);
	      result = result && !(env->Conflict(*assign));
	      if(bottomgoal->isConstant())
	    result = result && env->addVariableAssignment(*bottomvar,*bottomgoal);
	      else
		result = result && env->addVariableAssignment(*bottomgoal,*bottomvar);
	      
	      delete assign;
	    }
	}
    }
 if(!result)
   {
     delete newenv;
     newenv = NULL;
   }
 return newenv;
}

/*S DataSingleVariableClass
 */
/*F DataSingleVariableClass() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataSingleVariableClass::DataSingleVariableClass()
{
  Identification = PREDICATEGOAL_SINGLEVARIABLE_ID;
  NameTag = PREDICATEGOAL_SINGLEVARIABLE_NAME;
  SubClass = "Object";
  EncodeDecodeClass = NameTag;
} 
/*F DataSingleVariableClass(data) . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataSingleVariableClass::DataSingleVariableClass(const DataSingleVariableClass& data)
  : DataObjectClass(data)
{
} 
 
/*F DataSingleVariableClass(id,name,descr)  . . . . . . . . . . . . . . . constructor
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
DataSingleVariableClass::DataSingleVariableClass(const int id, 
				 const String& name,
				 const String& descr)
  : DataObjectClass(id,name,descr)
{
  SubClass = "Object";
  EncodeDecodeClass = PREDICATEGOAL_SINGLEVARIABLE_NAME;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . . DataSingleVariableClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataSingleVariableClass::print(ostream& out) const
{
  DataObjectClass::print(out);
  // the rest
       
       return out;
}
 
/*F in1 = Read(in)  . . . . . . . . . . . . . . . . . . . . . DataSingleVariableClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataSingleVariableClass, there is no further information.
**
**  REMARKS
**
*/
bool DataSingleVariableClass::Read(istream& in, DataSetOfObjectsClass &set)
{
  bool result = DataObjectClass::Read(in,set);

  return result;
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . . . DataSingleVariableClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataSingleVariableClass::CopyClone(Identify *  objc)
{
  DataSingleVariableClass *objcfull = (DataSingleVariableClass *) objc;
  *this = *objcfull;
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . . . DataSingleVariableClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataSingleVariableClass::Clone()
    {
      DataSingleVariableClass* id = new DataSingleVariableClass(*this);
      return (Identify *) id;
    }
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . . DataSingleVariableClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataSingleVariableClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataObjectClass::EncodeThis(buffer);
  // result = result && Encode(buffer,------);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . . DataSingleVariableClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataSingleVariableClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataObjectClass::DecodeThis(buffer);
//  result = result && Decode(buffer,-----);

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
BaseDataObject * DataSingleVariableClass::BaseDataObjectExample()
{ 
  return (BaseDataObject *) new BaseDataSingleVariable();
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . DataSingleVariableClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataSingleVariableClass*& obj)
     {
     obj = new DataSingleVariableClass;
     return obj->DecodeThis(buffer);
     }
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . BaseDataSingleVariable
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataSingleVariable*& obj)
     {
     obj = new BaseDataSingleVariable;
     return obj->DecodeThis(buffer);
     }
/*S BaseDataVariableAssignment
 */ 
/*F BaseDataVariableAssignment()  . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataVariableAssignment::BaseDataVariableAssignment()
{
  Identification = PREDICATEGOAL_VARIABLEASSIGNMENT_ID;
  NameTag = PREDICATEGOAL_VARIABLEASSIGNMENT_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;
} 
/*F BaseDataVariableAssignment(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataVariableAssignment::BaseDataVariableAssignment(const BaseDataVariableAssignment& data)
  : BaseDataSingleVariable(data),
    Assignment(data.Assignment)
{
}
/*F BaseDataVariableAssignment(var,assign)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    var: The variable to be assigned to
**    assign: The assignment
**
**  REMARKS
**
*/
BaseDataVariableAssignment::BaseDataVariableAssignment(const BaseDataSingleVariable& var,
						       const BaseDataSingleVariable& assign)
  : BaseDataSingleVariable(var),
    Assignment(assign)
{
}
/*F Read(in,objc) . . . . . . . . . . . . . . . . . .  Read in BaseDataVariableAssignment
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataVariableAssignment::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . . . . . . . .  Read in BaseDataVariableAssignment
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataVariableAssignment::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = BaseDataSingleVariable::Read(in,objc,name);
  Assignment.Read(in,objc);
  
  return result;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . .  BaseDataVariableAssignment
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataVariableAssignment::print(ostream& out) const
{
  out << "Assigned To: ";
  BaseDataSingleVariable::print(out);
  out << "Assignment: ";
  Assignment.print(out);

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . . . . .BaseDataVariableAssignment
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataVariableAssignment::Clone()
{
  BaseDataVariableAssignment *obj = new BaseDataVariableAssignment;
  obj->CopyClone(this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . . . . .BaseDataVariableAssignment
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataVariableAssignment::CopyClone(Identify * obj)
{
  BaseDataVariableAssignment *objfull = (BaseDataVariableAssignment *) obj;
  
  *this = *objfull;
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataVariableAssignment
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataVariableAssignment::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataSingleVariable::EncodeThis(buffer);
  result = result && Assignment.EncodeThis(buffer);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataVariableAssignment
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataVariableAssignment::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataSingleVariable::DecodeThis(buffer);
  result = result && Assignment.DecodeThis(buffer);

  return result;
}
/*F var = getVariable() . . . . . . . . . . . . . get variable to be assigned
**
**  DESCRIPTION
**    var: Variable to be assigned to
**
**  REMARKS
**
*/
BaseDataSingleVariable* BaseDataVariableAssignment::getVariable()
{
  return (BaseDataSingleVariable * ) this;
}
/*F assign = getAssignment() . . . . . . . . . . . . . get variable to be assigned
**
**  DESCRIPTION
**    assign: Assignment made to variable
**
**  REMARKS
**
*/
BaseDataSingleVariable* BaseDataVariableAssignment::getAssignment()
{
  return &Assignment;
}
/*F ans = operator==(assignment)  . . . . . . . . . . .BaseDataSingleVariable
**
**  DESCRIPTION
**     assignment: The assignment to be compared
**     ans: true if equal
**
**  REMARKS
**
*/
bool BaseDataVariableAssignment::operator==(BaseDataVariableAssignment& assign)
{
  bool result = BaseDataSingleVariable::operator==(assign);
  result = result && getAssignment()->operator==(*(assign.getAssignment()));
  return result;
}
/*S DataVariableAssignmentClass
 */
/*F DataVariableAssignmentClass() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataVariableAssignmentClass::DataVariableAssignmentClass()
{
  Identification = PREDICATEGOAL_VARIABLEASSIGNMENT_ID;
  NameTag = PREDICATEGOAL_VARIABLEASSIGNMENT_NAME;
  SubClass = "SingleVariable";
  EncodeDecodeClass = NameTag;
} 
/*F DataVariableAssignmentClass(data) . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataVariableAssignmentClass::DataVariableAssignmentClass(const DataVariableAssignmentClass& data)
  : DataSingleVariableClass(data)
{
} 
 
/*F DataVariableAssignmentClass(id,name,descr)  . . . . . . . . . . . . . . . constructor
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
DataVariableAssignmentClass::DataVariableAssignmentClass(const int id, 
				 const String& name,
				 const String& descr)
  : DataSingleVariableClass(id,name,descr)
{
  SubClass = "SingleVariable";
  EncodeDecodeClass = "VariableAssignment";
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . . DataVariableAssignmentClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataVariableAssignmentClass::print(ostream& out) const
{
  DataSingleVariableClass::print(out);
  // the rest
       
       return out;
}
 
/*F in1 = Read(in)  . . . . . . . . . . . . . . . . . . . . . DataVariableAssignmentClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataVariableAssignmentClass, there is no further information.
**
**  REMARKS
**
*/
bool DataVariableAssignmentClass::Read(istream& in, DataSetOfObjectsClass &set)
{
  bool result = DataSingleVariableClass::Read(in,set);

  return result;
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . . . DataVariableAssignmentClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataVariableAssignmentClass::CopyClone(Identify *  objc)
{
  DataVariableAssignmentClass *objcfull = (DataVariableAssignmentClass *) objc;
  *this = *objcfull;
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . . . DataVariableAssignmentClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataVariableAssignmentClass::Clone()
    {
      DataVariableAssignmentClass* id = new DataVariableAssignmentClass(*this);
      return (Identify *) id;
    }
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . . DataVariableAssignmentClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataVariableAssignmentClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataSingleVariableClass::EncodeThis(buffer);
  // result = result && Encode(buffer,------);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . . DataVariableAssignmentClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataVariableAssignmentClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataSingleVariableClass::DecodeThis(buffer);
//  result = result && Decode(buffer,-----);

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
BaseDataObject * DataVariableAssignmentClass::BaseDataObjectExample()
{ 
  return (BaseDataObject *) new BaseDataVariableAssignment();
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . DataVariableAssignmentClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataVariableAssignmentClass*& obj)
     {
     obj = new DataVariableAssignmentClass;
     return obj->DecodeThis(buffer);
     }
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . BaseDataVariableAssignment
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataVariableAssignment*& obj)
     {
     obj = new BaseDataVariableAssignment;
     return obj->DecodeThis(buffer);
     }
/*S BaseDataVariableEnvironment
 */ 
/*F BaseDataVariableEnvironment()  . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataVariableEnvironment::BaseDataVariableEnvironment()
{
  Identification = PREDICATEGOAL_VARIABLEENVIRONMENT_ID;
  NameTag = PREDICATEGOAL_VARIABLEENVIRONMENT_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;

  String title("------- Set of Variable Assignments -------\n");
  Assignments.setTitle(title);
  String delimitor("\n");
  Assignments.setDelimitor(delimitor);
} 
/*F BaseDataVariableEnvironment(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataVariableEnvironment::BaseDataVariableEnvironment(const BaseDataVariableEnvironment& data)
  : BaseDataObject(data),
    Assignments(data.Assignments)
{
}
/*F Read(in,objc) . . . . . . . . . . . . . . . . . .  Read in BaseDataVariableEnvironment
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataVariableEnvironment::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . . . . . . . .  Read in BaseDataVariableEnvironment
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataVariableEnvironment::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = BaseDataObject::Read(in,objc,name);
  DataVariableEnvironmentClass *objclass = (DataVariableEnvironmentClass *) objc;
  result = result && Assignments.Read(in,objclass->getStandard(),name);

  return result;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . .  BaseDataVariableEnvironment
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataVariableEnvironment::print(ostream& out) const
{
  BaseDataObject::print(out);
  Assignments.print(out);

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . . . . .BaseDataVariableEnvironment
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataVariableEnvironment::Clone()
{
  BaseDataVariableEnvironment *obj = new BaseDataVariableEnvironment;
  obj->CopyClone(this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . . . . .BaseDataVariableEnvironment
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataVariableEnvironment::CopyClone(Identify * obj)
{
  BaseDataVariableEnvironment *objfull = (BaseDataVariableEnvironment *) obj;
  
  *this = *objfull;
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataVariableEnvironment
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataVariableEnvironment::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataObject::EncodeThis(buffer);
  result = result && Assignments.EncodeThis(buffer);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataVariableEnvironment
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataVariableEnvironment::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataObject::DecodeThis(buffer);
  result = result && Assignments.DecodeThis(buffer);

  return result;
}
/*F addVariableAssignment(var,assign) . . . . . . BaseDataVariableEnvironment
**
**  DESCRIPTION
**     var: The variable to be assigned to
**     assign: The assignment
**
**     The variable and its assignment are added to the environment
**
**  REMARKS
**
*/
bool BaseDataVariableEnvironment::addVariableAssignment(BaseDataSingleVariable& var,
							BaseDataSingleVariable& assign)
{
  bool result = !(isAssigned(var));
  if(result)
    {
    BaseDataVariableAssignment vassign(var,assign);
    result = result && Assignments.AddObject(&vassign);
    }
  return result;
}
/*F addVariableAssignment(assign) . . . . . . . . BaseDataVariableEnvironment
**
**  DESCRIPTION
**     assign: The variable-assignment pair
**
**     The assignment is added to the environment
**
**  REMARKS
**
*/
bool BaseDataVariableEnvironment:: addVariableAssignment(BaseDataVariableAssignment& assign)
{
  bool result = !(isAssigned(*(assign.getVariable())));
  result = result && Assignments.AddObject(&assign);
  return result;
}
/*F assign = getImmediateAssignment(var)  . . . . BaseDataVariableEnvironment
**
**  DESCRIPTION
**    var: The variable that was assigned
**    assign: The assignment
**
**    This returns a pointer to the assignment, if the variable was
**    not assigned, then NULL is returned.
**
**  REMARKS
**
*/
BaseDataSingleVariable *BaseDataVariableEnvironment::getImmediateAssignment(BaseDataSingleVariable& var)
{
  bool result = isAssigned(var);
  BaseDataSingleVariable *assign;
  BaseDataSingleVariable *tassign;
  if(result)
    {
      BaseDataVariableAssignment *vassign = 
	(BaseDataVariableAssignment *) Assignments.GetObject(var.NameTag);
      tassign = vassign->getAssignment();
      assign = tassign;
    }
  else
    {
      assign = NULL;
    }
  return assign;
}
/*F assign = getAssignment(var)  . . . . BaseDataVariableEnvironment
**
**  DESCRIPTION
**    var: The variable that was assigned
**    assign: The assignment
**
**    This returns a pointer to the direct assignment, if the variable was
**    not assigned, then NULL is returned.
**
**  REMARKS
**
*/
BaseDataSingleVariable *BaseDataVariableEnvironment::getAssignment(BaseDataSingleVariable& var)
{
  BaseDataSingleVariable *assigned;
  BaseDataSingleVariable *tofind = &var;

  while(isAssigned(*tofind))
    {
      assigned = getImmediateAssignment(*tofind);
      tofind = assigned;
    }
  return assigned;
}
/*F ans = Conflict(assignment)  . . . . . . . . . BaseDataVariableEnvironment
**
**  DESCRIPTION
**     assignment: The variable an its assignment
**     ans: true if no conflict arises
**
**     The environment is checked to see whether the assignment causes a conflict.
**     The final assignments of all variables are checked, the environment is recursively
**     checked until a variable is reached for which there is no assignment.
**     If the variable has not been assigned yet, then no conflict.
**     The final assignment of the assigned variable is also checked
**      
**  REMARKS
**
*/
bool BaseDataVariableEnvironment::Conflict(BaseDataVariableAssignment& assign)
{
  bool result = false;

  BaseDataSingleVariable  *var = assign.getVariable();
  BaseDataSingleVariable  *intermediateassign = assign.getAssignment();
  BaseDataSingleVariable  *finalassign = intermediateassign;
  if(isAssigned(*finalassign))
     {
       finalassign = getAssignment(*finalassign);
     }
  if(isAssigned(*var))
    {
      BaseDataSingleVariable *envassign = getAssignment(*var);
      if(!(*finalassign == *envassign))
	result = true;
    }
  return result;
}
/*F ans = isAssigned(var) . . . . . . . . . . . . BaseDataVariableEnvironment
**
**  DESCRIPTION
**  var: The variable to check
**  ans: True if assigned within the environment     
**      
**  REMARKS
**
*/
bool BaseDataVariableEnvironment::isAssigned(BaseDataSingleVariable& var)
{
    return Assignments.IsInList(var.NameTag);
}

/*S DataVariableEnvironmentClass
 */
/*F DataVariableEnvironmentClass() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataVariableEnvironmentClass::DataVariableEnvironmentClass()
{
  Identification = PREDICATEGOAL_VARIABLEENVIRONMENT_ID;
  NameTag = PREDICATEGOAL_VARIABLEENVIRONMENT_NAME;
  SubClass = "Object";
  EncodeDecodeClass = NameTag;

  Classes = StandardAllowedClasses;
} 
/*F DataVariableEnvironmentClass(data) . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataVariableEnvironmentClass::DataVariableEnvironmentClass(const DataVariableEnvironmentClass& data)
  : DataObjectClass(data),
    Classes(data.Classes)
{
} 
 
/*F DataVariableEnvironmentClass(id,name,descr)  . . . . . . . . . . . . . . . constructor
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
DataVariableEnvironmentClass::DataVariableEnvironmentClass(const int id, 
				 const String& name,
				 const String& descr)
  : DataObjectClass(id,name,descr)
{
  SubClass = "Object";
  EncodeDecodeClass = "VariableEnvironment";
  Classes = StandardAllowedClasses;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . . DataVariableEnvironmentClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataVariableEnvironmentClass::print(ostream& out) const
{
  DataObjectClass::print(out);
  // the rest
       
       return out;
}
 
/*F in1 = Read(in)  . . . . . . . . . . . . . . . . . . . . . DataVariableEnvironmentClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataVariableEnvironmentClass, there is no further information.
**
**  REMARKS
**
*/
bool DataVariableEnvironmentClass::Read(istream& in, DataSetOfObjectsClass &set)
{
  bool result = DataObjectClass::Read(in,set);

  return result;
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . . . DataVariableEnvironmentClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataVariableEnvironmentClass::CopyClone(Identify *  objc)
{
  DataVariableEnvironmentClass *objcfull = (DataVariableEnvironmentClass *) objc;
  *this = *objcfull;
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . . . DataVariableEnvironmentClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataVariableEnvironmentClass::Clone()
    {
      DataVariableEnvironmentClass* id = new DataVariableEnvironmentClass(*this);
      return (Identify *) id;
    }
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . . DataVariableEnvironmentClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataVariableEnvironmentClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataObjectClass::EncodeThis(buffer);
  // result = result && Encode(buffer,------);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . . DataVariableEnvironmentClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataVariableEnvironmentClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataObjectClass::DecodeThis(buffer);
//  result = result && Decode(buffer,-----);

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
BaseDataObject * DataVariableEnvironmentClass::BaseDataObjectExample()
{ 
  return (BaseDataObject *) new BaseDataVariableEnvironment();
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . DataVariableEnvironmentClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataVariableEnvironmentClass*& obj)
     {
     obj = new DataVariableEnvironmentClass;
     return obj->DecodeThis(buffer);
     }
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . BaseDataVariableEnvironment
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataVariableEnvironment*& obj)
     {
     obj = new BaseDataVariableEnvironment;
     return obj->DecodeThis(buffer);
     }
/*F getStandard() . . . . . . . . . . . . . . . . . . . DataVariableEnvironmentClass
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataSetOfObjectsClass *DataVariableEnvironmentClass::getStandard()
{
  return Classes;
}
/*S BaseDataGoalPredicate
 */ 
/*F BaseDataGoalPredicate()  . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataGoalPredicate::BaseDataGoalPredicate()
  : PConstant(true)
{
  Identification = PREDICATEGOAL_GOALPREDICATE_ID;
  NameTag = PREDICATEGOAL_GOALPREDICATE_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;
} 
/*F BaseDataGoalPredicate(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataGoalPredicate::BaseDataGoalPredicate(const BaseDataGoalPredicate& data)
  : BaseDataGoalSpec(data),
    PredicateName(data.PredicateName),
    PConstant(data.PConstant)
{
}
/*F Read(in,objc) . . . . . . . . . . . . . . . . . .  Read in BaseDataGoalPredicate
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataGoalPredicate::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . . . . . . . .  Read in BaseDataGoalPredicate
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataGoalPredicate::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result;
  StreamObjectInput str(in,' ');
  String key = str.ReadNext();
  if(key == "Fact:")
    setAsFact();
  else if(key == "Rule:")
    setAsRule();
  else
    {
      cerr << "Expected 'Fact:' or 'Rule:' got '" << key << "'\n";
      result = false;
    }
  if(result)
    PredicateName = str.ReadNext();

  result = result && BaseDataGoalSpec::Read(in,objc,name);
  return result;
}
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . .  BaseDataGoalPredicate
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataGoalPredicate::print(ostream& out) const
{
  out << "Predicate ";
  if(isFact())
    cout << "Fact: ";
  else
    cout << "Rule: ";
  cout << PredicateName << "   ";
  BaseDataGoalSpec::print(out);
  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . . . . .BaseDataGoalPredicate
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataGoalPredicate::Clone()
{
  BaseDataGoalPredicate *obj = new BaseDataGoalPredicate;
  obj->CopyClone(this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . . . . .BaseDataGoalPredicate
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataGoalPredicate::CopyClone(Identify * obj)
{
  BaseDataGoalPredicate *objfull = (BaseDataGoalPredicate *) obj;
  
  *this = *objfull;
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataGoalPredicate
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataGoalPredicate::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataGoalSpec::EncodeThis(buffer);
  result = result && Encode(buffer,PredicateName);
  result = result && BoolEncode(buffer,PConstant);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataGoalPredicate
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataGoalPredicate::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataGoalSpec::DecodeThis(buffer);
  result = result && Decode(buffer,PredicateName);
  result = result && BoolDecode(buffer,PConstant);

  return result;
}
/*F ans = operator==(pred)  . . . . . . . . . . . . . . BaseDataGoalPredicate
**
**  DESCRIPTION
**    ans: True if equal
**
**  REMARKS
**
*/
bool BaseDataGoalPredicate::operator==(BaseDataGoalPredicate& pred)
{
  bool result = pred.getPredicateName() == getPredicateName();
  result = result && VariableNamesEqual(pred);
  result = result && ClassNamesEqual(pred);
  return result;
}
/*F ans = operator<(pred)  . . . . . . . . . . . . . . BaseDataGoalPredicate
**
**  DESCRIPTION
**    pred: The goal predicate
**    ans:  True if equal
**
**  REMARKS
**
*/
bool BaseDataGoalPredicate::operator<(BaseDataGoalPredicate& pred)
{
  bool result = pred.NameTag < NameTag;
  return result;
}
/*F ans = Unifiable(pred)  . . . . . . . . . . . . . . BaseDataGoalPredicate
**
**  DESCRIPTION
**    pred: The goal predicate
**    ans:  True if equal
**
**    A primitive test for a unifiable predicate:
**    - name
**    - Number of parameters
**    - The parameter classes
**
**  REMARKS
**
*/
bool BaseDataGoalPredicate::Unifiable(BaseDataGoalPredicate *pred)
{
  bool result = (pred->getPredicateName() == getPredicateName());
  if(result)
    cout << "True\n";
  else
    cout << "False\n";
  result = result && (getParameterSpecs()->size() == pred->getParameterSpecs()->size());
  if(result)
    cout << "True\n";
  else
    cout << "False\n";
  result = result && ClassNamesEqual(*pred);
  if(result)
    cout << "True\n";
  else
    cout << "False\n";
  return result;
}
/*F newenv = Unify(fact,env,level)  . . . . . . . BaseDataVariableEnvironment
**
**  DESCRIPTION
**    fact: The predicate goal to unify with
**    env: The current variable assignments
**    level: The current levels
**    newenv: The new variable assignments after unification (NULL if not unifiable)
**
**    The unification process proceeds in several steps:
**    - Copy the current environment
**    - Check if the goal is unifiable (i.e. name, number and type of args, etc.)
**    - Set up looping over argument list
**    - Loop over set of arguments
**      - Isolate goal argument and fact argument as variables
**      - Unify goal and fact
**    - If goal was not unifiable, then set new environment to NULL
**      
**  REMARKS
**
*/
BaseDataVariableEnvironment *BaseDataGoalPredicate::Unify(BaseDataGoalPredicate *fact,
							  BaseDataVariableEnvironment *env,
							  unsigned int level)
{
  bool result = Unifiable(fact);
  if(result)
    cout << "Unifiable\n";
  else
    cout << "not Unifiable\n";
  BaseDataVariableEnvironment *newenv = NULL;
  if(result)
    {
      newenv = (BaseDataVariableEnvironment *) env->Clone();
      cout << "\n GetParameter Specs \n";
      ObjectNameClassPairs *factargs = fact->getParameterSpecs();
      ObjectNameClassPairs *goalargs = getParameterSpecs();

      cout << "\n Specs to compare\n";
      factargs->print(cout);
      cout << endl;
      goalargs->print(cout);
      cout << endl;

      ObjectNameClassPairs::iterator factarg;
      ObjectNameClassPairs::iterator goalarg = goalargs->begin();
      for(factarg=factargs->begin();
	  result && factarg != factargs->end();
	  factarg++)
	{
	  BaseDataSingleVariable fvar((*factarg).I,(*factarg).I,(*factarg).J,
				      level,fact->isFact());
	  BaseDataSingleVariable gvar((*goalarg).I,(*goalarg).I,(*goalarg).J,
				      level,isFact());
	  cout << "\n Unify Argument\n";
	  fvar.print(cout);
	  cout << endl;
	  gvar.print(cout);
	  cout << endl;
	  newenv = gvar.Unify(&fvar,newenv,level);
	  cout << "Environment after unify\n";
	  if(newenv != NULL)
	    newenv->print(cout);
	  else
	    cout << "nil";
	  cout << endl;
	  if(newenv == NULL)
	    result = false;
	  goalarg++;
	}
    }
  cout << "Final Environment after unify\n";
  if(newenv != NULL)
    newenv->print(cout);
  else
    cout << "nil";
  cout << endl;
  if(!result && newenv != NULL)
    {
      delete newenv;
      newenv = NULL;
    }
  return newenv;
}
/*F setPredicateName(name) . . . . . . . . . . . . . . . . . set name
**
**  DESCRIPTION
**     name: The name of the predicate
** 
**  REMARKS
**
*/
void BaseDataGoalPredicate::setPredicateName(String name)
{
  PredicateName = name;
}
/*F name = getPredicateName()  . . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    name: The name of the variables
**
**  REMARKS
**
*/
String BaseDataGoalPredicate::getPredicateName() const
{
  return PredicateName;
}
/*F ans = isFact()  . . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    ans: true if predicate is a fact (i.e. the variables are constants)
**
**  REMARKS
**
*/
bool BaseDataGoalPredicate::isFact() const
{
  return PConstant;
}
/*F ans = setAsFact()  . . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    sets up predicate as fact (i.e. the variables are constants)
**
**  REMARKS
**
*/
void BaseDataGoalPredicate::setAsFact()
{
  PConstant = true;
}
/*F ans = setAsFact()  . . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    sets up predicate as fact (i.e. the variables are constants)
**
**  REMARKS
**
*/
void BaseDataGoalPredicate::setAsRule()
{
  PConstant = false;
}

/*S DataGoalPredicateClass
 */
/*F DataGoalPredicateClass() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataGoalPredicateClass::DataGoalPredicateClass()
{
  Identification = PREDICATEGOAL_GOALPREDICATE_ID;
  NameTag = PREDICATEGOAL_GOALPREDICATE_NAME;
  SubClass = "GoalSpec";
  EncodeDecodeClass = NameTag;
} 
/*F DataGoalPredicateClass(data) . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataGoalPredicateClass::DataGoalPredicateClass(const DataGoalPredicateClass& data)
  : DataGoalSpecClass(data)
{
} 
 
/*F DataGoalPredicateClass(id,name,descr)  . . . . . . . . . . . . . . . constructor
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
DataGoalPredicateClass::DataGoalPredicateClass(const int id, 
				 const String& name,
				 const String& descr)
  : DataGoalSpecClass(id,name,descr)
{
  SubClass = "GoalSpec";
  EncodeDecodeClass = PREDICATEGOAL_GOALPREDICATE_NAME;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . . DataGoalPredicateClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataGoalPredicateClass::print(ostream& out) const
{
  DataGoalSpecClass::print(out);
  // the rest
       
       return out;
}
 
/*F in1 = Read(in)  . . . . . . . . . . . . . . . . . . . . . DataGoalPredicateClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataGoalPredicateClass, there is no further information.
**
**  REMARKS
**
*/
bool DataGoalPredicateClass::Read(istream& in, DataSetOfObjectsClass &set)
{
  bool result = DataGoalSpecClass::Read(in,set);

  return result;
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . . . DataGoalPredicateClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataGoalPredicateClass::CopyClone(Identify *  objc)
{
  DataGoalPredicateClass *objcfull = (DataGoalPredicateClass *) objc;
  *this = *objcfull;
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . . . DataGoalPredicateClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataGoalPredicateClass::Clone()
    {
      DataGoalPredicateClass* id = new DataGoalPredicateClass(*this);
      return (Identify *) id;
    }
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . . DataGoalPredicateClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataGoalPredicateClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataGoalSpecClass::EncodeThis(buffer);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . . DataGoalPredicateClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataGoalPredicateClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataGoalSpecClass::DecodeThis(buffer);
//  result = result && Decode(buffer,-----);

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
BaseDataObject * DataGoalPredicateClass::BaseDataObjectExample()
{ 
  return (BaseDataObject *) new BaseDataGoalPredicate();
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . DataGoalPredicateClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataGoalPredicateClass*& obj)
     {
     obj = new DataGoalPredicateClass;
     return obj->DecodeThis(buffer);
     }
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . BaseDataGoalPredicate
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataGoalPredicate*& obj)
     {
     obj = new BaseDataGoalPredicate;
     return obj->DecodeThis(buffer);
     }
/*S BaseDataSetOfGoalPredicates
 */ 
/*F BaseDataSetOfGoalPredicates()  . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataSetOfGoalPredicates::BaseDataSetOfGoalPredicates()
{
  Identification = PREDICATEGOAL_SETOFGOALS_ID;
  NameTag = PREDICATEGOAL_SETOFGOALS_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;

  String title(" --------------- Set of Goal Predicates --------------------\n");
  String delimitor("\n");
  GoalPredicates.setTitle(title);
  GoalPredicates.setDelimitor(delimitor);
  String stitle(" Predicate Names:\n");
  String sdelimitor("   ");
  GoalPredicateNames.ChangeTitle(stitle);
  GoalPredicateNames.ChangeDelimitor(sdelimitor);
} 
/*F BaseDataSetOfGoalPredicates(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataSetOfGoalPredicates::BaseDataSetOfGoalPredicates(const BaseDataSetOfGoalPredicates& data)
  : BaseDataObject(data),
    GoalPredicateNames(data.GoalPredicateNames),
    GoalPredicates(data.GoalPredicates)
{
}
/*F Read(in,objc) . . . . . . . . . . . . . . . . . .  Read in BaseDataSetOfGoalPredicates
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataSetOfGoalPredicates::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . . . . . . . .  Read in BaseDataSetOfGoalPredicates
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataSetOfGoalPredicates::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = BaseDataObject::Read(in,objc,name);
  DataSetOfGoalPredicatesClass * objclass = (DataSetOfGoalPredicatesClass *) objc;

  ObjectNameClassPairs clspairs;
  clspairs.Read(in);
  objclass->getStandard()->ReplaceObjectTypes(clspairs);

  result = result && GoalPredicates.Read(in,objclass->getStandard(),name);
  GoalPredicateNames = GoalPredicates.ListOfObjectNames();
  return result;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . .  BaseDataSetOfGoalPredicates
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataSetOfGoalPredicates::print(ostream& out) const
{
  BaseDataObject::print(out);
  GoalPredicates.print(out);
  out << endl;
  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . . . . .BaseDataSetOfGoalPredicates
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataSetOfGoalPredicates::Clone()
{
  BaseDataSetOfGoalPredicates *obj = new BaseDataSetOfGoalPredicates;
  obj->CopyClone(this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . . . . .BaseDataSetOfGoalPredicates
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataSetOfGoalPredicates::CopyClone(Identify * obj)
{
  BaseDataSetOfGoalPredicates *objfull = (BaseDataSetOfGoalPredicates *) obj;
  
  *this = *objfull;
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataSetOfGoalPredicates
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataSetOfGoalPredicates::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataObject::EncodeThis(buffer);
  result = result && GoalPredicateNames.EncodeThis(buffer);
  result = result && GoalPredicates.EncodeThis(buffer);
  //result = result && Encode(buffer,---);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataSetOfGoalPredicates
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataSetOfGoalPredicates::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataObject::DecodeThis(buffer);
  result = result && GoalPredicateNames.DecodeThis(buffer);
  result = result && GoalPredicates.DecodeThis(buffer);

  return result;
}
/*F ans = notEmpty()  . . . . . . . . . . . . . . BaseDataSetOfGoalPredicates
**
**  DESCRIPTION
**    ans: true if there are still predicates in the list
**
**  REMARKS
**
*/
bool BaseDataSetOfGoalPredicates::notEmpty()
{
  bool result = true;
  if(GoalPredicateNames.size() > 0)
    result = false;
  return result;
}
/*F   . . . . . . . . . . . . . . . .  BaseDataSetOfGoalPredicates
**
**  DESCRIPTION
**
**  REMARKS
**
*/
BaseDataGoalPredicate *BaseDataSetOfGoalPredicates::popPredicate()
{
  BaseDataGoalPredicate *goal;
  if(notEmpty())
    {
      String name = GoalPredicateNames.front();
      GoalPredicateNames.pop_front();
      goal = (BaseDataGoalPredicate *) GoalPredicates.GetObject(name);
      if(!(GoalPredicates.RemoveObject(name)))
	{
	goal = NULL;
	cerr << "Could not remove Predicate during popPredicate()\n";
	}
    }
  else
    goal = NULL;

  return goal;
}
/*F  names = getListOfPredicateNames()  . . . . . BaseDataSetOfGoalPredicates
**
**  DESCRIPTION
**    names: The set of predicate names
**
**  REMARKS
**
*/
ObjectList<String> BaseDataSetOfGoalPredicates:: getGoalPredicateNames()
{
  return GoalPredicateNames;
}
/*F ans = addGoalPredicateToFront(pred)  . . . . . . . . . . . . . . . .  BaseDataSetOfGoalPredicates
**
**  DESCRIPTION
**    pred: A goal predicate
**    ans: true if successful
**
**  REMARKS
**
*/
bool BaseDataSetOfGoalPredicates::addGoalPredicateToFront(BaseDataGoalPredicate *pred)
{
  String name = pred->NameTag;
  GoalPredicateNames.push_front(name);
  return GoalPredicates.AddObject(pred);
}
/*S DataSetOfGoalPredicatesClass
 */
/*F DataSetOfGoalPredicatesClass() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataSetOfGoalPredicatesClass::DataSetOfGoalPredicatesClass()
{
  Identification = PREDICATEGOAL_SETOFGOALS_ID;
  NameTag = PREDICATEGOAL_SETOFGOALS_NAME;
  SubClass = "Object";
  EncodeDecodeClass = NameTag;

  Classes = StandardAllowedClasses;
} 
/*F DataSetOfGoalPredicatesClass(data) . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataSetOfGoalPredicatesClass::DataSetOfGoalPredicatesClass(const DataSetOfGoalPredicatesClass& data)
  : DataObjectClass(data)
{
} 
 
/*F DataSetOfGoalPredicatesClass(id,name,descr)  . . . . . . . . . . . . . . . constructor
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
DataSetOfGoalPredicatesClass::DataSetOfGoalPredicatesClass(const int id, 
				 const String& name,
				 const String& descr)
  : DataObjectClass(id,name,descr)
{
  SubClass = "Object";
  EncodeDecodeClass = PREDICATEGOAL_SETOFGOALS_NAME;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . . DataSetOfGoalPredicatesClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataSetOfGoalPredicatesClass::print(ostream& out) const
{
  DataObjectClass::print(out);
  // the rest
       
       return out;
}
 
/*F in1 = Read(in)  . . . . . . . . . . . . . . . . . . . . . DataSetOfGoalPredicatesClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataSetOfGoalPredicatesClass, there is no further information.
**
**  REMARKS
**
*/
bool DataSetOfGoalPredicatesClass::Read(istream& in, DataSetOfObjectsClass &set)
{
  bool result = DataObjectClass::Read(in,set);

  return result;
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . . . DataSetOfGoalPredicatesClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataSetOfGoalPredicatesClass::CopyClone(Identify *  objc)
{
  DataSetOfGoalPredicatesClass *objcfull = (DataSetOfGoalPredicatesClass *) objc;
  *this = *objcfull;
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . . . DataSetOfGoalPredicatesClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataSetOfGoalPredicatesClass::Clone()
    {
      DataSetOfGoalPredicatesClass* id = new DataSetOfGoalPredicatesClass(*this);
      return (Identify *) id;
    }
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . . DataSetOfGoalPredicatesClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataSetOfGoalPredicatesClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataObjectClass::EncodeThis(buffer);
  // result = result && Encode(buffer,------);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . . DataSetOfGoalPredicatesClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataSetOfGoalPredicatesClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataObjectClass::DecodeThis(buffer);
//  result = result && Decode(buffer,-----);

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
BaseDataObject * DataSetOfGoalPredicatesClass::BaseDataObjectExample()
{ 
  return (BaseDataObject *) new BaseDataSetOfGoalPredicates();
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . DataSetOfGoalPredicatesClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataSetOfGoalPredicatesClass*& obj)
     {
     obj = new DataSetOfGoalPredicatesClass;
     return obj->DecodeThis(buffer);
     }
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . BaseDataSetOfGoalPredicates
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataSetOfGoalPredicates*& obj)
     {
     obj = new BaseDataSetOfGoalPredicates;
     return obj->DecodeThis(buffer);
     }
/*F getStandard() . . . . . . . . . . . . . . .  DataSetOfGoalPredicatesClass
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataSetOfObjectsClass *DataSetOfGoalPredicatesClass::getStandard()
{
  return Classes;
}
/*S BaseDataGoalPredicateEnvironment
 */ 
/*F BaseDataGoalPredicateEnvironment()  . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataGoalPredicateEnvironment::BaseDataGoalPredicateEnvironment()
{
  Identification = PREDICATEGOAL_GOALENV_ID;
  NameTag = PREDICATEGOAL_GOALENV_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;
} 
/*F BaseDataGoalPredicateEnvironment(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataGoalPredicateEnvironment::BaseDataGoalPredicateEnvironment(const BaseDataGoalPredicateEnvironment& data)
  : BaseDataSetOfGoalPredicates(data)
{
}
/*F Read(in,objc) . . . . . . . . . . . . . . . . . .  Read in BaseDataGoalPredicateEnvironment
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataGoalPredicateEnvironment::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . . . . . . . .  Read in BaseDataGoalPredicateEnvironment
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataGoalPredicateEnvironment::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = BaseDataSetOfGoalPredicates::Read(in,objc,name);
  
  return result;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . .  BaseDataGoalPredicateEnvironment
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataGoalPredicateEnvironment::print(ostream& out) const
{
  BaseDataSetOfGoalPredicates::print(out);
  // The rest

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . . . . .BaseDataGoalPredicateEnvironment
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataGoalPredicateEnvironment::Clone()
{
  BaseDataGoalPredicateEnvironment *obj = new BaseDataGoalPredicateEnvironment;
  obj->CopyClone(this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . . . . .BaseDataGoalPredicateEnvironment
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataGoalPredicateEnvironment::CopyClone(Identify * obj)
{
  BaseDataGoalPredicateEnvironment *objfull = (BaseDataGoalPredicateEnvironment *) obj;
  
  *this = *objfull;
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataGoalPredicateEnvironment
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataGoalPredicateEnvironment::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataSetOfGoalPredicates::EncodeThis(buffer);
  //result = result && ---.EncodeThis(buffer);
  //result = result && Encode(buffer,---);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataGoalPredicateEnvironment
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataGoalPredicateEnvironment::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataSetOfGoalPredicates::DecodeThis(buffer);
  // The rest

  return result;
}
 
 
/*S DataGoalPredicateEnvironmentClass
 */
/*F DataGoalPredicateEnvironmentClass() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataGoalPredicateEnvironmentClass::DataGoalPredicateEnvironmentClass()
{
  Identification = PREDICATEGOAL_GOALENV_ID;
  NameTag = PREDICATEGOAL_GOALENV_NAME;
  SubClass = "SetOfGoalPredicates";
  EncodeDecodeClass = NameTag;
} 
/*F DataGoalPredicateEnvironmentClass(data) . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataGoalPredicateEnvironmentClass::DataGoalPredicateEnvironmentClass(const DataGoalPredicateEnvironmentClass& data)
  : DataSetOfGoalPredicatesClass(data)
{
} 
 
/*F DataGoalPredicateEnvironmentClass(id,name,descr)  . . . . . . . . . . . . . . . constructor
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
DataGoalPredicateEnvironmentClass::DataGoalPredicateEnvironmentClass(const int id, 
				 const String& name,
				 const String& descr)
  : DataSetOfGoalPredicatesClass(id,name,descr)
{
  SubClass = PREDICATEGOAL_SETOFGOALS_NAME;
  EncodeDecodeClass = PREDICATEGOAL_GOALENV_NAME;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . . DataGoalPredicateEnvironmentClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataGoalPredicateEnvironmentClass::print(ostream& out) const
{
  DataSetOfGoalPredicatesClass::print(out);
  // the rest
       
       return out;
}
 
/*F in1 = Read(in)  . . . . . . . . . . . . . . . . . . . . . DataGoalPredicateEnvironmentClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataGoalPredicateEnvironmentClass, there is no further information.
**
**  REMARKS
**
*/
bool DataGoalPredicateEnvironmentClass::Read(istream& in, DataSetOfObjectsClass &set)
{
  bool result = DataSetOfGoalPredicatesClass::Read(in,set);

  return result;
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . . . DataGoalPredicateEnvironmentClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataGoalPredicateEnvironmentClass::CopyClone(Identify *  objc)
{
  DataGoalPredicateEnvironmentClass *objcfull = (DataGoalPredicateEnvironmentClass *) objc;
  *this = *objcfull;
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . . . DataGoalPredicateEnvironmentClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataGoalPredicateEnvironmentClass::Clone()
    {
      DataGoalPredicateEnvironmentClass* id = new DataGoalPredicateEnvironmentClass(*this);
      return (Identify *) id;
    }
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . . DataGoalPredicateEnvironmentClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataGoalPredicateEnvironmentClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataSetOfGoalPredicatesClass::EncodeThis(buffer);
  // result = result && Encode(buffer,------);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . . DataGoalPredicateEnvironmentClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataGoalPredicateEnvironmentClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataSetOfGoalPredicatesClass::DecodeThis(buffer);
//  result = result && Decode(buffer,-----);

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
BaseDataObject * DataGoalPredicateEnvironmentClass::BaseDataObjectExample()
{ 
  //cout << "Make GoalPredicateEnvironment Example\n";
  return (BaseDataObject *) new BaseDataGoalPredicateEnvironment();
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . DataGoalPredicateEnvironmentClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataGoalPredicateEnvironmentClass*& obj)
     {
     obj = new DataGoalPredicateEnvironmentClass;
     return obj->DecodeThis(buffer);
     }
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . BaseDataGoalPredicateEnvironment
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataGoalPredicateEnvironment*& obj)
     {
     obj = new BaseDataGoalPredicateEnvironment;
     return obj->DecodeThis(buffer);
     }
/*S BaseDataFactPredicateEnvironment
 */ 
/*F BaseDataFactPredicateEnvironment()  . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataFactPredicateEnvironment::BaseDataFactPredicateEnvironment()
{
  Identification = PREDICATEGOAL_FACTENV_ID;
  NameTag = PREDICATEGOAL_FACTENV_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;

  String title("List of Current Fact Names");
  String delimitor(" ");
  FactList.ChangeTitle(title);
  FactList.ChangeDelimitor(delimitor);
} 
/*F BaseDataFactPredicateEnvironment(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataFactPredicateEnvironment::BaseDataFactPredicateEnvironment(const BaseDataFactPredicateEnvironment& data)
  : BaseDataObject(data),
    FactList(data.FactList)
{
}
/*F Read(in,objc) . . . . . . . . . . . . . . . . . .  Read in BaseDataFactPredicateEnvironment
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataFactPredicateEnvironment::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . . . . . . . .  Read in BaseDataFactPredicateEnvironment
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataFactPredicateEnvironment::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = BaseDataObject::Read(in,objc,name);

  StreamObjectInput str(in,' ');

  String next = str.ReadNext();
  while(!(next == "END"))
    {
      FactList.AddObject(next);
      next = str.ReadNext();
    }

  return result;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . .  BaseDataFactPredicateEnvironment
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataFactPredicateEnvironment::print(ostream& out) const
{
  BaseDataObject::print(out);
  FactList.print(out);

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . . . . .BaseDataFactPredicateEnvironment
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataFactPredicateEnvironment::Clone()
{
  BaseDataFactPredicateEnvironment *obj = new BaseDataFactPredicateEnvironment;
  obj->CopyClone(this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . . . . .BaseDataFactPredicateEnvironment
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataFactPredicateEnvironment::CopyClone(Identify * obj)
{
  BaseDataFactPredicateEnvironment *objfull = (BaseDataFactPredicateEnvironment *) obj;
  
  *this = *objfull;
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataFactPredicateEnvironment
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataFactPredicateEnvironment::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataObject::EncodeThis(buffer);
  result = result && Encode(buffer,FactList);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataFactPredicateEnvironment
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataFactPredicateEnvironment::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataObject::DecodeThis(buffer);
  result = result && Decode(buffer,FactList);

  return result;
}
/*F ans = moreFacts() . . . . . . . . . . . . . . . . . are there facts left?
**
**  DESCRIPTION
**    ans: true if the fact list is not empty
**
**  REMARKS
**
*/
bool BaseDataFactPredicateEnvironment::moreFacts()
{
  return FactList.size();
}
/*F next = popNextFact()  . . . . . . . . . . . . . get next fact in the list
**
**  DESCRIPTION
**     next: The name of the next fact in the list
**
**     The next fact is retrieved and popped off the list
**
**  REMARKS
**
*/
String BaseDataFactPredicateEnvironment::popNextFact()
{
  String name = FactList.front();
  FactList.pop_front();
  return name;
}
/*F InitializeFacts(facts)  . . . . . . . . . . . .  set up the list of facts
**
**  DESCRIPTION
**     facts: The list of facts
**
**  REMARKS
**
*/
void BaseDataFactPredicateEnvironment::InitializeFacts(BaseDataSetOfGoalPredicates& facts)
{
  FactList = facts.getGoalPredicateNames();
}
 
/*S DataFactPredicateEnvironmentClass
 */
/*F DataFactPredicateEnvironmentClass() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataFactPredicateEnvironmentClass::DataFactPredicateEnvironmentClass()
{
  Identification = PREDICATEGOAL_FACTENV_ID;
  NameTag = PREDICATEGOAL_FACTENV_NAME;
  SubClass = "Object";
  EncodeDecodeClass = NameTag;
} 
/*F DataFactPredicateEnvironmentClass(data) . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataFactPredicateEnvironmentClass::DataFactPredicateEnvironmentClass(const DataFactPredicateEnvironmentClass& data)
  : DataObjectClass(data)
{
} 
 
/*F DataFactPredicateEnvironmentClass(id,name,descr)  . . . . . . . . . . . . . . . constructor
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
DataFactPredicateEnvironmentClass::DataFactPredicateEnvironmentClass(const int id, 
				 const String& name,
				 const String& descr)
  : DataObjectClass(id,name,descr)
{
  SubClass = "Object";
  EncodeDecodeClass = PREDICATEGOAL_FACTENV_NAME;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . . DataFactPredicateEnvironmentClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataFactPredicateEnvironmentClass::print(ostream& out) const
{
  DataObjectClass::print(out);
  // the rest
       
       return out;
}
 
/*F in1 = Read(in)  . . . . . . . . . . . . . . . . . . . . . DataFactPredicateEnvironmentClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataFactPredicateEnvironmentClass, there is no further information.
**
**  REMARKS
**
*/
bool DataFactPredicateEnvironmentClass::Read(istream& in, DataSetOfObjectsClass &set)
{
  bool result = DataObjectClass::Read(in,set);

  return result;
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . . . DataFactPredicateEnvironmentClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataFactPredicateEnvironmentClass::CopyClone(Identify *  objc)
{
  DataFactPredicateEnvironmentClass *objcfull = (DataFactPredicateEnvironmentClass *) objc;
  *this = *objcfull;
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . . . DataFactPredicateEnvironmentClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataFactPredicateEnvironmentClass::Clone()
    {
      DataFactPredicateEnvironmentClass* id = new DataFactPredicateEnvironmentClass(*this);
      return (Identify *) id;
    }
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . . DataFactPredicateEnvironmentClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataFactPredicateEnvironmentClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataObjectClass::EncodeThis(buffer);
  // result = result && Encode(buffer,------);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . . DataFactPredicateEnvironmentClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataFactPredicateEnvironmentClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataObjectClass::DecodeThis(buffer);
//  result = result && Decode(buffer,-----);

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
BaseDataObject * DataFactPredicateEnvironmentClass::BaseDataObjectExample()
{ 
  //cout << "Make FactPredicateEnvironment Example\n";
  return (BaseDataObject *) new BaseDataFactPredicateEnvironment();
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . DataFactPredicateEnvironmentClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataFactPredicateEnvironmentClass*& obj)
     {
     obj = new DataFactPredicateEnvironmentClass;
     return obj->DecodeThis(buffer);
     }
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . BaseDataFactPredicateEnvironment
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataFactPredicateEnvironment*& obj)
     {
     obj = new BaseDataFactPredicateEnvironment;
     return obj->DecodeThis(buffer);
     }

/*S BaseDataCurrentEnvironment
 */ 
/*F BaseDataCurrentEnvironment()  . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataCurrentEnvironment::BaseDataCurrentEnvironment()
{
  Identification = PREDICATEGOAL_CURRENTENV_ID;
  NameTag = PREDICATEGOAL_CURRENTENV_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;
} 
/*F BaseDataCurrentEnvironment(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataCurrentEnvironment::BaseDataCurrentEnvironment(const BaseDataCurrentEnvironment& data)
  : BaseDataObject(data),
    VarEnv(data.VarEnv),
    Goals(data.Goals),
    Facts(data.Facts)
{
}
/*F BaseDataCurrentEnvironment(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataCurrentEnvironment::BaseDataCurrentEnvironment(const BaseDataFactPredicateEnvironment& facts,
						       BaseDataGoalPredicate *goal)
  : Facts(facts)
{
  Goals.addGoalPredicateToFront(goal);
}
/*F BaseDataCurrentEnvironment(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataCurrentEnvironment::BaseDataCurrentEnvironment(const BaseDataFactPredicateEnvironment& facts,
						       const BaseDataGoalPredicateEnvironment& goals)
  : Goals(goals),
    Facts(facts)
    
{
}
/*F Read(in,objc) . . . . . . . . . . . . . . . . . .  Read in BaseDataCurrentEnvironment
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataCurrentEnvironment::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . . . . . . . .  Read in BaseDataCurrentEnvironment
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataCurrentEnvironment::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = BaseDataObject::Read(in,objc,name);
  DataCurrentEnvironmentClass *oclass = (DataCurrentEnvironmentClass *) objc;

  result = result && VarEnv.Read(in,oclass->getVarEnvClass(),name);
  result = result && Goals.Read(in,oclass->getGoalEnvClass(),name);
  result = result && Facts.Read(in,oclass->getFactEnvClass(),name);
  
  return result;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . .  BaseDataCurrentEnvironment
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataCurrentEnvironment::print(ostream& out) const
{
  BaseDataObject::print(out);
  VarEnv.print(out);
  Goals.print(out);
  Facts.print(out);

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . . . . .BaseDataCurrentEnvironment
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataCurrentEnvironment::Clone()
{
  BaseDataCurrentEnvironment *obj = new BaseDataCurrentEnvironment;
  obj->CopyClone(this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . . . . .BaseDataCurrentEnvironment
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataCurrentEnvironment::CopyClone(Identify * obj)
{
  BaseDataCurrentEnvironment *objfull = (BaseDataCurrentEnvironment *) obj;
  
  *this = *objfull;
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataCurrentEnvironment
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataCurrentEnvironment::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataObject::EncodeThis(buffer);
  result = result && VarEnv.EncodeThis(buffer);
  result = result && Goals.EncodeThis(buffer);
  result = result && Facts.EncodeThis(buffer);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataCurrentEnvironment
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataCurrentEnvironment::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataObject::DecodeThis(buffer);
  result = result && VarEnv.DecodeThis(buffer);
  result = result && Goals.DecodeThis(buffer);
  result = result && Facts.DecodeThis(buffer);

  return result;
}
/*F env = getVariableEnvironment()  . . . . . . . . . . . . . . . .  BaseDataCurrentEnvironment
**
**  DESCRIPTION
**    env: The pointer to the current variable environment
**
**  REMARKS
**
*/
BaseDataVariableEnvironment *BaseDataCurrentEnvironment::getVariableEnvironment()
{
  return &VarEnv;
}
/*F goal = popGoal()  . . . . . . . . . . . . . . . .  BaseDataCurrentEnvironment
**
**  DESCRIPTION
**    goal: The next goal predicate to resolve, NULL if no goal
**
**  REMARKS
**
*/
BaseDataGoalPredicate *BaseDataCurrentEnvironment::popGoal()
{
  if(Goals.notEmpty())
    {
      return Goals.popPredicate();
    }
  else
    {
      return NULL;
    }
}
/*F goal = popFactName()  . . . . . . . . . . . . . . . .  BaseDataCurrentEnvironment
**
**  DESCRIPTION
**    goal: The next fact name to resolve, empty string if no fact
**
**  REMARKS
**
*/
String BaseDataCurrentEnvironment::popFactName()
{
  if(!Facts.moreFacts())
    {
      String *name = new String("");
      return *name;
    }
  return Facts.popNextFact();
}
/*S DataCurrentEnvironmentClass
 */
/*F DataCurrentEnvironmentClass() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataCurrentEnvironmentClass::DataCurrentEnvironmentClass()
{
  Identification = PREDICATEGOAL_CURRENTENV_ID;
  NameTag = PREDICATEGOAL_CURRENTENV_NAME;
  SubClass = "Object";
  EncodeDecodeClass = NameTag;
} 
/*F DataCurrentEnvironmentClass(data) . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataCurrentEnvironmentClass::DataCurrentEnvironmentClass(const DataCurrentEnvironmentClass& data)
  : DataObjectClass(data),
    VarEnvClass(data.VarEnvClass),
    GoalEnvClass(data.GoalEnvClass),
    FactEnvClass(data.FactEnvClass)
{
} 
 
/*F DataCurrentEnvironmentClass(id,name,descr)  . . . . . . . . . . . . . . . constructor
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
DataCurrentEnvironmentClass::DataCurrentEnvironmentClass(const int id, 
				 const String& name,
				 const String& descr)
  : DataObjectClass(id,name,descr)
{
  SubClass = "Object";
  EncodeDecodeClass = PREDICATEGOAL_CURRENTENV_NAME;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . . DataCurrentEnvironmentClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataCurrentEnvironmentClass::print(ostream& out) const
{
  DataObjectClass::print(out);
       
  return out;
}
 
/*F in1 = Read(in)  . . . . . . . . . . . . . . . . . . . . . DataCurrentEnvironmentClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataCurrentEnvironmentClass, there is no further information.
**
**  REMARKS
**
*/
bool DataCurrentEnvironmentClass::Read(istream& in, DataSetOfObjectsClass &set)
{
  bool result = DataObjectClass::Read(in,set);
  VarEnvClass.Read(in,set);
  GoalEnvClass.Read(in,set);
  FactEnvClass.Read(in,set);

  return result;
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . . . DataCurrentEnvironmentClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataCurrentEnvironmentClass::CopyClone(Identify *  objc)
{
  DataCurrentEnvironmentClass *objcfull = (DataCurrentEnvironmentClass *) objc;
  *this = *objcfull;
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . . . DataCurrentEnvironmentClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataCurrentEnvironmentClass::Clone()
    {
      DataCurrentEnvironmentClass* id = new DataCurrentEnvironmentClass(*this);
      return (Identify *) id;
    }
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . . DataCurrentEnvironmentClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataCurrentEnvironmentClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataObjectClass::EncodeThis(buffer);
  result = result && VarEnvClass.EncodeThis(buffer);
  result = result && FactEnvClass.EncodeThis(buffer);
  result = result && GoalEnvClass.EncodeThis(buffer);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . . DataCurrentEnvironmentClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataCurrentEnvironmentClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataObjectClass::DecodeThis(buffer);
  result = result && VarEnvClass.DecodeThis(buffer);
  result = result && FactEnvClass.DecodeThis(buffer);
  result = result && GoalEnvClass.DecodeThis(buffer);

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
BaseDataObject * DataCurrentEnvironmentClass::BaseDataObjectExample()
{ 
  //cout << "Make CurrentEnvironment Example\n";
  return (BaseDataObject *) new BaseDataCurrentEnvironment();
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . DataCurrentEnvironmentClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataCurrentEnvironmentClass*& obj)
     {
     obj = new DataCurrentEnvironmentClass;
     return obj->DecodeThis(buffer);
     }
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . BaseDataCurrentEnvironment
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataCurrentEnvironment*& obj)
     {
     obj = new BaseDataCurrentEnvironment;
     return obj->DecodeThis(buffer);
     }
/*F env = getVarEnvClass() . . . . . . . . . . . . . . . BaseDataCurrentEnvironment
**
**  DESCRIPTION
**   env: The Variable Environment Class
**
**  REMARKS
**
*/
DataVariableEnvironmentClass *DataCurrentEnvironmentClass::getVarEnvClass()
{
  return &VarEnvClass;
}
/*F env = getGoalEnvClass() . . . . . . . . . . . . . . . BaseDataCurrentEnvironment
**
**  DESCRIPTION
**   env: The Goal Environment Class
**
**  REMARKS
**
*/
DataGoalPredicateEnvironmentClass *DataCurrentEnvironmentClass::getGoalEnvClass()
{
  return &GoalEnvClass;
}
/*F env = getFactEnvClass() . . . . . . . . . . . . . . . BaseDataCurrentEnvironment
**
**  DESCRIPTION
**   env: The Fact Environment Class
**
**  REMARKS
**
*/
DataFactPredicateEnvironmentClass *DataCurrentEnvironmentClass::getFactEnvClass()
{
  return &FactEnvClass;
}
/*S BaseDataTopLevelEnvironment
 */ 
/*F BaseDataTopLevelEnvironment()  . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataTopLevelEnvironment::BaseDataTopLevelEnvironment()
{
  Identification = PREDICATEGOAL_TOPLEVEL_ID;
  NameTag = PREDICATEGOAL_TOPLEVEL_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;
} 
/*F BaseDataTopLevelEnvironment(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataTopLevelEnvironment::BaseDataTopLevelEnvironment(const BaseDataTopLevelEnvironment& data)
  : BaseDataObject(data),
    Facts(data.Facts)
{
}
/*F Read(in,objc) . . . . . . . . . . . . . . . . . .  Read in BaseDataTopLevelEnvironment
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataTopLevelEnvironment::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . . . . . . . .  Read in BaseDataTopLevelEnvironment
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataTopLevelEnvironment::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = BaseDataObject::Read(in,objc,name);
  DataTopLevelEnvironmentClass *oclass = (DataTopLevelEnvironmentClass *) objc;

  StreamObjectInput file(in,' ');
  String factname = file.ReadNext();
  result = result && (factname == "FactTypes");
  ObjectNameClassPairs ncpairs;
  result = result && ncpairs.Read(in);
  result = result && ReplaceObjectTypes(ncpairs);
  factname = file.ReadNext();
  result = result && (factname == "Facts");
  result = result && Facts.Read(in,oclass->getFactClass(),factname);

  return result;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . .  BaseDataTopLevelEnvironment
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataTopLevelEnvironment::print(ostream& out) const
{
  BaseDataObject::print(out);
  Facts.print(out);

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . . . . .BaseDataTopLevelEnvironment
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataTopLevelEnvironment::Clone()
{
  BaseDataTopLevelEnvironment *obj = new BaseDataTopLevelEnvironment;
  obj->CopyClone(this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . . . . .BaseDataTopLevelEnvironment
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataTopLevelEnvironment::CopyClone(Identify * obj)
{
  BaseDataTopLevelEnvironment *objfull = (BaseDataTopLevelEnvironment *) obj;
  
  *this = *objfull;
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataTopLevelEnvironment
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataTopLevelEnvironment::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataObject::EncodeThis(buffer);
  result = result && Facts.EncodeThis(buffer);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataTopLevelEnvironment
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataTopLevelEnvironment::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataObject::DecodeThis(buffer);
  result = result && Facts.DecodeThis(buffer);

  return result;
}
/*S DataTopLevelEnvironmentClass
 */
/*F DataTopLevelEnvironmentClass() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataTopLevelEnvironmentClass::DataTopLevelEnvironmentClass()
{
  Identification = PREDICATEGOAL_TOPLEVEL_ID;
  NameTag = PREDICATEGOAL_TOPLEVEL_NAME;
  SubClass = "Object";
  EncodeDecodeClass = NameTag;
} 
/*F DataTopLevelEnvironmentClass(data) . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataTopLevelEnvironmentClass::DataTopLevelEnvironmentClass(const DataTopLevelEnvironmentClass& data)
  : DataObjectClass(data),
    FactClasses(data.FactClasses)
{
} 
 
/*F DataTopLevelEnvironmentClass(id,name,descr)  . . . . . . . . . . . . . . . constructor
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
DataTopLevelEnvironmentClass::DataTopLevelEnvironmentClass(const int id, 
				 const String& name,
				 const String& descr)
  : DataObjectClass(id,name,descr)
{
  SubClass = "Object";
  EncodeDecodeClass = PREDICATEGOAL_TOPLEVEL_NAME;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . . DataTopLevelEnvironmentClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataTopLevelEnvironmentClass::print(ostream& out) const
{
  DataObjectClass::print(out);
       
  return out;
}
 
/*F in1 = Read(in)  . . . . . . . . . . . . . . . . . . . . . DataTopLevelEnvironmentClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataTopLevelEnvironmentClass, there is no further information.
**
**  REMARKS
**
*/
bool DataTopLevelEnvironmentClass::Read(istream& in, DataSetOfObjectsClass &set)
{
  bool result = DataObjectClass::Read(in,set);

  return result;
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . . . DataTopLevelEnvironmentClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataTopLevelEnvironmentClass::CopyClone(Identify *  objc)
{
  DataTopLevelEnvironmentClass *objcfull = (DataTopLevelEnvironmentClass *) objc;
  *this = *objcfull;
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . . . DataTopLevelEnvironmentClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataTopLevelEnvironmentClass::Clone()
    {
      DataTopLevelEnvironmentClass* id = new DataTopLevelEnvironmentClass(*this);
      return (Identify *) id;
    }
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . . DataTopLevelEnvironmentClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataTopLevelEnvironmentClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataObjectClass::EncodeThis(buffer);
  result = result && FactClasses.EncodeThis(buffer);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . . DataTopLevelEnvironmentClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataTopLevelEnvironmentClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataObjectClass::DecodeThis(buffer);
  result = result && FactClasses.DecodeThis(buffer);

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
BaseDataObject * DataTopLevelEnvironmentClass::BaseDataObjectExample()
{ 
  return (BaseDataObject *) new BaseDataTopLevelEnvironment();
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . DataTopLevelEnvironmentClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataTopLevelEnvironmentClass*& obj)
     {
     obj = new DataTopLevelEnvironmentClass;
     return obj->DecodeThis(buffer);
     }
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . BaseDataTopLevelEnvironment
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataTopLevelEnvironment*& obj)
     {
     obj = new BaseDataTopLevelEnvironment;
     return obj->DecodeThis(buffer);
     }
/*F cls = getFactClass()  . . . . . . . . . . . . BaseDataTopLevelEnvironment
**
**  DESCRIPTION
**    cls: The Fact Environment Class
**
**  REMARKS
**
*/
DataFactPredicateEnvironmentClass *DataTopLevelEnvironmentClass::getFactClass()
{
  return &FactClasses;
}
/*S Utilities
 */
/*F InitialGoalObjectsEncodeDecodeRoutines()  . . . . . .  instance algorithm
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
extern void InitialPredicateGoalObjectsEncodeDecodeRoutines()
{
  bool (*toproutine)(CommBuffer&,Identify*&);

  bool (*rout1)(CommBuffer&,DataSingleVariableClass*&) = TopDecode;
  toproutine = rout1;
  SingleDecodeRoutine p1(PREDICATEGOAL_SINGLEVARIABLE_NAME,toproutine);
  (*SetOfEncodeDecodeRoutines)[p1.StructureName] = p1;
  
  String s11("Object.");
  String s111(PREDICATEGOAL_SINGLEVARIABLE_NAME);
  s11.AppendToEnd(s111);
  bool (*rout11)(CommBuffer&,BaseDataSingleVariable*&) = TopDecode;
  toproutine = rout11;
  SingleDecodeRoutine p11(s11,toproutine);
  (*SetOfEncodeDecodeRoutines)[p11.StructureName] = p11;
  
  bool (*rout2)(CommBuffer&,DataVariableAssignmentClass*&) = TopDecode;
  toproutine = rout2;
  SingleDecodeRoutine p2(PREDICATEGOAL_VARIABLEASSIGNMENT_NAME,toproutine);
  (*SetOfEncodeDecodeRoutines)[p2.StructureName] = p2;
  
  String s22("Object.");
  String s222(PREDICATEGOAL_VARIABLEASSIGNMENT_NAME);
  s22.AppendToEnd(s222);
  bool (*rout22)(CommBuffer&,BaseDataVariableAssignment*&) = TopDecode;
  toproutine = rout22;
  SingleDecodeRoutine p22(s22,toproutine);
  (*SetOfEncodeDecodeRoutines)[p22.StructureName] = p22;
  
  bool (*rout3)(CommBuffer&,DataVariableEnvironmentClass*&) = TopDecode;
  toproutine = rout3;
  SingleDecodeRoutine p3(PREDICATEGOAL_VARIABLEENVIRONMENT_NAME,toproutine);
  (*SetOfEncodeDecodeRoutines)[p3.StructureName] = p3;
  
  String s33("Object.");
  String s333(PREDICATEGOAL_VARIABLEENVIRONMENT_NAME);
  s33.AppendToEnd(s333);
  bool (*rout33)(CommBuffer&,BaseDataVariableEnvironment*&) = TopDecode;
  toproutine = rout33;
  SingleDecodeRoutine p33(s33,toproutine);
  (*SetOfEncodeDecodeRoutines)[p33.StructureName] = p33;
  
  bool (*rout4)(CommBuffer&,DataGoalPredicateClass*&) = TopDecode;
  toproutine = rout4;
  SingleDecodeRoutine p4(PREDICATEGOAL_GOALPREDICATE_NAME,toproutine);
  (*SetOfEncodeDecodeRoutines)[p4.StructureName] = p4;
  
  String s44("Object.");
  String s444(PREDICATEGOAL_GOALPREDICATE_NAME);
  s44.AppendToEnd(s444);
  bool (*rout44)(CommBuffer&,BaseDataGoalPredicate*&) = TopDecode;
  toproutine = rout44;
  SingleDecodeRoutine p44(s44,toproutine);
  (*SetOfEncodeDecodeRoutines)[p44.StructureName] = p44;

  bool (*rout5)(CommBuffer&,DataSetOfGoalPredicatesClass*&) = TopDecode;
  toproutine = rout5;
  SingleDecodeRoutine p5(PREDICATEGOAL_SETOFGOALS_NAME,toproutine);
  (*SetOfEncodeDecodeRoutines)[p5.StructureName] = p5;
  
  String s55("Object.");
  String s555(PREDICATEGOAL_SETOFGOALS_NAME);
  s55.AppendToEnd(s555);
  bool (*rout55)(CommBuffer&,BaseDataSetOfGoalPredicates*&) = TopDecode;
  toproutine = rout55;
  SingleDecodeRoutine p55(s55,toproutine);
  (*SetOfEncodeDecodeRoutines)[p55.StructureName] = p55;
 
  bool (*rout6)(CommBuffer&,DataFactPredicateEnvironmentClass*&) = TopDecode;
  toproutine = rout6;
  SingleDecodeRoutine p6(PREDICATEGOAL_FACTENV_NAME,toproutine);
  (*SetOfEncodeDecodeRoutines)[p6.StructureName] = p6;
  
  String s66("Object.");
  String s666(PREDICATEGOAL_FACTENV_NAME);
  s55.AppendToEnd(s666);
  bool (*rout66)(CommBuffer&,BaseDataFactPredicateEnvironment*&) = TopDecode;
  toproutine = rout66;
  SingleDecodeRoutine p66(s66,toproutine);
  (*SetOfEncodeDecodeRoutines)[p66.StructureName] = p66;

  bool (*rout7)(CommBuffer&,DataGoalPredicateEnvironmentClass*&) = TopDecode;
  toproutine = rout7;
  SingleDecodeRoutine p7(PREDICATEGOAL_GOALENV_NAME,toproutine);
  (*SetOfEncodeDecodeRoutines)[p7.StructureName] = p7;
  
  String s77("Object.");
  String s777(PREDICATEGOAL_GOALENV_NAME);
  s55.AppendToEnd(s777);
  bool (*rout77)(CommBuffer&,BaseDataGoalPredicateEnvironment*&) = TopDecode;
  toproutine = rout77;
  SingleDecodeRoutine p77(s77,toproutine);
  (*SetOfEncodeDecodeRoutines)[p77.StructureName] = p77;

  bool (*rout8)(CommBuffer&,DataCurrentEnvironmentClass*&) = TopDecode;
  toproutine = rout8;
  SingleDecodeRoutine p8(PREDICATEGOAL_CURRENTENV_NAME,toproutine);
  (*SetOfEncodeDecodeRoutines)[p8.StructureName] = p8;
  
  String s88("Object.");
  String s888(PREDICATEGOAL_CURRENTENV_NAME);
  s55.AppendToEnd(s888);
  bool (*rout88)(CommBuffer&,BaseDataCurrentEnvironment*&) = TopDecode;
  toproutine = rout88;
  SingleDecodeRoutine p88(s88,toproutine);
  (*SetOfEncodeDecodeRoutines)[p88.StructureName] = p88;

  bool (*rout9)(CommBuffer&,DataTopLevelEnvironmentClass*&) = TopDecode;
  toproutine = rout9;
  SingleDecodeRoutine p9(PREDICATEGOAL_TOPLEVEL_NAME,toproutine);
  (*SetOfEncodeDecodeRoutines)[p9.StructureName] = p9;
  
  String s99("Object.");
  String s999(PREDICATEGOAL_TOPLEVEL_NAME);
  s55.AppendToEnd(s999);
  bool (*rout99)(CommBuffer&,BaseDataTopLevelEnvironment*&) = TopDecode;
  toproutine = rout99;
  SingleDecodeRoutine p99(s99,toproutine);
  (*SetOfEncodeDecodeRoutines)[p99.StructureName] = p99;

}
/*F AddGoalObjectsClasses(set)  . . . . . . . . . . . . . add classes to list
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
void AddPredicateObjectsClasses(DataSetOfObjectsClass& set)
{
  String vardescr("The Single Goal Predicate Specification");
  String assigndescr("The Goal Predicate Variable Assignment Specification");
  String envdescr("The Goal Predicate Variable Environment Specification");
  String preddescr("The Goal Predicate Specification");
  String setpreddescr("The Set of Goal Predicates Specification");
  String factenv("The list of Current Fact Names");
  String goalenv("The list of Goals to be resolved");
  String curenv("The Current Environment");
  String topenv("The Top Level Environment");
  
  DataSingleVariableClass varclass(PREDICATEGOAL_SINGLEVARIABLE_ID,
				   PREDICATEGOAL_SINGLEVARIABLE_NAME,
				   vardescr);
  DataVariableAssignmentClass assignclass(PREDICATEGOAL_VARIABLEASSIGNMENT_ID,
					  PREDICATEGOAL_VARIABLEASSIGNMENT_NAME,
					  assigndescr);
  DataVariableEnvironmentClass envclass(PREDICATEGOAL_VARIABLEENVIRONMENT_ID,
					PREDICATEGOAL_VARIABLEENVIRONMENT_NAME,
					envdescr);
  
  DataGoalPredicateClass predclass(PREDICATEGOAL_GOALPREDICATE_ID,
					PREDICATEGOAL_GOALPREDICATE_NAME,
					preddescr);
  
  DataSetOfGoalPredicatesClass setpredclass(PREDICATEGOAL_SETOFGOALS_ID,
					PREDICATEGOAL_SETOFGOALS_NAME,
					setpreddescr);
  DataFactPredicateEnvironmentClass factenvclass(PREDICATEGOAL_FACTENV_ID,
						 PREDICATEGOAL_FACTENV_NAME,
						 factenv);
  DataGoalPredicateEnvironmentClass goalenvclass(PREDICATEGOAL_GOALENV_ID,
						 PREDICATEGOAL_GOALENV_NAME,
						 goalenv);
  DataCurrentEnvironmentClass curenvclass(PREDICATEGOAL_CURRENTENV_ID,
						 PREDICATEGOAL_CURRENTENV_NAME,
						 curenv);
  DataTopLevelEnvironmentClass topenvclass(PREDICATEGOAL_GOALENV_ID,
						 PREDICATEGOAL_GOALENV_NAME,
						 topenv);
  
  set.AddObjectClass(varclass);
  set.AddObjectClass(assignclass);
  set.AddObjectClass(envclass);
  set.AddObjectClass(predclass);
  set.AddObjectClass(setpredclass);
  set.AddObjectClass(factenvclass);
  set.AddObjectClass(goalenvclass);
  set.AddObjectClass(curenvclass);
  set.AddObjectClass(topenvclass);
}
