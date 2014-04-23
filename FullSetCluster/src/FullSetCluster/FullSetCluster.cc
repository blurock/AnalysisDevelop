/*  FILE     FullSetCluster.cc
**  PACKAGE  FullSetCluster
**  AUTHOR   Edward S. Blurock
**
**  CONTENT
**    Exported functions for the "FullSetCluster" package.
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

/*S BaseDataFullSetClusterTree
 */ 
/*F BaseDataFullSetClusterTree()  . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataFullSetClusterTree::BaseDataFullSetClusterTree()
  : trainInstanceNamesS(TRAINSET_INSTANCENAMES),
    testInstanceNamesS(TESTSET_INSTANCENAMES)
{
  Identification = FULLSETCLUSTER_TREE_ID;
  NameTag = FULLSETCLUSTER_TREE_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;
} 
/*F BaseDataFullSetClusterTree(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataFullSetClusterTree::BaseDataFullSetClusterTree(const BaseDataFullSetClusterTree& data)
  : BaseDataClusterTree(data),
    trainInstanceNamesS(data.trainInstanceNamesS),
    testInstanceNamesS(data.testInstanceNamesS)
{
}
/*F Read(in,objc) . . . . . . . . . . . . . . . . . .  Read in BaseDataFullSetClusterTree
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataFullSetClusterTree::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . . . . . . . .  Read in BaseDataFullSetClusterTree
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataFullSetClusterTree::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = BaseDataClusterTree::Read(in,objc,name);
  
  return result;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . .  BaseDataFullSetClusterTree
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataFullSetClusterTree::print(ostream& out) const
{
  BaseDataClusterTree::print(out);
  // The rest

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . . . . .BaseDataFullSetClusterTree
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataFullSetClusterTree::Clone()
{
  BaseDataFullSetClusterTree *obj = new BaseDataFullSetClusterTree;
  obj->CopyClone(this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . . . . .BaseDataFullSetClusterTree
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataFullSetClusterTree::CopyClone(Identify * obj)
{
  BaseDataFullSetClusterTree *objfull = (BaseDataFullSetClusterTree *) obj;
  
  *this = *objfull;
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataFullSetClusterTree
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataFullSetClusterTree::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataClusterTree::EncodeThis(buffer);
  //result = result && ---.EncodeThis(buffer);
  //result = result && Encode(buffer,---);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataFullSetClusterTree
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataFullSetClusterTree::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataClusterTree::DecodeThis(buffer);
  // The rest

  return result;
}
/*F ans = WriteAsLine(out,objc) . . . . . . . . .  BaseDataFullSetClusterTree
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
bool BaseDataFullSetClusterTree::WriteAsLine(ostream& out, DataObjectClass *objc)
{
  bool result = BaseDataClusterTree::WriteAsLine(out,objc);
  return result;
}
/*F ans = WriteAsASCII(out,objc)  . . . . . . . .  BaseDataFullSetClusterTree
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
bool BaseDataFullSetClusterTree::WriteAsASCII(ostream& out, DataObjectClass* objc)
{
  bool result = BaseDataClusterTree::WriteAsASCII(out,objc);
  return result;
}
/*F ans = WriteAsLatex(out,objc)  . . . . . . . .  BaseDataFullSetClusterTree
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
bool BaseDataFullSetClusterTree::WriteAsLatex(ostream& out, DataObjectClass* objc)
{
  bool result = BaseDataClusterTree::WriteAsLatex(out,objc);
  return result;
}
/*F ans = SetUpAlgorithms(instances,instancesclass,run,runclass)  . algorithm
**
**  DESCRIPTION
**    instances: The set of instances
**    instancesclass: The set of instance object classes
**    run: The algorithm run information
**    runclass: The run class
**    
**  REMARKS
**
*/
bool BaseDataFullSetClusterTree::SetUpAlgorithms(BaseDataSetOfInstances*,
						 DataSetOfInstancesClass*,
						 BaseDataAlgorithmRun* ,
						 DataAlgorithmRunClass*)
{
  return true;
}
/*F ans = CheckInput(instances,instancesclass,run,runclass) . . . . algorithm
**
**  DESCRIPTION
**    instances: The set of instances
**    instancesclass: The set of instance object classes
**    run: The algorithm run information
**    runclass: The run class
**
**  REMARKS
**
*/
bool BaseDataFullSetClusterTree::CheckInput(BaseDataSetOfInstances*,
					    DataSetOfInstancesClass*,
					    BaseDataAlgorithmRun *run,
					    DataAlgorithmRunClass*)
{
  bool result = false;
  if(run->ParameterInList(trainInstanceNamesS))
    {
      if(!run->ParameterInList(testInstanceNamesS))
	{
	  cerr << "The parameter '" << testInstanceNamesS << "' was not in the list of parameters\n";
	  result = false;
	}
    }
  else
    {
      cerr << "The parameter '" << trainInstanceNamesS << "' was not in the list of parameters\n";
      result = false;
    }
  return result;
}
/*F ans = SetUpInput(instances,instancesclass,run,runclass) . . . . algorithm
**
**  DESCRIPTION
**    instances: The set of instances
**    instancesclass: The set of instance object classes
**    run: The algorithm run information
**    runclass: The run class
**    
**  REMARKS
**
*/
bool BaseDataFullSetClusterTree::SetUpInput(BaseDataSetOfInstances* instances,
						 DataSetOfInstancesClass* instancesclass,
						 BaseDataAlgorithmRun *run,
						 DataAlgorithmRunClass*)
{
  bool result = true;

  trainInstanceNames = (BaseDataKeyWords *) run->ParameterValue(trainInstanceNamesS);
  testInstanceNames = (BaseDataKeyWords *) run->ParameterValue(testInstanceNamesS);
  return result;
}
/*F ans = Calculate(instances,instancesclass,run,runclass)  . . . . algorithm
**
**  DESCRIPTION
**    instances: The set of instances
**    instancesclass: The set of instance object classes
**    run: The algorithm run information
**    runclass: The run class
**    
**  REMARKS
**
*/
bool BaseDataFullSetClusterTree::Calculate(BaseDataSetOfInstances*,
						DataSetOfInstancesClass*,
						BaseDataAlgorithmRun*,
						DataAlgorithmRunClass*)
{
  bool result = true;
  return result;
}
/*F ans = WriteOutputValues(instances,instancesclass,run,runclass)  algorithm
**
**  DESCRIPTION
**    instances: The set of instances
**    instancesclass: The set of instance object classes
**    run: The algorithm run information
**    runclass: The run class
**    
**  REMARKS
**
*/
bool BaseDataFullSetClusterTree::WriteOutputValues(BaseDataSetOfInstances*,
							DataSetOfInstancesClass*,
							BaseDataAlgorithmRun* run,
							DataAlgorithmRunClass*)
{
  bool result = true;
  
//  run->AddParameter(ctree);

  return result;
}
/*F ans = ConcludeRun(instances,instancesclass,run,runclass)  . . . algorithm
**
**  DESCRIPTION
**    instances: The set of instances
**    instancesclass: The set of instance object classes
**    run: The algorithm run information
**    runclass: The run class
**    
**  REMARKS
**
*/
bool BaseDataFullSetClusterTree::ConcludeRun(BaseDataSetOfInstances*,
						  DataSetOfInstancesClass*,
						  BaseDataAlgorithmRun*,
						  DataAlgorithmRunClass*)
{
  bool result = true;
//  delete something
  return result;
}
 
 
/*F names = getTrainInstanceNames() . . . . . . .  BaseDataFullSetClusterTree
**
**  DESCRIPTION
**    names: Names of the instances
**
**  REMARKS
**
*/
BaseDataKeyWords *BaseDataFullSetClusterTree::getTrainInstanceNames()
{
  return trainInstanceNames;
}
/*F names = getTrainInstanceNames() . . . . . . .  BaseDataFullSetClusterTree
**
**  DESCRIPTION
**    names: Names of the instances
**
**  REMARKS
**
*/
BaseDataKeyWords *BaseDataFullSetClusterTree::getTestInstanceNames()
{
  return testInstanceNames;
}
/*F node = InitializeRootNode() . . . . . . . . . BaseDataDivisiveClusterTree
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
void BaseDataFullSetClusterTree::InitializeRootNode(DataClusterTreeClass *treeclass)
{
  BaseDataClusterTree::InitializeRootNode(treeclass);
}

/*S DataFullSetClusterTreeClass
 */
