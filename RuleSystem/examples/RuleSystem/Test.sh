#!/bin/csh
#
# FILE     runit.sh
# PACKAGE  Maintenance
# AUTHORS  Edward S. Blurock
#
# CONTENT
#   Run a rule system
#
#c COPYRIGHT (C) 1997 RISC Linz

cat <<EOF > program.prg
Read algClass.inp algInst.inp 0
SetAlgorithmClass AlgorithmTestRun
Read DefinitionsClass.inp Definitions.inp 0
%%% Read Test2Class.inp Test2.inp 0
%%% Print Attribute Logical
Read InstancesClass.inp Instances.inp 0
Read ruleClass.inp rule.inp 0
RunAlgorithm RuleAction 1
%%% Read Rules1Class.inp Rules1.inp 0
%%% Print Attribute
%%% RunAlgorithm RuleSystemSearch 3
%%% Print Instance Instance1 ProductionSystem
END
EOF

otest xxx Initial test 0 < program.prg

#otest xxx Experiment test 3 Print Attribute ProductionSystem
