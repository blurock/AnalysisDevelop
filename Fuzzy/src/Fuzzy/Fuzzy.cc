/*  FILE     Fuzzy.cc
**  PACKAGE  Fuzzy
**  AUTHOR   Harald Wahl
**
**  CONTENT
**    Exported functions for the "Fuzzy" package.
**
**  REFERENCES
**
**  COPYRIGHT (C) 1997 Edward S. Blurock
*/

 
/*I  . . . INCLUDES  . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/
#include "CoreDataObjects.hh"
#include "LogicalObjects.hh"
#include "Fuzzy.hh"



/*S BaseDataFuzzy
 */ 
/*F BaseDataFuzzy()  . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataFuzzy::BaseDataFuzzy()
{
  Identification = FUZZY_BASE_ID;
  NameTag = FUZZY_BASE_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;
} 
/*F BaseDataFuzzy(data)  . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataFuzzy::BaseDataFuzzy(const BaseDataFuzzy& data)
  : BaseDataLogical(data)
{
}
 
/*F Read(in,objc) . . . . . . . . . . . . . . . .  Read in BaseDataFuzzy
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataFuzzy::Read(istream& in, DataObjectClass* objc)
{
  bool result = BaseDataLogical::Read(in,objc);
  
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  String val = str.ReadNext();
  SetValue(val.ToFloat());
  
  return result;
}
/*F Read(in,objc,name)  . . . . . . . . . . . . .  Read in BaseDataFuzzy
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataFuzzy::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = BaseDataLogical::Read(in,objc,name);

  StreamObjectInput str(in,' ');

  String val = str.ReadNext();
  SetValue(val.ToFloat());
  
  return result;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . .  BaseDataFuzzy
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataFuzzy::print(ostream& out) const
{
  BaseDataLogical::print(out);
  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . .  BaseDataFuzzy
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataFuzzy::Clone()
{
  BaseDataFuzzy *obj = new BaseDataFuzzy;
  obj->CopyClone(this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . .  BaseDataFuzzy
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataFuzzy::CopyClone(Identify * obj)
{
  BaseDataFuzzy *objfull = (BaseDataFuzzy *) obj;
  
  *this = *objfull;
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . .  BaseDataFuzzy
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataFuzzy::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataLogical::EncodeThis(buffer);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . .  BaseDataFuzzy
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataFuzzy::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataLogical::DecodeThis(buffer);

  return result;
}
/*F ans = WriteAsLine(out,objc) . . . . . . . . . . . . . . .  BaseDataObject
**
**  DESCRIPTION
**    out: The output stream
**    objc: The class of the object
**    ans: true if successful
**
**    This writes out the object one one line
**
**  REMARKS
**
*/
bool BaseDataFuzzy::WriteAsLine(ostream& out, DataObjectClass *objc)
{
  bool result = BaseDataLogical::WriteAsLine(out,objc);
  out << GetValue() << endl;  
  return result;
}
/*F ans = WriteAsASCII(out,objc)  . . . . . . . . . . . . . .  BaseDataObject
**
**  DESCRIPTION
**    out: The output stream
**    objc: The class of the object
**    ans: true if successful
**
**    This writes out the object as complement to input
**
**  REMARKS
**
*/
bool BaseDataFuzzy::WriteAsASCII(ostream& out, DataObjectClass* objc)
{
  bool result = BaseDataLogical::WriteAsASCII(out,objc);
  out << GetValue() << " ";
  return result;
}
/*F ans = WriteAsLatex(out,objc)  . . . . . . . . . . . . . .  BaseDataObject
**
**  DESCRIPTION
**    out: The output stream
**    objc: The class of the object
**    ans: true if successful
**
**    This writes out the object prepared for latex
**
**  REMARKS
**
*/
bool BaseDataFuzzy::WriteAsLatex(ostream& out, DataObjectClass *objc)
{
  bool result = BaseDataLogical::WriteAsLatex(out,objc);
  out << "$ " << GetValue();
  out << " $ \\\\" << endl;
  
  return result;
}
/*F AND(val)  . . . . . . . . . . . . . . . . . . . . . . . . BaseDataFuzzy
**
**  DESCRIPTION
**    val: The first boolean 
**    and: The AND(val,Value) as min(val,Value)
**    
**  REMARKS
**
*/
void BaseDataFuzzy::AND(const BaseDataFuzzy& val)
{
  // TODO Fuzzy AND
  // Value = val.Value * Value
}
/*F OR(val) . . . . . . . . . . . . . . . . . . . . . . . . . BaseDataFuzzy
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
void BaseDataFuzzy::OR(const BaseDataFuzzy& val)
{
  // TODO Fuzzy OR
  // Value = Value + val.Value -  Value * val.Value;
}
/*F NOT() . . . . . . . . . . . . . . . . . . . . . . . . . . BaseDataFuzzy
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
void BaseDataFuzzy::NOT()
{
  // TODO Fuzzy NOT
  // Value = 1.0 - Value;
}
 

/*S DataFuzzyClass
 */
