#ifndef PARSINGEXCEPTION_H
#define PARSINGEXCEPTION_H

#include "Exception.h"

//*************************************************************************
class ParsingException : public Exception
{
public:
	ParsingException();
	ParsingException(const std::string &description);
	ParsingException(Exception * const cause);
	ParsingException(const std::string &description,
		Exception * const cause);
public:
	virtual ~ParsingException() override;
};
//*************************************************************************

#endif PARSINGEXCEPTION_H