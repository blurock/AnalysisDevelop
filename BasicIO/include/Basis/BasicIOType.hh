/*  FILE     BasicIOType.hh
**  PACKAGE  BasicIO
**  AUTHOR   Mario Drobics
**
**  CONTENT
**    Class definitions for the "BasicIO" package.
**
**  OVERVIEW
**
**  IMPLEMENTATION
**
**  REFERENCES
**
**  COPYRIGHT (C) 1996 Basis Project, RISC Linz
*/
 
#ifndef Basis_BASICIOTYPE_HH
#define Basis_BASICIOTYPE_HH



/*I  . . . INCLUDES  . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
*/
#include <vector>
#include <list>
#include <string>
#include <math.h>
#include <strstream>
#include <fstream.h>
#include <iostream>

#include <stdexcept>

using namespace std;

class BaseDataObject;

//*C==============================================================
/*!
 * \class  app_ioerror
 * \brief  Exception class for all I/O exceptions
 * \date   19.07.2001
 * \author mario.drobics@scch.at
*/
// ===============================================================

class app_ioerror : public domain_error
{
 public:
  app_ioerror(const string &nMsg)
    : domain_error(nMsg) {};
};
// ===============================================================
// declarations
// ===============================================================

string  readWord(istream &ifs, char &sep);
class   TBaseIO;
class   BaseDataObject;
typedef vector<string> TStringVec;   //!< string vector
typedef list<string> TStringList;    //!< string list

// ===============================================================
   class TBaseIO
// ===============================================================
{
 public:
  TBaseIO()  { open(); };
  virtual ~TBaseIO() { close(); };

  virtual void open() {};  //!< standard open method
  virtual void close() {}; //!< standard close method

  virtual void getNextHeader(string &header, string &type) = 0;
  virtual bool isEndElement(const string &curHeader, const string &type="") = 0;
  virtual void getBeginElement(const string &header) = 0;
  virtual void putBeginElement(const string &header) = 0;
  virtual void getBeginElement(const string &header, const string &type) = 0;
  virtual void putBeginElement(const string &header, const string &type) = 0;
  virtual void getEndElement(const string &header) = 0;
  virtual void putEndElement(const string &header) = 0;

  virtual void getBeginObject(const string &type) { getBeginElement("Obj",type); };
  virtual void putBeginObject(const string &type) { putBeginElement("Obj",type); };
  virtual void getEndObject() { getEndElement("Obj"); };
  virtual void putEndObject() { putEndElement("Obj"); };
  virtual void getBeginDerived() { getBeginElement("Derived"); };
  virtual void putBeginDerived() { putBeginElement("Derived"); };
  virtual void getEndDerived() { getEndElement("Derived"); };
  virtual void putEndDerived() { putEndElement("Derived"); };
  virtual void getBeginMembers() { getBeginElement("Members"); };
  virtual void putBeginMembers() { putBeginElement("Members"); };
  virtual void getEndMembers() { getEndElement("Members"); };
  virtual void putEndMembers() { putEndElement("Members"); };

  virtual void getElement(double &elem) = 0;
  virtual void putElement(const double &elem) = 0;
  virtual void getElement(long   &elem) = 0;
  virtual void putElement(const long   &elem) = 0;
  virtual void getElement(string &elem) = 0;
  virtual void putElement(const string &elem) = 0;

  // standard handlers mapped to other i/o routines
  // use template to access
  virtual void getElement(BaseDataObject &elem);
  virtual void putElement(const BaseDataObject &elem);
  virtual void getElement(BaseDataObject *&elem);
  virtual void putElement(const BaseDataObject *elem);
  virtual void getElement(char &elem) { getElement(static_cast<long>(elem)); };
  virtual void getElement(short int &elem) { getElement(static_cast<long>(elem)); };
  virtual void getElement(int &elem) { getElement(static_cast<long>(elem)); };
  virtual void getElement(unsigned int &elem) { getElement(static_cast<long>(elem)); };
  virtual void putElement(const int &elem) { putElement(static_cast<long>(elem)); };
  virtual void getElement(float &elem) { getElement(static_cast<double>(elem)); };
  virtual void putElement(const float &elem) { putElement(static_cast<double>(elem)); };

  template<class T>
    void getElement(vector<T> &vec)
    {
      T newElem;
      string header="Vector";
      string nextHeader, nextType;

      getBeginElement(header);
      getNextHeader(nextHeader, nextType);
      while(!isEndElement(nextHeader))
	{
	  getElement(newElem);
	  vec.push_back(newElem);
	  getNextHeader(nextHeader, nextType);
	}
      getEndElement(header);
    };
  template<class T>
    void getElement(list<T> &vec)
    {
      T newElem;
      string header="List";
      string nextHeader, nextType;

      getBeginElement(header);
      getNextHeader(nextHeader, nextType);
      while(!isEndElement(nextHeader))
	{
	  getElement(newElem);
	  vec.push_back(newElem);
	  getNextHeader(nextHeader, nextType);
	}
      getEndElement(header);
    };

  template<class T>
    void putElement(const vector<T> &vec)
    {
      vector<T>::const_iterator iter;
      string header="Vector";

      putBeginElement(header);
      for(iter=vec.begin(); iter!=vec.end(); iter++)
	putElement(*iter);
      putEndElement(header);
    };
  template<class T>
    void putElement(const list<T> &vec)
    {
      list<T>::const_iterator iter;
      string header="List";

      putBeginElement(header);
      putFunction(header, vec.size());
      for(iter=vec.begin(); iter!=vec.end(); iter++)
	putElement(*iter);
      putEndElement(header);
    };
};

