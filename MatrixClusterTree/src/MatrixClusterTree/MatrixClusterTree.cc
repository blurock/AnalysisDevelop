/*  FILE     MatrixClusterTree.cc
**  PACKAGE  MatrixClusterTree
**  AUTHOR   Edward S. Blurock
**
**  CONTENT
**    Exported functions for the "MatrixClusterTree" package.
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
#include "InstanceAlgorithms.hh"
#include "PredicateObjects.hh"
#include "EvaluationTree.hh"
#include "ClusterTree.hh"
#include "FullSetCluster.hh"
#include "MatrixClusterTree.hh"

/*S BaseDataMatrixClusterTree
 */ 
/*F BaseDataMatrixClusterTree()  . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataMatrixClusterTree::BaseDataMatrixClusterTree()
{
  Identification = _ID;
  NameTag = _NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;
} 
/*F BaseDataMatrixClusterTree(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataMatrixClusterTree::BaseDataMatrixClusterTree(const BaseDataMatrixClusterTree& data)
  : BaseDataDivisiveClusterTree(data)
{
}
/*F Read(in,objc) . . . . . . . . . . . . . . . . . .  Read in BaseDataMatrixClusterTree
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataMatrixClusterTree::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . . . . . . . .  Read in BaseDataMatrixClusterTree
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataMatrixClusterTree::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = BaseDataDivisiveClusterTree::Read(in,objc,name);
  
  return result;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . .  BaseDataMatrixClusterTree
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataMatrixClusterTree::print(ostream& out) const
{
  BaseDataDivisiveClusterTree::print(out);
  // The rest

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . . . . .BaseDataMatrixClusterTree
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataMatrixClusterTree::Clone()
{
  BaseDataMatrixClusterTree *obj = new BaseDataMatrixClusterTree;
  obj->CopyClone(this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . . . . .BaseDataMatrixClusterTree
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataMatrixClusterTree::CopyClone(Identify * obj)
{
  BaseDataMatrixClusterTree *objfull = (BaseDataMatrixClusterTree *) obj;
  
  *this = *objfull;
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataMatrixClusterTree
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataMatrixClusterTree::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataDivisiveClusterTree::EncodeThis(buffer);
  //result = result && ---.EncodeThis(buffer);
  //result = result && Encode(buffer,---);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataMatrixClusterTree
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataMatrixClusterTree::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataDivisiveClusterTree::DecodeThis(buffer);
  // The rest

  return result;
}
 
 
/*S DataMatrixClusterTreeClass
 */
