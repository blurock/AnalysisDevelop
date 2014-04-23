// ***************************************************************
/*! \file  iobase.cpp
 * \brief  Basic i/o classes
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

#include <iostream>

// ===============================================================
// global functions
// ===============================================================

//! seperators for input files
const char * separator="\f\n ;,\t=<>";


//*M--------------------------------------------------------------
/*!
 *         isws(c, wstr)
 * \brief  checks if c is a whitespace
 * \param  c    character to check
 * \param  wstr whitespaces
 * \return true if c is a whitespace
 * \date   10.07.2001
*/
// ---------------------------------------------------------------

inline int isws (char c, char const * const wstr)
{
  return (strchr(wstr,c) != NULL);
}

//*M--------------------------------------------------------------
/*!
 *         readWord(ifs, sep)
 * \brief  Read in one word seperated by a element of separator
 * \param  ifs input file stream
 * \param  sep first separator after input (or null for eof)
 * \return result read word
 * \date   28.3.2000
 * \author mario.drobics@scch.at
*/
// ---------------------------------------------------------------

string readWord(istream &ifs, char &sep)
{
  string result="";
  char chr;
  bool neof;
  bool blockOpen=false; // ignore ws (e.g. for quoted text)

  // read in left ws
  while ((neof=ifs.get(chr)) && isws(chr, separator))
    if (chr=='<') result += chr;
  
  // read in parameter
  while (neof && (blockOpen || !isws(chr,separator)))
    {      
      if (chr=='\"') 
	blockOpen = (!blockOpen);
      else
	result += chr;
      neof = ifs.get(chr);
    }

  if (result[result.size()-1]=='\n')
    result = result.substr(0, result.size()-1);
  if (chr=='\f') ifs.get(chr);
  if (chr=='>')  result += chr;
  if (chr=='<')  ifs.unget();
  // return seperator
  sep = chr;
 
  return result;
}

//*C==============================================================
/*!
 * \class  TBaseIO
 * \brief  Basic iolass
 * \date   17.07.2001
 * \author mario.drobics@scch.at
*/
// ===============================================================

//*M--------------------------------------------------------------
/*!
 *         getElement(elem)
 * \brief  Wrapper for i/o methods of BaseDataObject
 * \param  elem BaseDataObject to get
*/
// ---------------------------------------------------------------

void TBaseIO::getElement(BaseDataObject &elem)
{
  elem.get((*this));
};

//*M--------------------------------------------------------------
/*!
 *         putElement(elem)
 * \brief  Wrapper for i/o methods of BaseDataObject
 * \param  elem BaseDataObject to put
*/
// ---------------------------------------------------------------

void TBaseIO::putElement(const BaseDataObject &elem)
{
  elem.put((*this));
};

//*M--------------------------------------------------------------
/*!
 *         getElement(elem)
 * \brief  Wrapper for i/o methods of *BaseDataObject
 * \param  elem pointer to BaseDataObject to get
 *
 * Reads in type of element and creates a new object of that type.
 * If an EMPTY element is read in, a NULL pointer is created.
*/
// ---------------------------------------------------------------

void TBaseIO::getElement(BaseDataObject *&elem)
{
  string header;
  string type;
  // DataObjectClass *cls;

  getNextHeader(header, type);
  if (type=="Empty")
    {
      getBeginObject("Empty");
      getEndObject();
      elem=NULL;
    }
  else
    {
      // cls=classset.GetClassObject(type);
      // elem = cls->BaseDataObjectExample();
      elem->get((*this));
    }
};

//*M--------------------------------------------------------------
/*!
 *         putElement(elem)
 * \brief  Wrapper for i/o methods of *BaseDataObject
 * \param  elem pointer to BaseDataObject to put
*/
// ---------------------------------------------------------------

void TBaseIO::putElement(const BaseDataObject *elem)
{
  if (elem != NULL)
    elem->put((*this));
  else
    {
      putBeginObject("Empty");
      putEndObject();
    };
};

//*C==============================================================
/*!
 * \class  TBaseIOStream
 * \brief  Basic iolass for streams
 * \date   17.07.2001
 * \author mario.drobics@scch.at
*/
// ===============================================================

