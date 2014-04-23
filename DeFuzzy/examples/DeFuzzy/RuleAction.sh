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

otest xxxx Initial test -1 Read algClass.inp algInst.inp 0
otest xxxx Operate test 0  SetAlgorithmClass AlgorithmTestRun
### otest xxx  Experiment test 1 Print Class
### otest xxx  Experiment test 1 Print Class ProductionSystemSearch
### otest xxx  Experiment test 1 Print Attribute RuleSystemSearch

otest xxx Operate test 1 Read InstancesClass.inp Instances.inp 0
otest xxx Operate test 2 RunAlgorithm RuleAction 2
otest xx Experiment test 3 Print Instance Instance1 Action1
