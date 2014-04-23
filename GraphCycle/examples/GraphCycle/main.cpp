/*  FILE     
**  PACKAGE     REACTION    
**  AUTHOR   Edward S. Blurock
**
**  CONTENT
**    
**
**  REFERENCES
**
**  COPYRIGHT (C) 1995  REACTION Project / Edward S. Blurock 
*/
#define TEMPLATE_INSTANTIATION
#include "Basis/System.hh"
#include "Basis/Pairs.hh"
#include "Basis/Graph.hh"
#include "Basis/GraphCycle.hh"

//template class list< BasicPair<Identify,Identify> >;


ostream& operator<<(ostream& out, const PntrMixed<Identify,Identify>& mix)
	  {
	  return mix.Pntr->print(out);
	  }





void PathInIdentifyGraph();
void PathInIntegerGraph();

main(int argc, char *argv[])
     {
     PathInIntegerGraph();
	 return 0;
     }     

void PathInIntegerGraph()
     {
     PathSearchConditions conditions(true,true,-1,true,true);
     Graph<int,int> graph;
     
     graph.AddNodeToGraph(1,100);
     graph.AddNodeToGraph(2,200);
     graph.AddNodeToGraph(3,300);
     graph.AddNodeToGraph(4,400);
     graph.AddNodeToGraph(5,500);
     graph.AddNodeToGraph(6,600);
/*
     graph.AddNodeToGraph(7,700);
     graph.AddNodeToGraph(8,800);
     graph.AddNodeToGraph(9,900);
     graph.AddNodeToGraph(10,1100);
     graph.AddNodeToGraph(11,1200);
     graph.AddNodeToGraph(12,1300);
*/
     graph.AddBondToGraph(1,2);
     graph.AddBondToGraph(1,3);
     graph.AddBondToGraph(2,4);
     graph.AddBondToGraph(3,4);
     graph.AddBondToGraph(3,5);
     graph.AddBondToGraph(4,6);
     graph.AddBondToGraph(5,6);
     cout << "-----------------------------------------\n";
     cout << graph;
     cout << "-----------------------------------------\n";
     
     FindPathsInGraph<int,int> paths(graph,conditions);
     cout << "-----------------------------------------\n";
     cout << paths.Done;
     cout << "\n-----------------------------------------\n";
     cout << paths.Cycle;
     cout << "\n-----------------------------------------\n";
     paths.Cycle.Sort();
     cout << paths.Cycle;
     cout << "\n-----------------------------------------\n";
     }     

void PathInIdentifyGraph()
     {
     PathSearchConditions conditions(false,false,-1,true,true);
     Graph<Identify,Identify> graph;     
     Identify id1(1,"One");
     Identify id2(2,"Two");
     Identify id3(3,"Three");
     Identify id4(4,"Four");
     Identify id5(5,"Five");
     Identify id6(6,"Six");
     Identify id7(7,"Seven");
     Identify id8(8,"Eight");
     Identify id9(9,"Nine");
     Identify id10(10,"Ten");
     
     graph.AddNodeToGraph(id1,id2);
     graph.AddNodeToGraph(id3,id4);
     graph.AddNodeToGraph(id5,id6);
     graph.AddNodeToGraph(id7,id8);
     graph.AddNodeToGraph(id9,id10);
     
     graph.AddBondToGraph(id1,id3);
     graph.AddBondToGraph(id3,id5);
     graph.AddBondToGraph(id3,id7);
     graph.AddBondToGraph(id7,id9);
     graph.AddBondToGraph(id9,id1);
     cout << "-----------------------------------------\n";
     cout << graph;
     cout << "-----------------------------------------\n";
     
     FindPathsInGraph<Identify,Identify> paths(id1,graph,conditions);
     
     cout << "-----------------------------------------\n";
     cout << paths.Done;
     cout << "\n-----------------------------------------\n";
     cout << paths.Cycle;
     cout << "\n-----------------------------------------\n";
     }     