//*M--------------------------------------------------------------
/*!
 *         getNextWord(bufferPos)
 * \brief  Reads one word from the stream
 * \param  bufferPos number of elements to read ahead (-1 = none)
 *
 * If bufferPos<0 the next element on the stream or the first
 * element of the buffer is returned and removed from the 
 * stream/buffer.
 * If bufferPos>0 the bufferPos next element is put to the buffer
 * and returned without removing from the buffer, so that it
 * can be read again.
*/
// ---------------------------------------------------------------

string TBaseIOStream::getNextWord(int bufferPos=-1)
{
  char   chr;
  string curInput;
  TStringList::iterator iterP;
  int iterI;

  if (bufferPos==0)
    bufferPos=1;

  // move needed elements to buffer
  while(static_cast<int>(buffer.size())<abs(bufferPos))      
    buffer.push_back(readWord((*iostr), chr));

  // locate desired element
  for(iterI=1, iterP=buffer.begin(); 
      (iterI<bufferPos) && (iterP!=buffer.end());
      iterI++, iterP++);
  curInput = *iterP;

  // remove read element if non-buffer read
  if (bufferPos<0)
    buffer.pop_front();

  return curInput;
}

//*C==============================================================
/*!
 * \class  TBaseIOSimple
 * \brief  simple full iolass for streams
 * \date   17.07.2001
 * \author mario.drobics@scch.at
*/
// ===============================================================

//*M--------------------------------------------------------------
/*!
 *         getNextHeader(header, type)
 * \brief  Read in next header and type
 * \param  header header to check
 * \param  type   type of the block (optional)
*/
// ---------------------------------------------------------------

void TBaseIOSimple::getNextHeader(string &header, string &type)
{
  header = getNextWord(1);
  type   = "";
}

//*M--------------------------------------------------------------
/*!
 *         isEndElement(header, type)
 * \brief  check if a end element with header and type is on the stack
 * \param  header header to check
 * \param  type   type of the block (optional)
 * \return true if a end element
*/
// ---------------------------------------------------------------

bool TBaseIOSimple::isEndElement(const string &curHeader, const string &type="")
{
  return(curHeader=="END");
}

//*M--------------------------------------------------------------
/*!
 *         getBeginElement(header)
 * \brief  Read a block begin
 * \param  header block header
*/
// ---------------------------------------------------------------

void TBaseIOSimple::getBeginElement(const string &header)
{
};

//*M--------------------------------------------------------------
/*!
 *         putBeginElement(header)
 * \brief  Write a block end
 * \param  header block header
*/
// ---------------------------------------------------------------

void TBaseIOSimple::putBeginElement(const string &header)
{
};

//*M--------------------------------------------------------------
/*!
 *         getEndElement(header)
 * \brief  Read a block end
 * \param  header block header
*/
// ---------------------------------------------------------------

void TBaseIOSimple::getEndElement(const string &header)
{
  string curHeader;

  curHeader = getNextWord();
  if (!isEndElement(curHeader,header))
    throw app_ioerror("Expected end of "+header+", got a "+curHeader+".");
};

//*M--------------------------------------------------------------
/*!
 *         putEndElement(header)
 * \brief  Write a block end
 * \param  header block header
*/
// ---------------------------------------------------------------

void TBaseIOSimple::putEndElement(const string &header)
{
  (*iostr) << "END" << "\n";
};

//*M--------------------------------------------------------------
/*!
 *         getBeginElement(header, type)
 * \brief  Read a block end
 * \param  header block header
 * \param  type   block type
*/
// ---------------------------------------------------------------

void TBaseIOSimple::getBeginElement(const string &header, const string &type)
{
  string curInput;

  curInput = getNextWord();  
  if (curInput!=type)
    throw app_ioerror("Expected type "+type+", got a "+curInput+".");
};

//*M--------------------------------------------------------------
/*!
 *         putBeginElement(header, type)
 * \brief  Write a block end
 * \param  header block header
 * \param  type   block type
*/
// ---------------------------------------------------------------

void TBaseIOSimple::putBeginElement(const string &header, const string &type)
{
  (*iostr) << type << "\n";
};

//*M--------------------------------------------------------------
/*!
 *         getElement(elem)
 * \brief  Basic i/o method
 * \param  elem Value got
*/
// ---------------------------------------------------------------

void TBaseIOSimple::getElement(double &elem)
{
  string curInput;
  strstream strstr;

  curInput = getNextWord();
  strstr << curInput;
  strstr >> elem;
};

