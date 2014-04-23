#!/bin/csh
#
# FILE     runit.sh
# PACKAGE  Maintenance
# AUTHORS  Edward S. Blurock
#
# CONTENT
#   run of decision tree for tooling data
#
#c COPYRIGHT (C) 1997 RISC Linz
set skip = skip
set check = $1

if( $1 != skip ) then

otest xxx Initial test -1 Read algClass.inp alg.inp 0
otest xxx Change test 0 Read expClass.inp exp.inp 0
otest xxx Change test 0 Read instClass.inp inst.inp 0
otest xxx Change test 0 SetAlgorithmClass TestAlgorithmRun

#otest xxx Operate test 0 Read vaslinstClass.inp vaslinst.inp 0
otest xxx Operate  test 0 Read vaslinstClass.inp voestdata.150.dat 0
#otest xxx Change   test 1 Read analysisClass.inp analysis150.inp 0

otest xxx Operate test 1 Read vaslexp1Class.inp vaslexp1.inp 0
otest xxx Change  test 2 RunAlgorithm NewParameter 0
#otest xxx Experiment test 2 Print Instance BandNumber425136 Pass3Width
#otest xxx Experiment test 2 Print Instance BandNumber425136 Breite_nach_Stich_warm_3
#otest xxx Experiment test 2 Print Instance BandNumber425136 Pass5Width
#otest xxx Experiment test 2 Print Instance BandNumber425136 Breite_nach_Stich_warm_5

otest xxx Operate test 2 Read vaslexp2Class.inp vaslexp2.inp 0
#otest xxx Operate test 2 Read vaslexp2Class.inp vaslexp3.inp 0
otest xxx Change  test 3 RunAlgorithm NewParameter 0

#otest xxx Experiment test 3 Print Instance BandNumber425136 Pass3WidthDiff
#otest xxx Experiment test 3 Print Instance BandNumber425136 Pass5WidthDiff
#otest xxx Experiment test 3 Print Instance BandNumber425136 Pass5MeasuredDiff

otest xxx Operate test 3 RunAlgorithm InstanceSetUpAlg    0
otest xxx Change  test 4 RunAlgorithm AttributeByNameAlg  0
otest xxx Change  test 4 RunAlgorithm MatrixSetUpAlg      0
otest xxx Change  test 4 RunAlgorithm DistributionAlg     0

otest xxx Operate test 4 Read verifyClass.inp verify.inp 0
otest xxx Change test 5 RunAlgorithm NewParameter 0
otest xxx Change test 5 RunAlgorithm Verify 0


otest xxx Operate test 5 Read model1Class.inp model1.inp 0
otest xxx Change  test 6 RunAlgorithm InstanceListFromPredicate 2
otest xxx Experiment test 6 Print Attribute InstanceNameList

otest xxx Operate test 6 Read VASLModelOptimize_dataclass.inp VASLModelOptimize_data.inp 0
otest xxx Operate test 7 RunAlgorithm MatrixSetUpAlg10Percents 0
endif
otest xxx Operate test 8 RunAlgorithm AlgSAOpt 0
cp myASA_out SAOpt_ASA.out
otest xxx Operate test 9 RunAlgorithm AlgSATest 0
cp myASA_out SATest_ASA.out
