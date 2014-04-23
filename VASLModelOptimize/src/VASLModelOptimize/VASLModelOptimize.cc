/*  FILE     SimulatedAnnealing.cpp
**  PACKAGE  VASLModelOptimize    
**  AUTHOR   
**
**  CONTENT
**    
**
**  REFERENCES
**
*/
#define TEMPLATE_INSTANTIATION

#include "SimulatedAnnealing.hh"
#include "VASLModels.hh"
#include "VASLModelOptimize.hh"


Vector<int> *BaseDataWidthModelOptimizeFunction::indexVec = 0;



/*S BaseDataWidthModelMatrixSetUp
 */ 
/*F BaseDataWidthModelMatrixSetUp()  . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataWidthModelMatrixSetUp::BaseDataWidthModelMatrixSetUp()
: TenPercentsS("TenPercents"),
  TenPercents(false),
  TotalInstanceNameListS("TotalInstanceNameList"),
  AttributeNamesS("AttributeNames"),
  TestMatrixObjectS("TestMatrixObject"),
  TrainMatrixObjectS("TrainMatrixObject")
{
  Identification = WIDTHMODELALG_MATRIX_ID;
  NameTag = WIDTHMODELALG_MATRIX_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;
} 
/*F BaseDataWidthModelMatrixSetUp(data)  . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataWidthModelMatrixSetUp::BaseDataWidthModelMatrixSetUp(const BaseDataWidthModelMatrixSetUp& data)
  : BaseDataAlgorithmOperation(data)
{
}
 
/*F Read(in,objc) . . . . . . . . . . . . . . . . . .  Read in BaseDataWidthModelMatrixSetUp
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataWidthModelMatrixSetUp::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();
  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . . . . . . . .  Read in BaseDataWidthModelMatrixSetUp
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataWidthModelMatrixSetUp::Read(istream& in, DataObjectClass* objc, const String& name)
{
  return BaseDataAlgorithmOperation::Read(in,objc,name);
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . .  BaseDataWidthModelMatrixSetUp
**
**  DESCRIPTION
**    out,out1: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataWidthModelMatrixSetUp::print(ostream& out) const
{
  BaseDataAlgorithmOperation::print(out);
  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . . . . .BaseDataWidthModelMatrixSetUp
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataWidthModelMatrixSetUp::Clone()
{
  BaseDataWidthModelMatrixSetUp *obj = new BaseDataWidthModelMatrixSetUp;
  obj->CopyClone(this);
  return obj;
}
 
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . . . . .BaseDataWidthModelMatrixSetUp
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataWidthModelMatrixSetUp::CopyClone(Identify * obj)
{
  BaseDataWidthModelMatrixSetUp *objc = (BaseDataWidthModelMatrixSetUp *) obj;
  *this = *objc;
}
 
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataWidthModelMatrixSetUp
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataWidthModelMatrixSetUp::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataAlgorithmOperation::EncodeThis(buffer);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . .  BaseDataWidthModelMatrixSetUp
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataWidthModelMatrixSetUp::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataAlgorithmOperation::DecodeThis(buffer);
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
bool BaseDataWidthModelMatrixSetUp::SetUpAlgorithms(BaseDataSetOfInstances*,
					  DataSetOfInstancesClass*,
					  BaseDataAlgorithmRun* ,
					  DataAlgorithmRunClass*)
{
  return true;
}
/*F ans = CheckInput(instances,instancesclass,run,runclass) . . . . algorithm
**
**  DESCRIPTION
**    instances:     The set of instances
**    instancesclass: The instance classes
**    run:            The algorithm run class
**    runclass:       The class of algorithm run
**    
**  REMARKS
**
*/
bool BaseDataWidthModelMatrixSetUp::CheckInput(BaseDataSetOfInstances*,
				     DataSetOfInstancesClass*,
				     BaseDataAlgorithmRun* run,
				     DataAlgorithmRunClass*)
{
  bool result = true;
  
  if(!(run->ParameterInList(TotalInstanceNameListS)))  {
      cout << "Parameter not found: " << TotalInstanceNameListS << endl;
      result = false;
  }
  if(!(run->ParameterInList(AttributeNamesS)))  {
      cout << "Parameter not found: " << AttributeNamesS << endl;
      result = false;
  }

  if(run->AlgorithmSummary.KeyWordInList(TenPercentsS)) {
    TenPercents = true;
    cout << "TenPercents found" << endl;
  }
  else {
    TenPercents = false;
  }
  
  return result;
}
/*F ans = SetUpInput(instances,instancesclass,run,runclass) . . . . algorithm
**
**  DESCRIPTION
**    instances:     The set of instances
**    instancesclass: The instance classes
**    run:            The algorithm run class
**    runclass:       The class of algorithm run
**
**  REMARKS
**
*/
bool BaseDataWidthModelMatrixSetUp::SetUpInput(BaseDataSetOfInstances*,
				     DataSetOfInstancesClass*,
				     BaseDataAlgorithmRun* run,
				     DataAlgorithmRunClass*)
{
  bool result = true;
  
  TotalInstanceNameList = (BaseDataKeyWords *) run->ParameterValue(TotalInstanceNameListS);
  AttributeNames = (BaseDataKeyWords *) run->ParameterValue(AttributeNamesS);

  return result;
}
 
