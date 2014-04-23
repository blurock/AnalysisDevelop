/*  FILE     FullSetClusterType.hh
**  PACKAGE  FullSetCluster
**  AUTHOR   Edward S. Blurock
**
**  CONTENT
**    Class definitions for the "FullSetCluster" package.
**
**  OVERVIEW
**
**  IMPLEMENTATION
**
**  REFERENCES
**
**  COPYRIGHT (C) 1996 CoreObjects Project, RISC Linz
*/
 
#ifndef CoreObjects_FULLSETCLUSTERTYPE_HH
#define CoreObjects_FULLSETCLUSTERTYPE_HH

/*I  . . . INCLUDES  . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/

/*C BaseDataFullSetClusterTree  . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    This is the FullSetClusterTree class definitions
**
**  REMARKS
**    Inheirits BaseDataClusterTree
*/
class BaseDataFullSetClusterTree : public BaseDataClusterTree
{
  String trainInstanceNamesS;
  BaseDataKeyWords *trainInstanceNames;
  String testInstanceNamesS;
  BaseDataKeyWords *testInstanceNames;
public:
  BaseDataFullSetClusterTree();
  BaseDataFullSetClusterTree(const BaseDataFullSetClusterTree& data);

  STANDARD_VIRTUAL_METHODS_OBJECT;
  STANDARD_VIRTUAL_ALGORITHM_OBJECT_METHODS;
  virtual bool WriteAsLine(ostream&, DataObjectClass *);
  virtual bool WriteAsASCII(ostream&, DataObjectClass *);
  virtual bool WriteAsLatex(ostream&, DataObjectClass  *);

  BaseDataKeyWords *getTrainInstanceNames();
  BaseDataKeyWords *getTestInstanceNames();
  void InitializeRootNode(DataClusterTreeClass *treeclass);
};
/*C DataFullSetClusterTreeClass . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
**     Inheirits DataClusterTreeClass
*/
class DataFullSetClusterTreeClass : public DataClusterTreeClass
{
public:
  DataFullSetClusterTreeClass();
  DataFullSetClusterTreeClass(const DataFullSetClusterTreeClass& data);
  DataFullSetClusterTreeClass(const int id, 
		    const String& name,
		    const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS
};
/*C BaseDataFullSetClusterNode  . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    This is the FullSetClusterNode class definitions
**
**  REMARKS
**    Inheirits BaseDataClusterNode
*/
class BaseDataFullSetClusterNode : public BaseDataClusterNode
{
public:
  BaseDataFullSetClusterNode();
  BaseDataFullSetClusterNode(const BaseDataFullSetClusterNode& data);

  STANDARD_VIRTUAL_METHODS_OBJECT
};
/*C DataFullSetClusterNodeClass . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
**     Inheirits DataClusterNodeClass
*/
class DataFullSetClusterNodeClass : public DataClusterNodeClass
{
public:
  DataFullSetClusterNodeClass();
  DataFullSetClusterNodeClass(const DataFullSetClusterNodeClass& data);
  DataFullSetClusterNodeClass(const int id, 
		    const String& name,
		    const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS
};
/*C BaseDataDivisiveClusterNode  . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    This is the DivisiveClusterNode class definitions
**
**  REMARKS
**    Inheirits BaseDataFullSetClusterNode
*/
class BaseDataDivisiveClusterNode : public BaseDataFullSetClusterNode
{
public:
  BaseDataDivisiveClusterNode();
  BaseDataDivisiveClusterNode(const BaseDataDivisiveClusterNode& data);

  STANDARD_VIRTUAL_METHODS_OBJECT
};
/*C DataDivisiveClusterNodeClass . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
**     Inheirits DataFullSetClusterNodeClass
*/
class DataDivisiveClusterNodeClass : public DataFullSetClusterNodeClass
{
public:
  DataDivisiveClusterNodeClass();
  DataDivisiveClusterNodeClass(const DataDivisiveClusterNodeClass& data);
  DataDivisiveClusterNodeClass(const int id, 
		    const String& name,
		    const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS
};
/*C BaseDataDivisiveTreeCluster  . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    This is the DivisiveClusterTree class definitions
**
**  REMARKS
**    Inheirits BaseDataFullSetClusterTree
*/
class BaseDataDivisiveClusterTree : public BaseDataFullSetClusterTree
{
  ObjectList<String> OpenNodes;
  unsigned int debugLevel;

  String membershipCutOffS;
  double membershipCutOff;
  
public:
  BaseDataDivisiveClusterTree();
  BaseDataDivisiveClusterTree(const BaseDataDivisiveClusterTree& data);

  STANDARD_VIRTUAL_METHODS_OBJECT;
  STANDARD_VIRTUAL_ALGORITHM_OBJECT_METHODS;
  virtual bool WriteAsLine(ostream&, DataObjectClass *);
  virtual bool WriteAsASCII(ostream&, DataObjectClass *);
  virtual bool WriteAsLatex(ostream&, DataObjectClass  *);

