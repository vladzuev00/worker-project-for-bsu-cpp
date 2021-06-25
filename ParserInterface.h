#ifndef PARSERINTERFACE_H
#define PARSERINTERFACE_H

#include <vector>
#include <string>

//***********************************************************************************
class ParserInterface
{
public:
	ParserInterface();
public:
	virtual std::vector<std::string>* parseDescription(
		const std::string &description) const = 0;
public:
	virtual ~ParserInterface() = 0;
};
//***********************************************************************************

#endif PARSERINTERFACE_H