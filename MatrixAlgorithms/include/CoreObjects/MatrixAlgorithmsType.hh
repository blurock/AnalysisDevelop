/*  FILE     MatrixAlgorithmsType.hh
**  PACKAGE  MatrixAlgorithms
**  AUTHOR   Edward S. Blurock
**
**  CONTENT
**    Class definitions for the "MatrixAlgorithms" package.
**
**  OVERVIEW
**
**  IMPLEMENTATION
**
**  REFERENCES
**
**  COPYRIGHT (C) 1996 CoreObjects Project, RISC Linz
*/
 
#ifndef CoreObjects_MATRIXALGORITHMSTYPE_HH
#define CoreObjects_MATRIXALGORITHMSTYPE_HH

/*I  . . . INCLUDES  . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/
/*P  . . . PROTOTYPES  . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/
class DataMatrixClusterClass;

/*C BaseDataMatrixCluster  . . . . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    This is the MatrixCluster class definitions with the following 
**    virtual functions:
**    - Read(stream,objc): Read from ASCII stream (using objc for additional format info)
**    - Read(stream,objc,name): Read from ASCII stream (if the name of the object already known)
**    - Write(stream,objc): Write with formatting details
**    - Clone(),CopyClone(obj): Clone a copy
**    - EncodeThis(buffer),DecodeThis(buffer): Encode and Decode routines
**    - print(out): Standard default output routine
**
**  REMARKS
**    Inheirits BaseDataAlgorithmOperation
*/
class BaseDataMatrixCluster : public BaseDataAlgorithmOperation
{
public:
  BaseDataMatrixCluster();
  BaseDataMatrixCluster(const BaseDataMatrixCluster& data);

  virtual void operator()(BaseDataSetOfInstances& instances,
			  BaseDataAlgorithmRun& run,
			  DataAlgorithmRunClass& runclass);
  STANDARD_VIRTUAL_METHODS_OBJECT;
  STANDARD_VIRTUAL_ALGORITHM_OBJECT_METHODS;
};
/*C DataMatrixClusterClass . . . . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**    This is the base function about a data type:
**       Identification: The numerical value of the type
**       NameTag: The ASCII name of the type
**       Description: The text description of the class
**
**  REMARKS
**     Inheirits DataAlgorithmOperationClass
*/
class DataMatrixClusterClass : public DataAlgorithmOperationClass
{
public:
  DataMatrixClusterClass();
  DataMatrixClusterClass(const DataMatrixClusterClass& data);
  DataMatrixClusterClass(const int id, 
		    const String& name,
		    const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS;
};

#endif

