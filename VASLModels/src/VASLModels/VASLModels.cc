/*  FILE     VASLModelOperation.cpp
**  PACKAGE  VASLModelOperation    
**  AUTHOR   
**
**  CONTENT
**    
**
**  REFERENCES
**
*/
#define TEMPLATE_INSTANTIATION
#include "VASLModels.hh"



/*S BaseDataVASLModelOperation
 */ 
/*F BaseDataVASLModelOperation()  . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataVASLModelOperation::BaseDataVASLModelOperation()
  : TheInputParameters(NULL),
    TheCoefficients(NULL)
{
//cout << "constr vasl\n";
  Identification = OPERATION_VASLMODEL_ID;
  NameTag = OPERATION_VASLMODEL_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;

//  initTheInputParameters();
//  initTheCoefficients();

        // Attention: model funktioniert nur mit Horizontalgeruest
  setDiameterOfEdgerRolls(cDiameterOfHGRolls);
        setCurReductionLEdger(cReductionLEdger);
        setReductionHEdger(cReductionHEdger);
        setMaxReductionHEdger(cMaxReductionHEdger);
        setMaxReductionLEdger(cMaxReductionLEdger);

  setCorrHEdger(cCorrHEdger);
  setCorrRollingForce(cCorrRollingForce);
  setCorrKashima(cCorrKashima);
  setCorrDogBone(cCorrDogBone);

        setSumReduction(0.0);
        setSumMaxReduction(0.0); 
//      setSumReductionOld(0.0);
//      setSumMaxReductionOld(0.0); 
} 
/*F BaseDataVASLModelOperation(data)  . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataVASLModelOperation::BaseDataVASLModelOperation(const BaseDataVASLModelOperation& data)
: BaseDataOperation(data)
{
  TheInputParameters = (BaseDataParameterSet *) PointerClone((BaseDataObject *) data.TheInputParameters);
  TheCoefficients = (BaseDataParameterSet *) PointerClone((BaseDataObject *) data.TheCoefficients);
  setDiameterOfEdgerRolls(cDiameterOfHGRolls);
}
/*F
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataVASLModelOperation::~BaseDataVASLModelOperation()
{
  if(TheInputParameters != NULL)
    delete TheInputParameters;
  if(TheCoefficients != NULL)
    delete TheCoefficients;
  
  TheInputParameters = NULL;
  TheCoefficients = NULL;
}
/*F Read(in,objc) . . . . . . . . . . . Read in BaseDataVASLModelOperation
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataVASLModelOperation::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();

  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . Read in BaseDataVASLModelOperation
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataVASLModelOperation::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = true;
  
//  if(objc->getDebugLevel() > 2) {
//    cout << "Read in BaseDataVASLModelOperation:\n";
//  }
//
//  
//  BaseDataOperation::Read(in,objc,name);
//  DataVASLModelOperationClass * objclass = (DataVASLModelOperationClass *) objc;
//
//  if(objclass->TheInputParametersClass != NULL) {
//    result = result && TheInputParameters->Read(in,objclass->TheInputParametersClass,NameTag);
//    if(objc->getDebugLevel() > 1) {
//      cout << "The Input Parameters just read in:\n";
//      TheInputParameters->print(cout);
//      cout << "\n";
//    }
//
//    if(objclass->TheCoefficientsClass != NULL) {
//      result = result && TheCoefficients->Read(in,objclass->TheCoefficientsClass,NameTag);
//      if(objc->getDebugLevel() > 1) {
//        cout << "The Coefficients just read in:\n";
//        TheCoefficients->print(cout);
//        cout << "\n";
//      }
//    }
//    else {
//      cout << "The Coefficients Class not defined\n";
//      TheCoefficients = 0;
//      result = false;
//    }
//
//  }
//  else {
//    cout << "TheInputParametersClass not defined\n";
//    TheInputParameters = 0;
//    result = false;
//  }

  return result;
}
/*F out1 = print(out) . . . . . . . . . . . . . . . . . .  BaseDataVASLModelOperation
**
**  DESCRIPTION
**    out: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataVASLModelOperation::print(ostream& out) const
{
  BaseDataOperation::print(out);

  PointerPrint(out,"\nThe Input Parameters: ", "-", (BaseDataObject *) TheInputParameters);
  PointerPrint(out,"\nThe Coefficients: ", "-", (BaseDataObject *) TheCoefficients);
  out << "\n";

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . .  BaseDataVASLModelOperation
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataVASLModelOperation::Clone()
{
  BaseDataVASLModelOperation *obj = new BaseDataVASLModelOperation(*this);
  return obj;
}
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . .  BaseDataVASLModelOperation
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataVASLModelOperation::CopyClone(Identify * obj)
{
  BaseDataVASLModelOperation *objfull = (BaseDataVASLModelOperation *) obj;
  *this = *objfull;
  BaseDataOperation::CopyClone(obj);
  TheInputParameters = (BaseDataParameterSet *) PointerClone(objfull->TheInputParameters);
  TheCoefficients = (BaseDataParameterSet *) PointerClone(objfull->TheCoefficients);
//  TheInputParameters = (BaseDataSetOfObjects *) PointerClone(objfull->TheInputParameters);
//  TheCoefficients = (BaseDataSetOfObjects *) PointerClone(objfull->TheCoefficients);
}
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . .  BaseDataVASLModelOperation
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataVASLModelOperation::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataOperation::EncodeThis(buffer);

  result = result && PointerEncode(buffer,TheInputParameters);
  result = result && PointerEncode(buffer,TheCoefficients);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . .  BaseDataVASLModelOperation
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataVASLModelOperation::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataOperation::DecodeThis(buffer);

  result = result && PointerDecode(buffer,(BaseDataObject *&) TheInputParameters);
  result = result && PointerDecode(buffer,(BaseDataObject *&) TheCoefficients);

  return result;
}
///*F obj = operator() . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
//**
//**  DESCRIPTION
//**
//**
//**  REMARKS
//**
//*/
//BaseDataReal BaseDataVASLModelOperation::operator()(BaseDataSetOfObjects *parToOpt, 
//                                  BaseDataSetOfObjects *coeffs,
//                                  DataSetOfObjectsClass *parToOptClass,
//                                  DataSetOfObjectsClass *coeffsClass) 
//{
//  setTheInputParameters(parToOpt);
//  setTheCoefficients(coeffs);
//  
//  BaseDataReal val;
//  val = calculate();
//  
//  return val;
//}
/*F obj = operator()(cls,x,xc,y,yc) . . . . . . . . with parameters and input
**
**  DESCRIPTION
**    cls: This class
**    x: The set of function parameters
**    xc: The function parameter class
**    y: The input parameters
**    yc: The input parameter class
**
**  REMARKS
**
*/
BaseDataObject *BaseDataVASLModelOperation::operator()(DataObjectClass *cls,
                                                          BaseDataObject *x,
                                                          BaseDataObject *y,
                                                          DataObjectClass *xc,
                                                          DataObjectClass *yc)
{
  return operator()(x,y,xc,yc);
}
/*F operator()(cls,x,xc)  . . . . . . . . . . Execute the function with input
**
**  DESCRIPTION
**    cls: This class
**    x: The set of objects as input parameters
**    xc: The class of the set of objects
**
**    The operation at this level can be used to set up the output object
**
**  REMARKS
**
*/
BaseDataObject *BaseDataVASLModelOperation::operator()(DataObjectClass *cls,
                                                       BaseDataObject *x,
                                                       DataObjectClass *xc)
{
  return operator()(x,xc);
}
/*F operator()(cls,x,xc)  . . . . . . . . . . Execute the function with input
**
**  DESCRIPTION
**    cls: This class
**    x: The set of objects as input parameters
**    xc: The class of the set of objects
**
**    The operation at this level can be used to set up the output object
**
**  REMARKS
**
*/
BaseDataObject *BaseDataVASLModelOperation::operator()(BaseDataObject *x,
                                                       DataObjectClass *xc)
{
  if(TheInputParameters == NULL)
    initTheInputParameters();
  if(TheCoefficients == NULL)
    initTheCoefficients();
  return (BaseDataObject *) x->Clone();
}
/*F obj = operator()(cls,x,xc,y,yc) . . . . . . . . with parameters and input
**
**  DESCRIPTION
**    cls: This class
**    x: The set of function parameters
**    xc: The function parameter class
**    y: The input parameters
**    yc: The input parameter class
**
**  REMARKS
**
*/
BaseDataObject *BaseDataVASLModelOperation::operator()(BaseDataObject *x,
                                                       BaseDataObject *y,
                                                       DataObjectClass *xc,
                                                       DataObjectClass *yc)
{
  //cout << "BaseDataVASLModelOperation::operator(2)" << endl;
  //x->print(cout);
  //cout << endl;
  //y->print(cout);
  //cout << endl;
  BaseDataParameterSet *parToOpt = (BaseDataParameterSet *) x;
  setTheInputParameters(parToOpt);
  BaseDataParameterSet *coeffs =  (BaseDataParameterSet *) y;
  setTheCoefficients(coeffs);
  
  BaseDataReal *val = new BaseDataReal();
  *val = calculate();
  
  return (BaseDataObject *) val;
}
/*F obj = operator() . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**
**  REMARKS
**
*/
BaseDataReal BaseDataVASLModelOperation::operator()() 
{
  if (TheInputParameters == NULL) {
    initTheInputParameters();
  }
  if (TheCoefficients == NULL) {
    initTheCoefficients();
  }
  BaseDataReal val;
  val = calculate();
  
  return val;
}
/*F calculate . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
BaseDataReal BaseDataVASLModelOperation::calculate()
{
//      cout << "BaseDataVASLModelOperation::calculate called " << endl;
  BaseDataReal val;
  val.SetValue(0.0);
  return val;
}
/*F setTheInputParameters . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLModelOperation::setTheInputParameters(BaseDataParameterSet* inp)
{
  ObjectList<String> ipars = TheInputParameters->OrderedListOfParameterNames();
  ObjectList<String> iparameters = inp->OrderedListOfParameterNames();
  if( ipars.size() == iparameters.size() )
    {
      ObjectList<String>::iterator ipar;
      ObjectList<String>::iterator iparameter = iparameters.begin();
      for(ipar = ipars.begin();ipar != ipars.end();ipar++)
        {
          BaseDataObject *obj = inp->GetObject(*iparameter);
          obj->NameTag = *ipar;
          TheInputParameters->AddObject(obj);
          //BaseDataNumeric *num =  (BaseDataNumeric *) obj;
          //cout << setw(20) << num->NameTag << setw(20) << num->Distance() << endl;
          iparameter++;
        }
    }
  else
    {
      cerr << "The Number Coefficients don't match" << endl;
      cerr << "Original Size: " << ipars.size() << "   Input Size: " << iparameters.size() << endl;
      ipars.print(cerr);
      cout << endl;
      iparameters.print(cerr);
      cout << endl;
    }
}
/*F setTheCoefficients . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLModelOperation::setTheCoefficients(BaseDataParameterSet* coeff)
{
  ObjectList<String> ipars = TheCoefficients->OrderedListOfParameterNames();
  ObjectList<String> iparameters = coeff->OrderedListOfParameterNames();
  if( ipars.size() == iparameters.size() )
    {
      ObjectList<String>::iterator ipar;
      ObjectList<String>::iterator iparameter = iparameters.begin();
      for(ipar = ipars.begin();ipar != ipars.end();ipar++)
        {
          BaseDataObject *obj = coeff->GetObject(*iparameter);
          obj->NameTag = *ipar;
          TheCoefficients->AddObject(obj);
          //BaseDataNumeric *num = (BaseDataNumeric *) obj;
          //cout << setw(20) << num->NameTag << setw(20) << num->Distance() << endl;
          iparameter++;
        }
    }
  else
    {
      cerr << "The Number Coefficients don't match" << endl;
      cerr << "Original Size: " << ipars.size() << "   Input Size: " << iparameters.size() << endl;
      ipars.print(cerr);
      cout << endl;
      iparameters.print(cerr);
      cout << endl;
    }
}
/*F initTheInputParameters . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLModelOperation::initTheInputParameters()
{
  TheInputParameters = new BaseDataParameterSet();
//  TheInputParameters = new BaseDataSetOfObjects();
}
/*F initTheCoefficients . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLModelOperation::initTheCoefficients()
{
  TheCoefficients = new BaseDataParameterSet();
//  TheCoefficients = new BaseDataSetOfObjects();
}
/*F fillCoefficients . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLModelOperation::fillCoefficients(BaseDataDoubleVector *parToOpt)
{
  if(TheCoefficients == NULL)
    initTheCoefficients();
//  cout << "BaseDataVASLModelOperation::fillCoefficients called" << endl; 
}
/*F fillInputParameters . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLModelOperation::fillInputParameters(VectorNumeric *dataVec)
{
  if(TheInputParameters == NULL)
    initTheInputParameters();
//  cout << "BaseDataVASLModelOperation::fillInputParameters called" << endl; 
}
/*F setCoefficient . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
bool BaseDataVASLModelOperation::setCoefficient(String str, BaseDataObject *obj)
{
  obj->NameTag = str;
  return TheCoefficients->AddObject(obj);
}
/*F getCoefficient . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
BaseDataObject* BaseDataVASLModelOperation::getCoefficient(String str)
{
  if (TheCoefficients->IsInList(str)) {  
    return TheCoefficients->GetObject(str);
  }
  else {
    cout << "Not in Coefficients List: " << str << endl;
    TheCoefficients->print(cout);
    return NULL;
  }
}
/*F setInputParameter . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
bool BaseDataVASLModelOperation::setInputParameter(String str, BaseDataObject *obj)
{
  obj->NameTag = str;
  return TheInputParameters->AddObject(obj);
}
/*F getInputParameter . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
BaseDataObject* BaseDataVASLModelOperation::getInputParameter(String str)
{
  if (TheInputParameters->IsInList(str)) {  
    return TheInputParameters->GetObject(str);
  }
  else {
    cout << "Not in Input Parameter List: " << str << endl;
    return NULL;
  }
}
/*F setDiameterOfEdgerRolls . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLModelOperation::setDiameterOfEdgerRolls(double val)
{
  diameterOfEdgerRolls = val;
}
/*F getDiameterOfEdgerRolls . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
double BaseDataVASLModelOperation::getDiameterOfEdgerRolls(void)
{
  return diameterOfEdgerRolls;
}
/*F setCurReductionLEdger . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLModelOperation::setCurReductionLEdger(double val)
{
  curReductionLEdger = val;
}
/*F getCurReductionLEdger . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
double BaseDataVASLModelOperation::getCurReductionLEdger(void)
{
  return curReductionLEdger;
}
/*F setReductionHEdger . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLModelOperation::setReductionHEdger(double val)
{
  reductionHEdger = val;
}
/*F getReductionHEdger . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
double BaseDataVASLModelOperation::getReductionHEdger(void)
{
  return reductionHEdger;
}
/*F setMaxReductionHEdger . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLModelOperation::setMaxReductionHEdger(double val)
{
  maxReductionHEdger = val;
}
/*F getMaxReductionHEdger . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
double BaseDataVASLModelOperation::getMaxReductionHEdger(void)
{
  return maxReductionHEdger;
}
/*F setMaxReductionLEdger . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLModelOperation::setMaxReductionLEdger(double val)
{
  maxReductionLEdger = val;
}
/*F getMaxReductionLEdger . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
double BaseDataVASLModelOperation::getMaxReductionLEdger(void)
{
  return maxReductionLEdger;
}
/*F setCorrHEdger . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLModelOperation::setCorrHEdger(double val)
{
  corrHEdger = val;
}
/*F getCorrHEdger . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
double BaseDataVASLModelOperation::getCorrHEdger(void)
{
  return corrHEdger;
}
/*F setCorrRollingForce . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLModelOperation::setCorrRollingForce(double val)
{
  corrRollingForce = val;
}
/*F getCorrRollingForce . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
double BaseDataVASLModelOperation::getCorrRollingForce(void)
{
  return corrRollingForce;
}
/*F setCorrKashima . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLModelOperation::setCorrKashima(double val)
{
  corrKashima = val;
}
/*F getCorrKashima . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
double BaseDataVASLModelOperation::getCorrKashima(void)
{
  return corrKashima;
}
/*F setCorrDogBone . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLModelOperation::setCorrDogBone(double val)
{
  corrDogBone = val;
}
/*F getCorrDogBone . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
double BaseDataVASLModelOperation::getCorrDogBone(void)
{
  return corrDogBone;
}
/*F setSumReduction . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLModelOperation::setSumReduction(double val)
{
  sumReduction = val;
}
/*F getSumReduction . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
double BaseDataVASLModelOperation::getSumReduction(void)
{
  return sumReduction;
}
/*F setSumMaxReduction . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLModelOperation::setSumMaxReduction(double val)
{
  sumMaxReduction = val;
}
/*F getSumMaxReduction . . . . . . . . . . . . . . . . . . BaseDataVASLModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
double BaseDataVASLModelOperation::getSumMaxReduction(void)
{
  return sumMaxReduction;
}


/*S DataVASLModelOperationClass
 */ 
