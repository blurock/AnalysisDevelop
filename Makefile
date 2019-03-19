SHELL         =/bin/bash
MergePackage   = $(ANALYSIS_BINARIES)/MergePackage

BASIS=\
      CommBuffer String Objects ONames BasisSystem MixedClasses System\
      Vector MatrixNumeric MatrixUtilities MatrixOut\
      EigenValues EigenValuesOut BasicLaTeXTable PCAAnalysis PrimitiveStats\
      Pairs Graph StartPairs FindCorrespondences SubGraph\
      Dbase LineGraph SimulatedAnnealing


COREOBJECTS=\
            CoreDataObjects NonStandard NumericObjects LogicalObjects FunctionReal1DObjects\
            DataObjects OperationObjects InstanceObjects MenuObjects\
            PredicateObjects\
            DirectedTreeObjects SelectObjects\
            DescriptionProbs LogicalOperations\
            GoalObjects\
            PredicateGen\
            AlgorithmObjects InstanceAlgorithms\
            EvaluationTree ClusterTree EntropyObjects NumericProperties\
            CobwebCluster DecisionTreeAlgorithms GeneralGraph\
            DistributionAlgorithm\
            InstancePCA ExpressionTree Consecutive\
            NumericOperations GeneticOperations\
            Optimize PopulationBasedOptimization\
            ParameterizedFunction VectorOperations Iterator\
            RuleSystem GraphOperations\
            EquivalentClasses VerifyEnvironment FullSystem

space:=$(empty) $(empty)
sBASIS:=$(space)$(BASIS)
sCOREOBJECTS:=$(space)$(COREOBJECTS)

compileprefix:=c
mergeprefix:=m

cBASIS=$(subst $(space),$(space)$(compileprefix),$(sBASIS))
mBASIS=$(subst $(space),$(space)$(mergeprefix),$(sBASIS))
cCOREOBJECTS=$(subst $(space),$(space)$(compileprefix),$(sCOREOBJECTS))
mCOREOBJECTS=$(subst $(space),$(space)$(mergeprefix),$(sCOREOBJECTS))

mergeall: mergeBasis mergeCoreObjects

all: mergeall compileBasis compileCoreObjects

compileBasis: $(cBASIS)

mergeBasis: $(mBASIS)

compileCoreObjects: $(cCOREOBJECTS)

mergeCoreObjects: $(mCOREOBJECTS)

$(cBASIS):
	pushd $(subst $(space)$(compileprefix),$(empty),$(space)$@);\
	cd lib;\
	make cleaner;\
	make all;\
	mv lib*.a $(CodeBaseRoot)/lib;\
	make cleaner;\
	popd;

$(mBASIS):
	$(MergePackage) $(subst $(space)$(mergeprefix),$(empty),$(space)$@) Basis

$(cCOREOBJECTS):
	pushd $(subst $(space)$(compileprefix),$(empty),$(space)$@);\
	cd lib;\
	make cleaner;\
	make all;\
	mv lib*.a $(CodeBaseRoot)/lib;\
	make cleaner;\
	popd;

$(mCOREOBJECTS):
	$(MergePackage) $(subst $(space)$(mergeprefix),$(empty),$(space)$@) CoreObjects

.PHONY: $(cBASIS) $(mBASIS) compileBasis mergeBasis

