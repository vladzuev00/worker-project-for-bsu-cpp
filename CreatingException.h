#ifndef CREATINGEXCEPTION_H
#define CREATINGEXCEPTION_H

#include "Exception.h"

//***************************************************************************************
class CreatingException : virtual public Exception
{
public:
	CreatingException();
	CreatingException(const std::string &description);
	CreatingException(Exception * const cause);
	CreatingException(const std::string &description,
		Exception * const cause);
public:
	virtual ~CreatingException() override;
};
//***************************************************************************************

#endif CREATINGEXCEPTION_H