#ifndef WRITEABLE_H
#define WRITEABLE_H

#include <string>

//********************************************************************
class Writeable
{
public:
	Writeable();
public:
	virtual std::string toString() const = 0;   //лучше сделать метод write
public:
	virtual ~Writeable() = 0;
};
//********************************************************************

#endif WRITEABLE_H