/*F ans = Calculate(instances,instancesclass,run,runclass)  . . . . algorithm
**
**  DESCRIPTION
**    instances:     The set of instances
**    instancesclass: The instance classes
**    run:            The algorithm run class
**    runclass:       The class of algorithm run
**
**  REMARKS
**
*/
bool BaseDataWidthModelMatrixSetUp::Calculate(BaseDataSetOfInstances* instances,
				    DataSetOfInstancesClass*,
				    BaseDataAlgorithmRun *,
				    DataAlgorithmRunClass*)
{
cout << "BaseDataWidthModelMatrixSetUp::Calculate" << endl;
  bool result = true;
	int icount = 0;
	int nbTrainData = 0;
	int nbTestData = 0;
  
  ObjectList<String>::iterator in;
  ObjectList<String>::iterator attr;
  ObjectList<String> insts = TotalInstanceNameList->GetKeyWords();
  ObjectList<String> attrs = AttributeNames->GetKeyWords();

  MatrixNumeric *matTest = new MatrixNumeric();
  MatrixNumeric *matTrain = new MatrixNumeric();
  BaseDataKeyWords *instNameTest = new BaseDataKeyWords();
  BaseDataKeyWords *instNameTrain = new BaseDataKeyWords();


  if (TenPercents) {
    cout << "------- TenPercents ------" << endl;

    for(in = insts.begin(); in!=insts.end(); in++) {
      BaseDataInstance *instance = instances->GetInstance(*in);
      VectorNumeric vec;
      for(attr = attrs.begin(); attr != attrs.end(); attr++) {
        BaseDataNumeric *param = (BaseDataNumeric *) instance->GetAttributeValue(*attr);
        double value = param->Distance();
        vec.AddObject(value);
      }

  		if (icount % 10 == 0)	{ // 10 percent of data for learning;
        nbTrainData++;        // count the number of traindata
        matTrain->AddObject(vec);
        instNameTrain->AddKeyWord(*in);
      }
      else {                  // 90 percent of data for testing;
        nbTestData++;        // count the number of testdata
        matTest->AddObject(vec);
        instNameTest->AddKeyWord(*in);
      }
      icount++;
    }
	
    cout << "------- nbTrainData ------" << nbTrainData << endl;
    cout << "----vgl nbTrainData ------" << matTrain->size() << endl;
    cout << "------- nbTestData -------" << nbTestData << endl;
    cout << "---vgl- nbTestData -------" << matTest->size() << endl;
    cout << "---vgl- icount -----------" << icount << endl;
  }
  

    TestMatrixObject = 
      new BaseDataInstanceDoubleMatrix(*matTest,
                                       *instNameTest,
                                       *AttributeNames);
    TestMatrixObject->NameTag = TestMatrixObjectS;

    TrainMatrixObject = 
      new BaseDataInstanceDoubleMatrix(*matTrain,
                                       *instNameTrain,
                                       *AttributeNames);
    TrainMatrixObject->NameTag = TrainMatrixObjectS;

				



  delete matTest;
  delete matTrain;
  delete instNameTest;
  delete instNameTrain;
  
cout << "BaseDataWidthModelMatrixSetUp::Calculate end" << endl;
  return result;
}
/*F ans = WriteOutputValues(instances,instancesclass,run,runclass) algorithm 
**
**  DESCRIPTION
**    instances:     The set of instances
**    instancesclass: The instance classes
**    run:            The algorithm run class
**    runclass:       The class of algorithm run
**    
**  REMARKS
**
*/
bool BaseDataWidthModelMatrixSetUp::WriteOutputValues(BaseDataSetOfInstances*,
					    DataSetOfInstancesClass*,
					    BaseDataAlgorithmRun* run,
					    DataAlgorithmRunClass*) 
{
cout << "====================== WriteOutputValues" << endl;
  bool result = true;

  run->AddParameter(TestMatrixObject);
  run->AddParameter(TrainMatrixObject);

cout << "====================== WriteOutputValues end" << endl;
  return result;
}
/*F ans = ConcludeRun(instances,instancesclass,run,runclass)  . . . algorithm
**
**  DESCRIPTION
**    instances:     The set of instances
**    instancesclass: The instance classes
**    run:            The algorithm run class
**    runclass:       The class of algorithm run
**    
**  REMARKS
**
*/
bool BaseDataWidthModelMatrixSetUp::ConcludeRun(BaseDataSetOfInstances*,
				      DataSetOfInstancesClass*,
				      BaseDataAlgorithmRun*,
				      DataAlgorithmRunClass* ) 
{
cout << "====================== ConcludeRun" << endl;
  if(TestMatrixObject != NULL)
    delete TestMatrixObject;
  if(TrainMatrixObject != NULL)
    delete TrainMatrixObject;
  
  TestMatrixObject = NULL;
  TrainMatrixObject = NULL;

cout << "====================== ConcludeRun end" << endl;
  return true;
}

