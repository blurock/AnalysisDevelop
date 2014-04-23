/*  FILE     MatrixClusterTreeType.hh
**  PACKAGE  MatrixClusterTree
**  AUTHOR   Edward S. Blurock
**
**  CONTENT
**    Class definitions for the "MatrixClusterTree" package.
**
**  OVERVIEW
**
**  IMPLEMENTATION
**
**  REFERENCES
**
**  COPYRIGHT (C) 1996 CoreObjects Project, RISC Linz
*/
 
#ifndef CoreObjects_MATRIXCLUSTERTREETYPE_HH
#define CoreObjects_MATRIXCLUSTERTREETYPE_HH

/*I  . . . INCLUDES  . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/
/*C BaseDataMatrixClusterTree  . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    This is the MatrixClusterTree class definitions
**
**  REMARKS
**    Inheirits BaseDataDivisiveClusterTree
*/
class BaseDataMatrixClusterTree : public BaseDataDivisiveClusterTree
{
public:
  BaseDataMatrixClusterTree();
  BaseDataMatrixClusterTree(const BaseDataMatrixClusterTree& data);

  STANDARD_VIRTUAL_METHODS_OBJECT
};
/*C DataMatrixClusterTreeClass . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
**     Inheirits DataDivisiveClusterTreeClass
*/
class DataMatrixClusterTreeClass : public DataDivisiveClusterTreeClass
{
public:
  DataMatrixClusterTreeClass();
  DataMatrixClusterTreeClass(const DataMatrixClusterTreeClass& data);
  DataMatrixClusterTreeClass(const int id, 
		    const String& name,
		    const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS
};
/*C BaseDataMatrixClusterNode  . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    This is the MatrixClusterNode class definitions
**
**  REMARKS
**    Inheirits BaseDataDivisiveClusterNode
*/
class BaseDataMatrixClusterNode : public BaseDataDivisiveClusterNode
{
public:
  BaseDataMatrixClusterNode();
  BaseDataMatrixClusterNode(const BaseDataMatrixClusterNode& data);

  STANDARD_VIRTUAL_METHODS_OBJECT
};
/*C DataMatrixClusterNodeClass . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
**     Inheirits DataDivisiveClusterNodeClass
*/
class DataMatrixClusterNodeClass : public DataDivisiveClusterNodeClass
{
public:
  DataMatrixClusterNodeClass();
  DataMatrixClusterNodeClass(const DataMatrixClusterNodeClass& data);
  DataMatrixClusterNodeClass(const int id, 
		    const String& name,
		    const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS
};




#endif
