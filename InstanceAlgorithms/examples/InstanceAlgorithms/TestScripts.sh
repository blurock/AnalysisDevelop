#! /bin/tcsh -f

set PROGRAM     = otest 
set TOOLS = $ANALYSIS_BASE/tools/programs
set CREATEMATRIX = $TOOLS/Matrix/MatrixCalculate.sh
set REPORTGENERATION = $TOOLS/Report/ReportGeneration.sh

$PROGRAM xxx Initial test 0 Read ./input/RunClass.inp ./input/Run.inp 0
$PROGRAM xxx Change  test 1 SetAlgorithmClass InstanceAlgorithmRun
$PROGRAM xxx Operate test 1 Read ./input/InitialClass.inp ./data/ToolingSetup.inp 0
$PROGRAM xxx Change  test 2 RunAlgorithm ReadInstancesAlg 0

$CREATEMATRIX --program $PROGRAM ./input/MatrixSetup test 2 0
$REPORTGENERATION --program $PROGRAM test 3 Matrix Thick ASpeed LSpeed USpeed


pushd plots
mv ../input/document.tex .
hyperlatex document
latex document
dvips -o document.ps document
popd

