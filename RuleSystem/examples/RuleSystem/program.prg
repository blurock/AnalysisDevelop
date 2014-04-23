Read algClass.inp algInst.inp 0
SetAlgorithmClass AlgorithmTestRun
Read DefinitionsClass.inp Definitions.inp 0
%%% Read Test2Class.inp Test2.inp 0
%%% Print Attribute Logical
Read InstancesClass.inp Instances.inp 0
%%% Read ruleClass.inp rule.inp 0
%%% Print Attribute Rule
%%% RunAlgorithm RuleAction 0
%%% Print Instance Instance1 Action1
%%% Print Instance Instance2 Action1
%%% Print Instance Instance3 Action1
Read Rule1DefinitionClass.inp Rule1Definition.inp 0
Print Class NormalProductionSystem
Read Rules1Class.inp Rule1.inp 0
Print Attribute ProductionSystem
RunAlgorithm RuleSystemSearch 5
%%% Print Instance Instance1 ProductionSystem
END
