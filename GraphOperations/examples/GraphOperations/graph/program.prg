Read algClass.inp alg.inp 0
SetAlgorithmClass TestAlgorithmRun
Read expClass.inp exp.inp 0
Read predClass.inp pred.inp 0
Read grpexampleClass.inp grpexample.inp 0

Read nodedescrClass.inp nodedescr.inp 0
RunAlgorithm Operation 0
Print Attribute NewGraph
Read graphClass.inp graph.inp 0
RunAlgorithm Operation 0
Print Attribute MatchGraph

Read NeighborsClass.inp Neighbors.inp 0
RunAlgorithm Operation 0
Attribute NextNodes
END