/*F DataFunctionToOptimizeClass() . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataVASLModelOperationClass::DataVASLModelOperationClass()
  : TheInputParametersClass(NULL),
    TheCoefficientsClass(NULL)
{
  Identification = OPERATION_VASLMODEL_ID;
  SubClass = OPERATION_BASE_NAME;
  NameTag = OPERATION_VASLMODEL_NAME;
  EncodeDecodeClass = OPERATION_VASLMODEL_NAME;

  TheInputParametersClass = new DataParameterSetClass();
  TheCoefficientsClass = new DataParameterSetClass();
} 
/*F DataVASLModelOperationClass(data) . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataVASLModelOperationClass::DataVASLModelOperationClass(const DataVASLModelOperationClass& data)
  : DataOperationClass(data)
{
  TheInputParametersClass = (DataParameterSetClass *) PointerClone((BaseDataObject *) data.TheInputParametersClass);
  TheCoefficientsClass = (DataParameterSetClass *) PointerClone((BaseDataObject *) data.TheCoefficientsClass);
} 
/*F DataVASLModelOperationClass(id,name,descr)  . . . . . . . . . . . . . constructor
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
DataVASLModelOperationClass::DataVASLModelOperationClass(const int id, 
                                                       const String& name,
                                                       const String& descr)
  : DataOperationClass(id,name,descr),
    TheInputParametersClass(NULL),
    TheCoefficientsClass(NULL)
{
  SubClass = OPERATION_BASE_NAME;
  EncodeDecodeClass = OPERATION_VASLMODEL_NAME;
}
/*F ~DataFunctionToOptimizeClass() . . . . . . . . . . . . . . . . . destructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataVASLModelOperationClass::~DataVASLModelOperationClass()
{
  if(TheInputParametersClass != NULL)
    delete TheInputParametersClass;
  if(TheCoefficientsClass != NULL)
    delete TheCoefficientsClass;
  
  TheInputParametersClass = NULL;
  TheCoefficientsClass = NULL;
} 
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . DataVASLModelOperationClass
**
**  DESCRIPTION
**    out: The output buffer
**
**  REMARKS
**
*/
ostream& DataVASLModelOperationClass::print(ostream& out) const
{
  DataOperationClass::print(out);

  out << "\n          TheInputParametersClass: ";
  if(TheInputParametersClass != NULL)
    out << TheInputParametersClass->NameTag;
  else
    out << "None Specified";

  out << "     TheCoefficientsClass: ";
  if(TheCoefficientsClass != NULL)
    out << TheCoefficientsClass->NameTag;
  else
    out << "None Specified";

  out << endl;

  return out;
}
/*F in1 = Read(in,set)  . . . . . . . . . . . . . . . . . DataVASLModelOperationClass
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
bool DataVASLModelOperationClass::Read(istream& in, DataSetOfObjectsClass& set)
{
  bool result = DataOperationClass::Read(in,set);

  StreamObjectInput str(in,' ');

  String inp = str.ReadNext();
  String coeff = str.ReadNext();
  TheInputParametersClass = (DataParameterSetClass *) set.CloneClassFromName(inp);
  TheCoefficientsClass = (DataParameterSetClass *) set.CloneClassFromName(coeff);

  return result;
}
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . DataVASLModelOperationClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataVASLModelOperationClass::CopyClone(Identify * objc)
{
  DataVASLModelOperationClass *objcfull = (DataVASLModelOperationClass*) objc;
  *this = *objcfull;
  DataOperationClass::CopyClone(objc);
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . DataVASLModelOperationClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataVASLModelOperationClass::Clone()
{
  DataVASLModelOperationClass* id = new DataVASLModelOperationClass(*this);
  return (Identify *) id;
}
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . DataVASLModelOperationClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataVASLModelOperationClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataOperationClass::EncodeThis(buffer);

  result = result && PointerEncode(buffer,TheInputParametersClass);
  result = result && PointerEncode(buffer,TheCoefficientsClass);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . DataVASLModelOperationClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataVASLModelOperationClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataOperationClass::DecodeThis(buffer);
  result = result && PointerDecode(buffer,(BaseDataObject *&) TheInputParametersClass);
  result = result && PointerDecode(buffer,(BaseDataObject *&) TheCoefficientsClass);
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
BaseDataObject * DataVASLModelOperationClass::BaseDataObjectExample()
{ 
  BaseDataObject *obj = (BaseDataObject *) new BaseDataVASLModelOperation();
  obj->SetType(Identification);
  return obj;
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . DataVASLModelOperationClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataVASLModelOperationClass*& obj)
{
  obj = new DataVASLModelOperationClass;
  return obj->DecodeThis(buffer);
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . .  BaseDataVASLModelOperation
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataVASLModelOperation*& obj)
{
  obj = new BaseDataVASLModelOperation;
  return obj->DecodeThis(buffer);
}



/*S BaseDataVASLDogBoneModelOperation
 */ 
