/*  FILE     GraphCycle.cc
**  PACKAGE  GraphCycle
**  AUTHOR   Edward S. Blurock
**
**  CONTENT
**    Exported functions for the "GraphCycle" package.
**
**  REFERENCES
**
**  COPYRIGHT (C) REACTION Project, Edward S. Blurock
*/

 
/*I  . . . INCLUDES  . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/
#define TEMPLATE_INSTANTIATION
#include "Basis/System.hh"
#include "Basis/Pairs.hh"
#include "Basis/Graph.hh"
#include "Basis/GraphCycle.hh"

 
 
/*P  . . . PROTOTYPES  . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/
template class FindPathsInGraph<int, int>;
//template class PathsSearchNode<int>;
template class DetermineNextNode<int, int>;
//template class ostream_iterator<PathsSearchNode<int> >;

template DetermineNextNode<int, int> for_each(list<int>::iterator, 
					      list<int>::iterator,
					      DetermineNextNode<int, int>);

// whchange !!  could not deduce...
//template ostream  operator<<(ostream &, ObjectList<PathsSearchNode<int> > const &);
template ostream operator<<(ostream &, PathsSearchNode<int> const &);

template bool operator==(PathsSearchNode<int> const &, PathsSearchNode<int> const &);
template bool operator!=(PathsSearchNode<int> const &, PathsSearchNode<int> const &);
template bool operator<(PathsSearchNode<int> const &, PathsSearchNode<int> const &);
template bool Decode(CommBuffer &, PathsSearchNode<int> &);
template bool Encode(CommBuffer &, PathsSearchNode<int> &);

/*P  . . . PROTOTYPES  . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/
template class FindPathsInGraph<Identify,Identify>;
//template class PathsSearchNode<Identify>;
template class DetermineNextNode<Identify, Identify>;
template bool operator<<(ostream &, PathsSearchNode<Identify> const &);

template bool operator==(PathsSearchNode<Identify> const &, PathsSearchNode<Identify> const &);
template bool lexicographical_compare(Identify const *, Identify const *, Identify const *, Identify
				      const *, less<Identify>);

template bool operator!=(PathsSearchNode<Identify> const &, PathsSearchNode<Identify> const &);
template bool operator<(PathsSearchNode<Identify> const &, PathsSearchNode<Identify> const &);
template bool Decode(CommBuffer &, PathsSearchNode<Identify> &);
template bool Encode(CommBuffer &, PathsSearchNode<Identify> &);