  virtual void InitializeRootNode(DataClusterTreeClass *treeclass);
  virtual bool NodePreProcessing(BaseDataDivisiveClusterNode *node);
  virtual bool NodePostProcessing(BaseDataSetOfObjects *sons);
  virtual bool expandNodeP(BaseDataDivisiveClusterNode *node);
  virtual BaseDataSetOfObjects *PerformDivisiveClustering(BaseDataSetOfInstances* instances,
							  DataSetOfInstancesClass* instancesclass,
							  BaseDataDivisiveClusterNode *node);
  virtual BaseDataDivisiveClusterNode *getNextOpenNode();
  virtual void addNodesToTree(BaseDataSetOfObjects *newnodes,
			     BaseDataDivisiveClusterNode *parent);
  virtual bool ContinueClusterIteration(double diff,
					BaseDataSetOfObjects *);
  virtual void ClusterInstancesOnNodes(BaseDataSetOfInstances* instances,
				       DataSetOfInstancesClass* instancesclass,
				       BaseDataDivisiveClusterNode *node,
				       BaseDataSetOfObjects *sons);
  virtual void ComputeClusterQualityMeasure(BaseDataDivisiveClusterNode *,
					    BaseDataSetOfObjects *);
  virtual double AdjustClusterStructure(BaseDataDivisiveClusterNode *,
					BaseDataSetOfObjects *);
  virtual double GetDistanceToNode(BaseDataInstance *instance, 
				   BaseDataDivisiveClusterNode *object);
  virtual BaseDataLogicDescription *DetermineNodeMembership(BaseDataSetOfObjects *sons,
							    DataClusterNodeClass *nodeclass,
							    ObjectList<double> distancelist);
  virtual BaseDataSetOfObjects *InitializationOfSons(BaseDataDivisiveClusterNode *node);
  virtual void AssignInstanceToNode(BaseDataLogicDescription *membership,
				    BaseDataSetOfObjects *sons,
				    BaseDataInstance *instance);
  unsigned int getDebugLevel();
};
/*C DataDivisiveClusterTreeClass . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
**     Inheirits DataFullSetClusterTreeClass
*/
class DataDivisiveClusterTreeClass : public DataFullSetClusterTreeClass
{
public:
  DataDivisiveClusterTreeClass();
  DataDivisiveClusterTreeClass(const DataDivisiveClusterTreeClass& data);
  DataDivisiveClusterTreeClass(const int id, 
			       const String& name,
			       const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS;
};
/*C BaseDataFixedClusterNode  . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    This is the FixedClusterNode class definitions
**
**  REMARKS
**    Inheirits BaseDataDivisiveClusterNode
*/
class BaseDataFixedClusterNode : public BaseDataDivisiveClusterNode
{
public:
  BaseDataFixedClusterNode();
  BaseDataFixedClusterNode(const BaseDataFixedClusterNode& data);

  STANDARD_VIRTUAL_METHODS_OBJECT
};
/*C DataFixedClusterNodeClass . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
**     Inheirits DataDivisiveClusterNodeClass
*/
class DataFixedClusterNodeClass : public DataDivisiveClusterNodeClass
{
public:
  DataFixedClusterNodeClass();
  DataFixedClusterNodeClass(const DataFixedClusterNodeClass& data);
  DataFixedClusterNodeClass(const int id, 
		    const String& name,
		    const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS
};
/*C BaseDataFixedClusterTree  . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    This is the FixedClusterTree class definitions
**
**  REMARKS
**    Inheirits BaseDataDivisiveClusterTree
*/
class BaseDataFixedClusterTree : public BaseDataDivisiveClusterTree
{
  String numberOfNodesS;
  BaseDataKeyWords *numberOfNodesKeys;
  ObjectList<unsigned int> numberOfNodes;

public:
  BaseDataFixedClusterTree();
  BaseDataFixedClusterTree(const BaseDataFixedClusterTree& data);

  STANDARD_VIRTUAL_METHODS_OBJECT;
  STANDARD_VIRTUAL_ALGORITHM_OBJECT_METHODS;
  virtual BaseDataSetOfObjects
    *DetermineClusterOfFixedSize(unsigned int nclusters, 
				 BaseDataDivisiveClusterNode *node);
  virtual double EvaluateCluster(BaseDataDivisiveClusterNode *node,
				 BaseDataSetOfObjects *cluster);
  virtual BaseDataSetOfObjects *PerformDivisiveClustering(BaseDataSetOfInstances* instances,
							  DataSetOfInstancesClass* instancesclass,
							  BaseDataDivisiveClusterNode *node);
};
/*C DataFixedClusterTreeClass . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
**     Inheirits DataDivisiveClusterTreeClass
*/
class DataFixedClusterTreeClass : public DataDivisiveClusterTreeClass
{
public:
  DataFixedClusterTreeClass();
  DataFixedClusterTreeClass(const DataFixedClusterTreeClass& data);
  DataFixedClusterTreeClass(const int id, 
		    const String& name,
		    const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS
};

#endif
