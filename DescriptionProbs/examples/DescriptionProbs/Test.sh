#! /usr/bin/tcsh -f

otest xxx Initial test 0 Read algClass.inp algInst.inp 0
otest xxx Operate test 1 Read TestClass.inp Test.inp 0
otest xxx Operate test 2 SetAlgorithmClass AlgorithmTestRun
otest xxx Operate test 3 RunAlgorithm SetUp 0
otest xxx Operate test 4 Read CobwebClass.inp Cobweb.inp 0
otest xxx Experiment test 5 Print Attribute SingleMembership
otest xxx Experiment test 5 Print Attribute GroupProbs
otest xxx Operate test 5 RunAlgorithm Cobweb 0
