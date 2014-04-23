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
 
#ifndef BASIS_VASLMODELOPTIMIZETYPE_HH
#define BASIS_VASLMODELOPTIMIZETYPE_HH




/*C BaseDataWidthModelMatrixSetUp  . . . . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**
**  REMARKS
*/
class BaseDataWidthModelMatrixSetUp : public BaseDataAlgorithmOperation
{
  // BaseDataWidthModelMatrixSetUp Keywords:
  String TenPercentsS;
  bool TenPercents;
  
  // BaseDataWidthModelMatrixSetUp InParameters:
  String TotalInstanceNameListS;
  BaseDataKeyWords *TotalInstanceNameList;
  String AttributeNamesS;
  BaseDataKeyWords *AttributeNames;

  String TestMatrixObjectS;
  BaseDataInstanceDoubleMatrix *TestMatrixObject;
  String TrainMatrixObjectS;
  BaseDataInstanceDoubleMatrix *TrainMatrixObject;

public:
  BaseDataWidthModelMatrixSetUp();
  BaseDataWidthModelMatrixSetUp(const BaseDataWidthModelMatrixSetUp& data);
  STANDARD_VIRTUAL_ALGORITHM_OBJECT_METHODS;
  STANDARD_VIRTUAL_METHODS_OBJECT;
};
/*C DataWidthModelMatrixSetUpClass . . . . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
*/
class DataWidthModelMatrixSetUpClass : public DataAlgorithmOperationClass
{
public:
  DataWidthModelMatrixSetUpClass();
  DataWidthModelMatrixSetUpClass(const DataWidthModelMatrixSetUpClass& data);
  DataWidthModelMatrixSetUpClass(const int id, 
		    const String& name,
		    const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS;
};


/*C BaseDataWidthModelOptimizeFunction
**
**  DESCRIPTION
**        
**  REMARKS
**
*/
class BaseDataWidthModelOptimizeFunction : public BaseDataFunctionToOptimize
{
  static Vector<int> *indexVec;
  VectorNumeric origPars;
public:
  BaseDataWidthModelOptimizeFunction();
  BaseDataWidthModelOptimizeFunction(const BaseDataWidthModelOptimizeFunction& data);
  BaseDataWidthModelOptimizeFunction(BaseDataInteger *parDim,
      BaseDataSimAnnUpperLower *upLow, 
      BaseDataDoubleVector *parVec, 
      BaseDataInstanceDoubleMatrix *dataMat,
      BaseDataDoubleVector *costTanVec,
      BaseDataDoubleVector *parIntRealVec);

  STANDARD_VIRTUAL_METHODS_OBJECT;

  virtual BaseDataReal operator()(BaseDataDoubleVector *parToOpt, 
                                  BaseDataInstanceDoubleMatrix *dataMat,
                                  DataDoubleVectorClass *parToOptClass, 
                                  DataInstanceDoubleMatrixClass *dataMatClass);
	virtual BaseDataInstanceDoubleMatrix * testOptimizedResult(
																	 BaseDataDoubleVector *origPars, 
																	 BaseDataDoubleVector *optimizedPars, 
																	 BaseDataInstanceDoubleMatrix *dataMat);

  void createIndexVector(MatrixNumeric& mat,
                         BaseDataVASLWidthModelOperation& widthModOp,
                         BaseDataVASLWidthModelOperation& widthModOpOrig);
  double calculateDiff(VectorNumeric& modelOutput, 
                       VectorNumeric& actualOutput);
  
  void initOrigPars(void);
  Vector<int> * getIndecesOfFirstN(PairList<double, int>& pairsOfValsAndInds, int n);
}; // end class BaseDataWidthModelOptimizeFunction


/*C DataTestFunction1Class . . . . . . . . . . . . . . .  
**
**  DESCRIPTION
**
**  REMARKS
**
*/
class DataWidthModelOptimizeFunctionClass : public DataFunctionToOptimizeClass
{
public:
  DataWidthModelOptimizeFunctionClass();
  DataWidthModelOptimizeFunctionClass(const DataWidthModelOptimizeFunctionClass& data);
  DataWidthModelOptimizeFunctionClass(const int id, 
                         const String& name,
                         const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS;
};  // end class DataWidthModelOptimizeFunctionClass



#endif
