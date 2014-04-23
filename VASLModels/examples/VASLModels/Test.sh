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


endif

otest xxx Operate test 1 Read NewParametersClass.inp NewParameters.inp 0
otest xxx Operate test 2 RunAlgorithm NewParameter 0

otest xxx Operate test 3 Read vaslexpClass.inp vaslexp.inp 0
otest xxx Operate test 4 RunAlgorithm NewParameter 0

otest xxx Experiment test 5 Print Instance BandNumber425136 NewVariable
#otest xxx Experiment test 5 Print Instance BandNumber425136 Breite_nach_Stich_gemessen_5
otest xxx Experiment test 5 Print Instance BandNumber425138 NewVariable
#otest xxx Experiment test 5 Print Instance BandNumber425138 Breite_nach_Stich_gemessen_5
otest xxx Experiment test 5 Print Instance BandNumber425140 NewVariable
#otest xxx Experiment test 5 Print Instance BandNumber425140 Breite_nach_Stich_gemessen_5
otest xxx Experiment test 5 Print Instance BandNumber425141 NewVariable
#otest xxx Experiment test 5 Print Instance BandNumber425141 Breite_nach_Stich_gemessen_5


otest xxx Operate test 5 Read vasloptexpClass.inp vasloptexp.inp 0
#otest xxx Operate  test 6 RunAlgorithm Genetic 2
#otest xxx Experiment test 7 Print Attribute OptimizedObject

#otest xxx Operate    test 6 Read walzkraftClass.inp walzkraft.inp 0
#otest xxx Operate    test 7 RunAlgorithm Genetic 2
#otest xxx Experiment test 8 Print Attribute OptimizedObject

#otest xxx Operate    test 6 Read laengeClass.inp laenge.inp 0
#otest xxx Operate    test 7 RunAlgorithm Genetic 2
#otest xxx Experiment test 8 Print Attribute OptimizedObject
otest xxx Operate    test 6 Read dectreeClass.inp dectree.inp 0
otest xxx Operate    test 7 Read predgenClass.inp predgen.inp 0
otest xxx Operate    test 8 RunAlgorithm CriticalPointReadAlg 0
otest xxx Operate    test 9 RunAlgorithm PartitionsFromCriticalPointsAlg 0
otest xxx Operate    test 10 RunAlgorithm DecisionTreeAlg 1
