#!/bin/csh
# ---------------------------------------------------------------------------
#
# Script to execute a series of tests
#
# ---------------------------------------------------------------------------
#set verbose

otest Initial test 0 Read algClass.inp algInst.inp 5
otest Operate test 1 Read SpecInstanceClass.inp SpecInstance.inp 5
otest Operate test 2 SetGoalClass TestGoalRun
otest Operate test 3 RunGoal MatrixSetUp