/*F BaseDataVASLModelOperation()  . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataVASLDogBoneModelOperation::BaseDataVASLDogBoneModelOperation()
{
  Identification = OPERATION_VASLDOGBONEMODEL_ID;
  NameTag = OPERATION_VASLDOGBONEMODEL_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;  

//  initTheInputParameters();
//  initTheCoefficients();
} 
/*F BaseDataVASLDogBoneModelOperation(data)  . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataVASLDogBoneModelOperation::BaseDataVASLDogBoneModelOperation(const BaseDataVASLDogBoneModelOperation& data)
: BaseDataVASLModelOperation(data)
{
}
/*F
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataVASLDogBoneModelOperation::~BaseDataVASLDogBoneModelOperation()
{
  if(TheInputParameters != NULL)
    delete TheInputParameters;
  if(TheCoefficients != NULL)
    delete TheCoefficients;
  
  TheInputParameters = NULL;
  TheCoefficients = NULL;
}
/*F Read(in,objc) . . . . . . . . . . . Read in BaseDataVASLDogBoneModelOperation
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataVASLDogBoneModelOperation::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();

  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . Read in BaseDataVASLDogBoneModelOperation
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataVASLDogBoneModelOperation::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = true;
  
  if(objc->getDebugLevel() > 2) {
    cout << "Read in BaseDataVASLDogBoneModelOperation:\n";
  }

  
  BaseDataVASLModelOperation::Read(in,objc,name);
  //DataVASLDogBoneModelOperationClass * objclass = (DataVASLDogBoneModelOperationClass *) objc;

  return result;
}
/*F out1 = print(out) . . . . . . . . . . . . . . . . . .  BaseDataVASLDogBoneModelOperation
**
**  DESCRIPTION
**    out: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataVASLDogBoneModelOperation::print(ostream& out) const
{
  BaseDataVASLModelOperation::print(out);

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . .  BaseDataVASLDogBoneModelOperation
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataVASLDogBoneModelOperation::Clone()
{
  BaseDataVASLDogBoneModelOperation *obj = new BaseDataVASLDogBoneModelOperation(*this);
  return obj;
}
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . .  BaseDataVASLDogBoneModelOperation
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataVASLDogBoneModelOperation::CopyClone(Identify * obj)
{
  BaseDataVASLDogBoneModelOperation *objfull = (BaseDataVASLDogBoneModelOperation *) obj;
  *this = *objfull;
  BaseDataVASLModelOperation::CopyClone(obj);
}
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . .  BaseDataVASLDogBoneModelOperation
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataVASLDogBoneModelOperation::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataVASLModelOperation::EncodeThis(buffer);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . .  BaseDataVASLDogBoneModelOperation
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataVASLDogBoneModelOperation::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataVASLModelOperation::DecodeThis(buffer);

  return result;
}
/*F calculate . . . . . . . . . . . . . . . . . . BaseDataVASLDogBoneModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
BaseDataReal BaseDataVASLDogBoneModelOperation::calculate()
{
// cout << "BaseDataVASLDogBoneModelOperation::calculate" << endl;
        
  double wBeforeEdger = ((BaseDataReal *) getInputParameter("widthBeforeEdger"))->GetValue();
  double wAfterEdger = ((BaseDataReal *) getInputParameter("widthAfterEdger"))->GetValue();
//cout << "DOGBONE------------widthBeforeEdger " << wBeforeEdger << endl;                       
//cout << "DOGBONE------------widthAfterEdger " << wAfterEdger << endl;                 

  double factor = calculateDogBoneFactor();
//cout << "DOGBONE------------factor " << factor << endl;                       
        // Meanvalue of all corrHEdger = 0.75
        // "Abschwaechungsfaktor" = 0.25
        factor = factor * (1 + (getCorrHEdger()/cCorrEdgerMean -1.0) * 0.25);
        //cout << "DOGBONE------------getCorrHEdger " << getCorrHEdger() << endl;                       
        //cout << "DOGBONE------------cCorrEdgerMean " << cCorrEdgerMean << endl;                       
        //cout << "DOGBONE------------factor " << factor << endl;                       
        //cout << "DOGBONE------------getCorrDogBone " << getCorrDogBone() << endl;                     
  double widthInc = factor * (wBeforeEdger - wAfterEdger) * getCorrDogBone();
  //cout << "DOGBONE------------widthInc " << widthInc << endl;                 
  
  BaseDataReal val;  
  val.SetValue(widthInc);
  return val;
}
/*F calculateDogBoneFactor . . . . . . . . . . . . . . . . . . BaseDataVASLDogBoneModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
double BaseDataVASLDogBoneModelOperation::calculateDogBoneFactor()
{
  double wBeforeEdger = ((BaseDataReal *) getInputParameter("widthBeforeEdger"))->GetValue();
  double wAfterEdger = ((BaseDataReal *) getInputParameter("widthAfterEdger"))->GetValue();
  double hBeforeEdger = ((BaseDataReal *) getInputParameter("heightBeforeEdger"))->GetValue();
  double cnstdb1 = ((BaseDataReal *) getCoefficient("cdb1"))->GetValue();
  double cnstdb2 = ((BaseDataReal *) getCoefficient("cdb2"))->GetValue();
  double cnstdb3 = ((BaseDataReal *) getCoefficient("cdb3"))->GetValue();
  double cnstdb4 = ((BaseDataReal *) getCoefficient("cdb4"))->GetValue();
  double cnstdb5 = ((BaseDataReal *) getCoefficient("cdb5"))->GetValue();
//cout << "--------calcFactor ---------wBeforeEdger " << wBeforeEdger << endl;                  
//cout << "--------calcFactor ---------wAfterEdger " << wAfterEdger << endl;                    
//cout << "--------calcFactor ---------hBeforeEdger " << hBeforeEdger << endl;                  
//cout << "--------calcFactor ---------getDiameterOfEdgerRolls() " << getDiameterOfEdgerRolls() << endl;                        
//cout << "--------Parameter: --------- " << cnstdb1 << " " << cnstdb2 << " " << cnstdb3 << " " << cnstdb4 << " " << cnstdb5 << endl;                   
  
  double res;
  res =         exp(cnstdb1 * 
          pow( (wBeforeEdger - wAfterEdger) / wBeforeEdger, cnstdb2) *
          pow( hBeforeEdger / (getDiameterOfEdgerRolls()/2.0), cnstdb3 ) *
          pow( (getDiameterOfEdgerRolls()/2.0) / wBeforeEdger, cnstdb4 ) *
          pow( wBeforeEdger / wAfterEdger, cnstdb5 ) );
//cout << "--------calcFactor result: " << res << endl;                 
        
        return res;
}
/*F initTheInputParameters . . . . . . . . . . . . . . . . . . BaseDataVASLDogBoneModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLDogBoneModelOperation::initTheInputParameters()
{
  TheInputParameters = new BaseDataParameterSet();

  BaseDataReal *realHlp = new BaseDataReal();
  realHlp->NameTag = "widthBeforeEdger";
  realHlp->SetValue(0.0);
  TheInputParameters->AddObject(realHlp);

  realHlp->NameTag = "widthAfterEdger";
  TheInputParameters->AddObject(realHlp);

  realHlp->NameTag = "heightBeforeEdger";
  TheInputParameters->AddObject(realHlp);
  
  delete realHlp;
}
/*F initTheCoefficients . . . . . . . . . . . . . . . . . . BaseDataVASLDogBoneModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLDogBoneModelOperation::initTheCoefficients()
{
  TheCoefficients = new BaseDataParameterSet();

  BaseDataReal *realHlp = new BaseDataReal();
  realHlp->NameTag = "cdb1";
  realHlp->SetValue(-1.877);
  TheCoefficients->AddObject(realHlp);

  realHlp->NameTag = "cdb2";
  realHlp->SetValue(0.063);
  TheCoefficients->AddObject(realHlp);

  realHlp->NameTag = "cdb3";
  realHlp->SetValue(0.441);
  TheCoefficients->AddObject(realHlp);

  realHlp->NameTag = "cdb4";
  realHlp->SetValue(0.989);
  TheCoefficients->AddObject(realHlp);

  realHlp->NameTag = "cdb5";
  realHlp->SetValue(7.591);
  TheCoefficients->AddObject(realHlp);
  
  delete realHlp;
}
/*F fillCoefficients . . . . . . . . . . . . . . . . . . BaseDataVASLDogBoneModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLDogBoneModelOperation::fillCoefficients(BaseDataDoubleVector *parToOpt)
{
  BaseDataVASLModelOperation::fillCoefficients(parToOpt);

  VectorNumeric theVec = parToOpt->CurrentVector();

  BaseDataReal *obj0 = (BaseDataReal *) TheCoefficients->GetObject("cdb1");
  obj0->SetValue(theVec[0]);
  BaseDataReal *obj1 = (BaseDataReal *) TheCoefficients->GetObject("cdb2");
  obj1->SetValue(theVec[1]);
  BaseDataReal *obj2 = (BaseDataReal *) TheCoefficients->GetObject("cdb3");
  obj2->SetValue(theVec[2]);
  BaseDataReal *obj3 = (BaseDataReal *) TheCoefficients->GetObject("cdb4");
  obj3->SetValue(theVec[3]);
  BaseDataReal *obj4 = (BaseDataReal *) TheCoefficients->GetObject("cdb5");
  obj4->SetValue(theVec[4]);

  /*
    BaseDataReal *cdb1Obj = new BaseDataReal();
    cdb1Obj->SetValue(theVec.at(0));
    this->setCoefficient("cdb1", cdb1Obj);

    BaseDataReal *cdb2Obj = new BaseDataReal();
    cdb2Obj->SetValue(theVec.at(1));
    this->setCoefficient("cdb2", cdb2Obj);

    BaseDataReal *cdb3Obj = new BaseDataReal();
    cdb3Obj->SetValue(theVec.at(2));
    this->setCoefficient("cdb3", cdb3Obj);

    BaseDataReal *cdb4Obj = new BaseDataReal();
    cdb4Obj->SetValue(theVec.at(3));
    this->setCoefficient("cdb4", cdb4Obj);

    BaseDataReal *cdb5Obj = new BaseDataReal();
    cdb5Obj->SetValue(theVec.at(4));
    this->setCoefficient("cdb5", cdb5Obj);
    delete cdb1Obj;
    delete cdb2Obj;
    delete cdb3Obj;
    delete cdb4Obj;
    delete cdb5Obj;
  */
}
/*F fillInputParameters . . . . . . . . . . . . . . . . . . BaseDataVASLDogBoneModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLDogBoneModelOperation::fillInputParameters(VectorNumeric *dataVec)
{
//  cout << "BaseDataVASLDogBoneModelOperation::fillInputParameters called" << endl; 
  BaseDataVASLModelOperation::fillInputParameters(dataVec);
}


/*S DataVASLDogBoneModelOperationClass
 */ 
