#!/bin/csh
#
# FILE     runit.sh
# PACKAGE  Maintenance
# AUTHORS  Edward S. Blurock
#
# CONTENT
#   run of decision tree for tooling data
#
#c COPYRIGHT (C) 1997 RISC Linz
cat <<EOF > program.prg
Read algClass.inp alg.inp 0
SetAlgorithmClass TestAlgorithmRun
Read instancesClass.inp instances.inp 0
Read setClass.inp set.inp 0
Print Attribute Set
Read runSetClass.inp runSet.inp 0
Print Attribute VarsAndExps
RunAlgorithm Operation 0
%%%Read instClass.inp inst.inp 0
Print Instance Instance1 NewVariable
Print Instance Instance2 NewVariable
Print Instance Instance3 NewVariable
Print Instance Instance4 NewVariable
END
EOF

otest xxx Initial test 0 < program.prg
