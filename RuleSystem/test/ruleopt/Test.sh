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

set ANALYSISEXE   = otest


if(!(-d saves)) then
mkdir saves
endif

if($1 != last) then

$ANALYSISEXE xxxx Initial test -1 Read algClass.inp alg.inp 0
$ANALYSISEXE xxxx Operate test 0  SetAlgorithmClass AlgorithmTestRun
$ANALYSISEXE xxx  Operate test 1 Read instClass.inp inst.inp 0
$ANALYSISEXE xxx  Operate test 2 Read distClass.inp dist.inp 0
$ANALYSISEXE xxx Operate test 3 Read expClass.inp exp.inp 0

$ANALYSISEXE xxx Operate test 4 Read ruleoptClass.inp ruleopt.inp 0
$ANALYSISEXE xxx Operate test 5 RunAlgorithm Genetic 1
$ANALYSISEXE xxx Experiment test 6 Print Attribute OptimizedObject 


$ANALYSISEXE xxx Operate test 6 Read condoptClass.inp condopt.inp 0
$ANALYSISEXE xxx Operate test 7 RunAlgorithm Genetic 2
$ANALYSISEXE xxx Experiment test 8 Print Attribute OptimizedObject 
endif

$ANALYSISEXE xxx Operate test 8 Read lineoptClass.inp lineopt.inp 0
$ANALYSISEXE xxx Operate test 9 RunAlgorithm Genetic 2
#$ANALYSISEXE xxx Experiment test 10 Print Attribute OptimizedObject 