/*F DataVASLDogBoneModelOperationClass() . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataVASLDogBoneModelOperationClass::DataVASLDogBoneModelOperationClass()
{
  Identification = OPERATION_VASLDOGBONEMODEL_ID;
  NameTag = OPERATION_VASLDOGBONEMODEL_NAME;
  SubClass = OPERATION_VASLMODEL_NAME;
  EncodeDecodeClass = NameTag;
} 
/*F DataVASLDogBoneModelOperationClass<(data) . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataVASLDogBoneModelOperationClass::DataVASLDogBoneModelOperationClass(const DataVASLDogBoneModelOperationClass& data)
  : DataVASLModelOperationClass(data)
{
} 
/*F DataVASLDogBoneModelOperationClass(id,name,descr)  . . . . . . . . . . . . . constructor
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
DataVASLDogBoneModelOperationClass::DataVASLDogBoneModelOperationClass(const int id, 
                                                       const String& name,
                                                       const String& descr)
  : DataVASLModelOperationClass(id,name,descr)

{
  SubClass = OPERATION_VASLMODEL_NAME;
  EncodeDecodeClass = OPERATION_VASLDOGBONEMODEL_NAME;
}
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . DataVASLDogBoneModelOperationClass
**
**  DESCRIPTION
**    out: The output buffer
**
**  REMARKS
**
*/
ostream& DataVASLDogBoneModelOperationClass::print(ostream& out) const
{
  DataVASLModelOperationClass::print(out);
  return out;
}
/*F in1 = Read(in,set)  . . . . . . . . . . . . . . . . . DataVASLDogBoneModelOperationClass
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
bool DataVASLDogBoneModelOperationClass::Read(istream& in, DataSetOfObjectsClass& set)
{
  bool result = DataVASLModelOperationClass::Read(in,set);
  return result;
}
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . DataVASLDogBoneModelOperationClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataVASLDogBoneModelOperationClass::CopyClone(Identify * objc)
{
  DataVASLDogBoneModelOperationClass *objcfull = (DataVASLDogBoneModelOperationClass*) objc;
  *this = *objcfull;
  DataVASLModelOperationClass::CopyClone(objc);
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . DataVASLDogBoneModelOperationClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataVASLDogBoneModelOperationClass::Clone()
{
  DataVASLDogBoneModelOperationClass* id = new DataVASLDogBoneModelOperationClass(*this);
  return (Identify *) id;
}
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . DataVASLDogBoneModelOperationClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataVASLDogBoneModelOperationClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataVASLModelOperationClass::EncodeThis(buffer);
  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . DataVASLDogBoneModelOperationClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataVASLDogBoneModelOperationClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataVASLModelOperationClass::DecodeThis(buffer);
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
BaseDataObject * DataVASLDogBoneModelOperationClass::BaseDataObjectExample()
{ 
  BaseDataObject *obj = (BaseDataObject *) new BaseDataVASLDogBoneModelOperation();
  obj->SetType(Identification);
  return obj;
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . DataVASLDogBoneModelOperationClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataVASLDogBoneModelOperationClass*& obj)
{
  obj = new DataVASLDogBoneModelOperationClass;
  return obj->DecodeThis(buffer);
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . .  BaseDataVASLDogBoneModelOperation
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataVASLDogBoneModelOperation*& obj)
{
  obj = new BaseDataVASLDogBoneModelOperation;
  return obj->DecodeThis(buffer);
}



/*S BaseDataVASLKashimaModelOperation
 */ 