//*M--------------------------------------------------------------
/*!
 *         putElement(elem)
 * \brief  Basic i/o method
 * \param  elem Value to put
*/
// ---------------------------------------------------------------

void TBaseIOSimple::putElement(const double &elem)
{
  (*iostr) << elem << " ";
};

//*M--------------------------------------------------------------
/*!
 *         getElement(elem)
 * \brief  Basic i/o method
 * \param  elem Value got
*/
// ---------------------------------------------------------------

void TBaseIOSimple::getElement(long   &elem)
{
  string curInput;
  strstream strstr;

  curInput = getNextWord();
  strstr << curInput;
  strstr >> elem;
};

//*M--------------------------------------------------------------
/*!
 *         putElement(elem)
 * \brief  Basic i/o method
 * \param  elem Value to put
*/
// ---------------------------------------------------------------

void TBaseIOSimple::putElement(const long   &elem)
{
  (*iostr) << elem << " ";
};

//*M--------------------------------------------------------------
/*!
 *         getElement(elem)
 * \brief  Basic i/o method
 * \param  elem Value got
*/
// ---------------------------------------------------------------

void TBaseIOSimple::getElement(string &elem)
{
  elem = getNextWord();
};

//*M--------------------------------------------------------------
/*!
 *         putElement(elem)
 * \brief  Basic i/o method
 * \param  elem Value to put
*/
// ---------------------------------------------------------------

void TBaseIOSimple::putElement(const string &elem)
{
  (*iostr) << elem << " ";
};


//*C==============================================================
/*!
 * \class  TBaseIOXML
 * \brief  Basic iolass for xml on streams
 * \date   17.07.2001
 * \author mario.drobics@scch.at
*/
// ===============================================================

//*M--------------------------------------------------------------
/*!
 *         getNextToken(items, bufferPos)
 * \brief  Reads in one XML token
 * \param  items     list of elements
 * \param  bufferPos -1 for unbuffered, +1 for bufferd read
 *
 * Reads in one XML token starting with < and ending with >
 * Parameters are added to the items list.
 * '<', '>' and '=' are removed from input.
*/
// ---------------------------------------------------------------

void TBaseIOXML::getNextToken(TStringVec &items, int bufferPos=-1)
{
  string curInput;
  bool   endToken;

  items.clear();
  do
    {
      curInput = getNextWord((bufferPos>0)?bufferPos+items.size():bufferPos);
      // end token if last character is a >
      endToken = (curInput.substr(curInput.size()-1,1)==">");
      // end token if first word does not start with a <
      if (items.size()==0)
	endToken = endToken || (curInput.substr(0,1)!="<");

      // trim brackets
      if(curInput.substr(0,1)=="<") 
	curInput=curInput.substr(1,curInput.size()-1);
      if(curInput.substr(curInput.size()-1,1)==">") 
	curInput=curInput.substr(0,curInput.size()-1);

      items.push_back(curInput);
    }
  while (!endToken);
}

//*M--------------------------------------------------------------
/*!
 *         getNextHeader(header, type)
 * \brief  Read in next header and type
 * \param  header header to check
 * \param  type   type of the block (optional)
*/
// ---------------------------------------------------------------

void TBaseIOXML::getNextHeader(string &header, string &type)
{
  unsigned int        iter;
  TStringVec items;

  getNextToken(items, 1);

  header = "";
  type = "";
  if (items.size()>0) header = items[0];
  for(iter=1; iter < items.size()-1; iter++)
    if(items[iter]=="type")
      type = items[iter+1];
}

//*M--------------------------------------------------------------
/*!
 *         isEndElement(header, type)
 * \brief  check if a end element with header and type is on the stack
 * \param  header header to check
 * \param  type   type of the block (optional)
 * \return true if a end element
*/
// ---------------------------------------------------------------

bool TBaseIOXML::isEndElement(const string &curHeader, const string &type="")
{
  unsigned int    testLen;
  string teststr;

  testLen = 1+type.size();
  if (curHeader.size()>=testLen)
    teststr=curHeader.substr(0,testLen);
  else
    teststr="";
  return((teststr==("/"+type)));
}

//*M--------------------------------------------------------------
/*!
 *         getBeginElement(header)
 * \brief  Read a block begin
 * \param  header block header
*/
// ---------------------------------------------------------------

