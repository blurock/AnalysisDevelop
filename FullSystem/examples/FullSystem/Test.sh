#!/bin/csh
# ---------------------------------------------------------------------------
#
# Script to execute a series of tests
#
# ---------------------------------------------------------------------------
#c COPYRIGHT (C) 1998 Edward S. Blurock 
#set verbose
set PROGRAM         = ./otest
set DEBUGLEVEL      = 0

set BASE = $ANALYSIS_BASE/tools/programs

echo start $PROGRAM

cat <<EOF > program.prg
Read $BASE/Full/algClass.inp $BASE/Full/algInstance.inp 0
SetGoalClass TestGoalRun
SetAlgorithmClass TestGoalRun
Read InstanceClass.inp Instances.inp 0
RunAlgorithm PCAVarGenAlg 0
END
EOF
$PROGRAM xxx Initial test 0  < program.prg



##$PROGRAM Operate test 3 RunAlgorithm DistributionAlg 1
#$PROGRAM Operate test 4 RunGoal AttributeSetUp 1
#$PROGRAM Operate test 5 RunAlgorithm DecisionTreeAlg
#$PROGRAM Operate test 6 Read ExpressionTestClass.inp ExpressionTest.inp 0
#$PROGRAM Operate test 7 RunAlgorithm ExpressionTreeAlg 1

##$PROGRAM Operate test 5 RunAlgorithm CriticalPointsReadAlg
##$PROGRAM Operate test 5 RunAlgorithm PartitionsFromCriticalPoints