/*S DataWidthModelMatrixSetUpClass
 */
/*F DataWidthModelMatrixSetUpClass() . . . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataWidthModelMatrixSetUpClass::DataWidthModelMatrixSetUpClass()
{
  NameTag = WIDTHMODELALG_MATRIX_NAME;
  Identification = WIDTHMODELALG_MATRIX_ID;
  SubClass = "AlgorithmOperation";
  EncodeDecodeClass = WIDTHMODELALG_MATRIX_NAME;
} 
/*F DataWidthModelMatrixSetUpClass(data) . . . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataWidthModelMatrixSetUpClass::DataWidthModelMatrixSetUpClass(const DataWidthModelMatrixSetUpClass& data)
  : DataAlgorithmOperationClass(data)
     // the rest
{
} 
 
/*F DataWidthModelMatrixSetUpClass(id,name,descr)  . . . . . . . . . . . . . . . constructor
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
DataWidthModelMatrixSetUpClass::DataWidthModelMatrixSetUpClass(const int id, 
					   const String& name,
					   const String& descr)
  : DataAlgorithmOperationClass(id,name,descr)
{
  SubClass = "AlgorithmOperation";
  EncodeDecodeClass = WIDTHMODELALG_MATRIX_NAME;
}
 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . . . DataWidthModelMatrixSetUpClass
**
**  DESCRIPTION
**    out1,out: The output buffer
**
**  REMARKS
**
*/
ostream& DataWidthModelMatrixSetUpClass::print(ostream& out) const
{
  DataAlgorithmOperationClass::print(out);
  out << NameTag << "  ";
  // the rest
	   
       return out;
}
 
/*F in1 = Read(in,set)  . . . . . . . . . . . . . . . . . . . . . DataWidthModelMatrixSetUpClass
**
**  DESCRIPTION
**    in,in1: The input buffer
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataMatrixSetUpClass, there is no further information.
**
**  REMARKS
**
*/
bool DataWidthModelMatrixSetUpClass::Read(istream& in, DataSetOfObjectsClass& set)
{
  return DataAlgorithmOperationClass::Read(in,set);
}
 
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . . . DataWidthModelMatrixSetUpClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataWidthModelMatrixSetUpClass::CopyClone(Identify *  objc)
{
  DataWidthModelMatrixSetUpClass *objcc = (DataWidthModelMatrixSetUpClass *) objc;
  *this = *objcc;
}
 
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . . . DataWidthModelMatrixSetUpClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataWidthModelMatrixSetUpClass::Clone()
{
  DataWidthModelMatrixSetUpClass* id = new DataWidthModelMatrixSetUpClass(*this);
  return (Identify *) id;
}
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . . . DataWidthModelMatrixSetUpClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataWidthModelMatrixSetUpClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataAlgorithmOperationClass::EncodeThis(buffer);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . . . DataWidthModelMatrixSetUpClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataWidthModelMatrixSetUpClass::DecodeThis(CommBuffer& buffer)
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
BaseDataObject * DataWidthModelMatrixSetUpClass::BaseDataObjectExample()
{ 
  //cout << "Make WidthModelMatrixSetUp Example\n";
  return (BaseDataObject *) new BaseDataWidthModelMatrixSetUp();
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . DataWidthModelMatrixSetUpClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataWidthModelMatrixSetUpClass*& obj)
{
  obj = new DataWidthModelMatrixSetUpClass;
  return obj->DecodeThis(buffer);
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . . . BaseDataWidthModelMatrixSetUp
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataWidthModelMatrixSetUp*& obj)
{
  obj = new BaseDataWidthModelMatrixSetUp;
  return obj->DecodeThis(buffer);
}




