#ifndef READINGEXCEPTION_H
#define READINGEXCEPTION_H

#include "Exception.h"

//**********************************************************************************
class ReadingException : public Exception
{
public:
	ReadingException();
	ReadingException(const std::string &description);
	ReadingException(Exception * const cause);
	ReadingException(const std::string &description, Exception * const cause);
public:
	virtual ~ReadingException() override;
};
//**********************************************************************************

#endif READINGEXCEPTION_H