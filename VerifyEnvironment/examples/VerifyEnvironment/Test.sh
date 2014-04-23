#! /usr/bin/tcsh -f

set ANALYSISEXE   = otest

if(!(-d saves)) then
mkdir saves
endif

    # Setup of the main 'Operation' to apply expressions
    $ANALYSISEXE xxx Initial test -1 Read algClass.inp alg.inp 0
    $ANALYSISEXE xxx Change test 0 SetAlgorithmClass TestAlgorithmRun

    # Setup the simple instance set
    $ANALYSISEXE xxx Operate test 0 Read instClass.inp inst.inp 0
    # Setup the expressions and description expressions
    $ANALYSISEXE xxx Change test 1 Read expClass.inp exp.inp 0
    $ANALYSISEXE xxx Change test 1 Read descrClass.inp descr.inp 0

    $ANALYSISEXE xxx Operate test 1 RunAlgorithm CreateExpressions 0
    $ANALYSISEXE xxx Experiment  test 2 Print Instance Instance1 LogicDescription
    $ANALYSISEXE xxx Experiment  test 2 Print Instance Instance2 LogicDescription
    $ANALYSISEXE xxx Experiment  test 2 Print Instance Instance3 LogicDescription
    $ANALYSISEXE xxx Experiment  test 2 Print Instance Instance4 LogicDescription
    $ANALYSISEXE xxx Experiment  test 2 Print Instance Instance5 LogicDescription
    $ANALYSISEXE xxx Change test 2 RunAlgorithm Verify 0
    $ANALYSISEXE xxx Experiment  test 2 Print Instance Instance1 VerificationError
    $ANALYSISEXE xxx Experiment  test 2 Print Instance Instance2 VerificationError
    $ANALYSISEXE xxx Experiment  test 2 Print Instance Instance3 VerificationError
    $ANALYSISEXE xxx Experiment  test 2 Print Instance Instance4 VerificationError
    $ANALYSISEXE xxx Experiment  test 2 Print Instance Instance5 VerificationError
    $ANALYSISEXE xxx Experiment  test 2 Print Attribute ErrorInstanceNames