/*S BaseDataWidthModelOptimizeFunction
 */ 
/*F BaseDataWidthModelOptimizeFunction()  . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataWidthModelOptimizeFunction::BaseDataWidthModelOptimizeFunction()
{
  Identification = OPERATION_WIDTHMODELTOOPT_ID;
  NameTag = OPERATION_WIDTHMODELTOOPT_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;
  
  initOrigPars();
} 
/*F BaseDataWidthModelOptimizeFunction(data)  . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataWidthModelOptimizeFunction::BaseDataWidthModelOptimizeFunction(const BaseDataWidthModelOptimizeFunction& data)
: BaseDataFunctionToOptimize(data),
origPars(data.origPars)
{
}
/*F BaseDataWidthModelOptimizeFunction. . . . . . . . . . . constructor
**
**  DESCRIPTION
**
**  REMARKS
*/
BaseDataWidthModelOptimizeFunction::BaseDataWidthModelOptimizeFunction(BaseDataInteger *parDim,
				BaseDataSimAnnUpperLower *upLow, 
				BaseDataDoubleVector *parVec,
				BaseDataInstanceDoubleMatrix *dataMat, 
				BaseDataDoubleVector *costTanVec,
				BaseDataDoubleVector *parIntRealVec)
:    BaseDataFunctionToOptimize(parDim,
        upLow, 
        parVec,
        dataMat,
        costTanVec,
        parIntRealVec)
{
  Identification = OPERATION_WIDTHMODELTOOPT_ID;
  NameTag = OPERATION_WIDTHMODELTOOPT_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;

  initOrigPars();
}
/*F initOrigPars()
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
void BaseDataWidthModelOptimizeFunction::initOrigPars(void)
{
  VectorNumeric vec;
  vec.AddObject(-1.877);
  vec.AddObject(0.063);
  vec.AddObject(0.441);
  vec.AddObject(0.989);
  vec.AddObject(7.591);
  vec.AddObject(-1.64);
  vec.AddObject(0.376);
  vec.AddObject(0.016);
  vec.AddObject(0.015);
  vec.AddObject(40.0);
  vec.AddObject(400.0);
  origPars = vec;
}
/*F Read(in,objc) . . . . . . . . . . . Read in BaseDataWidthModelOptimizeFunction
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataWidthModelOptimizeFunction::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();

  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . Read in BaseDataWidthModelOptimizeFunction
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataWidthModelOptimizeFunction::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = true;
  
  if(objc->getDebugLevel() > 2) {
    cout << "Read in BaseDataWidthModelOptimizeFunction:\n";
  }

  
  BaseDataFunctionToOptimize::Read(in,objc,name);

  return result;
}
/*F out1 = print(out) . . . . . . . . . . . . . . . . . .  BaseDataWidthModelOptimizeFunction
**
**  DESCRIPTION
**    out: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataWidthModelOptimizeFunction::print(ostream& out) const
{
  BaseDataFunctionToOptimize::print(out);

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . .  BaseDataWidthModelOptimizeFunction
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataWidthModelOptimizeFunction::Clone()
{
  BaseDataWidthModelOptimizeFunction *obj = new BaseDataWidthModelOptimizeFunction(*this);
  return obj;
}
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . .  BaseDataWidthModelOptimizeFunction
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataWidthModelOptimizeFunction::CopyClone(Identify * obj)
{
  BaseDataWidthModelOptimizeFunction *objfull = (BaseDataWidthModelOptimizeFunction *) obj;
  *this = *objfull;
  BaseDataFunctionToOptimize::CopyClone(obj);
}
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . .  BaseDataWidthModelOptimizeFunction
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataWidthModelOptimizeFunction::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataFunctionToOptimize::EncodeThis(buffer);
  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . .  BaseDataWidthModelOptimizeFunction
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataWidthModelOptimizeFunction::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataFunctionToOptimize::DecodeThis(buffer);
  return result;
}
/*F obj = operator()(x) . . . . . . . . . . . . . . . . . . BaseDataWidthModelOptimizeFunction
**
**  DESCRIPTION
**    x: The object to be operated on
**    obj: The result
**
**
**  REMARKS
**
*/
BaseDataReal BaseDataWidthModelOptimizeFunction::operator()(BaseDataDoubleVector *parToOpt, 
                         BaseDataInstanceDoubleMatrix *dataMat,
                         DataDoubleVectorClass *parToOptClass, 
                         DataInstanceDoubleMatrixClass *dataMatClass) 
{
//0  Dicke_nach_Stich_warm_4                 
//1  Walzkraft_Horizontalgeruest_5           
//2  Walzkraft_Egalisierungsgeruest_5        
//3  Dicke_nach_Stich_warm_5                 
//4  Breite_vor_Stich_warm_5                 
//5  Temperatur_5                            
//6  Anstichgeschwindigkeit_5                
//7  Laenge_nach_Stich_warm_5                
//8  Breite_nach_Stich_warm_5                
//9  Breite_nach_Stich_gemessen_5            
// only pass 5!!
  //  int pass = 5; 
	double sumTotal = 0;
	VectorNumeric modelOuts, actualOuts;
	
  BaseDataVASLWidthModelOperation widthModOp;
  widthModOp.fillCoefficients(parToOpt);
  
  BaseDataVASLWidthModelOperation widthModOpOrig;
  BaseDataDoubleVector *coeffs = new BaseDataDoubleVector(this->origPars);
  widthModOpOrig.fillCoefficients(coeffs);  


  MatrixNumeric theMat = dataMat->CurrentMatrix();
	MatrixNumeric::iterator iterMat;
	
//////  // only the first time create the indeces
//////  if (indexVec == 0) {
//////    createIndexVector(theMat, widthModOp, widthModOpOrig);
//////  }

  // only data from indexVec
//////  int iii = 0;
  int veccount = 0;
  for (iterMat=theMat.begin(); iterMat<theMat.end(); iterMat++) {
////////    if (iii == indexVec->at(veccount)) {
//cout << "iii: " << iii << " vec.at(" << veccount << "): " << indexVec->at(veccount) << endl;
      widthModOp.fillInputParameters(iterMat);
      widthModOpOrig.fillInputParameters(iterMat);

      BaseDataReal modValOrig = widthModOpOrig.calculate();
      BaseDataReal modVal = widthModOp.calculate();

			modelOuts.AddObject(modVal.GetValue());
			actualOuts.AddObject(modValOrig.GetValue());  // the orig one

      veccount++;
//////    }
//////    iii++;
  } 
    

//// only data with with less or equal than 1500
//  MatrixNumeric theMat = dataMat->CurrentMatrix();
//	MatrixNumeric::iterator iterMat;
//	for (iterMat=theMat.begin(); iterMat<theMat.end(); iterMat++) {
//		if ((*iterMat)[9] <= 1500)	{ // width less or equal than 1500
//			widthModOp.fillInputParameters(iterMat);
//			BaseDataReal modVal = widthModOp.calculate();
//			modelOuts.AddObject(modVal.GetValue());
//
//			actualOuts.AddObject((*iterMat)[9]);			// Breite_nach_Stich_gemessen_5
//		}
//		icount++;
//	}

//// only data with with greater than 1500
//  MatrixNumeric theMat = dataMat->CurrentMatrix();
//	MatrixNumeric::iterator iterMat;
//	for (iterMat=theMat.begin(); iterMat<theMat.end(); iterMat++) {
//		if ((*iterMat)[9] > 1500)	{ // width greater than 1500
//			widthModOp.fillInputParameters(iterMat);
//			BaseDataReal modVal = widthModOp.calculate();
//			modelOuts.AddObject(modVal.GetValue());
//
//			actualOuts.AddObject((*iterMat)[9]);			// Breite_nach_Stich_gemessen_5
//		}
//		icount++;
//	}

//// 90 percents of all:
//  MatrixNumeric theMat = dataMat->CurrentMatrix();
//	MatrixNumeric::iterator iterMat;
//	for (iterMat=theMat.begin(); iterMat<theMat.end(); iterMat++) {
//		if (icount % 10 != 0)	{ // 90 percent of data for learning
//			widthModOp.fillInputParameters(iterMat);
//			BaseDataReal modVal = widthModOp.calculate();
//			modelOuts.AddObject(modVal.GetValue());
//
//			actualOuts.AddObject((*iterMat)[9]);			// Breite_nach_Stich_gemessen_5
//		}
//		icount++;
//	}

	sumTotal = calculateDiff(modelOuts, actualOuts);
  cout << "sumTotal" << sumTotal << endl;


    BaseDataReal r;
    r.SetValue(sumTotal);
    
    return (r);

}
/*F obj = createIndexVector() . . . . . . . . . . . . . . . . . . BaseDataWidthModelOptimizeFunction
**
**  DESCRIPTION
**    x: The object to be operated on
**    obj: The result
**
**
**  REMARKS
**
*/
void BaseDataWidthModelOptimizeFunction::createIndexVector(MatrixNumeric& mat,
                                    BaseDataVASLWidthModelOperation& widthModOp,
                                    BaseDataVASLWidthModelOperation& widthModOpOrig) 
{
	int icount = 0;
//	int testID = KindOfTest->GetValue();
	int testID = 3;
  cout << "KindOfTest: " << testID << endl;

  PairList<double, int> pairsOfValsAndInds;
  indexVec = new Vector<int>();

  	MatrixNumeric::iterator iterMat;
    for (iterMat=mat.begin(); iterMat<mat.end(); iterMat++) {
      widthModOp.fillInputParameters(iterMat);
      widthModOpOrig.fillInputParameters(iterMat);

      BaseDataReal origModVal = widthModOpOrig.calculate();
      BaseDataReal modVal = widthModOp.calculate();

      double diff = modVal.GetValue() - origModVal.GetValue();

      // only data with differences: |measured - orig| < 2
      if (testID == 1) {
        if (fabs(diff) < 2.0) {
          indexVec->AddObject(icount);
        }
      }
      // only data with differences: |measured - orig| >= 2
      else if (testID == 2) {
        if (fabs(diff) >= 2.0) {
          indexVec->AddObject(icount);
        }
      }
      // create PairList
      else {
        double val = fabs(diff);
        BasicPair<double, int> OneValAndInd(val, icount);
        pairsOfValsAndInds.AddObject(OneValAndInd);
      }

      icount++;
    } 

  if (testID == 3) {
    indexVec = getIndecesOfFirstN(pairsOfValsAndInds, 5);
  }
  indexVec->AddObject(0);  // one element more because at(...) below will result in an overflow
  cout << "Number total: " << icount << endl;
  cout << "Number for opt: " << indexVec->size()-1 << endl;
  cout << indexVec;
  cout << endl;
}
/*F obj = getIndecesOfFirstN
**
**  DESCRIPTION
**
**  REMARKS
*/
Vector<int> * BaseDataWidthModelOptimizeFunction::
              getIndecesOfFirstN(PairList<double, int>& pairsOfValsAndInds,
                                 int n)
{
  Vector<int> *vec = new Vector<int>();
  pairsOfValsAndInds.Sort();
  PairList<double, int>::iterator iter;
  
  int i=0;
  for (iter=pairsOfValsAndInds.begin();
       iter!=pairsOfValsAndInds.end() && i<n;
       iter++) {
  
    vec->AddObject((*iter).J);
    i++;
  }

  return vec;
}
/*F obj = testOptimizedResult . . . . . . . . . . . . . . . . . . BaseDataWidthModelOptimizeFunction
**
**  DESCRIPTION
**    x: The object to be operated on
**    obj: The result
**
**
**  REMARKS
**	true....gemessen
**	original....urspruengliche parameter
**	optimized....optimierte parameter
*/
BaseDataInstanceDoubleMatrix * BaseDataWidthModelOptimizeFunction::testOptimizedResult(
												BaseDataDoubleVector *origPars, 
												BaseDataDoubleVector *optimizedPars, 
                        BaseDataInstanceDoubleMatrix *dataMat) 
{
	cout << "------- Optimized Parameters ------" << endl;
	optimizedPars->print(cout);
	cout << "------- origPars Parameters ------" << endl;
	origPars->print(cout);
//	cout << "------- dataMat ------" << endl;
//	dataMat->print(cout);
	cout << "------------------------------------" << endl;
// only pass 5!!
	//  int pass = 5; 
	int icount = 0;
	int nbTestData = 0;
	int nbOrigBetter = 0;
	VectorNumeric origOuts, optimizedOuts;
	VectorNumeric diffsOrigOptimized, diffsTrueOrig, diffsTrueOptimized;
	
  BaseDataVASLWidthModelOperation widthModOpOrig;
  widthModOpOrig.fillCoefficients(origPars);  
  BaseDataVASLWidthModelOperation widthModOpOptimized;
  widthModOpOptimized.fillCoefficients(optimizedPars);
  
  
  MatrixNumeric theMat = dataMat->CurrentMatrix();
	MatrixNumeric::iterator iterMat;

	double totalErrTrueOptimized = 0.0;
	double totalErrTrueOrig = 0.0;
	

	BaseDataKeyWords parNames;
	parNames.AddKeyWord("DiffTrueOptimized");
	parNames.AddKeyWord("DiffTrueOrig");
	parNames.AddKeyWord("DiffOrigOptimized");
	ObjectList<String> pnames = parNames.GetKeyWords();
	
	BaseDataKeyWords instNames = dataMat->getInstanceNames();
	ObjectList<String> names = instNames.GetKeyWords();
	
	MatrixNumeric matOfDiffs(names.size(), pnames.size());
	
	for (iterMat=theMat.begin(); iterMat<theMat.end(); iterMat++) {
//		if (icount % 10 == 0)	{ // 90 percent of data for learning; the rest for evaluating the result
			nbTestData++;
			

			widthModOpOrig.fillInputParameters(iterMat);
			widthModOpOptimized.fillInputParameters(iterMat);

			BaseDataReal origModVal = widthModOpOrig.calculate();
			BaseDataReal optimizedModVal = widthModOpOptimized.calculate();

			origOuts.AddObject(origModVal.GetValue());
			optimizedOuts.AddObject(optimizedModVal.GetValue());

			double trueWidth = (*iterMat)[9];	// Breite_nach_Stich_gemessen_5
			double currDiffTrueOptimized = trueWidth - optimizedModVal.GetValue();
			double currDiffTrueOrig = trueWidth - origModVal.GetValue();
			double currDiffOrigOptimized = origModVal.GetValue() - optimizedModVal.GetValue();

			totalErrTrueOptimized += fabs(currDiffTrueOptimized);
			totalErrTrueOrig += fabs(currDiffTrueOrig);

			matOfDiffs[icount][0] = fabs(currDiffTrueOptimized);
			matOfDiffs[icount][1] = fabs(currDiffTrueOrig);
			matOfDiffs[icount][2] = fabs(currDiffOrigOptimized);
			
			diffsTrueOptimized.AddObject(currDiffTrueOptimized);
			diffsTrueOrig.AddObject(currDiffTrueOrig);
			diffsOrigOptimized.AddObject(currDiffOrigOptimized);
			
			if( fabs(currDiffTrueOrig) < fabs(currDiffTrueOptimized) ) {
				nbOrigBetter++;
			}
//		}
		icount++;
	}

	cout << endl;
	cout << "Nb of test data:     " << nbTestData << endl;
	cout << "Nb original better:  " << nbOrigBetter << endl;
	cout << "Nb optimized better: " << nbTestData - nbOrigBetter << endl;
	cout << "totalErrTrueOptimized: " << totalErrTrueOptimized << endl;
	cout << "average: " << totalErrTrueOptimized/((double) nbTestData) << endl;
	cout << "totalErrTrueOrig: " << totalErrTrueOrig << endl;
	cout << "average: " << totalErrTrueOrig/((double) nbTestData) << endl;

	
	
	BaseDataInstanceDoubleMatrix *returnMat = 
		new BaseDataInstanceDoubleMatrix(matOfDiffs,
																		 instNames,
																		 parNames);

				
	return returnMat;
}

