#!/bin/csh
#./T
# FILE     runit.sh
# PACKAGE  Maintenance
# AUTHORS  Edward S. Blurock
#
# CONTENT
#
#c COPYRIGHT (C) 1997 RISC Linz

    #./VASLModelOptimize.exe xxx Initial VASLModelOptimize -1 T
    #./VASLModelOptimize.exe xxx Initial VASLModelOptimize -1 Print Class
    #./VASLModelOptimize.exe xxx Experiment VASLModelOptimize 0 Print Class




##### Read in algorithm classes:
# ------------------------------
#otest xxx Initial VASLModelOptimize -1 Read VASLModelOptimizeAlgClass.inp VASLModelOptimizeAlgInst.inp 0
#otest xxx Change VASLModelOptimize 0 SetAlgorithmClass TestGoalRun 




##### Read in data:
# -----------------
#otest xxx Operate VASLModelOptimize 0 Read VASLforWidthOpt_dataclass.inp VASLforWidthOpt_data.inp 0
    #./VASLModelOptimize.exe xxx Experiment VASLModelOptimize 1 Print Attribute 


    #./VASLModelOptimize.exe xxx Operate VASLModelOptimize 1 RunAlgorithm MatrixSetUpAlg 0
      #./VASLModelOptimize.exe xxx Experiment VASLModelOptimize 2 Print Attribute 
      #./VASLModelOptimize.exe xxx Experiment VASLModelOptimize 2 Print Attribute MatrixObject




##### Create TrainMatrix and TestMatrix using MatrixSetUpAlg10Percents:
##### not neceeary, if TestMatrixObject and TrainMatrixObject already exist.
# --------------------------------------------------------------------------
#otest xxx Operate VASLModelOptimize 1 RunAlgorithm MatrixSetUpAlg10Percents 0
    #./VASLModelOptimize.exe xxx Experiment VASLModelOptimize 2 Print Attribute 
    #./VASLModelOptimize.exe xxx Experiment VASLModelOptimize 2 Print Attribute TrainMatrixObject
    #./VASLModelOptimize.exe xxx Experiment VASLModelOptimize 2 Print Attribute TestMatrixObject


          #./VASLModelOptimize.exe xxx Operate VASLModelOptimize 0 Read manybands_dataclass.inp manybands_data.inp 0


##### Read in FunctionToOptimize:
# -------------------------------
#otest xxx Operate VASLModelOptimize 2 Read VASLModelOptimize_dataclass.inp VASLModelOptimize_data.inp 0

          #./VASLModelOptimize.exe xxx Experiment VASLModelOptimize 2 Print Attribute 
          #./VASLModelOptimize.exe xxx Experiment VASLModelOptimize 0 Print Attribute SAOptAlg
          #./VASLModelOptimize.exe xxx Experiment VASLModelOptimize 0 Print Attribute SATestAlg
          #./VASLModelOptimize.exe xxx Experiment VASLModelOptimize 3 Print Attribute
          #./VASLModelOptimize.exe xxx Experiment VASLModelOptimize 3 Print Instance 
          #./VASLModelOptimize.exe xxx Experiment VASLModelOptimize 3 Print Instance BandNumber425136
          #./VASLModelOptimize.exe xxx Experiment VASLModelOptimize 3 Print Attribute TheFunctionToOptimize


##### Optimize:
##### I.e. Run algorithm SAOptAlg
# -------------------------------
otest xxx Experiment VASLModelOptimize 3 RunAlgorithm SAOptAlg 0



##### Or check optimized pars:
# ----------------------------
##### Read in TheOptimizedPars:
##### not neceeary, if TheOptimizedPars already exists.
# -------------------------------------------------
#./VASLModelOptimize.exe xxx Operate VASLModelOptimize 3 Read VASLWidthOptimized_dataclass.inp VASLWidthOptimized_data.inp 0
		#./VASLModelOptimize.exe xxx Experiment VASLModelOptimize 4 Print Attribute 
		#./VASLModelOptimize.exe xxx Experiment VASLModelOptimize 4 Print Attribute TheOptimizedPars
##### And now check it:
##### I.e. Run SATestAlg
# ----------------------
#./VASLModelOptimize.exe xxx Operate VASLModelOptimize 4 RunAlgorithm SATestAlg 0
		#./VASLModelOptimize.exe xxx Experiment VASLModelOptimize 5 Print Instance BandNumber425139 DiffOrigOptimized 




