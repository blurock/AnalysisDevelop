#! /usr/bin/tcsh -f
pushd /home/analysis/Analysis/MenuObjects/examples/MenuObjects

otest rundemo.sh Experiment test 1 $1 $2 $3 $4

popd
exit(0)
