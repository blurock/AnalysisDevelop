#!/bin/csh
#
# FILE     Test.sh
# PACKAGE  Maintenance
# AUTHORS  Edward S. Blurock
#
# CONTENT
#   run of decision tree for tooling data
#
#c COPYRIGHT (C) 1997 RISC Linz

set ANALYSISEXE   = otest
set DONT          = "true"

set NOTALL = $1

if(!(-d saves)) then
mkdir saves
endif

if($NOTALL != $DONT) then

    # Setup of the main 'Operation' to apply expressions
    $ANALYSISEXE xxx Initial test -1 Read algClass.inp alg.inp 0
    $ANALYSISEXE xxx Change test 0 SetAlgorithmClass TestAlgorithmRun
    
    # Setup the simple instance set
    $ANALYSISEXE xxx Operate test 0 Read instClass.inp inst.inp 0
    $ANALYSISEXE xxx Experiment test 1 Print Instance Instance1
    $ANALYSISEXE xxx Experiment test 1 Write Instance Instance1 VarT1
    $ANALYSISEXE xxx Experiment test 1 Write Instance Instance1 VarT2
    
    # Examples of predicate expressions
    $ANALYSISEXE xxx Operate test 1 Read predClass.inp pred.inp 0
    $ANALYSISEXE xxx Experiment test 2 Print Attribute ParGreaterThanZero
	$ANALYSISEXE xxx Experiment test 2 Print Attribute Var3GreaterThanZero
    $ANALYSISEXE xxx Experiment test 2 Write Attribute Var3GreaterThanZero
    
    # Examples of description expression
    $ANALYSISEXE xxx Operate test 2 Read descrClass.inp descr.inp 0
    $ANALYSISEXE xxx Experiment test 3 Print Attribute PredicateDescription
    $ANALYSISEXE xxx Experiment test 3 Write Attribute PredicateDescription

    # Examples a bit more complicated expressions
    $ANALYSISEXE xxx Operate test 3 Read expClass.inp exp.inp 0
    $ANALYSISEXE xxx Experiment test 4 Print Attribute 

    $ANALYSISEXE xxx Operate test 4 RunAlgorithm Operation 0
    $ANALYSISEXE xxx Experiment test 5 Print Instance Instance1 ModelValue
    $ANALYSISEXE xxx Experiment test 5 Print Instance Instance2 ModelValue
    $ANALYSISEXE xxx Experiment test 5 Print Instance Instance3 ModelValue

    $ANALYSISEXE xxx Operate test 5 Read expParamsClass.inp expParams.inp 0
    $ANALYSISEXE xxx Operate test 6 RunAlgorithm Operation 0
    $ANALYSISEXE xxx Experiment test 7 Print Attribute ModelValue

    $ANALYSISEXE xxx Operate test 7 Read expLogDescrClass.inp expLogDescr.inp 0
    $ANALYSISEXE xxx Operate test 8 RunAlgorithm Operation 0
    $ANALYSISEXE xxx Experiment test 9 Print Attribute Comparison

endif

    $ANALYSISEXE xxx Operate test 9 Read expDescrClass.inp expDescr.inp 0
    $ANALYSISEXE xxx Operate test 10 RunAlgorithm Operation 0
    $ANALYSISEXE xxx Experiment test 11 Print Attribute LogicDescription
