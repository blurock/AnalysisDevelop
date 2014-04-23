// ***************************************************************
/*! \file  main.cpp
 * \brief  test main for i/o classes
 * \date   17.07.2001
 * \author mario.drobics@scch.a
 *
 * (c) SCCH Software Competence Center Hagenberg 2000
*/
// ***************************************************************

// ===============================================================
// includes
// ===============================================================

#include "BasicIO.hh"
#include "stdio.h"



// ===============================================================
   class BaseDataObject 
// ===============================================================
{
 protected:
  string name;
 public:
  virtual ~BaseDataObject() { }
  virtual void get(TBaseIO &ioclass);
  virtual void put(TBaseIO &ioclass) const;
};


//*C==============================================================
/*!
 * \class  BaseDataObject
 * \brief  basic object class
 * \date   17.07.2001
 * \author mario.drobics@scch.at
*/
// ===============================================================

void BaseDataObject::get(TBaseIO &ioclass) 
{
  ioclass.getBeginObject("Object");

  ioclass.getBeginDerived();
  ioclass.getEndDerived();

  ioclass.getBeginMembers();
  ioclass.getElement(name);
  ioclass.getEndMembers();

  ioclass.getEndObject();
};

void BaseDataObject::put(TBaseIO &ioclass) const 
{
  ioclass.putBeginObject("Object");

  ioclass.putBeginDerived();
  ioclass.putEndDerived();

  ioclass.putBeginMembers();
  ioclass.putElement(name);
  ioclass.putEndMembers();

  ioclass.putEndObject();
};



// ---------------------------------------------------------------
   int main(int argc, char *argv[])
// ---------------------------------------------------------------
{
  int result=0;  //!< Returns

  // if one or more arguments, read xml input
  if (argc>1)
    {
      istream *istr;
      ostream *ostr;

      if (argc>1) 
	istr = new ifstream(argv[1]);
      else
	istr = &std::cin;
      if (argc>2)
	ostr = new ofstream(argv[2]);
      else
	ostr = &(std::cout);

      TBaseIOXML    input(*istr);
      TBaseIOSimple output(*ostr);
      double d1,d2,d3,d4;
      BaseDataObject *obj = NULL;

      try
	{
	  input.getElement(obj);
	  input.getElement(d1);
	  input.getElement(d2);
	  input.getElement(d3);
	  input.getElement(d4);
	  output.putElement(d1);
	  output.putElement(d2);
	  output.putElement(d3);
	  output.putElement(d4);
	  output.putElement(obj);
	}
      catch(const app_ioerror &curException)
	{
	  cerr << curException.what() << endl;
	  exit(1);
	}
    }
  // if no arguments, open a mathematica session
  else
    {
    }

  return result;
}

// ===============================================================
// ===============================================================
