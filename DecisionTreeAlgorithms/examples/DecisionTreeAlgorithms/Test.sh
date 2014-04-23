#!/bin/csh
# ---------------------------------------------------------------------------
#
# Script to execute a series of tests
#
# ---------------------------------------------------------------------------
#set verbose
otest xxx Initial test -2 Read algClass.inp alg.inp 0
otest xxx Operate test -1 SetAlgorithmClass TestGoalRun
otest xxx Operate test 0 Read InitialInstancesClass.inp InitialInstances.inp 0
otest xxx Operate test 1 Read InstanceClass.inp Instances.inp 0


#otest xxx Operate test 1 Read instClass.inp inst.inp 0

otest xxx Operate test 2 RunAlgorithm ReadInstancesAlg 0
otest xxx Operate test 3 RunAlgorithm InstanceSetUpAlg 0
otest xxx Operate test 4 RunAlgorithm AttributeSetUpAlg 0
otest xxx Operate test 5 RunAlgorithm DecisionTreeAlg 1

##otest xxx Operate test 2 RunGoal MatrixSetUp
##otest Operate test 2 RunGoal PartitionsFromCriticalPoints
##otest Operate test 2 RunGoal CriticalPointRead
