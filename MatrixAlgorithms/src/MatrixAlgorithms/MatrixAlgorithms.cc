/*  FILE     MatrixAlgorithms.cc
**  PACKAGE  MatrixAlgorithms
**  AUTHOR   Edward S. Blurock
**
**  CONTENT
**    Exported functions for the "MatrixAlgorithms" package.
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
#include "MatrixAlgorithms.hh"

/*S BaseDataMatrixCluster
 */ 
/*F BaseDataMatrixCluster()  . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataMatrixCluster::BaseDataMatrixCluster()
{
  Identification = MATALGORITHMS_CLUSTER_ID;
  NameTag = MATALGORITHMS_CLUSTER_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;
} 
/*F BaseDataMatrixCluster(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataMatrixCluster::BaseDataMatrixCluster(const BaseDataMatrixCluster& data)
  : BaseDataAlgorithmOperation(data)
{
}
 
/*F Read(in,objc) . . . . . . . . . . . . . . . . . .  Read in BaseDataMatrixCluster
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataMatrixCluster::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . . . . . . . .  Read in BaseDataMatrixCluster
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataMatrixCluster::Read(istream& in, DataObjectClass* objc, const String& name)
{
  return BaseDataAlgorithmOperation::Read(in,objc,name);
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . .  BaseDataMatrixCluster
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataMatrixCluster::print(ostream& out) const
{
  BaseDataAlgorithmOperation::print(out);
  

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . . . . .BaseDataMatrixCluster
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataMatrixCluster::Clone()
{
  BaseDataMatrixCluster *obj = new BaseDataMatrixCluster;
  obj->CopyClone(this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . . . . .BaseDataMatrixCluster
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataMatrixCluster::CopyClone(Identify * obj)
{
  BaseDataMatrixCluster *objc = (BaseDataMatrixCluster *) obj;
  *this = *objc;
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataMatrixCluster
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataMatrixCluster::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataAlgorithmOperation::EncodeThis(buffer);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataMatrixCluster
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataMatrixCluster::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataAlgorithmOperation::DecodeThis(buffer);

  return result;
}
/*S DataMatrixClusterClass
 */
/*F DataMatrixClusterClass() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataMatrixClusterClass::DataMatrixClusterClass()
{
  NameTag =   MATALGORITHMS_CLUSTER_NAME;
  Identification = MATALGORITHMS_CLUSTER_ID;
  SubClass = "AlgorithmOperation";
  EncodeDecodeClass = "MatrixCluster";
} 
/*F DataMatrixClusterClass(data) . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataMatrixClusterClass::DataMatrixClusterClass(const DataMatrixClusterClass& data)
  : DataAlgorithmOperationClass(data)
{
} 
 
/*F DataMatrixClusterClass(id,name,descr)  . . . . . . . . . . . . . . . constructor
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
DataMatrixClusterClass::DataMatrixClusterClass(const int id, 
                                               const String& name,
                                               const String& descr)
  : DataAlgorithmOperationClass(id,name,descr)
{
  SubClass = "AlgorithmOperation";
  EncodeDecodeClass = "MatrixCluster";
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . . DataMatrixClusterClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataMatrixClusterClass::print(ostream& out) const
{
  DataAlgorithmOperationClass::print(out);
  out << NameTag << "  ";
  // the rest
           
       return out;
}
 
/*F in1 = Read(in,set)  . . . . . . . . . . . . . . . . . . . . . DataMatrixClusterClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataMatrixClusterClass, there is no further information.
**
**  REMARKS
**
*/
bool DataMatrixClusterClass::Read(istream& in, SetOfDataObjectClasses& set)
{
  return DataAlgorithmOperationClass::Read(in,set);
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . . . DataMatrixClusterClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataMatrixClusterClass::CopyClone(Identify *  objc)
{
  DataMatrixClusterClass *objc = (DataMatrixClusterClass *) obj;
  *this = *objc;
}
 
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . . . DataMatrixClusterClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataMatrixClusterClass::Clone()
{
  DataMatrixClusterClass* id = new DataMatrixClusterClass(*this);
  return (Identify *) id;
}
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . . DataMatrixClusterClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataMatrixClusterClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataAlgorithmOperationClass::EncodeThis(buffer);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . . DataMatrixClusterClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataMatrixClusterClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataAlgorithmOperationClass::DecodeThis(buffer);

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
BaseDataMatrixCluster * DataMatrixClusterClass::BaseDataObjectExample()
{ 
  return (BaseDataMatrixCluster *) new BaseDataMatrixCluster();
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . DataMatrixClusterClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataMatrixClusterClass*& obj)
{
  obj = new DataMatrixClusterClass;
  return obj->DecodeThis(buffer);
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . BaseDataMatrixCluster
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataMatrixCluster*& obj)
{
  obj = new BaseDataMatrixCluster;
  return obj->DecodeThis(buffer);
}