/*F DataFullSetClusterTreeClass() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataFullSetClusterTreeClass::DataFullSetClusterTreeClass()
{
  Identification = FULLSETCLUSTER_TREE_ID;
  NameTag = FULLSETCLUSTER_TREE_NAME;
  SubClass = "ClusterTree";
  EncodeDecodeClass = NameTag;
} 
/*F DataFullSetClusterTreeClass(data) . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataFullSetClusterTreeClass::DataFullSetClusterTreeClass(const DataFullSetClusterTreeClass& data)
  : DataClusterTreeClass(data)
{
} 
 
/*F DataFullSetClusterTreeClass(id,name,descr)  . . . . . . . . . . . . . . . constructor
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
DataFullSetClusterTreeClass::DataFullSetClusterTreeClass(const int id, 
				 const String& name,
				 const String& descr)
  : DataClusterTreeClass(id,name,descr)
{
  SubClass = "ClusterTree";
  EncodeDecodeClass = FULLSETCLUSTER_TREE_NAME;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . . DataFullSetClusterTreeClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataFullSetClusterTreeClass::print(ostream& out) const
{
  DataClusterTreeClass::print(out);
  // the rest
       
       return out;
}
 
/*F in1 = Read(in)  . . . . . . . . . . . . . . . . . . . . . DataFullSetClusterTreeClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataFullSetClusterTreeClass, there is no further information.
**
**  REMARKS
**
*/
bool DataFullSetClusterTreeClass::Read(istream& in, DataSetOfObjectsClass &set)
{
  bool result = DataClusterTreeClass::Read(in,set);

  return result;
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . . . DataFullSetClusterTreeClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataFullSetClusterTreeClass::CopyClone(Identify *  objc)
{
  DataFullSetClusterTreeClass *objcfull = (DataFullSetClusterTreeClass *) objc;
  *this = *objcfull;
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . . . DataFullSetClusterTreeClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataFullSetClusterTreeClass::Clone()
    {
      DataFullSetClusterTreeClass* id = new DataFullSetClusterTreeClass(*this);
      return (Identify *) id;
    }
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . . DataFullSetClusterTreeClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataFullSetClusterTreeClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataClusterTreeClass::EncodeThis(buffer);
  // result = result && Encode(buffer,------);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . . DataFullSetClusterTreeClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataFullSetClusterTreeClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataClusterTreeClass::DecodeThis(buffer);
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
BaseDataObject * DataFullSetClusterTreeClass::BaseDataObjectExample()
{ 
  //cout << "Make FullSetClusterTree Example\n";
  return (BaseDataObject *) new BaseDataFullSetClusterTree();
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . DataFullSetClusterTreeClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataFullSetClusterTreeClass*& obj)
     {
     obj = new DataFullSetClusterTreeClass;
     return obj->DecodeThis(buffer);
     }
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . BaseDataFullSetClusterTree
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataFullSetClusterTree*& obj)
     {
     obj = new BaseDataFullSetClusterTree;
     return obj->DecodeThis(buffer);
     }
/*S BaseDataFullSetClusterNode
 */ 
/*F BaseDataFullSetClusterNode()  . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataFullSetClusterNode::BaseDataFullSetClusterNode()
{
  Identification = FULLSETCLUSTER_NODE_ID;
  NameTag = FULLSETCLUSTER_NODE_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;
} 
/*F BaseDataFullSetClusterNode(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataFullSetClusterNode::BaseDataFullSetClusterNode(const BaseDataFullSetClusterNode& data)
  : BaseDataClusterNode(data)
{
}
/*F Read(in,objc) . . . . . . . . . . . . . . . . . .  Read in BaseDataFullSetClusterNode
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataFullSetClusterNode::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . . . . . . . .  Read in BaseDataFullSetClusterNode
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataFullSetClusterNode::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = BaseDataClusterNode::Read(in,objc,name);
  
  return result;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . .  BaseDataFullSetClusterNode
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataFullSetClusterNode::print(ostream& out) const
{
  BaseDataClusterNode::print(out);
  // The rest

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . . . . .BaseDataFullSetClusterNode
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataFullSetClusterNode::Clone()
{
  BaseDataFullSetClusterNode *obj = new BaseDataFullSetClusterNode;
  obj->CopyClone(this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . . . . .BaseDataFullSetClusterNode
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataFullSetClusterNode::CopyClone(Identify * obj)
{
  BaseDataFullSetClusterNode *objfull = (BaseDataFullSetClusterNode *) obj;
  
  *this = *objfull;
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataFullSetClusterNode
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataFullSetClusterNode::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataClusterNode::EncodeThis(buffer);
  //result = result && ---.EncodeThis(buffer);
  //result = result && Encode(buffer,---);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataFullSetClusterNode
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataFullSetClusterNode::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataClusterNode::DecodeThis(buffer);
  // The rest

  return result;
}
 
 
/*S DataFullSetClusterNodeClass
 */
/*F DataFullSetClusterNodeClass() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataFullSetClusterNodeClass::DataFullSetClusterNodeClass()
{
  Identification = FULLSETCLUSTER_NODE_ID;
  NameTag = FULLSETCLUSTER_NODE_NAME;
  SubClass = "ClusterNode";
  EncodeDecodeClass = NameTag;
} 
/*F DataFullSetClusterNodeClass(data) . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataFullSetClusterNodeClass::DataFullSetClusterNodeClass(const DataFullSetClusterNodeClass& data)
  : DataClusterNodeClass(data)
{
} 
 
/*F DataFullSetClusterNodeClass(id,name,descr)  . . . . . . . . . . . . . . . constructor
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
DataFullSetClusterNodeClass::DataFullSetClusterNodeClass(const int id, 
				 const String& name,
				 const String& descr)
  : DataClusterNodeClass(id,name,descr)
{
  SubClass = "ClusterNode";
  EncodeDecodeClass = FULLSETCLUSTER_NODE_NAME;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . . DataFullSetClusterNodeClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataFullSetClusterNodeClass::print(ostream& out) const
{
  DataClusterNodeClass::print(out);
  // the rest
       
       return out;
}
 
/*F in1 = Read(in)  . . . . . . . . . . . . . . . . . . . . . DataFullSetClusterNodeClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataFullSetClusterNodeClass, there is no further information.
**
**  REMARKS
**
*/
bool DataFullSetClusterNodeClass::Read(istream& in, DataSetOfObjectsClass &set)
{
  bool result = DataClusterNodeClass::Read(in,set);

  return result;
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . . . DataFullSetClusterNodeClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataFullSetClusterNodeClass::CopyClone(Identify *  objc)
{
  DataFullSetClusterNodeClass *objcfull = (DataFullSetClusterNodeClass *) objc;
  *this = *objcfull;
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . . . DataFullSetClusterNodeClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataFullSetClusterNodeClass::Clone()
    {
      DataFullSetClusterNodeClass* id = new DataFullSetClusterNodeClass(*this);
      return (Identify *) id;
    }
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . . DataFullSetClusterNodeClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataFullSetClusterNodeClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataClusterNodeClass::EncodeThis(buffer);
  // result = result && Encode(buffer,------);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . . DataFullSetClusterNodeClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataFullSetClusterNodeClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataClusterNodeClass::DecodeThis(buffer);
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
BaseDataObject * DataFullSetClusterNodeClass::BaseDataObjectExample()
{ 
  //cout << "Make FullSetClusterNode Example\n";
  return (BaseDataObject *) new BaseDataFullSetClusterNode();
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . DataFullSetClusterNodeClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataFullSetClusterNodeClass*& obj)
     {
     obj = new DataFullSetClusterNodeClass;
     return obj->DecodeThis(buffer);
     }
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . BaseDataFullSetClusterNode
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataFullSetClusterNode*& obj)
     {
     obj = new BaseDataFullSetClusterNode;
     return obj->DecodeThis(buffer);
     }
/*S BaseDataDivisiveClusterTree
 */ 
/*F BaseDataDivisiveClusterTree()  . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataDivisiveClusterTree::BaseDataDivisiveClusterTree()
{
  Identification = FULLSETCLUSTER_DIVISIVETREE_ID;
  NameTag = FULLSETCLUSTER_DIVISIVETREE_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;
} 
/*F BaseDataDivisiveClusterTree(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataDivisiveClusterTree::BaseDataDivisiveClusterTree(const BaseDataDivisiveClusterTree& data)
  : BaseDataFullSetClusterTree(data)
{
}
/*F Read(in,objc) . . . . . . . . . . . . . . . . . .  Read in BaseDataDivisiveClusterTree
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataDivisiveClusterTree::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . . . . . . . .  Read in BaseDataDivisiveClusterTree
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataDivisiveClusterTree::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = BaseDataFullSetClusterTree::Read(in,objc,name);
  
  return result;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . .  BaseDataDivisiveClusterTree
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataDivisiveClusterTree::print(ostream& out) const
{
  BaseDataFullSetClusterTree::print(out);
  // The rest

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . . . . .BaseDataDivisiveClusterTree
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataDivisiveClusterTree::Clone()
{
  BaseDataDivisiveClusterTree *obj = new BaseDataDivisiveClusterTree;
  obj->CopyClone(this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . . . . .BaseDataDivisiveClusterTree
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataDivisiveClusterTree::CopyClone(Identify * obj)
{
  BaseDataDivisiveClusterTree *objfull = (BaseDataDivisiveClusterTree *) obj;
  
  *this = *objfull;
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataDivisiveClusterTree
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataDivisiveClusterTree::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataFullSetClusterTree::EncodeThis(buffer);
  //result = result && ---.EncodeThis(buffer);
  //result = result && Encode(buffer,---);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataDivisiveClusterTree
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataDivisiveClusterTree::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataFullSetClusterTree::DecodeThis(buffer);
  // The rest

  return result;
}
/*F ans = WriteAsLine(out,objc) . . . . . . . . . BaseDataDivisiveClusterTree
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
bool BaseDataDivisiveClusterTree::WriteAsLine(ostream& out, DataObjectClass *objc)
{
  bool result = BaseDataFullSetClusterTree::WriteAsLine(out,objc);
  return result;
}
/*F ans = WriteAsASCII(out,objc)  . . . . . . . . BaseDataDivisiveClusterTree
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
bool BaseDataDivisiveClusterTree::WriteAsASCII(ostream& out, DataObjectClass* objc)
{
  bool result = BaseDataFullSetClusterTree::WriteAsASCII(out,objc);
  return result;
}
/*F ans = WriteAsLatex(out,objc)  . . . . . . . . BaseDataDivisiveClusterTree
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
bool BaseDataDivisiveClusterTree::WriteAsLatex(ostream& out, DataObjectClass* objc)
{
  bool result = BaseDataFullSetClusterTree::WriteAsLatex(out,objc);
  return result;
}
/*F ans = SetUpAlgorithms(instances,instancesclass,run,runclass)  . algorithm
**
**  DESCRIPTION
**    instances: The set of instances
**    instancesclass: The set of instance object classes
**    run: The algorithm run information
**    runclass: The run class
**    
**  REMARKS
**
*/
bool BaseDataDivisiveClusterTree::SetUpAlgorithms(BaseDataSetOfInstances*,
						      DataSetOfInstancesClass*,
						      BaseDataAlgorithmRun* ,
						      DataAlgorithmRunClass*)
{
  return true;
}
/*F ans = CheckInput(instances,instancesclass,run,runclass) . . . . algorithm
**
**  DESCRIPTION
**    instances: The set of instances
**    instancesclass: The set of instance object classes
**    run: The algorithm run information
**    runclass: The run class
**
**  REMARKS
**
*/
bool BaseDataDivisiveClusterTree::CheckInput(BaseDataSetOfInstances*,
						 DataSetOfInstancesClass*,
						 BaseDataAlgorithmRun*,
						 DataAlgorithmRunClass*)
{
  bool result = true;

//  if(run->ParameterInList(trainInstanceNamesS))
//    {
//    }
//  else
//    {
//      cerr << "The parameter '" << trainInstanceNamesS << "' was not in the list of parameters";
//      result = false;
//    }

  return result;
}
/*F ans = SetUpInput(instances,instancesclass,run,runclass) . . . . algorithm
**
**  DESCRIPTION
**    instances: The set of instances
**    instancesclass: The set of instance object classes
**    run: The algorithm run information
**    runclass: The run class
**    
**  REMARKS
**
*/
bool BaseDataDivisiveClusterTree::SetUpInput(BaseDataSetOfInstances* instances,
						 DataSetOfInstancesClass* instancesclass,
						 BaseDataAlgorithmRun*,
						 DataAlgorithmRunClass* rclass)
{
  bool result = true;

//  BaseDataKeyWords *tlist = (BaseDataKeyWords *) run->ParameterValue(trainInstanceNamesS);
  return result;
}
/*F ans = Calculate(instances,instancesclass,run,runclass)  . . . . algorithm
**
**  DESCRIPTION
**    instances: The set of instances
**    instancesclass: The set of instance object classes
**    run: The algorithm run information
**    runclass: The run class
**    
**  REMARKS
**
*/
bool BaseDataDivisiveClusterTree::Calculate(BaseDataSetOfInstances* instances,
					    DataSetOfInstancesClass *instancesclass,
					    BaseDataAlgorithmRun*,
					    DataAlgorithmRunClass *runclass)
{
  bool result = true;
  debugLevel = runclass->getDebugLevel();

  DataDivisiveClusterTreeClass *treeclass = (DataDivisiveClusterTreeClass *) 
    instancesclass->PointerToAllowedClasses()->GetObjectClass(GetType());

  InitializeRootNode(treeclass);
  while(!(OpenNodes.size() > 0) && result)
    {
      BaseDataDivisiveClusterNode *nextnode = getNextOpenNode();
      if(getDebugLevel() > 2)
	{
	  cout << "Divisive Clustering: Expand Next Node: " << nextnode->NameTag << endl;
	}
      if(expandNodeP(nextnode))
	{
	  bool cont = NodePreProcessing(nextnode);
	  if(cont)
	    {
	      BaseDataSetOfObjects *newnodes = PerformDivisiveClustering(instances,
									 instancesclass,
									 nextnode);
	      cont = NodePostProcessing(newnodes);
	      if(cont)
		{
		  addNodesToTree(newnodes,nextnode);
		}
	    }
	}
    }
  return result;
}
/*F addNodeToTree(newnodes) . . . . . . . . . . . BaseDataDivisiveClusterTree
**
**  DESCRIPTION
**    For each son:
**    - Set the node name (SetNewNodeName)
**    - Add the connection to parent (AddConnection)
**    - Add the node
**
**  REMARKS
**
*/
void BaseDataDivisiveClusterTree::addNodesToTree(BaseDataSetOfObjects *newnodes,
						BaseDataDivisiveClusterNode *parent)
{
  ObjectList<String> nodenames = newnodes->ListOfObjectNames();
  ObjectList<String>::iterator son;
  for(son = nodenames.begin(); son != nodenames.end();son++)
    {
      BaseDataDivisiveClusterNode *n = (BaseDataDivisiveClusterNode *) newnodes->GetObject(*son);
      Tree.SetNewNodeName(n,n->NameTag,parent->NameTag);
      Tree.AddConnection(parent->NameTag,n->NameTag);
      Tree.AddNode(n);
    }
} 
/*F node = getNextOpenNode()  . . . . . . . . . . BaseDataDivisiveClusterNode
**
**  DESCRIPTION
**    Gets the node from the top of the open nodes list
**
**  REMARKS
**
*/
BaseDataDivisiveClusterNode *BaseDataDivisiveClusterTree::getNextOpenNode()
{
  String next = OpenNodes.front();
  OpenNodes.pop_front();
  return (BaseDataDivisiveClusterNode *) Tree.GetNode(next);
}
/*F ans = WriteOutputValues(instances,instancesclass,run,runclass)  algorithm
**
**  DESCRIPTION
**    instances: The set of instances
**    instancesclass: The set of instance object classes
**    run: The algorithm run information
**    runclass: The run class
**    
**  REMARKS
**
*/
bool BaseDataDivisiveClusterTree::WriteOutputValues(BaseDataSetOfInstances*,
							DataSetOfInstancesClass*,
							BaseDataAlgorithmRun* run,
							DataAlgorithmRunClass*)
{
  bool result = true;
  return result;
}
/*F ans = ConcludeRun(instances,instancesclass,run,runclass)  . . . algorithm
**
**  DESCRIPTION
**    instances: The set of instances
**    instancesclass: The set of instance object classes
**    run: The algorithm run information
**    runclass: The run class
**    
**  REMARKS
**
*/
bool BaseDataDivisiveClusterTree::ConcludeRun(BaseDataSetOfInstances*,
						  DataSetOfInstancesClass*,
						  BaseDataAlgorithmRun*,
						  DataAlgorithmRunClass*)
{
  bool result = true;
//  delete something
  return result;
}
/*F node = InitializeRootNode() . . . . . . . . . BaseDataDivisiveClusterTree
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
void BaseDataDivisiveClusterTree::InitializeRootNode(DataClusterTreeClass *treeclass)
{
  BaseDataFullSetClusterTree::InitializeRootNode(treeclass);
  BaseDataDivisiveClusterNode *node = (BaseDataDivisiveClusterNode *) Tree.getRootNode();
  OpenNodes.AddObject(node->NameTag);

}
 
/*F ans = NodePreProcessing(node) . . . . . . . . BaseDataDivisiveClusterTree
**
**  DESCRIPTION
**    node: The parent node for preprocessing information
**    ans: True if successful (and if the node should be expanded)
**
**  REMARKS
**
*/
bool BaseDataDivisiveClusterTree::NodePreProcessing(BaseDataDivisiveClusterNode *node)
{
  bool result = true;
  return result;
}
 
/*F ans = NodePostProcessing(node)  . . . . . . . BaseDataDivisiveClusterTree
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
bool BaseDataDivisiveClusterTree::NodePostProcessing(BaseDataSetOfObjects *sons)
{
  bool result = true;
  return result;
}
 
/*F ans = expandNodeP(node) . . . . . . . . . . . BaseDataDivisiveClusterTree
**
**  DESCRIPTION
**    node: The node that could be expanded
**    ans: True if can be expanded
**
**    The simple criteria used here is that the cluster level is not exceeded.
**
**  REMARKS
**
*/
bool BaseDataDivisiveClusterTree::expandNodeP(BaseDataDivisiveClusterNode *node)
{
  unsigned int level = node->getLevel();
  bool result = true;
  if(level >= getMaxLevel())
    result = false;
  return result;
}
 
/*F sons = PerformDivisiveClustering(node)  . . . BaseDataDivisiveClusterTree
**
**  DESCRIPTION
**    node: The parent node
**    sons: The next set sons
**
**  REMARKS
**
*/
BaseDataSetOfObjects *BaseDataDivisiveClusterTree::PerformDivisiveClustering(BaseDataSetOfInstances* instances,
									     DataSetOfInstancesClass* instancesclass,
									     BaseDataDivisiveClusterNode *node)
{
  if(getDebugLevel() > 2)
    {
      cout << "Begin: PerformDivisiveClustering on " << node->NameTag << endl;
    }
  BaseDataSetOfObjects *newclusters = InitializationOfSons(node);
  double diff = 1000.0;
  while(ContinueClusterIteration(diff,newclusters))
    {
      if(getDebugLevel() > 2)
	{
	  cout << "Loop: PerformDivisiveClustering on " << node->NameTag << endl;
	}
      ClusterInstancesOnNodes(instances,
			      instancesclass,
			      node,newclusters);
      ComputeClusterQualityMeasure(node,newclusters);
      diff = AdjustClusterStructure(node,newclusters);
    }
  if(getDebugLevel() > 2)
    {
      cout << "Begin: PerformDivisiveClustering on " << node->NameTag << endl;
    }
  return newclusters;
}
/*F set = InitializationOfSons(node)  . . . . . . BaseDataDivisiveClusterTree
**
**  DESCRIPTION
**    node: The original node from which to derive the sons
**    set: The set of initial sons
** 
**    In this base routine, the sons are initialized to the empty set.
**
**  REMARKS
**
*/
BaseDataSetOfObjects *BaseDataDivisiveClusterTree::InitializationOfSons(BaseDataDivisiveClusterNode *node)
{
  if(getDebugLevel() > 3) 
    {
      cout << "Initialization of Sons" << endl;
    }
  BaseDataSetOfObjects *set = new BaseDataSetOfObjects();

  return set;
}
/*F ClusterInstancesOnNodes(instances,instancesclass,node,sons)
**
**  DESCRIPTION
**    The instances are assigned to the sons.
**
**  REMARKS
**
*/
void BaseDataDivisiveClusterTree::ClusterInstancesOnNodes(BaseDataSetOfInstances* instances,
							  DataSetOfInstancesClass* instancesclass,
							  BaseDataDivisiveClusterNode *node,
							  BaseDataSetOfObjects *sons)
{
  if(getDebugLevel() > 3)
    {
      cout << "ClusterInstancesOnNodes" << endl;
    }
  ObjectList<String>::iterator name,son;

  ObjectList<String> names = getTrainInstanceNames()->GetKeyWords();
  ObjectList<String> sonnames = sons->ListOfObjectNames();
  for(name = names.begin(); name != names.end(); name++)
    {
      if(getDebugLevel() > 5)
	{
	  cout << "ClusterInstancesOnNodes: Loop over instances: " << *name << endl;
	}
      BaseDataInstance *instance = instances->GetInstance(*name);
      ObjectList<double> distancelist;
      for(son=sonnames.begin(); son != sonnames.end();son++)
	{
	  if(getDebugLevel() > 6)
	    {
	      cout << "ClusterInstancesOnNodes: Loop over nodes: " << *son << endl;
	    }
	  BaseDataDivisiveClusterNode *sonobject = (BaseDataDivisiveClusterNode *) sons->GetObject(*son);
	  double distance = GetDistanceToNode(instance,sonobject);
	  distancelist.AddObject(distance);
	}
      if(getDebugLevel() > 5)
	{
	  cout << "ClusterInstancesOnNodes: Loop over instances: " << *name << " Distances: ";
	  distancelist.print(cout);
	  cout << endl;
	}
      BaseDataLogicDescription *membership = DetermineNodeMembership(sons,distancelist);
      AssignInstanceToNode(membership,sons,instance);
    }
}
/*F AssignInstanceToNode(membership,sons,instance)
**
**  DESCRIPTION
**    membership: The membership of instance on each node
**    sons: The set of nodes
**    instance: The instance to add
**
**  REMARKS
**
*/
void BaseDataDivisiveClusterTree::AssignInstanceToNode(BaseDataLogicDescription *membership,
			  BaseDataSetOfObjects *sons,
			  BaseDataInstance *instance)
{
  ObjectList<String> sonnames = sons->ListOfObjectNames();
  ObjectList<String>::iterator son,name;
  for(name = sonnames.begin(); name != sonnames.end(); name++)
    {
      BaseDataDivisiveClusterNode *node = (BaseDataDivisiveClusterNode *) Tree.GetNode(*name);
      BaseDataLogical *mem = (BaseDataLogical *) membership->GetObject(*name);
      node->AssignElementToCluster(*son,mem);
    }
}
/*F membership = DetermineNodeMembership(sons,distancelist)
**
**  DESCRIPTION
**    sons: The list of nodes
**    distancelist: The distance of the instance to the nodes
**
**  REMARKS
**
*/
BaseDataLogicDescription *BaseDataDivisiveClusterTree::DetermineNodeMembership(BaseDataSetOfObjects *sons,
									       DataClusterNodeClass *nodeclass,
									       ObjectList<double> distancelist)
{
  DataLogicalClass *logclass = nodeclass->getLogicClass();
  ObjectList<String> sonnames = sons->ListOfObjectNames();
  ObjectList<String>::iterator son;
  ObjectList<double>::iterator mem = distancelist.begin();
  double total = 0.0;
  double best = *mem;
  String bestnode = *(sonnames.begin());
  for(son = sonnames.begin(); son != sonnames.end(); son++)
    {
      BaseDataLogical *log = (BaseDataLogical *) logclass->BaseDataObjectExample();
      log->NameTag = *son;
      total += *mem;
      if(*mem < best)
	{
	  best = *mem;
	  bestnode = *son;
	}
    }
  mem = distancelist.begin();
  for(son = sonnames.begin(); son != sonnames.end(); son++)
    {
      
    }
}
/*F dist = GetDistanceToNode(instance,object) 
**
**  DESCRIPTION
**    instance: The instance to compare
**    node: The node to compare
**
**  REMARKS
**
*/
double BaseDataDivisiveClusterTree::GetDistanceToNode(BaseDataInstance *instance, 
						      BaseDataDivisiveClusterNode *object)
{
  double value = 0.0;
  return value;
}
/*F ans = ContinueClusterIteration(diff,clusters) BaseDataDivisiveClusterTree
**
**  DESCRIPTION
**    diff: The difference after cluster adjustments
**    clusters: The new clusters
**
**  REMARKS
**
*/
bool BaseDataDivisiveClusterTree::ContinueClusterIteration(double diff,
							   BaseDataSetOfObjects *)
{
  bool result = true;
  if(diff > .01)
    result = false;
  return result;
}
/*F ComputeClusterQualityMeasure(node,clusters) . BaseDataDivisiveClusterTree
**
**  DESCRIPTION
**    node: The node
**    clusters: 
**
**  REMARKS
**
*/
void BaseDataDivisiveClusterTree::ComputeClusterQualityMeasure(BaseDataDivisiveClusterNode *,
							       BaseDataSetOfObjects *)
{
}
 
/*F diff = AdjustClusterStructure(node,clusters)  BaseDataDivisiveClusterTree
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
double BaseDataDivisiveClusterTree::AdjustClusterStructure(BaseDataDivisiveClusterNode *,
							   BaseDataSetOfObjects *)
{
  double diff = 0.0;
  return diff;
}
 
/*F
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
unsigned int BaseDataDivisiveClusterTree::getDebugLevel()
{
  return debugLevel;
}

/*S DataDivisiveClusterTreeClass
 */
/*F DataDivisiveClusterTreeClass() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataDivisiveClusterTreeClass::DataDivisiveClusterTreeClass()
{
  Identification = FULLSETCLUSTER_DIVISIVETREE_ID;
  NameTag = FULLSETCLUSTER_DIVISIVETREE_NAME;
  SubClass = "FullSetClusterTree";
  EncodeDecodeClass = NameTag;
} 
/*F DataDivisiveClusterTreeClass(data) . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataDivisiveClusterTreeClass::DataDivisiveClusterTreeClass(const DataDivisiveClusterTreeClass& data)
  : DataFullSetClusterTreeClass(data)
{
} 
 
/*F DataDivisiveClusterTreeClass(id,name,descr)  . . . . . . . . . . . . . . . constructor
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
DataDivisiveClusterTreeClass::DataDivisiveClusterTreeClass(const int id, 
				 const String& name,
				 const String& descr)
  : DataFullSetClusterTreeClass(id,name,descr)
{
  SubClass = "FullSetClusterTree";
  EncodeDecodeClass = FULLSETCLUSTER_DIVISIVETREE_NAME;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . . DataDivisiveClusterTreeClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataDivisiveClusterTreeClass::print(ostream& out) const
{
  DataFullSetClusterTreeClass::print(out);
  // the rest
       
       return out;
}
 
/*F in1 = Read(in)  . . . . . . . . . . . . . . . . . . . . . DataDivisiveClusterTreeClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataDivisiveClusterTreeClass, there is no further information.
**
**  REMARKS
**
*/
bool DataDivisiveClusterTreeClass::Read(istream& in, DataSetOfObjectsClass &set)
{
  bool result = DataFullSetClusterTreeClass::Read(in,set);

  return result;
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . . . DataDivisiveClusterTreeClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataDivisiveClusterTreeClass::CopyClone(Identify *  objc)
{
  DataDivisiveClusterTreeClass *objcfull = (DataDivisiveClusterTreeClass *) objc;
  *this = *objcfull;
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . . . DataDivisiveClusterTreeClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataDivisiveClusterTreeClass::Clone()
    {
      DataDivisiveClusterTreeClass* id = new DataDivisiveClusterTreeClass(*this);
      return (Identify *) id;
    }
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . . DataDivisiveClusterTreeClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataDivisiveClusterTreeClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataFullSetClusterTreeClass::EncodeThis(buffer);
  // result = result && Encode(buffer,------);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . . DataDivisiveClusterTreeClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataDivisiveClusterTreeClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataFullSetClusterTreeClass::DecodeThis(buffer);
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
BaseDataObject * DataDivisiveClusterTreeClass::BaseDataObjectExample()
{ 
  //cout << "Make DivisiveClusterTree Example\n";
  return (BaseDataObject *) new BaseDataDivisiveClusterTree();
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . DataDivisiveClusterTreeClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataDivisiveClusterTreeClass*& obj)
     {
     obj = new DataDivisiveClusterTreeClass;
     return obj->DecodeThis(buffer);
     }
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . BaseDataDivisiveClusterTree
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataDivisiveClusterTree*& obj)
     {
     obj = new BaseDataDivisiveClusterTree;
     return obj->DecodeThis(buffer);
     }
/*S BaseDataDivisiveClusterNode
 */ 
/*F BaseDataDivisiveClusterNode()  . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataDivisiveClusterNode::BaseDataDivisiveClusterNode()
{
  Identification = FULLSETCLUSTER_DIVISIVENODE_ID;
  NameTag = FULLSETCLUSTER_DIVISIVENODE_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;
} 
/*F BaseDataDivisiveClusterNode(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataDivisiveClusterNode::BaseDataDivisiveClusterNode(const BaseDataDivisiveClusterNode& data)
  : BaseDataFullSetClusterNode(data)
{
}
/*F Read(in,objc) . . . . . . . . . . . . . . . . . .  Read in BaseDataDivisiveClusterNode
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataDivisiveClusterNode::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . . . . . . . .  Read in BaseDataDivisiveClusterNode
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataDivisiveClusterNode::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = BaseDataFullSetClusterNode::Read(in,objc,name);
  
  return result;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . .  BaseDataDivisiveClusterNode
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataDivisiveClusterNode::print(ostream& out) const
{
  BaseDataFullSetClusterNode::print(out);
  // The rest

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . . . . .BaseDataDivisiveClusterNode
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataDivisiveClusterNode::Clone()
{
  BaseDataDivisiveClusterNode *obj = new BaseDataDivisiveClusterNode;
  obj->CopyClone(this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . . . . .BaseDataDivisiveClusterNode
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataDivisiveClusterNode::CopyClone(Identify * obj)
{
  BaseDataDivisiveClusterNode *objfull = (BaseDataDivisiveClusterNode *) obj;
  
  *this = *objfull;
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataDivisiveClusterNode
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataDivisiveClusterNode::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataFullSetClusterNode::EncodeThis(buffer);
  //result = result && ---.EncodeThis(buffer);
  //result = result && Encode(buffer,---);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataDivisiveClusterNode
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataDivisiveClusterNode::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataFullSetClusterNode::DecodeThis(buffer);
  // The rest

  return result;
}
 
 
/*S DataDivisiveClusterNodeClass
 */
/*F DataDivisiveClusterNodeClass() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataDivisiveClusterNodeClass::DataDivisiveClusterNodeClass()
{
  Identification = FULLSETCLUSTER_DIVISIVENODE_ID;
  NameTag = FULLSETCLUSTER_DIVISIVENODE_NAME;
  SubClass = "FullSetClusterNode";
  EncodeDecodeClass = NameTag;
} 
/*F DataDivisiveClusterNodeClass(data) . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataDivisiveClusterNodeClass::DataDivisiveClusterNodeClass(const DataDivisiveClusterNodeClass& data)
  : DataFullSetClusterNodeClass(data)
{
} 
 
/*F DataDivisiveClusterNodeClass(id,name,descr)  . . . . . . . . . . . . . . . constructor
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
DataDivisiveClusterNodeClass::DataDivisiveClusterNodeClass(const int id, 
				 const String& name,
				 const String& descr)
  : DataFullSetClusterNodeClass(id,name,descr)
{
  SubClass = "FullSetClusterNode";
  EncodeDecodeClass = FULLSETCLUSTER_DIVISIVENODE_NAME;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . . DataDivisiveClusterNodeClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataDivisiveClusterNodeClass::print(ostream& out) const
{
  DataFullSetClusterNodeClass::print(out);
  // the rest
       
       return out;
}
 
/*F in1 = Read(in)  . . . . . . . . . . . . . . . . . . . . . DataDivisiveClusterNodeClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataDivisiveClusterNodeClass, there is no further information.
**
**  REMARKS
**
*/
bool DataDivisiveClusterNodeClass::Read(istream& in, DataSetOfObjectsClass &set)
{
  bool result = DataFullSetClusterNodeClass::Read(in,set);

  return result;
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . . . DataDivisiveClusterNodeClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataDivisiveClusterNodeClass::CopyClone(Identify *  objc)
{
  DataDivisiveClusterNodeClass *objcfull = (DataDivisiveClusterNodeClass *) objc;
  *this = *objcfull;
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . . . DataDivisiveClusterNodeClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataDivisiveClusterNodeClass::Clone()
    {
      DataDivisiveClusterNodeClass* id = new DataDivisiveClusterNodeClass(*this);
      return (Identify *) id;
    }
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . . DataDivisiveClusterNodeClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataDivisiveClusterNodeClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataFullSetClusterNodeClass::EncodeThis(buffer);
  // result = result && Encode(buffer,------);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . . DataDivisiveClusterNodeClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataDivisiveClusterNodeClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataFullSetClusterNodeClass::DecodeThis(buffer);
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
BaseDataObject * DataDivisiveClusterNodeClass::BaseDataObjectExample()
{ 
  //cout << "Make DivisiveClusterNode Example\n";
  return (BaseDataObject *) new BaseDataDivisiveClusterNode();
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . DataDivisiveClusterNodeClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataDivisiveClusterNodeClass*& obj)
     {
     obj = new DataDivisiveClusterNodeClass;
     return obj->DecodeThis(buffer);
     }
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . BaseDataDivisiveClusterNode
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataDivisiveClusterNode*& obj)
     {
     obj = new BaseDataDivisiveClusterNode;
     return obj->DecodeThis(buffer);
     }
/*S BaseDataFixedClusterNode
 */ 
/*F BaseDataFixedClusterNode()  . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataFixedClusterNode::BaseDataFixedClusterNode()
{
  Identification = FULLSETCLUSTER_FIXEDCLUSTERNODE_ID;
  NameTag = FULLSETCLUSTER_FIXEDCLUSTERNODE_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;
} 
/*F BaseDataFixedClusterNode(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataFixedClusterNode::BaseDataFixedClusterNode(const BaseDataFixedClusterNode& data)
  : BaseDataDivisiveClusterNode(data)
{
}
/*F Read(in,objc) . . . . . . . . . . . . . . . . . .  Read in BaseDataFixedClusterNode
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataFixedClusterNode::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . . . . . . . .  Read in BaseDataFixedClusterNode
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataFixedClusterNode::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = BaseDataDivisiveClusterNode::Read(in,objc,name);
  
  return result;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . .  BaseDataFixedClusterNode
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataFixedClusterNode::print(ostream& out) const
{
  BaseDataDivisiveClusterNode::print(out);
  // The rest

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . . . . .BaseDataFixedClusterNode
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataFixedClusterNode::Clone()
{
  BaseDataFixedClusterNode *obj = new BaseDataFixedClusterNode;
  obj->CopyClone(this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . . . . .BaseDataFixedClusterNode
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataFixedClusterNode::CopyClone(Identify * obj)
{
  BaseDataFixedClusterNode *objfull = (BaseDataFixedClusterNode *) obj;
  
  *this = *objfull;
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataFixedClusterNode
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataFixedClusterNode::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataDivisiveClusterNode::EncodeThis(buffer);
  //result = result && ---.EncodeThis(buffer);
  //result = result && Encode(buffer,---);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataFixedClusterNode
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataFixedClusterNode::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataDivisiveClusterNode::DecodeThis(buffer);
  // The rest

  return result;
}
 
 
/*S DataFixedClusterNodeClass
 */
/*F DataFixedClusterNodeClass() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataFixedClusterNodeClass::DataFixedClusterNodeClass()
{
  Identification = FULLSETCLUSTER_FIXEDCLUSTERNODE_ID;
  NameTag = FULLSETCLUSTER_FIXEDCLUSTERNODE_NAME;
  SubClass = "DivisiveClusterNode";
  EncodeDecodeClass = NameTag;
} 
/*F DataFixedClusterNodeClass(data) . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataFixedClusterNodeClass::DataFixedClusterNodeClass(const DataFixedClusterNodeClass& data)
  : DataDivisiveClusterNodeClass(data)
{
} 
 
/*F DataFixedClusterNodeClass(id,name,descr)  . . . . . . . . . . . . . . . constructor
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
DataFixedClusterNodeClass::DataFixedClusterNodeClass(const int id, 
				 const String& name,
				 const String& descr)
  : DataDivisiveClusterNodeClass(id,name,descr)
{
  SubClass = "DivisiveClusterNode";
  EncodeDecodeClass = FULLSETCLUSTER_FIXEDCLUSTERNODE_NAME;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . . DataFixedClusterNodeClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataFixedClusterNodeClass::print(ostream& out) const
{
  DataDivisiveClusterNodeClass::print(out);
  // the rest
       
       return out;
}
 
/*F in1 = Read(in)  . . . . . . . . . . . . . . . . . . . . . DataFixedClusterNodeClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataFixedClusterNodeClass, there is no further information.
**
**  REMARKS
**
*/
bool DataFixedClusterNodeClass::Read(istream& in, DataSetOfObjectsClass &set)
{
  bool result = DataDivisiveClusterNodeClass::Read(in,set);

  return result;
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . . . DataFixedClusterNodeClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataFixedClusterNodeClass::CopyClone(Identify *  objc)
{
  DataFixedClusterNodeClass *objcfull = (DataFixedClusterNodeClass *) objc;
  *this = *objcfull;
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . . . DataFixedClusterNodeClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataFixedClusterNodeClass::Clone()
    {
      DataFixedClusterNodeClass* id = new DataFixedClusterNodeClass(*this);
      return (Identify *) id;
    }
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . . DataFixedClusterNodeClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataFixedClusterNodeClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataDivisiveClusterNodeClass::EncodeThis(buffer);
  // result = result && Encode(buffer,------);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . . DataFixedClusterNodeClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataFixedClusterNodeClass::DecodeThis(CommBuffer& buffer)
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
BaseDataObject * DataFixedClusterNodeClass::BaseDataObjectExample()
{ 
  //cout << "Make FixedClusterNode Example\n";
  return (BaseDataObject *) new BaseDataFixedClusterNode();
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . DataFixedClusterNodeClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataFixedClusterNodeClass*& obj)
     {
     obj = new DataFixedClusterNodeClass;
     return obj->DecodeThis(buffer);
     }
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . BaseDataFixedClusterNode
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataFixedClusterNode*& obj)
     {
     obj = new BaseDataFixedClusterNode;
     return obj->DecodeThis(buffer);
     }
/*S BaseDataFixedClusterTree
 */ 
/*F BaseDataFixedClusterTree()  . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataFixedClusterTree::BaseDataFixedClusterTree()
{
  Identification = FULLSETCLUSTER_FIXEDCLUSTERTREE_ID;
  NameTag = FULLSETCLUSTER_FIXEDCLUSTERTREE_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;
} 
/*F BaseDataFixedClusterTree(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataFixedClusterTree::BaseDataFixedClusterTree(const BaseDataFixedClusterTree& data)
  : BaseDataDivisiveClusterTree(data)
{
}
/*F Read(in,objc) . . . . . . . . . . . . . . . . . .  Read in BaseDataFixedClusterTree
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataFixedClusterTree::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . . . . . . . .  Read in BaseDataFixedClusterTree
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataFixedClusterTree::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = BaseDataDivisiveClusterTree::Read(in,objc,name);
  
  return result;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . .  BaseDataFixedClusterTree
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataFixedClusterTree::print(ostream& out) const
{
  BaseDataDivisiveClusterTree::print(out);
  // The rest

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . . . . .BaseDataFixedClusterTree
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataFixedClusterTree::Clone()
{
  BaseDataFixedClusterTree *obj = new BaseDataFixedClusterTree;
  obj->CopyClone(this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . . . . .BaseDataFixedClusterTree
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataFixedClusterTree::CopyClone(Identify * obj)
{
  BaseDataFixedClusterTree *objfull = (BaseDataFixedClusterTree *) obj;
  
  *this = *objfull;
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataFixedClusterTree
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataFixedClusterTree::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataDivisiveClusterTree::EncodeThis(buffer);
  //result = result && ---.EncodeThis(buffer);
  //result = result && Encode(buffer,---);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataFixedClusterTree
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataFixedClusterTree::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataDivisiveClusterTree::DecodeThis(buffer);
  // The rest

  return result;
}
/*F ans = SetUpAlgorithms(instances,instancesclass,run,runclass)  . algorithm
**
**  DESCRIPTION
**    instances: The set of instances
**    instancesclass: The set of instance object classes
**    run: The algorithm run information
**    runclass: The run class
**    
**  REMARKS
**
*/
bool BaseDataFixedClusterTree::SetUpAlgorithms(BaseDataSetOfInstances*,
						      DataSetOfInstancesClass*,
						      BaseDataAlgorithmRun* ,
						      DataAlgorithmRunClass*)
{
  return true;
}
/*F ans = CheckInput(instances,instancesclass,run,runclass) . . . . algorithm
**
**  DESCRIPTION
**    instances: The set of instances
**    instancesclass: The set of instance object classes
**    run: The algorithm run information
**    runclass: The run class
**
**  REMARKS
**
*/
bool BaseDataFixedClusterTree::CheckInput(BaseDataSetOfInstances *instances,
					  DataSetOfInstancesClass *instancesclass,
					  BaseDataAlgorithmRun *run,
					  DataAlgorithmRunClass *runclass)
{
  bool result = BaseDataDivisiveClusterTree::CheckInput(instances,instancesclass,run,runclass);

  if(!run->ParameterInList(numberOfNodesS))
    {
      cerr << "The parameter '" << numberOfNodesS << "' was not in the list of parameters";
      result = false;
    }

  return result;
}
/*F ans = SetUpInput(instances,instancesclass,run,runclass) . . . . algorithm
**
**  DESCRIPTION
**    instances: The set of instances
**    instancesclass: The set of instance object classes
**    run: The algorithm run information
**    runclass: The run class
**    
**  REMARKS
**
*/
bool BaseDataFixedClusterTree::SetUpInput(BaseDataSetOfInstances* instances,
						 DataSetOfInstancesClass* instancesclass,
						 BaseDataAlgorithmRun *run,
						 DataAlgorithmRunClass* runclass)
{
  bool result = BaseDataDivisiveClusterTree::CheckInput(instances,instancesclass,run,runclass);

  numberOfNodesKeys = (BaseDataKeyWords *) run->ParameterValue(numberOfNodesS);
  ObjectList<String> numbers = numberOfNodesKeys->GetKeyWords();
  while(numbers.size() > 0)
    {
      String number = numbers.front();
      numbers.pop_front();
      unsigned int num = number.ToInteger();
      numberOfNodes.AddObject(num);
    }
  return result;
}
/*F ans = Calculate(instances,instancesclass,run,runclass)  . . . . algorithm
**
**  DESCRIPTION
**    instances: The set of instances
**    instancesclass: The set of instance object classes
**    run: The algorithm run information
**    runclass: The run class
**    
**  REMARKS
**
*/
bool BaseDataFixedClusterTree::Calculate(BaseDataSetOfInstances *instances,
						DataSetOfInstancesClass *instancesclass,
						BaseDataAlgorithmRun *run,
						DataAlgorithmRunClass *runclass)
{
  bool result = BaseDataDivisiveClusterTree::Calculate(instances,instancesclass,run,runclass);
  return result;
}
/*F ans = WriteOutputValues(instances,instancesclass,run,runclass)  algorithm
**
**  DESCRIPTION
**    instances: The set of instances
**    instancesclass: The set of instance object classes
**    run: The algorithm run information
**    runclass: The run class
**    
**  REMARKS
**
*/
bool BaseDataFixedClusterTree::WriteOutputValues(BaseDataSetOfInstances*,
							DataSetOfInstancesClass*,
							BaseDataAlgorithmRun* run,
							DataAlgorithmRunClass*)
{
  bool result = true;
  
//  run->AddParameter(ctree);

  return result;
}
/*F ans = ConcludeRun(instances,instancesclass,run,runclass)  . . . algorithm
**
**  DESCRIPTION
**    instances: The set of instances
**    instancesclass: The set of instance object classes
**    run: The algorithm run information
**    runclass: The run class
**    
**  REMARKS
**
*/
bool BaseDataFixedClusterTree::ConcludeRun(BaseDataSetOfInstances*,
						  DataSetOfInstancesClass*,
						  BaseDataAlgorithmRun*,
						  DataAlgorithmRunClass*)
{
  bool result = true;
//  delete something
  return result;
}
 
/*F sons = PerformDivisiveClustering(node)  . . . .  BaseDataFixedClusterNode
**
**  DESCRIPTION
**    node: The parent node
**    sons: The sons 
**
**  REMARKS
**
*/
BaseDataSetOfObjects *BaseDataFixedClusterTree::PerformDivisiveClustering(BaseDataSetOfInstances* instances,
									  DataSetOfInstancesClass* instancesclass,
									  BaseDataDivisiveClusterNode *node)
{
  BaseDataSetOfObjects *set = NULL;
  return set;
} 
/*F measure = EvaluateCluster(node,cluster) . . . .  BaseDataFixedClusterTree
**
**  DESCRIPTION
**    node: 
**    cluster: The set of nodes 
**
**  REMARKS
**
*/
double BaseDataFixedClusterTree::EvaluateCluster(BaseDataDivisiveClusterNode *node,
						 BaseDataSetOfObjects *cluster)
{
  return 0.0;
}
 /*F
**
**  DESCRIPTION
**    
**  REMARKS
**
*/

/*S DataFixedClusterTreeClass
 */
/*F DataFixedClusterTreeClass() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataFixedClusterTreeClass::DataFixedClusterTreeClass()
{
  Identification = FULLSETCLUSTER_FIXEDCLUSTERTREE_ID;
  NameTag = FULLSETCLUSTER_FIXEDCLUSTERTREE_NAME;
  SubClass = "DivisiveClusterTree";
  EncodeDecodeClass = NameTag;
} 
/*F DataFixedClusterTreeClass(data) . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataFixedClusterTreeClass::DataFixedClusterTreeClass(const DataFixedClusterTreeClass& data)
  : DataDivisiveClusterTreeClass(data)
{
} 
 
/*F DataFixedClusterTreeClass(id,name,descr)  . . . . . . . . . . . . . . . constructor
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
DataFixedClusterTreeClass::DataFixedClusterTreeClass(const int id, 
				 const String& name,
				 const String& descr)
  : DataDivisiveClusterTreeClass(id,name,descr)
{
  SubClass = "DivisiveClusterTree";
  EncodeDecodeClass = FULLSETCLUSTER_FIXEDCLUSTERTREE_NAME;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . . DataFixedClusterTreeClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataFixedClusterTreeClass::print(ostream& out) const
{
  DataDivisiveClusterTreeClass::print(out);
  // the rest
       
       return out;
}
 
/*F in1 = Read(in)  . . . . . . . . . . . . . . . . . . . . . DataFixedClusterTreeClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataFixedClusterTreeClass, there is no further information.
**
**  REMARKS
**
*/
bool DataFixedClusterTreeClass::Read(istream& in, DataSetOfObjectsClass &set)
{
  bool result = DataDivisiveClusterTreeClass::Read(in,set);

  return result;
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . . . DataFixedClusterTreeClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataFixedClusterTreeClass::CopyClone(Identify *  objc)
{
  DataFixedClusterTreeClass *objcfull = (DataFixedClusterTreeClass *) objc;
  *this = *objcfull;
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . . . DataFixedClusterTreeClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataFixedClusterTreeClass::Clone()
    {
      DataFixedClusterTreeClass* id = new DataFixedClusterTreeClass(*this);
      return (Identify *) id;
    }
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . . DataFixedClusterTreeClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataFixedClusterTreeClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataDivisiveClusterTreeClass::EncodeThis(buffer);
  // result = result && Encode(buffer,------);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . . DataFixedClusterTreeClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataFixedClusterTreeClass::DecodeThis(CommBuffer& buffer)
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
BaseDataObject * DataFixedClusterTreeClass::BaseDataObjectExample()
{ 
  //cout << "Make FixedClusterTree Example\n";
  return (BaseDataObject *) new BaseDataFixedClusterTree();
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . DataFixedClusterTreeClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataFixedClusterTreeClass*& obj)
     {
     obj = new DataFixedClusterTreeClass;
     return obj->DecodeThis(buffer);
     }
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . BaseDataFixedClusterTree
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataFixedClusterTree*& obj)
     {
     obj = new BaseDataFixedClusterTree;
     return obj->DecodeThis(buffer);
     }
