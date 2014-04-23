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
otest Initial test 0 Read instClass.inp inst.inp 0
otest Operate test 1 SetAlgorithmClass TestAlgorithmRun
otest Operate test 2 RunAlgorithm MatrixSetUpAlg 0
otest Operate test 3 RunAlgorithm PCAAlg 0
otest Operate test 4 RunAlgorithm PCAVarGenAlg 0