/*F DataMatrixClusterTreeClass() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataMatrixClusterTreeClass::DataMatrixClusterTreeClass()
{
  Identification = _ID;
  NameTag = _NAME;
  SubClass = "DivisiveClusterTree";
  EncodeDecodeClass = NameTag;
} 
/*F DataMatrixClusterTreeClass(data) . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataMatrixClusterTreeClass::DataMatrixClusterTreeClass(const DataMatrixClusterTreeClass& data)
  : DataDivisiveClusterTreeClass(data)
{
} 
 
/*F DataMatrixClusterTreeClass(id,name,descr)  . . . . . . . . . . . . . . . constructor
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
DataMatrixClusterTreeClass::DataMatrixClusterTreeClass(const int id, 
				 const String& name,
				 const String& descr)
  : DataDivisiveClusterTreeClass(id,name,descr)
{
  SubClass = "DivisiveClusterTree";
  EncodeDecodeClass = "MatrixClusterTree";
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . . DataMatrixClusterTreeClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataMatrixClusterTreeClass::print(ostream& out) const
{
  DataDivisiveClusterTreeClass::print(out);
  // the rest
       
       return out;
}
 
/*F in1 = Read(in)  . . . . . . . . . . . . . . . . . . . . . DataMatrixClusterTreeClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataMatrixClusterTreeClass, there is no further information.
**
**  REMARKS
**
*/
bool DataMatrixClusterTreeClass::Read(istream& in, DataSetOfObjectsClass &set)
{
  bool result = DataDivisiveClusterTreeClass::Read(in,set);

  return result;
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . . . DataMatrixClusterTreeClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataMatrixClusterTreeClass::CopyClone(Identify *  objc)
{
  DataMatrixClusterTreeClass *objcfull = (DataMatrixClusterTreeClass *) objc;
  *this = *objcfull;
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . . . DataMatrixClusterTreeClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataMatrixClusterTreeClass::Clone()
    {
      DataMatrixClusterTreeClass* id = new DataMatrixClusterTreeClass(*this);
      return (Identify *) id;
    }
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . . DataMatrixClusterTreeClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataMatrixClusterTreeClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataDivisiveClusterTreeClass::EncodeThis(buffer);
  // result = result && Encode(buffer,------);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . . DataMatrixClusterTreeClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataMatrixClusterTreeClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataDivisiveClusterTreeClass::DecodeThis(buffer);
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
BaseDataObject * DataMatrixClusterTreeClass::BaseDataObjectExample()
{ 
  //cout << "Make MatrixClusterTree Example\n";
  return (BaseDataObject *) new BaseDataMatrixClusterTree();
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . DataMatrixClusterTreeClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataMatrixClusterTreeClass*& obj)
     {
     obj = new DataMatrixClusterTreeClass;
     return obj->DecodeThis(buffer);
     }
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . BaseDataMatrixClusterTree
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataMatrixClusterTree*& obj)
     {
     obj = new BaseDataMatrixClusterTree;
     return obj->DecodeThis(buffer);
     }
/*S BaseDataMatrixClusterNode
 */ 
/*F BaseDataMatrixClusterNode()  . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataMatrixClusterNode::BaseDataMatrixClusterNode()
{
  Identification = _ID;
  NameTag = _NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;
} 
/*F BaseDataMatrixClusterNode(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataMatrixClusterNode::BaseDataMatrixClusterNode(const BaseDataMatrixClusterNode& data)
  : BaseDataDivisiveClusterNode(data)
{
}
/*F Read(in,objc) . . . . . . . . . . . . . . . . . .  Read in BaseDataMatrixClusterNode
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataMatrixClusterNode::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . . . . . . . .  Read in BaseDataMatrixClusterNode
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataMatrixClusterNode::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = BaseDataDivisiveClusterNode::Read(in,objc,name);
  
  return result;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . .  BaseDataMatrixClusterNode
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataMatrixClusterNode::print(ostream& out) const
{
  BaseDataDivisiveClusterNode::print(out);
  // The rest

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . . . . .BaseDataMatrixClusterNode
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataMatrixClusterNode::Clone()
{
  BaseDataMatrixClusterNode *obj = new BaseDataMatrixClusterNode;
  obj->CopyClone(this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . . . . .BaseDataMatrixClusterNode
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataMatrixClusterNode::CopyClone(Identify * obj)
{
  BaseDataMatrixClusterNode *objfull = (BaseDataMatrixClusterNode *) obj;
  
  *this = *objfull;
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataMatrixClusterNode
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataMatrixClusterNode::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataDivisiveClusterNode::EncodeThis(buffer);
  //result = result && ---.EncodeThis(buffer);
  //result = result && Encode(buffer,---);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataMatrixClusterNode
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataMatrixClusterNode::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataDivisiveClusterNode::DecodeThis(buffer);
  // The rest

  return result;
}
 
 
/*S DataMatrixClusterNodeClass
 */
/*F DataMatrixClusterNodeClass() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataMatrixClusterNodeClass::DataMatrixClusterNodeClass()
{
  Identification = _ID;
  NameTag = _NAME;
  SubClass = "DivisiveClusterNode";
  EncodeDecodeClass = NameTag;
} 
/*F DataMatrixClusterNodeClass(data) . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataMatrixClusterNodeClass::DataMatrixClusterNodeClass(const DataMatrixClusterNodeClass& data)
  : DataDivisiveClusterNodeClass(data)
{
} 
 
/*F DataMatrixClusterNodeClass(id,name,descr)  . . . . . . . . . . . . . . . constructor
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
DataMatrixClusterNodeClass::DataMatrixClusterNodeClass(const int id, 
				 const String& name,
				 const String& descr)
  : DataDivisiveClusterNodeClass(id,name,descr)
{
  SubClass = "DivisiveClusterNode";
  EncodeDecodeClass = "MatrixClusterNode";
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . . DataMatrixClusterNodeClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataMatrixClusterNodeClass::print(ostream& out) const
{
  DataDivisiveClusterNodeClass::print(out);
  // the rest
       
       return out;
}
 
/*F in1 = Read(in)  . . . . . . . . . . . . . . . . . . . . . DataMatrixClusterNodeClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataMatrixClusterNodeClass, there is no further information.
**
**  REMARKS
**
*/
bool DataMatrixClusterNodeClass::Read(istream& in, DataSetOfObjectsClass &set)
{
  bool result = DataDivisiveClusterNodeClass::Read(in,set);

  return result;
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . . . DataMatrixClusterNodeClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataMatrixClusterNodeClass::CopyClone(Identify *  objc)
{
  DataMatrixClusterNodeClass *objcfull = (DataMatrixClusterNodeClass *) objc;
  *this = *objcfull;
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . . . DataMatrixClusterNodeClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataMatrixClusterNodeClass::Clone()
    {
      DataMatrixClusterNodeClass* id = new DataMatrixClusterNodeClass(*this);
      return (Identify *) id;
    }
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . . DataMatrixClusterNodeClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataMatrixClusterNodeClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataDivisiveClusterNodeClass::EncodeThis(buffer);
  // result = result && Encode(buffer,------);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . . DataMatrixClusterNodeClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataMatrixClusterNodeClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataDivisiveClusterNodeClass::DecodeThis(buffer);
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
BaseDataObject * DataMatrixClusterNodeClass::BaseDataObjectExample()
{ 
  //cout << "Make MatrixClusterNode Example\n";
  return (BaseDataObject *) new BaseDataMatrixClusterNode();
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . DataMatrixClusterNodeClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataMatrixClusterNodeClass*& obj)
     {
     obj = new DataMatrixClusterNodeClass;
     return obj->DecodeThis(buffer);
     }
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . BaseDataMatrixClusterNode
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataMatrixClusterNode*& obj)
     {
     obj = new BaseDataMatrixClusterNode;
     return obj->DecodeThis(buffer);
     }
