#! /usr/bin/tcsh -f

otest xxx Initial test 0 Read InstancesClass.inp Instances.inp 2
otest xxxx Change test 1 SetAlgorithmClass TestGoalRun

#otest xxx Experiment test 1 Print Class TestGoalRun
otest xxx Operate test 1 RunAlgorithm Optimize 0
#otest xxx Experiment test 2 Print Attribute OptimizedObject
#otest xxx Experiment test 2 Print Class

