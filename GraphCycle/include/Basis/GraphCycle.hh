/*  FILE     GraphCycle.hh
**  PACKAGE  GraphCycle
**  AUTHOR   Edward S. Blurock
**
**  CONTENT
**    Definitions for the "GraphCycle" package.
**
**  OVERVIEW
**
**  IMPLEMENTATION
**
**  REFERENCES
**
**  COPYRIGHT (C) 1996 Reaction, Edward S. Blurock
*/
 
#ifndef REACTION_GRAPHCYCLE_HH
#define REACTION_GRAPHCYCLE_HH
 
/*C PathSearchConditions  . . . . . . . . . . . . .  set of search conditions
**
**  DESCRIPTION
**     The search and whether certain types of paths should
**     be included in the search are constrolled by a set of conditions:
**     - Both Parents and Sons (IncludeParents)
**     - Include all incomplete paths also (IncludeIncompletePaths)
**     - Limit the number of iterations (MaxNumberOfIterations)
**
**  REMARKS
**
*/
class PathSearchConditions
     {
 public:
     bool IncludeParents;
     bool IncludeIncompletePaths;
     int MaxNumberOfIterations;
     bool Cycles;
     bool Paths;

     inline PathSearchConditions(bool includeparents,
				 bool includeincomplete,
				 int maxnumiter,
				 bool Cycles,
				 bool Paths);
     PathSearchConditions(const PathSearchConditions& conditions)
	  : IncludeParents(conditions.IncludeParents),
	  IncludeIncompletePaths(conditions.IncludeIncompletePaths),
	  MaxNumberOfIterations(conditions.MaxNumberOfIterations),
	  Cycles(conditions.Cycles),
	  Paths(conditions.Paths)
	       {
	       }
     };

/*C PathsSearchNode . . . . . . . . . . . . . . . . . basic search node class
**
**  DESCRIPTION
**    This holds the current information for the path search.  It represents
**    a particular state in the search.
**
**    Equality is determined by comparing the path.  Less than or equal, etc.
**    is determined by the length of the path and a lexicographical compare.
**
**  REMARKS
**
*/
template <class KeyType>
class PathsSearchNode
     {
 public:
     ObjectList<KeyType> NodesLeft;
     ObjectList<KeyType> Path;     
     
     inline PathsSearchNode();
     inline PathsSearchNode(const ObjectList<KeyType>& nodesleft,
			   const KeyType& key);
     inline PathsSearchNode(const PathsSearchNode<KeyType>& searchnode);

     inline ObjectList<KeyType> GetPath();

     bool EncodeThis(CommBuffer& buffer)
	  {
	  bool result = Encode(buffer,NodesLeft);
	  result = result && Encode(buffer,Path);
	  return result;
	  }
     bool DecodeThis(CommBuffer& buffer)
	  {
	  bool result = Decode(buffer,NodesLeft);
	  result = result && Decode(buffer,Path);
	  return result;
	  }
     
     
     };
 
/*C FindPathsInGraph  . . . . . . . . . . . . . . . . . . . . .  Search class
**
**  DESCRIPTION
**     This class holds all the information for a search for the
**     set of paths
**
**  REMARKS
**
*/
template <class KeyType, class T>
class FindPathsInGraph
     {
     PathSearchConditions Conditions;
     Graph<KeyType,T>& GraphToSearch;
     
     inline void Iterate();
     inline void AddNextLevel();
     
 public:
     ObjectList<PathsSearchNode<KeyType> > NotFinished;     
     ObjectList<PathsSearchNode<KeyType> > Done;
     ObjectList<PathsSearchNode<KeyType> > Cycle;
     FindPathsInGraph(const FindPathsInGraph<KeyType,T>& paths)
	  : Conditions(paths.Conditions),
	  GraphToSearch(paths.GraphToSearch)
	  {
	  }
	      
     inline FindPathsInGraph(const ObjectList<PathsSearchNode<KeyType> >& searchnodes,
			     Graph<KeyType,T>& graph,
			     const PathSearchConditions& conditions);
     inline FindPathsInGraph(const KeyType& key,
			     Graph<KeyType,T>& graph,
			     const PathSearchConditions& conditions);
     inline FindPathsInGraph(Graph<KeyType,T>& graph,
			     const PathSearchConditions& conditions);
     };
/*C DetermineNextNode . . . . . . . . . . . . . next node with key from graph
**
**  DESCRIPTION
**    The operator() function either adds a path to the current list of 
**    paths (if key is not in the available node list) as a cycle (the key
**    matches the first in the path) or as an ended path.
**
**  REMARKS
**
*/
template <class KeyType, class T>
class DetermineNextNode
     {
     PathsSearchNode<KeyType>& Current;
     PathSearchConditions& Conditions;
     FindPathsInGraph<KeyType,T>& search;
     
 public:
     inline DetermineNextNode(PathsSearchNode<KeyType>& current, 
			      PathSearchConditions& conditions,
			      FindPathsInGraph<KeyType,T>& srch);
     inline void operator()(const KeyType& key);
     };

 
/*P  . . . PROTOTYPES  . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/
template <class KeyType>
bool Encode(CommBuffer& buffer, PathsSearchNode<KeyType>& node);
template <class KeyType>
bool Decode(CommBuffer& buffer, PathsSearchNode<KeyType>& node);
template <class KeyType>
inline bool 
operator==(const PathsSearchNode<KeyType>& searchnode1,
	   const PathsSearchNode<KeyType>& searchnode2);
template <class KeyType>
inline bool 
operator<(const PathsSearchNode<KeyType>& searchnode1,
	  const PathsSearchNode<KeyType>& searchnode2);
template <class KeyType>
ostream& operator<<(ostream& out, const PathsSearchNode<KeyType>& node);

/*I  . . . INCLUDES  . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/

#include "GraphCycle.icc"
#include "FindPaths.icc"
#ifdef TEMPLATE_INSTANTIATION
#include "GraphCycle.itc"
#endif

#endif


