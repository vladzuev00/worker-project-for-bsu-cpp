#ifndef READERINTERFACE_H
#define READERINTERFACE_H

#include <vector>
#include <string>

using std::vector;
using std::string;

//**************************************************************************************************
class ReaderInterface
{
protected:
	static char findFileSeparator();
public:
	ReaderInterface();
public:
	virtual vector<string>* read(const string &filePath, const string &fileName) const = 0;
public:
	virtual ~ReaderInterface() = 0;
};
//**************************************************************************************************

#endif READERINTERFACE_H