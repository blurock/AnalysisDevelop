# FILE     Makefile
# PACKAGE  ExpressionTree
# AUTHOR   Edward S. Blurock
#
# CONTENT
#   Makefile for example programs of the "ExpressionTree" package.
#
# COPYRIGHT (C)  1997 CoreObjects Library

#V PackageRoot . . . . . . . . . . . . . . The root directory of this package.
PackageRoot:=$(shell cd ../../..; pwd)


#I
include ../../../etc/CoreObjects/MakeDef


#V
ALL=otest
OBJECTS=main.o
LIBS=\
	-L$(PackageRoot)/lib\
	-L$(CodeBaseRoot)/lib\
	-lVASLModels\
	-lVerifyEnvironment\
	-lDecisionTreeAlgorithms\
	-lEntropyObjects\
	-lEvaluationTree\
        -lPopulationBasedOptimization\
	-lGeneticOperations\
        -lOptimize\
	-lRuleSystem\
	-lNumericOperations\
	-lParameterizedFunction\
	-lPredicateGen\
	-lPredicateObjects\
	-lDistributionAlgorithm\
	-lPrimitiveStats\
	-lAlgorithmObjects\
        -lExpressionTree\
	-lClusterTree\
	-lMenuObjects\
	-lInstanceAlgorithms\
	-lInstanceObjects\
	-lDataObjects\
	-lSelectObjects\
	-lDirectedTreeObjects\
	-lOperationObjects\
	-lFunctionReal1DObjects\
	-lLogicalObjects\
	-lLogicalOperations\
	-lNumericObjects\
	-lCoreDataObjects\
        -lGraph\
	-lPairs\
        -lSystem\
	-lMatrixNumeric\
	-lVector\
        -lONames\
        -lMixedClasses\
        -lString\
        -lObjects\
        -lCommBuffer\
        -lm




#F Targets.

all: $(ALL)

otest: $(OBJECTS)
	CompileC++ -o otest $(OBJECTS) $(LIBS)


cleaner::
	$(RM) $(ALL)