/*F BaseDataVASLKashimaModelOperation()  . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataVASLKashimaModelOperation::BaseDataVASLKashimaModelOperation()
{
  Identification = OPERATION_VASLKASHIMAMODEL_ID;
  NameTag = OPERATION_VASLKASHIMAMODEL_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;  

//  initTheInputParameters();
//  initTheCoefficients();
} 
/*F BaseDataVASLKashimaModelOperation(data)  . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataVASLKashimaModelOperation::BaseDataVASLKashimaModelOperation(const BaseDataVASLKashimaModelOperation& data)
: BaseDataVASLModelOperation(data)
{
}
/*F
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataVASLKashimaModelOperation::~BaseDataVASLKashimaModelOperation()
{
  if(TheInputParameters != NULL)
    delete TheInputParameters;
  if(TheCoefficients != NULL)
    delete TheCoefficients;

  TheInputParameters = NULL;
  TheCoefficients = NULL;
}
/*F Read(in,objc) . . . . . . . . . . . Read in BaseDataVASLKashimaModelOperation
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataVASLKashimaModelOperation::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();

  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . Read in BaseDataVASLKashimaModelOperation
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataVASLKashimaModelOperation::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = true;
  
  if(objc->getDebugLevel() > 2) {
    cout << "Read in BaseDataVASLKashimaModelOperation:\n";
  }

  
  BaseDataVASLModelOperation::Read(in,objc,name);
  //  DataVASLKashimaModelOperationClass * objclass = (DataVASLKashimaModelOperationClass *) objc;

  return result;
}
/*F out1 = print(out) . . . . . . . . . . . . . . . . . .  BaseDataVASLKashimaModelOperation
**
**  DESCRIPTION
**    out: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataVASLKashimaModelOperation::print(ostream& out) const
{
  BaseDataVASLModelOperation::print(out);

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . .  BaseDataVASLKashimaModelOperation
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataVASLKashimaModelOperation::Clone()
{
  BaseDataVASLKashimaModelOperation *obj = new BaseDataVASLKashimaModelOperation(*this);
  return obj;
}
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . .  BaseDataVASLKashimaModelOperation
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataVASLKashimaModelOperation::CopyClone(Identify * obj)
{
  BaseDataVASLKashimaModelOperation *objfull = (BaseDataVASLKashimaModelOperation *) obj;
  *this = *objfull;
  BaseDataVASLModelOperation::CopyClone(obj);
}
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . .  BaseDataVASLKashimaModelOperation
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataVASLKashimaModelOperation::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataVASLModelOperation::EncodeThis(buffer);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . .  BaseDataVASLKashimaModelOperation
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataVASLKashimaModelOperation::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataVASLModelOperation::DecodeThis(buffer);

  return result;
}
/*F calculate . . . . . . . . . . . . . . . . . . BaseDataVASLKashimaModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
BaseDataReal BaseDataVASLKashimaModelOperation::calculate()
{
// cout << "BaseDataVASLKashimaModelOperation::calculate" << endl;
  double hBeforePass = ((BaseDataReal *) getInputParameter("heightBeforePass"))->GetValue();
  double hAfterPass = ((BaseDataReal *) getInputParameter("heightAfterPass"))->GetValue();
  double wBeforePass = ((BaseDataReal *) getInputParameter("widthBeforePass"))->GetValue();

  double widthInc = 
    ( pow( (hBeforePass / hAfterPass),
            calculateWidthExponent()
         ) - 1.0 
    )   * wBeforePass;
  
  BaseDataReal val;  
  val.SetValue(widthInc);

  return val;
}
/*F calculateWidthExponent . . . . . . . . . . . . . . . . . . BaseDataVASLKashimaModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
double BaseDataVASLKashimaModelOperation::calculateWidthExponent()
{
  double wBeforePass = ((BaseDataReal *) getInputParameter("widthBeforePass"))->GetValue();
  double hBeforePass = ((BaseDataReal *) getInputParameter("heightBeforePass"))->GetValue();
  double hAfterPass = ((BaseDataReal *) getInputParameter("heightAfterPass"))->GetValue();
  
  double diamOfRoughingRolls = 990;
//  double diamOfRoughingRolls = ((BaseDataReal *) getInputParameter("diameterOfRoughingRolls"))->GetValue();
  double cnstk1 = ((BaseDataReal *) getCoefficient("ck1"))->GetValue();
  double cnstk2 = ((BaseDataReal *) getCoefficient("ck2"))->GetValue();
  double cnstk3 = ((BaseDataReal *) getCoefficient("ck3"))->GetValue();
  double cnstk4 = ((BaseDataReal *) getCoefficient("ck4"))->GetValue();

                double widthTHeigth = wBeforePass / hBeforePass;
                // precalculate factor "ldi"
                double ldi = sqrt( (diamOfRoughingRolls/2.0) * 
                                                                                ( hBeforePass - hAfterPass));

                
                return  exp (   cnstk1 
                                                * pow(widthTHeigth, cnstk2) 
                                                * pow( (wBeforePass / ldi), (cnstk3 * widthTHeigth) ) 
                                                * pow( (hBeforePass / (diamOfRoughingRolls/2.0)), (cnstk4 * widthTHeigth) )
                                        );
}
/*F initTheInputParameters . . . . . . . . . . . . . . . . . . BaseDataVASLKashimaModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLKashimaModelOperation::initTheInputParameters()
{
  TheInputParameters = new BaseDataParameterSet();

  BaseDataReal *realHlp = new BaseDataReal();
  realHlp->NameTag = "widthBeforePass";
  realHlp->SetValue(0.0);
  TheInputParameters->AddObject(realHlp);

  realHlp->NameTag = "heightBeforePass";
  TheInputParameters->AddObject(realHlp);

  realHlp->NameTag = "heightAfterPass";
  TheInputParameters->AddObject(realHlp);
  
  realHlp->NameTag = "diameterOfRoughingRolls";
  TheInputParameters->AddObject(realHlp);

  delete realHlp;
}
/*F initTheCoefficients . . . . . . . . . . . . . . . . . . BaseDataVASLKashimaModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLKashimaModelOperation::initTheCoefficients()
{
  TheCoefficients = new BaseDataParameterSet();

  BaseDataReal *realHlp = new BaseDataReal();
  realHlp->NameTag = "ck1";
  realHlp->SetValue(-1.64);
  TheCoefficients->AddObject(realHlp);

  realHlp->NameTag = "ck2";
  realHlp->SetValue(0.376);
  TheCoefficients->AddObject(realHlp);

  realHlp->NameTag = "ck3";
  realHlp->SetValue(0.016);
  TheCoefficients->AddObject(realHlp);

  realHlp->NameTag = "ck4";
  realHlp->SetValue(0.015);
  TheCoefficients->AddObject(realHlp);
  
  delete realHlp;
}
/*F fillCoefficients . . . . . . . . . . . . . . . . . . BaseDataVASLKashimaModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLKashimaModelOperation::fillCoefficients(BaseDataDoubleVector *parToOpt)
{
  BaseDataVASLModelOperation::fillCoefficients(parToOpt);
  
  VectorNumeric theVec = parToOpt->CurrentVector();
  
  BaseDataReal *obj0 = (BaseDataReal *) TheCoefficients->GetObject("ck1");
  obj0->SetValue(theVec[0]);
  BaseDataReal *obj1 = (BaseDataReal *) TheCoefficients->GetObject("ck2");
  obj1->SetValue(theVec[1]);
  BaseDataReal *obj2 = (BaseDataReal *) TheCoefficients->GetObject("ck3");
  obj2->SetValue(theVec[2]);
  BaseDataReal *obj3 = (BaseDataReal *) TheCoefficients->GetObject("ck4");
  obj3->SetValue(theVec[3]);

  /*
    BaseDataReal *ck1Obj = new BaseDataReal();
    ck1Obj->SetValue(theVec.at(0));
    this->setCoefficient("ck1", ck1Obj);

    BaseDataReal *ck2Obj = new BaseDataReal();
    ck2Obj->SetValue(theVec.at(1));
    this->setCoefficient("ck2", ck2Obj);

    BaseDataReal *ck3Obj = new BaseDataReal();
    ck3Obj->SetValue(theVec.at(2));
    this->setCoefficient("ck3", ck3Obj);

    BaseDataReal *ck4Obj = new BaseDataReal();
    ck4Obj->SetValue(theVec.at(3));
    this->setCoefficient("ck4", ck4Obj);

    delete ck1Obj;
    delete ck2Obj;
    delete ck3Obj;
    delete ck4Obj;
  */
}
/*F fillInputParameters . . . . . . . . . . . . . . . . . . BaseDataVASLKashimaModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLKashimaModelOperation::fillInputParameters(VectorNumeric *dataVec)
{
//  cout << "BaseDataVASLKashimaModelOperation::fillInputParameters called" << endl; 
  BaseDataVASLModelOperation::fillInputParameters(dataVec);
}

/*S DataVASLKashimaModelOperationClass
 */ 
/*F DataVASLKashimaModelOperationClass() . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataVASLKashimaModelOperationClass::DataVASLKashimaModelOperationClass()
{
  Identification = OPERATION_VASLKASHIMAMODEL_ID;
  NameTag = OPERATION_VASLKASHIMAMODEL_NAME;
  SubClass = OPERATION_VASLMODEL_NAME;
  EncodeDecodeClass = OPERATION_VASLKASHIMAMODEL_NAME;
} 
/*F DataVASLKashimaModelOperationClass<(data) . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataVASLKashimaModelOperationClass::DataVASLKashimaModelOperationClass(const DataVASLKashimaModelOperationClass& data)
  : DataVASLModelOperationClass(data)
{
} 
/*F DataVASLKashimaModelOperationClass(id,name,descr)  . . . . . . . . . . . . . constructor
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
DataVASLKashimaModelOperationClass::DataVASLKashimaModelOperationClass(const int id, 
                                                       const String& name,
                                                       const String& descr)
  : DataVASLModelOperationClass(id,name,descr)

{
  SubClass = OPERATION_VASLMODEL_NAME;
  EncodeDecodeClass = OPERATION_VASLKASHIMAMODEL_NAME;
}
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . DataVASLKashimaModelOperationClass
**
**  DESCRIPTION
**    out: The output buffer
**
**  REMARKS
**
*/
ostream& DataVASLKashimaModelOperationClass::print(ostream& out) const
{
  DataVASLModelOperationClass::print(out);
  return out;
}
/*F in1 = Read(in,set)  . . . . . . . . . . . . . . . . . DataVASLKashimaModelOperationClass
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
bool DataVASLKashimaModelOperationClass::Read(istream& in, DataSetOfObjectsClass& set)
{
  bool result = DataVASLModelOperationClass::Read(in,set);
  return result;
}
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . DataVASLKashimaModelOperationClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataVASLKashimaModelOperationClass::CopyClone(Identify * objc)
{
  DataVASLKashimaModelOperationClass *objcfull = (DataVASLKashimaModelOperationClass*) objc;
  *this = *objcfull;
  DataVASLModelOperationClass::CopyClone(objc);
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . DataVASLKashimaModelOperationClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataVASLKashimaModelOperationClass::Clone()
{
  DataVASLKashimaModelOperationClass* id = new DataVASLKashimaModelOperationClass(*this);
  return (Identify *) id;
}
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . DataVASLKashimaModelOperationClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataVASLKashimaModelOperationClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataVASLModelOperationClass::EncodeThis(buffer);
  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . DataVASLKashimaModelOperationClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataVASLKashimaModelOperationClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataVASLModelOperationClass::DecodeThis(buffer);
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
BaseDataObject * DataVASLKashimaModelOperationClass::BaseDataObjectExample()
{ 
  BaseDataObject *obj = (BaseDataObject *) new BaseDataVASLKashimaModelOperation();
  obj->SetType(Identification);
  return obj;
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . DataVASLKashimaModelOperationClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataVASLKashimaModelOperationClass*& obj)
{
  obj = new DataVASLKashimaModelOperationClass;
  return obj->DecodeThis(buffer);
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . .  BaseDataVASLKashimaModelOperation
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataVASLKashimaModelOperation*& obj)
{
  obj = new BaseDataVASLKashimaModelOperation;
  return obj->DecodeThis(buffer);
}



/*S BaseDataVASLWidthModelOperation
 */ 
