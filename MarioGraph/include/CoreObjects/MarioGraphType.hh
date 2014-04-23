/*  FILE     MarioGraphType.hh
**  PACKAGE  MarioGraph
**  AUTHOR   Mario Drobics
**
**  CONTENT
**    Class definitions for the "MarioGraph" package.
**
**  OVERVIEW
**
**  IMPLEMENTATION
**
**  REFERENCES
**
**  COPYRIGHT (C) 1996 CoreObjects Project, RISC Linz
*/
 
#ifndef CoreObjects_MARIOGRAPHTYPE_HH
#define CoreObjects_MARIOGRAPHTYPE_HH

/*C BaseDataGraph  . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    This is the Graph class definitions
**
**  REMARKS
**    Inheirits BaseDataObject
*/
class BaseDataGraph : public BaseDataObject
{
public:
  BaseDataGraph();
  BaseDataGraph(const BaseDataGraph& data);

  STANDARD_VIRTUAL_METHODS_OBJECT
};
/*C DataGraphClass . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
**     Inheirits DataObjectClass
*/
class DataGraphClass : public DataObjectClass
{
public:
  DataGraphClass();
  DataGraphClass(const DataGraphClass& data);
  DataGraphClass(const int id, 
		    const String& name,
		    const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS
};



/*I  . . . INCLUDES  . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/

#endif
