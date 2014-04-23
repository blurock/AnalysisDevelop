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
otest xxx Change test 0 SetAlgorithmClass TestAlgorithmRun
otest xxx Change test 0 Read expClass.inp exp.inp   0

otest xxx Operate  test 0 Read vaslinstClass.inp vaslinst.inp 0
otest xxx Change   test 1 Read analysisClass.inp analysis.inp 0

#otest xxx Change   test 1 Read vaslinstClass.inp voestdata.150.dat 0
#otest xxx Change   test 1 Read analysisClass.inp analysis150.inp 0

otest xxx Operate test 1 Read vaslexpClass.inp vaslexp.inp 0
otest xxx Change  test 2 Read verifyexpClass.inp verifyexp.inp 0
otest xxx Change  test 2 RunAlgorithm NewParameter 0
otest xxx Experiment test 2 Print Instance  BandNumber425136

otest xxx Operate test 2 RunAlgorithm InstanceSetUpAlg    0
otest xxx Change  test 3 RunAlgorithm AttributeByNameAlg  0
otest xxx Change  test 3 RunAlgorithm MatrixSetUpAlg      0
otest xxx Change  test 3 RunAlgorithm DistributionAlg     0
otest xxx Experiment test 3 Print Attribute

endif


otest xxx Operate  test 3 Read descr1Class.inp descr1.inp   0
otest xxx Change   test 4 RunAlgorithm NewParameter 0
otest xxx Experiment test 4 Print Instance  BandNumber425136 LogicDescription
otest xxx Change   test 4 RunAlgorithm Verify 0
otest xxx Experiment test 4 Print Instance  BandNumber425136 VerificationError
otest xxx Experiment test 4 Print Instance  BandNumber425138 VerificationError