/*F DataFuzzyClass() . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataFuzzyClass::DataFuzzyClass()
{
  Identification = FUZZY_BASE_ID;
  NameTag = FUZZY_BASE_NAME;
  SubClass = LOGICAL_BASE_NAME;
  EncodeDecodeClass = NameTag;
} 
/*F DataFuzzyClass(data) . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataFuzzyClass::DataFuzzyClass(const DataFuzzyClass& data)
  : DataLogicalClass(data)
{
} 
 
/*F DataFuzzyClass(id,name,descr)  . . . . . . . . . . . . . constructor
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
DataFuzzyClass::DataFuzzyClass(const int id, 
                                         const String& name,
                                         const String& descr)
  : DataLogicalClass(id,name,descr)
{
  EncodeDecodeClass = name;
  SubClass = LOGICAL_BASE_NAME;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . DataFuzzyClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataFuzzyClass::print(ostream& out) const
{
  DataLogicalClass::print(out);
  return out;
}
 
/*F in1 = Read(in,set)  . . . . . . . . . . . . . . . . . DataFuzzyClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**    set: The set of standard classes
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataFuzzyClass, there is no further information.
**
**  REMARKS
**
*/
bool DataFuzzyClass::Read(istream& in, DataSetOfObjectsClass& set)
{
  bool result = DataLogicalClass::Read(in,set);

  return result;
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . DataFuzzyClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataFuzzyClass::CopyClone(Identify *  objc)
{
  DataFuzzyClass *objcfull = (DataFuzzyClass*) objc;
      
  *this = *objcfull;
}
 
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . DataFuzzyClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataFuzzyClass::Clone()
{
  DataFuzzyClass* id = new DataFuzzyClass(*this);
  return (Identify *) id;
}
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . DataFuzzyClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataFuzzyClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataLogicalClass::EncodeThis(buffer);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . DataFuzzyClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataFuzzyClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataLogicalClass::DecodeThis(buffer);

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
BaseDataObject * DataFuzzyClass::BaseDataObjectExample()
{ 
  //cout << "Make Fuzzy Example\n";
  return (BaseDataObject *) new BaseDataFuzzy();
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . DataFuzzyClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataFuzzyClass*& obj)
{
  obj = new DataFuzzyClass;
  return obj->DecodeThis(buffer);
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . .  BaseDataFuzzy
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataFuzzy*& obj)
{
  obj = new BaseDataFuzzy;
  return obj->DecodeThis(buffer);
}


/*S Utitilies
 */
 
/*F InitialSetOfLogicalEncodeDecodeRoutines() . . . . . . . . set of routines
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
extern void InitialSetOfFuzzyEncodeDecodeRoutines()
{
  EncodeDecodeRegisterClass(DataFuzzyClass,BaseDataFuzzy,FUZZY_BASE_NAME);
}

/*F AddFuzzyClasses(set)  . . . . . . . . . .  add to DataSetOfObjectsClass
**
**  DESCRIPTION
**    set: The set of classes of objects to add the numeric classes to
**
**  REMARKS
**
*/
void AddFuzzyClasses(DataSetOfObjectsClass& set)
{
  String fuzdescr("Fuzzy Base Class");
  
  DataFuzzyClass fuzclass(FUZZY_BASE_ID,FUZZY_BASE_NAME,fuzdescr);
  
  set.AddObjectClass(fuzclass);
}

