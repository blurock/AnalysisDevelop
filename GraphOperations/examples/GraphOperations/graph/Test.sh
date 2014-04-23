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
otest xxx Initial test -1 Read algClass.inp alg.inp 0
otest xxx Change test 0   SetAlgorithmClass TestAlgorithmRun
otest xxx Change test 0   Read expClass.inp exp.inp 0
otest xxx Change test 0   Read predClass.inp pred.inp 0
#otest xxx Change test 0   Read instClass.inp inst.inp 0

otest xxx Change test 0   Read grpexampleClass.inp grpexample.inp 0

otest xxx Change test 0   Read nodedescrClass.inp nodedescr.inp 0
otest xxx Operate test 0 RunAlgorithm Operation 0
otest xxx Experiment test 1 Print Attribute NewGraph

otest xxx Change  test 1 Read graphClass.inp graph.inp 0
otest xxx Operate test 1 RunAlgorithm Operation 0
otest xxx Experiment test 2 Print Attribute MatchGraph

otest xxx Change test 2 Read NeighborsClass.inp Neighbors.inp 0
otest xxx Operate test 2 RunAlgorithm Operation 0
otest xxx Experiment test 3 Print Attribute NextNodes