// ===============================================================
   class TBaseIOStream : public TBaseIO
// ===============================================================
{
 protected:
  std::iostream *iostr;
  TStringList   buffer;

  string getNextWord(int buffered=-1);

 public:
  TBaseIOStream(std::iostream &newIO) : TBaseIO()
    {iostr=&newIO;};
  TBaseIOStream(std::istream &newIO) : TBaseIO()
    {iostr=(std::iostream*)&newIO;};
  TBaseIOStream(std::ostream &newIO) : TBaseIO()
    {iostr=(std::iostream*)&newIO;};
  ~TBaseIOStream() {};
};

// ===============================================================
   class TBaseIOSimple : public TBaseIOStream
// ===============================================================
{
 public:
  TBaseIOSimple(std::iostream &newIO) : TBaseIOStream(newIO) {};
  TBaseIOSimple(std::istream &newIO)  : TBaseIOStream(newIO) {};
  TBaseIOSimple(std::ostream &newIO)  : TBaseIOStream(newIO) {};
  ~TBaseIOSimple() {};

  virtual void getBeginDerived() {};
  virtual void putBeginDerived() {};
  virtual void getEndDerived() {};
  virtual void putEndDerived() {};
  virtual void getBeginMembers() {};
  virtual void putBeginMembers() {};
  virtual void getEndMembers() {};
  virtual void putEndMembers() {};

  virtual void getNextHeader(string &header, string &type);
  virtual bool isEndElement(const string &curHeader, const string &type="");
  virtual void getBeginElement(const string &header);
  virtual void putBeginElement(const string &header);
  virtual void getBeginElement(const string &header, const string &type);
  virtual void putBeginElement(const string &header, const string &type);
  virtual void getEndElement(const string &header);
  virtual void putEndElement(const string &header);

  virtual void getElement(double &elem);
  virtual void putElement(const double &elem);
  virtual void getElement(long   &elem);
  virtual void putElement(const long   &elem);
  virtual void getElement(string &elem);
  virtual void putElement(const string &elem);

  template<class T> void getElement(T &elem) {TBaseIO::getElement(elem);};
  template<class T> void putElement(const T &elem) {TBaseIO::putElement(elem);};
};

// ===============================================================
   class TBaseIOXML : public TBaseIOStream
// ===============================================================
{
 public:
  TBaseIOXML(std::iostream &newIO) : TBaseIOStream(newIO) {};
  TBaseIOXML(std::istream &newIO)  : TBaseIOStream(newIO) {};
  TBaseIOXML(std::ostream &newIO)  : TBaseIOStream(newIO) {};
  ~TBaseIOXML() {};

  void getNextToken(TStringVec &items, int bufferPos=-1);

  virtual void getNextHeader(string &header, string &type);
  virtual bool isEndElement(const string &curHeader, const string &type="");
  virtual void getBeginElement(const string &header);
  virtual void putBeginElement(const string &header);
  virtual void getBeginElement(const string &header, const string &type);
  virtual void putBeginElement(const string &header, const string &type);
  virtual void getEndElement(const string &header);
  virtual void putEndElement(const string &header);

  virtual void getElement(double &elem);
  virtual void putElement(const double &elem);
  virtual void getElement(long   &elem);
  virtual void putElement(const long   &elem);
  virtual void getElement(string &elem);
  virtual void putElement(const string &elem);

  template<class T> void getElement(T &elem) {TBaseIOStream::getElement(elem);};
  template<class T> void putElement(const T &elem) {TBaseIOStream::putElement(elem);};
};

#endif