/*F BaseDataVASLWidthModelOperation()  . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataVASLWidthModelOperation::BaseDataVASLWidthModelOperation()
{
//cout << "constr width\n";
  Identification = OPERATION_VASLWIDTHMODEL_ID;
  NameTag = OPERATION_VASLWIDTHMODEL_NAME;
  SetType(Identification);
  String name("Object.");
  name.AppendToEnd(NameTag);
  EncodeDecodeClass = name;

//  initTheInputParameters();
//  initTheCoefficients();
} 
/*F BaseDataVASLWidthModelOperation(data)  . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**    data: data to be copied
**
**  REMARKS
**
*/
BaseDataVASLWidthModelOperation::BaseDataVASLWidthModelOperation(const BaseDataVASLWidthModelOperation& data)
: BaseDataVASLModelOperation(data)
{
}
/*F
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
BaseDataVASLWidthModelOperation::~BaseDataVASLWidthModelOperation()
{
  if(TheInputParameters != NULL)
    delete TheInputParameters;
  if(TheCoefficients != NULL)
    delete TheCoefficients;
  
  TheInputParameters = NULL;
  TheCoefficients = NULL;
}
/*F Read(in,objc) . . . . . . . . . . . Read in BaseDataVASLWidthModelOperation
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**
**  REMARKS
**
*/
bool BaseDataVASLWidthModelOperation::Read(istream& in, DataObjectClass* objc)
{
  StreamObjectInput str(in,' ');
  NameTag = str.ReadNext();

  return Read(in,objc,NameTag);
}
/*F Read(in,objc,name)  . . . . . . . . Read in BaseDataVASLWidthModelOperation
**
**  DESCRIPTION
**    in: The input stream
**    objc: The class definition
**    name: The name of the object (already assigned)
**
**  REMARKS
**
*/
bool BaseDataVASLWidthModelOperation::Read(istream& in, DataObjectClass* objc, const String& name)
{
  bool result = true;
  
  if(objc->getDebugLevel() > 2) {
    cout << "Read in BaseDataVASLWidthModelOperation:\n";
  }

  
  BaseDataVASLModelOperation::Read(in,objc,name);
  //  DataVASLWidthModelOperationClass * objclass = (DataVASLWidthModelOperationClass *) objc;

  return result;
}
/*F out1 = print(out) . . . . . . . . . . . . . . . . . .  BaseDataVASLWidthModelOperation
**
**  DESCRIPTION
**    out: The output buffer
**
**  REMARKS
**
*/
ostream& BaseDataVASLWidthModelOperation::print(ostream& out) const
{
  BaseDataVASLModelOperation::print(out);

  return out;
}
/*F obj = Clone() . . . . . . . . . . . . . . . . . . . .  BaseDataVASLWidthModelOperation
**
**  DESCRIPTION
**    obj: The copy
**
**  REMARKS
**
*/
Identify * BaseDataVASLWidthModelOperation::Clone()
{
  BaseDataVASLWidthModelOperation *obj = new BaseDataVASLWidthModelOperation(*this);
  return obj;
}
/*F CopyClone(obj)  . . . . . . . . . . . . . . . . . . .  BaseDataVASLModelOperation
**
**  DESCRIPTION
**    obj: The object to be copied
**
**  REMARKS
**
*/
void BaseDataVASLWidthModelOperation::CopyClone(Identify * obj)
{
  BaseDataVASLWidthModelOperation *objfull = (BaseDataVASLWidthModelOperation *) obj;
  *this = *objfull;
  BaseDataVASLModelOperation::CopyClone(obj);
}
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . .  BaseDataVASLWidthModelOperation
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataVASLWidthModelOperation::EncodeThis(CommBuffer& buffer)
{
  bool result = BaseDataVASLModelOperation::EncodeThis(buffer);

  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . .  BaseDataVASLWidthModelOperation
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: True if successful
**
**  REMARKS
**
*/
bool BaseDataVASLWidthModelOperation::DecodeThis(CommBuffer& buffer)
{
  bool result = BaseDataVASLModelOperation::DecodeThis(buffer);

  return result;
}
/*F calculate . . . . . . . . . . . . . . . . . . BaseDataVASLWidthModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
BaseDataReal BaseDataVASLWidthModelOperation::calculate()
{
  //cout << "BaseDataVASLWidthModelOperation::calculate" << endl;
  double widthBeforeEdger = 0.0;
  //notused double widthAfterEdger = 0.0;
  // notused double width = 0.0;   
        double adjEG = 0.0;   
        // notused double adjVG = 0.0;   

  
//  int pass = ((BaseDataInteger *) getInputParameter("pass"))->GetValue();
  int pass = 5;
  

  // notused  double cnstw1 = ((BaseDataReal *) getCoefficient("cw1"))->GetValue();
  // notused  double cnstw2 = ((BaseDataReal *) getCoefficient("cw2"))->GetValue();

  // not used   double wBeforeEdger = ((BaseDataReal *) getInputParameter("widthBeforeEdger"))->GetValue();
        double wAfterEdger = ((BaseDataReal *) getInputParameter("widthAfterEdger"))->GetValue();
//      double wAfterPass = ((BaseDataReal *) getInputParameter("widthAfterPass"))->GetValue();

        double crWidth = ((BaseDataReal *) getInputParameter("curWidth"))->GetValue();
        double crHeight = ((BaseDataReal *) getInputParameter("curHeight"))->GetValue();
        double heightAfterP = ((BaseDataReal *) getInputParameter("heightAfterPass"))->GetValue();
        
        
        widthBeforeEdger = crWidth;
//      if (isOdd(pass)) {
                //calculate width increase according to dogbone model after LIGHT edger 
                //light edger is only used in odd passes, except pass 1

                
                if (pass == 1) {
//      BaseDataVASLDogBoneModelOperation *dogBoneModOp = new BaseDataVASLDogBoneModelOperation();
//
////                    VASLDogBoneModel *dogHModel = new VASLDogBoneModel (BString("DogBone(HeavyEdger)Model"), this,  diameterOfHERolls);
//
//      BaseDataReal *crWidthObj = new BaseDataReal();
//      crWidthObj->SetValue(crWidth);
//      dogBoneModOp->setInputParameter("widthBeforeEdger", crWidthObj);
//      BaseDataReal *crHeightObj = new BaseDataReal();
//      crHeightObj->SetValue(crHeight);
//      dogBoneModOp->setInputParameter("heightBeforeEdger", crHeightObj);
////                    VASLDogBoneInPar *dogIn = new VASLDogBoneInPar();
////                    dogIn->widthBeforeEdger = this->curWidth;
////                    dogIn->heightBeforeEdger = this->curHeight;
//
////                    VASLWidthOutPar *widthOut = 0;
////                    widthOut = 0;
//
//      BaseDataReal *wAfterEdgerObj = new BaseDataReal();
//      wAfterEdgerObj->SetValue(crWidth - getReductionHEdger());
//      dogBoneModOp->setInputParameter("widthAfterEdger", wAfterEdgerObj);
////                    dogIn->widthAfterEdger = this->curWidth - reductionHEdger;
//
//      BaseDataReal widthInc = dogBoneModOp->calculate();
////                    dogHModel->calculate(dogIn, widthOut);
////                    assert (widthOut != 0);
//
//      adjVG = crWidth - getReductionLEdger();
//      crWidth = adjVG + widthInc.GetValue();
//      adjEG = crWidth + cnstw1;
////                    this->adjVG = this->curWidth - this->reductionLEdger;
////                    this->curWidth = this->adjVG + widthOut->widthInc;
////                    this->adjEG = this->curWidth + 40;
//
//      delete dogBoneModOp;
////                    delete dogHModel;
////                    delete dogIn;
////                    delete widthOut;
                } else  {
      BaseDataVASLDogBoneModelOperation *dogBoneModOp = new BaseDataVASLDogBoneModelOperation();
      dogBoneModOp->initTheInputParameters();
      dogBoneModOp->initTheCoefficients();
                        dogBoneModOp->setDiameterOfEdgerRolls(cDiameterOfLERolls);  // ligtht edger
//cout << "diameterOfLERolls: " << dogBoneModOp->getDiameterOfEdgerRolls() << endl;                     
      BaseDataReal *crWidthObj = new BaseDataReal();
      crWidthObj->SetValue(crWidth);
      dogBoneModOp->setInputParameter("widthBeforeEdger", crWidthObj);
//cout << "widthBeforeEdger " << *dogBoneModOp->getInputParameter("widthBeforeEdger") << endl;                  
      BaseDataReal *crHeightObj = new BaseDataReal();
      crHeightObj->SetValue(crHeight);
      dogBoneModOp->setInputParameter("heightBeforeEdger", crHeightObj);
//cout << "heightBeforeEdger " << *dogBoneModOp->getInputParameter("heightBeforeEdger") << endl;                        

      BaseDataReal *wAfterEdgerObj = new BaseDataReal();
      wAfterEdgerObj->SetValue(crWidth - getCurReductionLEdger());
      dogBoneModOp->setInputParameter("widthAfterEdger", wAfterEdgerObj);
//cout << "widthAfterEdger " << *dogBoneModOp->getInputParameter("widthAfterEdger") << endl;                    

      dogBoneModOp->setCoefficient("cdb1", this->getCoefficient("cdb1") );
      dogBoneModOp->setCoefficient("cdb2", this->getCoefficient("cdb2") );
      dogBoneModOp->setCoefficient("cdb3", this->getCoefficient("cdb3") );
      dogBoneModOp->setCoefficient("cdb4", this->getCoefficient("cdb4") );
      dogBoneModOp->setCoefficient("cdb5", this->getCoefficient("cdb5") );
//cout << "cdb1 " << *dogBoneModOp->getCoefficient("cdb1") << endl;                     
//cout << "cdb2 " << *dogBoneModOp->getCoefficient("cdb2") << endl;                     
//cout << "cdb3 " << *dogBoneModOp->getCoefficient("cdb3") << endl;                     
//cout << "cdb4 " << *dogBoneModOp->getCoefficient("cdb4") << endl;                     
//cout << "cdb5 " << *dogBoneModOp->getCoefficient("cdb5") << endl;                     


      BaseDataReal widthInc = dogBoneModOp->calculate();
//cout << "widthInc " << widthInc.GetValue() << endl;                   

                        // open LEdger if it is not used
//cout << "getCurReductionLEdger " << getCurReductionLEdger() << endl;                  
                        if (getCurReductionLEdger() > 0.0) {
                                adjEG = crWidth - getCurReductionLEdger();
//cout << "1 adjEG " << adjEG << endl;                  
                                wAfterEdger = adjEG;    
//cout << "1 wAfterEdger " << wAfterEdger << endl;                      
                        } else {
                                adjEG = crWidth + 40.0;
//cout << "2 adjEG " << adjEG << endl;                  
                                wAfterEdger = crWidth;  
//cout << "2 wAfterEdger " << wAfterEdger << endl;                      
                        }
                        crWidth = crWidth - getCurReductionLEdger() + widthInc.GetValue();
//cout << "crWidth " << crWidth << endl;                        

                        setSumReduction(getSumReduction() + getCurReductionLEdger());
                        setSumMaxReduction(getSumMaxReduction() + getMaxReductionLEdger());


// old version:
//      adjEG = crWidth - getReductionLEdger();
//      crWidth = adjEG + widthInc.GetValue();

      delete crWidthObj;
      delete crHeightObj;
      delete wAfterEdgerObj;
      delete dogBoneModOp;
                }
//      } 
//      else {
//    cout << "pass is even" << endl;
//              adjEG = crWidth + cnstw2;
//      }
        
        
        wAfterEdger = crWidth;  

  BaseDataVASLKashimaModelOperation *kashModOp = new BaseDataVASLKashimaModelOperation();
  kashModOp->initTheInputParameters();
  kashModOp->initTheCoefficients();
        kashModOp->setDiameterOfEdgerRolls(cDiameterOfHGRolls);
        
  BaseDataReal *crHeightObj = new BaseDataReal();
  crHeightObj->SetValue(crHeight);
  kashModOp->setInputParameter("heightBeforePass", crHeightObj);

  BaseDataReal *heightAfterPObj = new BaseDataReal();
  heightAfterPObj->SetValue(heightAfterP);
  kashModOp->setInputParameter("heightAfterPass", heightAfterPObj);  // heigtht after last pass

  BaseDataReal *wAfterEdgerObj = new BaseDataReal();
  wAfterEdgerObj->SetValue(wAfterEdger);
  kashModOp->setInputParameter("widthBeforePass", wAfterEdgerObj);

//      kashIn->corrKashima = corrKashima;

  kashModOp->setCoefficient("ck1", this->getCoefficient("ck1") );
  kashModOp->setCoefficient("ck2", this->getCoefficient("ck2") );
  kashModOp->setCoefficient("ck3", this->getCoefficient("ck3") );
  kashModOp->setCoefficient("ck4", this->getCoefficient("ck4") );

  BaseDataReal widthInc = kashModOp->calculate();

        crWidth = crWidth + widthInc.GetValue();
        double wAfterPass = crWidth;

  delete crHeightObj;
  delete heightAfterPObj;
  delete wAfterEdgerObj;
  delete kashModOp;


  BaseDataReal val;  
  val.SetValue(wAfterPass);

  return val;
}
/*F initTheInputParameters . . . . . . . . . . . . . . . . . . BaseDataVASLWidthModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLWidthModelOperation::initTheInputParameters()
{
  TheInputParameters = new BaseDataParameterSet();

  // The Input Parameters from the dogbone model
  BaseDataReal *realHlp = new BaseDataReal();
  realHlp->NameTag = "widthBeforeEdger";
  realHlp->SetValue(0.0);
  TheInputParameters->AddObject(realHlp);

  realHlp->NameTag = "widthAfterEdger";
  TheInputParameters->AddObject(realHlp);

  realHlp->NameTag = "heightBeforeEdger";
  TheInputParameters->AddObject(realHlp);

  
  // The Input Parameters from the kashima model
  realHlp->NameTag = "widthBeforePass";
  realHlp->SetValue(0.0);
  TheInputParameters->AddObject(realHlp);

  realHlp->NameTag = "heightBeforePass";
  TheInputParameters->AddObject(realHlp);

  realHlp->NameTag = "heightAfterPass";
  TheInputParameters->AddObject(realHlp);
  
  realHlp->NameTag = "diameterOfRoughingRolls";
  TheInputParameters->AddObject(realHlp);
  
  // The internal Input Parameters, i.e values of the strip
  
  realHlp->NameTag = "curWidth";
  TheInputParameters->AddObject(realHlp);
  
  realHlp->NameTag = "curHeight";
  TheInputParameters->AddObject(realHlp);
  
  realHlp->NameTag = "curTemp";
  TheInputParameters->AddObject(realHlp);
  
  realHlp->NameTag = "curSpeed";
  TheInputParameters->AddObject(realHlp);
  
  realHlp->NameTag = "curLength";
  TheInputParameters->AddObject(realHlp);
  /*  
  realHlp->NameTag = "widthBeforeEdger";
  TheInputParameters->AddObject(realHlp);
  
  realHlp->NameTag = "widthAfterEdger";
  TheInputParameters->AddObject(realHlp);
  */
  realHlp->NameTag = "widthAfterPass";
  TheInputParameters->AddObject(realHlp);
  
  realHlp->NameTag = "forceHG";
  TheInputParameters->AddObject(realHlp);
  
  realHlp->NameTag = "forceLE";
  TheInputParameters->AddObject(realHlp);
  
  realHlp->NameTag = "forceHE";
  TheInputParameters->AddObject(realHlp);
  
  realHlp->NameTag = "finalWidth";
  TheInputParameters->AddObject(realHlp);  
  
  BaseDataInteger *intHlp = new BaseDataInteger();
  intHlp->NameTag = "pass";
  intHlp->SetValue(0);
  TheInputParameters->AddObject(intHlp);

  delete realHlp;
  delete intHlp;
}
/*F initTheCoefficients . . . . . . . . . . . . . . . . . . BaseDataVASLWidthModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLWidthModelOperation::initTheCoefficients()
{
  TheCoefficients = new BaseDataParameterSet();

  // The Coefficients from the dogbone model
  BaseDataReal *realHlp = new BaseDataReal();
  realHlp->NameTag = "cdb1";
  realHlp->SetValue(-1.877);
  TheCoefficients->AddObject(realHlp);

  realHlp->NameTag = "cdb2";
  realHlp->SetValue(0.063);
  TheCoefficients->AddObject(realHlp);

  realHlp->NameTag = "cdb3";
  realHlp->SetValue(0.441);
  TheCoefficients->AddObject(realHlp);

  realHlp->NameTag = "cdb4";
  realHlp->SetValue(0.989);
  TheCoefficients->AddObject(realHlp);

  realHlp->NameTag = "cdb5";
  realHlp->SetValue(7.591);
  TheCoefficients->AddObject(realHlp);


  // The Coefficients from the kashima model
  realHlp->NameTag = "ck1";
  realHlp->SetValue(-1.64);
  TheCoefficients->AddObject(realHlp);

  realHlp->NameTag = "ck2";
  realHlp->SetValue(0.376);
  TheCoefficients->AddObject(realHlp);

  realHlp->NameTag = "ck3";
  realHlp->SetValue(0.016);
  TheCoefficients->AddObject(realHlp);

  realHlp->NameTag = "ck4";
  realHlp->SetValue(0.015);
  TheCoefficients->AddObject(realHlp);


  // The internal Coefficients
  realHlp->NameTag = "cw1";
  realHlp->SetValue(40.0);
  TheCoefficients->AddObject(realHlp);

  realHlp->NameTag = "cw2";
  realHlp->SetValue(400.0);
  TheCoefficients->AddObject(realHlp);
  
  delete realHlp;
}
/*F fillCoefficients . . . . . . . . . . . . . . . . . . BaseDataVASLWidthModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLWidthModelOperation::fillCoefficients(BaseDataDoubleVector *parToOpt)
{
  BaseDataVASLModelOperation::fillCoefficients(parToOpt);
//cout << "TheCoefficients======================" << endl;
//TheCoefficients->print(cout);

  VectorNumeric theVec = parToOpt->CurrentVector();
  BaseDataReal *obj0 = (BaseDataReal *) TheCoefficients->GetObject("cdb1");
  obj0->SetValue(theVec[0]);
  BaseDataReal *obj1 = (BaseDataReal *) TheCoefficients->GetObject("cdb2");
  obj1->SetValue(theVec[1]);
  BaseDataReal *obj2 = (BaseDataReal *) TheCoefficients->GetObject("cdb3");
  obj2->SetValue(theVec[2]);
  BaseDataReal *obj3 = (BaseDataReal *) TheCoefficients->GetObject("cdb4");
  obj3->SetValue(theVec[3]);
  BaseDataReal *obj4 = (BaseDataReal *) TheCoefficients->GetObject("cdb5");
  obj4->SetValue(theVec[4]);
  
  BaseDataReal *obj5 = (BaseDataReal *) TheCoefficients->GetObject("ck1");
  obj5->SetValue(theVec[5]);
  BaseDataReal *obj6 = (BaseDataReal *) TheCoefficients->GetObject("ck2");
  obj6->SetValue(theVec[6]);
  BaseDataReal *obj7 = (BaseDataReal *) TheCoefficients->GetObject("ck3");
  obj7->SetValue(theVec[7]);
  BaseDataReal *obj8 = (BaseDataReal *) TheCoefficients->GetObject("ck4");
  obj8->SetValue(theVec[8]);

  BaseDataReal *obj9 = (BaseDataReal *) TheCoefficients->GetObject("cw1");
  obj9->SetValue(theVec[9]);
  BaseDataReal *obj10 = (BaseDataReal *) TheCoefficients->GetObject("cw2");
  obj10->SetValue(theVec[10]);

  /*
    BaseDataReal *cdb1Obj = new BaseDataReal();
    cdb1Obj->SetValue(theVec.at(0));
    setCoefficient("cdb1", cdb1Obj);

    BaseDataReal *cdb2Obj = new BaseDataReal();
    cdb2Obj->SetValue(theVec.at(1));
    this->setCoefficient("cdb2", cdb2Obj);

    BaseDataReal *cdb3Obj = new BaseDataReal();
    cdb3Obj->SetValue(theVec.at(2));
    this->setCoefficient("cdb3", cdb3Obj);

    BaseDataReal *cdb4Obj = new BaseDataReal();
    cdb4Obj->SetValue(theVec.at(3));
    this->setCoefficient("cdb4", cdb4Obj);

    BaseDataReal *cdb5Obj = new BaseDataReal();
    cdb5Obj->SetValue(theVec.at(4));
    this->setCoefficient("cdb5", cdb5Obj);


    BaseDataReal *ck1Obj = new BaseDataReal();
    ck1Obj->SetValue(theVec.at(5));
    this->setCoefficient("ck1", ck1Obj);

    BaseDataReal *ck2Obj = new BaseDataReal();
    ck2Obj->SetValue(theVec.at(6));
    this->setCoefficient("ck2", ck2Obj);

    BaseDataReal *ck3Obj = new BaseDataReal();
    ck3Obj->SetValue(theVec.at(7));
    this->setCoefficient("ck3", ck3Obj);

    BaseDataReal *ck4Obj = new BaseDataReal();
    ck4Obj->SetValue(theVec.at(8));
    this->setCoefficient("ck4", ck4Obj);


    BaseDataReal *cw1Obj = new BaseDataReal();
    cw1Obj->SetValue(theVec.at(9));
    this->setCoefficient("cw1", cw1Obj);

    BaseDataReal *cw2Obj = new BaseDataReal();
    cw2Obj->SetValue(theVec.at(10));
    this->setCoefficient("cw2", cw2Obj);
    
    delete cdb1Obj;
    delete cdb2Obj;
    delete cdb3Obj;
    delete cdb4Obj;
    delete cdb5Obj;
    delete ck1Obj;
    delete ck2Obj;
    delete ck3Obj;
    delete ck4Obj;
    delete cw1Obj;
    delete cw2Obj;
  */ 
}
/*F fillInputParameters . . . . . . . . . . . . . . . . . . BaseDataVASLWidthModelOperation
**
**  DESCRIPTION
**
**  REMARKS
**
*/
void BaseDataVASLWidthModelOperation::fillInputParameters(VectorNumeric *dataVec)
{
  BaseDataVASLModelOperation::fillInputParameters(dataVec);
//  cout << "BaseDataVASLWidthModelOperation::fillInputParameters called" << endl; 
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

  BaseDataReal *realHlp = new BaseDataReal();
  realHlp->SetValue((*dataVec)[4]);
  setInputParameter("widthBeforeEdger", realHlp);

  realHlp->SetValue((*dataVec)[4]);
  setInputParameter("curWidth", realHlp);

  realHlp->SetValue((*dataVec)[3]);
  setInputParameter("heightAfterPass", realHlp);

  realHlp->SetValue((*dataVec)[0]);
  setInputParameter("curHeight", realHlp);

  realHlp->SetValue((*dataVec)[0]);
  setInputParameter("heightBeforeEdger", realHlp);

  realHlp->SetValue((*dataVec)[0]);
  setInputParameter("heightBeforePass", realHlp);

//      double wAfterEdger = ((BaseDataReal *) getInputParameter("widthAfterEdger"))->GetValue();
  realHlp->SetValue((*dataVec)[9]);
  setInputParameter("widthAfterEdger", realHlp);
  delete realHlp;
}

