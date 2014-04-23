/*  FILE     SimulatedAnnealingType.hh
**  PACKAGE  SimulatedAnnealing
**  AUTHOR   
**
**  CONTENT
**    Class definitions for the "SimulatedAnnealing" package.
**
**  OVERVIEW
**
**  IMPLEMENTATION
**
**  REFERENCES
**
*/
 
#ifndef BASIS_VASLMODELOPERATIONTYPE_HH
#define BASIS_VASLMODELOPERATIONTYPE_HH

//#include "VObject.hpp"


/*C BaseDataVASLModelOperation  . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**
**  REMARKS
*/
class BaseDataVASLModelOperation : public BaseDataOperation
{
  double diameterOfEdgerRolls;
//	double reductionLEdger;
//		float reductionLEdgerO70;
//		float reductionLEdgerU70;
	double curReductionLEdger;
	double reductionHEdger;
	double maxReductionHEdger;
	double maxReductionLEdger;

	double corrHEdger;
	double corrRollingForce;
	double corrKashima;	//Korrekturfaktor Kashimaformel
	double corrDogBone;	// Korrekturfaktor DogBoneModel

	double sumReduction;
	double sumMaxReduction; 
//	double sumReductionOld;
//	double sumMaxReductionOld; 



  
public:
  BaseDataParameterSet *TheInputParameters;
  BaseDataParameterSet *TheCoefficients;
//  BaseDataSetOfObjects *TheInputParameters;
//  BaseDataSetOfObjects *TheCoefficients;

public:
  BaseDataVASLModelOperation();
  BaseDataVASLModelOperation(const BaseDataVASLModelOperation& data);
  ~BaseDataVASLModelOperation();

  STANDARD_VIRTUAL_METHODS_OBJECT;
  STANDARD_VIRTUAL_OPERATION_METHODS;

//  virtual BaseDataReal operator()(BaseDataSetOfObjects *parToOpt, 
//                                  BaseDataSetOfObjects *coeffs,
//                                  DataSetOfObjectsClass *parToOptClass,
//                                  DataSetOfObjectsClass *coeffsClass);
  virtual BaseDataReal operator()();
  
  STANDARD_VIRTUAL_VASLMODELOPERATIONMETHODS_OBJECT;

  BaseDataObject *getInputParameter(String str);          
  bool setInputParameter(String str, BaseDataObject *obj);  
  BaseDataObject *getCoefficient(String str);  
  bool setCoefficient(String str, BaseDataObject *obj);
    
  void setTheInputParameters(BaseDataParameterSet* inp);
  void setTheCoefficients(BaseDataParameterSet* coeff);

  void setDiameterOfEdgerRolls(double val);
  double getDiameterOfEdgerRolls(void);
	void setCurReductionLEdger(double val);
	double getCurReductionLEdger(void);
	void setReductionHEdger(double val);
	double getReductionHEdger(void);
	void setMaxReductionHEdger(double val);
	double getMaxReductionHEdger(void);
	void setMaxReductionLEdger(double val);
	double getMaxReductionLEdger(void);

	void setCorrHEdger(double val);
	double getCorrHEdger(void);
	void setCorrRollingForce(double val);
	double getCorrRollingForce(void);
	void setCorrKashima(double val);
	double getCorrKashima(void);
	void setCorrDogBone(double val);
	double getCorrDogBone(void);

	void setSumReduction(double val);
	double getSumReduction(void);
	void setSumMaxReduction(double val);
	double getSumMaxReduction(void);

}; // end class BaseDataVASLModelOperation

/*C DataVASLModelOperationClass . . . . . . . . . . . . . . .  
**
**  DESCRIPTION
**
**  REMARKS
**
*/
class DataVASLModelOperationClass : public DataOperationClass
{
public:
  DataParameterSetClass* TheInputParametersClass;
  DataParameterSetClass* TheCoefficientsClass;
//  DataSetOfObjectsClass* TheInputParametersClass;
//  DataSetOfObjectsClass* TheCoefficientsClass;
public:
  DataVASLModelOperationClass();
  DataVASLModelOperationClass(const DataVASLModelOperationClass& data);
  DataVASLModelOperationClass(const int id, 
                             const String& name,
                             const String& descr);
  ~DataVASLModelOperationClass();
  STANDARD_VIRTUAL_METHODS_CLASS;
};  // end class DataVASLModelOperationClass



