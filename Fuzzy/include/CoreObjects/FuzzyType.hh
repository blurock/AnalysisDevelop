/*  FILE     FuzzyType.hh
**  PACKAGE  Fuzzy
**  AUTHOR   Harald Wahl
**
**  CONTENT
**    Class definitions for the "Fuzzy" package.
**
**  OVERVIEW
**
**  IMPLEMENTATION
**
**  REFERENCES
**
**  COPYRIGHT (C) 1996 CoreObjects Project, RISC Linz
*/
 
#ifndef CoreObjects_FUZZYTYPE_HH
#define CoreObjects_FUZZYTYPE_HH

/*I  . . . INCLUDES  . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/



/*C BaseDataFuzzy  . . . . . . . . . . . . . . . . . . . . . . . .  data
**
**  DESCRIPTION
**    This is the Fuzzy class
**
**  REMARKS
*/
class BaseDataFuzzy : public BaseDataLogical
{
public:
  BaseDataFuzzy();
  BaseDataFuzzy(const BaseDataFuzzy& data);
  
  
  virtual void AND(const BaseDataFuzzy& val);
  virtual void OR(const BaseDataFuzzy& val);
  virtual void NOT();
  

  STANDARD_VIRTUAL_METHODS_OBJECT
  virtual bool WriteAsLine(ostream&, DataObjectClass *);
  virtual bool WriteAsASCII(ostream&, DataObjectClass *);
  virtual bool WriteAsLatex(ostream&, DataObjectClass  *);
};
/*C DataFuzzyClass . . . . . . . . . . . . . . .  the info about a data type
**
**  DESCRIPTION
**
**  REMARKS
**
*/
class DataFuzzyClass : public DataLogicalClass
{

public:
  DataFuzzyClass();
  DataFuzzyClass(const DataFuzzyClass& data);
  DataFuzzyClass(const int id, 
                    const String& name,
                    const String& descr);
  STANDARD_VIRTUAL_METHODS_CLASS
};
 
#endif
