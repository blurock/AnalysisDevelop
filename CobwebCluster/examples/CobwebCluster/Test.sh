#! /usr/bin/tcsh -f

set ANALYSISEXE = otest

if(!(-d saves)) then
    mkdir saves
endif

if( $1 != skip ) then 
# Setup of the main algorithms
$ANALYSISEXE  xxx Initial test -1 Read algClass.inp alg.inp 0
$ANALYSISEXE xxx Change test 0 SetAlgorithmClass TestAlgorithmRun

# Setup the simple instance set
$ANALYSISEXE xxx Operate test 0 Read instClass.inp inst.inp 0

# Setup the attributes and training/test sets
$ANALYSISEXE xxx Change test 1 Read setupClass.inp setup.inp 0
$ANALYSISEXE xxx Change test 1 RunAlgorithm InstanceSetUpAlg 0
$ANALYSISEXE xxx Change test 1 RunAlgorithm AttributeSetUpAlg 0

# Setup the predicates
$ANALYSISEXE xxx Operate test 1 Read predClass.inp pred.inp 0
$ANALYSISEXE xxx Change test 2 Read predgenClass.inp predgen.inp 0
$ANALYSISEXE xxx Change test 2 RunAlgorithm CriticalPointReadAlg 0
$ANALYSISEXE xxx Change test 2 RunAlgorithm PartitionsFromCriticalPointsAlg 0
$ANALYSISEXE xxx Experiment test 2 Print Attribute PartitionList


# perform cluster
$ANALYSISEXE xxx Operate test 2 Read cobwebClass.inp cobweb.inp 0
endif
$ANALYSISEXE xxx Change test 3 RunAlgorithm CobwebClusterAlg 1
$ANALYSISEXE xxx Change test 3 RunAlgorithm CobwebClusterTestAlg 0