/*S DataVASLWidthModelOperationClass
 */ 
/*F DataFunctionToOptimizeClass() . . . . . . . . . . . . . . . . . empty constructor
**
**  DESCRIPTION
**
**  REMARKS
**
*/
DataVASLWidthModelOperationClass::DataVASLWidthModelOperationClass()
{
  Identification = OPERATION_VASLWIDTHMODEL_ID;
  NameTag = OPERATION_VASLWIDTHMODEL_NAME;
  SubClass = OPERATION_VASLMODEL_NAME;
  EncodeDecodeClass = OPERATION_VASLWIDTHMODEL_NAME;
} 
/*F DataVASLWidthModelOperationClass<(data) . . . . . . . . . . . . . . .  copy constructor
**
**  DESCRIPTION
**     data: The class to be copied
**
**  REMARKS
**
*/
DataVASLWidthModelOperationClass::DataVASLWidthModelOperationClass(const DataVASLWidthModelOperationClass& data)
  : DataVASLModelOperationClass(data)
{
} 
/*F DataVASLWidthModelOperationClass(id,name,descr)  . . . . . . . . . . . . . constructor
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
DataVASLWidthModelOperationClass::DataVASLWidthModelOperationClass(const int id, 
                                                       const String& name,
                                                       const String& descr)
  : DataVASLModelOperationClass(id,name,descr)

{
  SubClass = OPERATION_VASLMODEL_NAME;
  EncodeDecodeClass = OPERATION_VASLWIDTHMODEL_NAME;
}
/*F out1 = print(out) . . . . . . . . . . . . . . . . . . DataVASLWidthModelOperationClass
**
**  DESCRIPTION
**    out: The output buffer
**
**  REMARKS
**
*/
ostream& DataVASLWidthModelOperationClass::print(ostream& out) const
{
  DataVASLModelOperationClass::print(out);
  return out;
}
/*F in1 = Read(in,set)  . . . . . . . . . . . . . . . . . DataVASLWidthModelOperationClass
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
bool DataVASLWidthModelOperationClass::Read(istream& in, DataSetOfObjectsClass& set)
{
  bool result = DataVASLModelOperationClass::Read(in,set);
  return result;
}
/*F CopyClone(objc) . . . . . . . . . . . . . . . . . . . DataVASLWidthModelOperationClass
**
**  DESCRIPTION
**    objc: The class to be copied
**
**  REMARKS
**
*/
void DataVASLWidthModelOperationClass::CopyClone(Identify * objc)
{
  DataVASLWidthModelOperationClass *objcfull = (DataVASLWidthModelOperationClass*) objc;
  *this = *objcfull;
  DataVASLModelOperationClass::CopyClone(objc);
}
/*F objc = Clone()  . . . . . . . . . . . . . . . . . . . DataVASLWidthModelOperationClass
**
**  DESCRIPTION
**    objc: The object class that was created
**
**  REMARKS
**
*/
Identify * DataVASLWidthModelOperationClass::Clone()
{
  DataVASLWidthModelOperationClass* id = new DataVASLWidthModelOperationClass(*this);
  return (Identify *) id;
}
/*F ans = EncodeThis(buffer)  . . . . . . . . . . . . . . DataVASLModelOperationClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataVASLWidthModelOperationClass::EncodeThis(CommBuffer& buffer)
{
  bool result = DataVASLModelOperationClass::EncodeThis(buffer);
  return result;
}
/*F ans = DecodeThis(buffer)  . . . . . . . . . . . . . . DataVASLModelOperationClass
**
**  DESCRIPTION
**    buffer: The buffer
**    ans: true if successful
**
**  REMARKS
**
*/
bool DataVASLWidthModelOperationClass::DecodeThis(CommBuffer& buffer)
{
  bool result = DataVASLModelOperationClass::DecodeThis(buffer);
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
BaseDataObject * DataVASLWidthModelOperationClass::BaseDataObjectExample()
{ 
  BaseDataObject *obj = (BaseDataObject *) new BaseDataVASLWidthModelOperation();
  obj->SetType(Identification);
  return obj;
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . . DataVASLWidthModelOperationClass
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, DataVASLWidthModelOperationClass*& obj)
{
  obj = new DataVASLWidthModelOperationClass;
  return obj->DecodeThis(buffer);
}
/*F ans = TopDecode(buffer,obj) . . . . . . . . . . . . .  BaseDataVASLWidthModelOperation
**
**  DESCRIPTION
**    buffer: The buffer 
**    obj: The object
**    ans: True if successful
**
**  REMARKS
**
*/
bool TopDecode(CommBuffer& buffer, BaseDataVASLWidthModelOperation*& obj)
{
  obj = new BaseDataVASLWidthModelOperation;
  return obj->DecodeThis(buffer);
}





/*F AddVASLModelOperationClasses(set) . . . . . . . . . . . . add new classes
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
void AddVASLModelOperationClasses(DataSetOfObjectsClass& set)
{
  String vaslModDescr("VASL Model as Operator");
  String vaslDogBoneModDescr("VASL Dog Bone Model as Operator");
  String vaslKashimaModDescr("VASL Kashima Model as Operator");
  String vaslWidthModDescr("VASL Width Model as Operator");
  
  DataVASLModelOperationClass vaslModelTstClass(OPERATION_VASLMODEL_ID,
                                                OPERATION_VASLMODEL_NAME,
                                                vaslModDescr);
  DataVASLDogBoneModelOperationClass vaslDogBoneModelTstClass(OPERATION_VASLDOGBONEMODEL_ID,
                                                              OPERATION_VASLDOGBONEMODEL_NAME,
                                                              vaslDogBoneModDescr);
  DataVASLKashimaModelOperationClass vaslKashimaModelTstClass(OPERATION_VASLKASHIMAMODEL_ID,
                                                              OPERATION_VASLKASHIMAMODEL_NAME,
                                                              vaslKashimaModDescr);
  DataVASLWidthModelOperationClass vaslWidthModelTstClass(OPERATION_VASLWIDTHMODEL_ID,
                                                          OPERATION_VASLWIDTHMODEL_NAME,
                                                          vaslWidthModDescr);
      
  set.AddObjectClass(vaslModelTstClass);
  set.AddObjectClass(vaslDogBoneModelTstClass);
  set.AddObjectClass(vaslKashimaModelTstClass);
  set.AddObjectClass(vaslWidthModelTstClass);
}


/*F InitialVASLModelOperationEncodeDecodeRoutines()
**
**  DESCRIPTION
**    
**  REMARKS
**
*/
extern void InitialVASLModelOperationEncodeDecodeRoutines()
{
  EncodeDecodeRegisterClass(DataVASLModelOperationClass,BaseDataVASLModelOperation,OPERATION_VASLMODEL_NAME);
  EncodeDecodeRegisterClass(DataVASLDogBoneModelOperationClass,BaseDataVASLDogBoneModelOperation,OPERATION_VASLDOGBONEMODEL_NAME);
  EncodeDecodeRegisterClass(DataVASLKashimaModelOperationClass,BaseDataVASLKashimaModelOperation,OPERATION_VASLKASHIMAMODEL_NAME);
  EncodeDecodeRegisterClass(DataVASLWidthModelOperationClass,BaseDataVASLWidthModelOperation,OPERATION_VASLWIDTHMODEL_NAME);
}

