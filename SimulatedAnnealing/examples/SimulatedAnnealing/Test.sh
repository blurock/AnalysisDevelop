#! /usr/bin/tcsh -f
otest xxx Initial test -1 Read SimAnnAlgClass.inp SimAnnAlgInst.inp 0
otest xxx Change  test  0  SetAlgorithmClass TestGoalRun
otest xxx Operate test  0 Read SimAnn_dataclass.inp SimAnn_data.inp 0
otest xxx Operate test  1 RunAlgorithm SAOptAlg 0
