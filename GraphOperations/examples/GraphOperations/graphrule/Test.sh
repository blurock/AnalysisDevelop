#!/bin/csh 
#
# FILE     runit.sh
# PACKAGE  Maintenance
# AUTHORS  Edward S. Blurock
#
# CONTENT
#   Run a rule system
#
#c COPYRIGHT (C) 1997 RISC Linz

set ANALYSISEXE = ./otest

$ANALYSISEXE  xxx  Initial test -1 Read algClass.inp  alg.inp    0
$ANALYSISEXE  xxx  Change  test 0  SetAlgorithmClass AlgorithmTestRun
$ANALYSISEXE  xxx  Change  test 0  Read expClass.inp exp.inp   0
$ANALYSISEXE  xxx  Change  test 0  Read graphClass.inp graph.inp   0

$ANALYSISEXE  xxx  Operate  test 0  Read instClass.inp inst.inp   0
$ANALYSISEXE  xxx  Change   test 1  Read ruleClass.inp rule.inp   0
$ANALYSISEXE  xxx  Operate  test 1  RunAlgorithm RuleSystemSearch 0
$ANALYSISEXE  xxx  Experiment test 2 Print Instance Instance1 ProductionSystem
