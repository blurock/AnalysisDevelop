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
Read numericClass.inp numeric.inp 0
Print Attribute Exp
Read runNumericClass.inp runNumeric.inp 0
RunAlgorithm Operation 0
Read logicClass.inp logic.inp 0
%%%Read instClass.inp inst.inp 0
Print Instance Instance1 NewVariable
Print Instance Instance2 NewVariable
Print Instance Instance3 NewVariable
Print Instance Instance4 NewVariable
Print Instance Instance5 NewVariable
END
EOF

otest xxx Initial test 0 < program.prg