/*C BaseDataVASLDogBoneModelOperation  . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**
**  REMARKS
*/
class BaseDataVASLDogBoneModelOperation : public BaseDataVASLModelOperation
{
public:
  BaseDataVASLDogBoneModelOperation();
  BaseDataVASLDogBoneModelOperation(const BaseDataVASLDogBoneModelOperation& data);
  ~BaseDataVASLDogBoneModelOperation();

  STANDARD_VIRTUAL_METHODS_OBJECT;
  STANDARD_VIRTUAL_VASLMODELOPERATIONMETHODS_OBJECT;
  
  double calculateDogBoneFactor();
}; // end class BaseDataVASLDogBoneModelOperation

/*C DataVASLDogBoneModelOperationClass . . . . . . . . . . . . . . .  
**
**  DESCRIPTION
**
**  REMARKS
**
*/
class DataVASLDogBoneModelOperationClass : public DataVASLModelOperationClass
{
public:
  DataVASLDogBoneModelOperationClass();
  DataVASLDogBoneModelOperationClass(const DataVASLDogBoneModelOperationClass& data);
  DataVASLDogBoneModelOperationClass(const int id, 
                              const String& name,
                              const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS;
};  // end class DataVASLDogBoneModelOperationClass 



/*C BaseDataVASLKashimaModelOperation  . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**
**  REMARKS
*/
class BaseDataVASLKashimaModelOperation : public BaseDataVASLModelOperation
{
public:
  BaseDataVASLKashimaModelOperation();
  BaseDataVASLKashimaModelOperation(const BaseDataVASLKashimaModelOperation& data);
  ~BaseDataVASLKashimaModelOperation();

  STANDARD_VIRTUAL_METHODS_OBJECT;
  STANDARD_VIRTUAL_VASLMODELOPERATIONMETHODS_OBJECT;
  
  double calculateWidthExponent();
  double calculateWidthExponent_old();
}; // end class DataVASLKashimaModelOperationClass

/*C DataVASLKashimaOperatorClass . . . . . . . . . . . . . . .  
**
**  DESCRIPTION
**
**  REMARKS
**
*/
class DataVASLKashimaModelOperationClass : public DataVASLModelOperationClass
{
public:
  DataVASLKashimaModelOperationClass();
  DataVASLKashimaModelOperationClass(const DataVASLKashimaModelOperationClass& data);
  DataVASLKashimaModelOperationClass(const int id, 
                              const String& name,
                              const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS;
};  // end class DataVASLKashimaOperatorClass 



/*C BaseDataVASLWidthModelOperation  . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**
**  REMARKS
*/
class BaseDataVASLWidthModelOperation : public BaseDataVASLModelOperation
{
public:
  BaseDataVASLWidthModelOperation();
  BaseDataVASLWidthModelOperation(const BaseDataVASLWidthModelOperation& data);
  ~BaseDataVASLWidthModelOperation();

  BaseDataReal calculateDogBone(double crWidth, double crHeight);
  STANDARD_VIRTUAL_METHODS_OBJECT;
  STANDARD_VIRTUAL_VASLMODELOPERATIONMETHODS_OBJECT;
  
}; // end class BaseDataVASLWidthModelOperation

/*C DataVASLWidthModelOperationClass . . . . . . . . . . . . . . .  
**
**  DESCRIPTION
**
**  REMARKS
**
*/
class DataVASLWidthModelOperationClass : public DataVASLModelOperationClass
{
public:
  DataVASLWidthModelOperationClass();
  DataVASLWidthModelOperationClass(const DataVASLWidthModelOperationClass& data);
  DataVASLWidthModelOperationClass(const int id, 
                              const String& name,
                              const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS;
};  // end class DataVASLWidthModelOperationClass 



#endif
