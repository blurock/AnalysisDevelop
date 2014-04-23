#! /bin/tcsh -f

set PROGRAM     = otest 
set TOOLS        = $ANALYSIS_BASE/tools/programs

if(!(-d plots)) then
    mkdir plots
endif


#  $PROGRAM xxx Initial test 0 Read ./input/RunClass.inp ./input/Run.inp 0
#   $PROGRAM xxx Operate test 1 SetAlgorithmClass InstanceAlgorithmRun
#   $PROGRAM xxx Operate test 2 Read ./data/FlameClass.inp ./data/Flame.inp 0
#   $PROGRAM xxx Operate test 3 Read ./input/NumericPropertiesClass.inp ./data/FlameNumeric.inp 0
#   $PROGRAM xxx Operate test 4 RunAlgorithm MatrixSetUpAlg 0
#  $PROGRAM xxx Operate test 5 RunAlgorithm DistributionAlg 0
#  $PROGRAM xxx Operate test 6 Read ./input/opClass.inp ./data/op.inp 0
#  $PROGRAM xxx Operate test 7 RunAlgorithm NormalizeFromDistAlg 5

#  $PROGRAM xxx Operate test 8 Read ./data/normClass.inp ./data/norm.inp 0
#  $PROGRAM xxx Operate test 9 RunAlgorithm Normalize 5

#  $PROGRAM xxx Operate test 10 RunAlgorithm MatrixSetUpAlg 0

#  $TOOLS/Report/ReportGeneration.sh --program $PROGRAM test 11 Report  y_dimless \
#    Norm3-CH2 NormC2H NormC2H2 NormC2H3 NormC2H4 NormC2H5 NormC2H6 NormC3H3 NormC3H4\
#    NormC3H5 NormC3H6 NormC3H7 NormC3H8 NormCH NormCH2O NormCH3 NormCH4 NormCHCO \
#    NormCHO NormCO NormCO2 NormH NormH2 NormH2O2 NormHO2 NormIPRO NormO NormO2 NormOH
#     ##$PROGRAM xxx Experiment test 3 DistributionReport report Distributions

# $PROGRAM xxx Operate test 10 Read ./input/NumericPropertiesClass.inp ./data/deriv.inp 0
# $PROGRAM xxx Operate test 11 RunAlgorithm   NumericProperties 0

# $PROGRAM xxx Operate test 12 RunAlgorithm MatrixSetUpAlg 0
$TOOLS/Report/ReportGeneration.sh --program $PROGRAM test 13 Report  y_dimless \
                   y_dimless_NormO_1stDerivative y_dimless_NormO_2ndDerivative \
                   y_dimless_NormOH_1stDerivative y_dimless_NormOH_2ndDerivative \
                   y_dimless_NormO2_1stDerivative y_dimless_NormO2_2ndDerivative \
                   y_dimless_NormH_1stDerivative y_dimless_NormH_2ndDerivative \
                   y_dimless_NormH2_1stDerivative y_dimless_NormH2_2ndDerivative \
                   y_dimless_NormCO_1stDerivative y_dimless_NormCO_2ndDerivative \
                   y_dimless_NormCO2_1stDerivative y_dimless_NormCO2_2ndDerivative \
                   y_dimless_NormH2O2_1stDerivative y_dimless_NormH2O2_2ndDerivative \
                   y_dimless_NormHO2_1stDerivative y_dimless_NormHO2_2ndDerivative \
                   y_dimless_NormIPRO_1stDerivative y_dimless_NormIPRO_2ndDerivative \
                   y_dimless_Norm3-CH2_1stDerivative y_dimless_Norm3-CH2_2ndDerivative \
                   y_dimless_NormC2H_1stDerivative y_dimless_NormC2H_2ndDerivative \
                   y_dimless_NormC2H2_1stDerivative y_dimless_NormC2H2_2ndDerivative \
                   y_dimless_NormC2H3_1stDerivative y_dimless_NormC2H3_2ndDerivative \
                   y_dimless_NormC2H4_1stDerivative y_dimless_NormC2H4_2ndDerivative \
                   y_dimless_NormC2H5_1stDerivative y_dimless_NormC2H5_2ndDerivative \
                   y_dimless_NormC2H6_1stDerivative y_dimless_NormC2H6_2ndDerivative \
                   y_dimless_NormC3H3_1stDerivative y_dimless_NormC3H3_2ndDerivative \
                   y_dimless_NormC3H4_1stDerivative y_dimless_NormC3H4_2ndDerivative \
                   y_dimless_NormC3H5_1stDerivative y_dimless_NormC3H5_2ndDerivative \
                   y_dimless_NormC3H6_1stDerivative y_dimless_NormC3H6_2ndDerivative \
                   y_dimless_NormC3H7_1stDerivative y_dimless_NormC3H7_2ndDerivative \
                   y_dimless_NormC3H8_1stDerivative y_dimless_NormC3H8_2ndDerivative \
                   y_dimless_NormCH_1stDerivative y_dimless_NormCH_2ndDerivative \
                   y_dimless_NormCH2O_1stDerivative y_dimless_NormCH2O_2ndDerivative \
                   y_dimless_NormCH3_1stDerivative y_dimless_NormCH3_2ndDerivative \
                   y_dimless_NormCH4_1stDerivative y_dimless_NormCH4_2ndDerivative \
                   y_dimless_NormCHCO_1stDerivative y_dimless_NormCHCO_2ndDerivative \
                   y_dimless_NormCHO_1stDerivative y_dimless_NormCHO_2ndDerivative 
#$PROGRAM xxx Operate test 2 Read ./input/InitialClass.inp ./data/ToolingSetup.inp 0
#$PROGRAM xxx Change test 3 RunAlgorithm ReadInstancesAlg 0
#$PROGRAM xxx Operate test 3 RunAlgorithm InstanceSetUpAlg 0
#$PROGRAM xxx Operate test 4 RunAlgorithm AttributeByTypeAlg 0
