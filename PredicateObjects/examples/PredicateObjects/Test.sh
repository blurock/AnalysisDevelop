#! /usr/bin/tcsh -f

otest Initial test 0 Read TestClass.inp Test.inp 0
otest Experiment test 1 Print Instance
otest Experiment test 1 Write Attribute Var1.EqualToZero
otest Experiment test 1 Write Attribute PartitionTable.Var3.Var1
otest Experiment test 1 Write Attribute ConjPartition
otest Experiment test 1 Print Attribute
otest Initial test 0 Read DescrClass.inp Descr.inp 0
otest Experiment test 1 Write Attribute
