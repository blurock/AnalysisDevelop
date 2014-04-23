#! /usr/bin/tcsh -f
cat <<EOF
The Inputs are:
xxx Experiment test 1 AlgorithmTree 
AddObject failed
Will Read Restart File
No Output Restart File will be written
ReadInVersion: './test.1.save'
The Input Buffer Size is: 27780

Decode Start
Read in Instances

Decode Finished
The  Command (0 arguments) is: AlgorithmTree:  Print Algorithm Tree
SERVERSENDDATA

DIRECTEDGRAPH
command=xxx AlgorithmTree 
activeCommunication=TRUE
Initial
Initial
Initial#InstanceAlgs
Initial#InstanceAlgs#Algorithms
Initial#InstanceAlgs#Algorithms#Read
Initial#InstanceAlgs#Algorithms#Instances
Initial#InstanceAlgs#Algorithms#Attributes
Initial#InstanceAlgs#Algorithms#Matrix
END
Initial Initial#InstanceAlgs
Initial#InstanceAlgs Initial#InstanceAlgs#Algorithms
Initial#InstanceAlgs#Algorithms Initial#InstanceAlgs#Algorithms#Read
Initial#InstanceAlgs#Algorithms Initial#InstanceAlgs#Algorithms#Instances
Initial#InstanceAlgs#Algorithms Initial#InstanceAlgs#Algorithms#Attributes
Initial#InstanceAlgs#Algorithms Initial#InstanceAlgs#Algorithms#Matrix
END
ENDDIRECTEDGRAPH
END
ENDSERVERSENDDATA

 Exit Run

EOF
