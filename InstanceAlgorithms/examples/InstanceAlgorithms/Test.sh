#! /bin/tcsh -f
set PROGRAM     = otest 

if(!(-d plots)) then
    mkdir plots
endif


$PROGRAM xxx Initial test 0 Read ./input/RunClass.inp ./input/Run.inp 0
$PROGRAM xxx Operate test 1 SetAlgorithmClass InstanceAlgorithmRun
$PROGRAM xxx Operate test 2 Read ./input/InitialClass.inp ./data/ToolingSetup.inp 0
$PROGRAM xxx Change test 3 RunAlgorithm ReadInstancesAlg 0
$PROGRAM xxx Operate test 3 RunAlgorithm InstanceSetUpAlg 0
$PROGRAM xxx Operate test 4 RunAlgorithm AttributeByTypeAlg 0
$PROGRAM xxx Operate test 5 RunAlgorithm MatrixSetUpAlg 0
$PROGRAM xxx Operate test 6 Read input/ReportSetupClass.inp data/ToolingReport.inp 0
$PROGRAM xxx Change test 7 RunAlgorithm MatrixPlotAlg 3

pushd plots
mv ../input/document.tex .
hyperlatex document
latex document
dvips -o document.ps document
popd
