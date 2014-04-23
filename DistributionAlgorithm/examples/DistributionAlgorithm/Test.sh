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
otest xxx Initial test 0 Read instClass.inp inst.inp 0
otest xxx Operate test 1 SetAlgorithmClass TestAlgorithmRun
otest xxx Operate test 2 RunAlgorithm MatrixSetUpAlg 0
otest xxx Operate test 3 RunAlgorithm DistributionAlg 0
otest xxx Operate test 4 Read opClass.inp op.inp 0
otest xxx Operate test 5 RunAlgorithm NormalizeFromDistAlg 5
otest xxx Operate test 6 Read normClass.inp norm.inp 0
otest xxx Operate test 7 RunAlgorithm Normalize 0
otest xxx Experiment test 8 Print Instance Instance1 NormedVar3