void TBaseIOXML::getBeginElement(const string &header)
{
  TStringVec items;

  getNextToken(items);
  if (header != items[0])
    throw app_ioerror("Expected begin of "+header+", got a "+items[0]+".");
};

//*M--------------------------------------------------------------
/*!
 *         putBeginElement(header)
 * \brief  Write a block begin
 * \param  header block header
*/
// ---------------------------------------------------------------

void TBaseIOXML::putBeginElement(const string &header)
{
  (*iostr) << "<" << header << ">\n";
};

//*M--------------------------------------------------------------
/*!
 *         getEndElement(header)
 * \brief  Read a block end
 * \param  header block header
*/
// ---------------------------------------------------------------

void TBaseIOXML::getEndElement(const string &header)
{
  TStringVec items;

  getNextToken(items);
  if (!isEndElement(items[0],header))
    throw app_ioerror("Expected end of "+header+", got a "+items[0]+".");
};

//*M--------------------------------------------------------------
/*!
 *         putEndElement(header)
 * \brief  Write a block end
 * \param  header block header
*/
// ---------------------------------------------------------------

void TBaseIOXML::putEndElement(const string &header)
{
  (*iostr) << "</" << header << ">\n";
};

//*M--------------------------------------------------------------
/*!
 *         getBeginElement(header, type)
 * \brief  Read a block begin
 * \param  header block header
 * \param  type   block type
*/
// ---------------------------------------------------------------

void TBaseIOXML::getBeginElement(const string &header, const string &type)
{
  TStringVec items;

  getNextToken(items);

  if (header!=items[0])
    throw app_ioerror("Expected begin of "+header+", got a "+items[0]+".");
  if ((items.size()<3) || (type != items[2]))
    throw app_ioerror("Expected type "+type+", got a "+items[2]+".");
};

//*M--------------------------------------------------------------
/*!
 *         putBeginElement(header, type)
 * \brief  Write a block begin
 * \param  header block header
 * \param  type   block type
*/
// ---------------------------------------------------------------

void TBaseIOXML::putBeginElement(const string &header, const string &type)
{
  (*iostr) << "<" << header << " type=\"" << type << "\">\n";
};

//*M--------------------------------------------------------------
/*!
 *         getElement(elem)
 * \brief  Basic i/o method
 * \param  elem Value got
*/
// ---------------------------------------------------------------

void TBaseIOXML::getElement(double &elem)
{
  string curInput;
  strstream strstr;

  getBeginElement("Double");
  curInput = getNextWord();
  getEndElement("Double");
  strstr << curInput;
  strstr >> elem;
};

//*M--------------------------------------------------------------
/*!
 *         putElement(elem)
 * \brief  Basic i/o method
 * \param  elem Value to put
*/
// ---------------------------------------------------------------

void TBaseIOXML::putElement(const double &elem)
{
  putBeginElement("Double");
  (*iostr) << elem << " ";
  putEndElement("Double");
};

//*M--------------------------------------------------------------
/*!
 *         getElement(elem)
 * \brief  Basic i/o method
 * \param  elem Value got
*/
// ---------------------------------------------------------------

void TBaseIOXML::getElement(long &elem)
{
  string curInput;
  strstream strstr;

  getBeginElement("Long");
  curInput = getNextWord();
  getEndElement("Long");
  strstr << curInput;
  strstr >> elem;
};

//*M--------------------------------------------------------------
/*!
 *         putElement(elem)
 * \brief  Basic i/o method
 * \param  elem Value to put
*/
// ---------------------------------------------------------------

void TBaseIOXML::putElement(const long   &elem)
{
  putBeginElement("Long");
  (*iostr) << elem << " ";
  putEndElement("Long");
};

//*M--------------------------------------------------------------
/*!
 *         getElement(elem)
 * \brief  Basic i/o method
 * \param  elem Value got
*/
// ---------------------------------------------------------------

void TBaseIOXML::getElement(string &elem)
{
  string curInput;

  getBeginElement("String");
  elem = getNextWord();
  getEndElement("String");
};

//*M--------------------------------------------------------------
/*!
 *         putElement(elem)
 * \brief  Basic i/o method
 * \param  elem Value to put
*/
// ---------------------------------------------------------------

void TBaseIOXML::putElement(const string &elem)
{
  putBeginElement("String");
  (*iostr) << elem << " ";
  putEndElement("String");
};

// ===============================================================
// ===============================================================
