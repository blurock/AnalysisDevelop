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

otest xxxx Initial test -1 Read algClass.inp alg.inp 0
otest xxxx Operate test 0  SetAlgorithmClass AlgorithmTestRun
otest xxx Operate  test 1 Read instClass.inp inst.inp 0
otest xxx Operate  test 2 Read distClass.inp dist.inp 0
otest xxx Operate  test 3 Read geneticClass.inp genetic.inp 0
otest xxx Operate  test 4 RunAlgorithm Genetic 1
otest xxx Experiment test 5 Print Attribute OptimizedObject

otest xxx Operate  test 5 Read geneticClass.inp genetic.inp 0
otest xxx Operate  test 6 RunAlgorithm Genetic 2
otest xxx Experiment test 7 Print Attribute OptimizedObject
