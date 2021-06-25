#ifndef WRITER_H
#define WRITER_H

#include "Writeable.h"
#include <vector>

//*****************************************************************************************
class Writer
{
private:
	static char findFileSeparator();
public:
	Writer();
public:
	void writeObjects(const std::vector<Writeable*> &objects, 
		const std::string &pathOfDocument, const std::string &nameOfDocument, 
		const std::string &separatorOfObjects) const;
public:
	~Writer();
};
//*****************************************************************************************

#endif WRITER_H