/*F BaseDataWidthModelOptimizeFunction::calculateDiff(modelOutput, actualOutput)
**
**  DESCRIPTION
**		calculates sum of quadratic errors between the vector modelOutput and
**		vector actualOutput
**
**  REMARKS
*/
double BaseDataWidthModelOptimizeFunction::calculateDiff(VectorNumeric& modelOutput, 
                                                         VectorNumeric& actualOutput) 
{
	double difference = 0;

	for (unsigned int i = 0; i < modelOutput.size(); i++)	{
		double help = modelOutput[i] - actualOutput[i];
		help = help/(modelOutput[i] + actualOutput[i]);
		difference += (help * help);
	}
	return difference;
}


/*S DataWidthModelOptimizeFunctionClass
 */ 
/*F DataWidthModelOptimizeFunctionClass() . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataWidthModelOptimizeFunctionClass::DataWidthModelOptimizeFunctionClass()
{
  Identification = OPERATION_WIDTHMODELTOOPT_ID;
  NameTag = OPERATION_WIDTHMODELTOOPT_NAME;
  SubClass = OPERATION_FCTTOOPT_NAME;
  EncodeDecodeClass = OPERATION_WIDTHMODELTOOPT_NAME;
} 
/*F DataWidthModelOptimizeFunctionClass(data) . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataWidthModelOptimizeFunctionClass::DataWidthModelOptimizeFunctionClass(const DataWidthModelOptimizeFunctionClass& data)
  : DataFunctionToOptimizeClass(data)
{
} 
/*F DataWidthModelOptimizeFunctionClass(id,name,descr)  . . . . . . . . . . . . . constructor
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
DataWidthModelOptimizeFunctionClass::DataWidthModelOptimizeFunctionClass(const int id, 
                                               const String& name,
                                               const String& descr)
  : DataFunctionToOptimizeClass(id,name,descr)

{
  SubClass = OPERATION_FCTTOOPT_NAME;
  EncodeDecodeClass = OPERATION_WIDTHMODELTOOPT_NAME;
}
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . DataWidthModelOptimizeFunctionClass
**
**  DESCRIPTION
**    out: The output buffer
**
**  REMARKS
**
*/
ostream& DataWidthModelOptimizeFunctionClass::print(ostream& out) const
{
  DataFunctionToOptimizeClass::print(out);
  return out;
}
/*F in1 = Read(in,set)  . . . . . . . . . . . . . . . . . DataWidthModelOptimizeFunctionClass
**
**  DESCRIPTION
**    in: The input buffer
**    set: The set of standard classes
**
**    This reads in the rest of the information (after the type
**    has been determined from the first line.  For the
**    base DataNumOpMinusClass, there is no further information.
**
**  REMARKS
**
*/
bool DataWidthModelOptimizeFunctionClass::Read(istream& in, DataSetOfObjectsClass& set)
{
  bool result = DataFunctionToOptimizeClass::Read(in,set);
  return result;
}
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . DataWidthModelOptimizeFunctionClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataWidthModelOptimizeFunctionClass::CopyClone(Identify * objc)
{
  DataWidthModelOptimizeFunctionClass *objcfull = (DataWidthModelOptimizeFunctionClass*) objc;
  *this = *objcfull;
  DataFunctionToOptimizeClass::CopyClone(objc);
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . DataWidthModelOptimizeFunctionClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataWidthModelOptimizeFunctionClass::Clone()
{
  DataWidthModelOptimizeFunctionClass* id = new DataWidthModelOptimizeFunctionClass(*this);
  return (Identify *) id;
}
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . DataWidthModelOptimizeFunctionClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataWidthModelOptimizeFunctionClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataFunctionToOptimizeClass::EncodeThis(buffer);
  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . DataWidthModelOptimizeFunctionClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataWidthModelOptimizeFunctionClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataFunctionToOptimizeClass::DecodeThis(buffer);
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
BaseDataObject * DataWidthModelOptimizeFunctionClass::BaseDataObjectExample()
{ 
  return (BaseDataObject *) new BaseDataWidthModelOptimizeFunction();
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . DataWidthModelOptimizeFunctionClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataWidthModelOptimizeFunctionClass*& obj)
{
  obj = new DataWidthModelOptimizeFunctionClass;
  return obj->DecodeThis(buffer);
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . .  BaseDataWidthModelOptimizeFunction
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataWidthModelOptimizeFunction*& obj)
{
  obj = new BaseDataWidthModelOptimizeFunction;
  return obj->DecodeThis(buffer);
}






/*F AddVASLModelOptimizeClasses(set) . . . . . . . . . . . . add new classes
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
void AddVASLModelOptimizeClasses(DataSetOfObjectsClass& set)
{
  String widthModOptDescr("Width Model Optimize Class");
  String widthModMatDescr("Width Model Matrix Setup Class");
  
  DataWidthModelOptimizeFunctionClass widthModOptClass(OPERATION_WIDTHMODELTOOPT_ID,OPERATION_WIDTHMODELTOOPT_NAME,widthModOptDescr);
  DataWidthModelMatrixSetUpClass widthModMatClass(WIDTHMODELALG_MATRIX_ID,WIDTHMODELALG_MATRIX_NAME,widthModMatDescr);
      
  set.AddObjectClass(widthModOptClass);
  set.AddObjectClass(widthModMatClass);
}



/*F InitialVASLModelOptimizeEncodeDecodeRoutines() . . .  instance algorithm
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
extern void InitialVASLModelOptimizeEncodeDecodeRoutines()
{
  EncodeDecodeRegisterClass(DataWidthModelOptimizeFunctionClass,BaseDataWidthModelOptimizeFunction,OPERATION_WIDTHMODELTOOPT_NAME);
  EncodeDecodeRegisterClass(DataWidthModelMatrixSetUpClass,BaseDataWidthModelMatrixSetUp,WIDTHMODELALG_MATRIX_NAME);
}


