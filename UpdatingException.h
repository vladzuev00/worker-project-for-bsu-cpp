#ifndef UPDATINGEXCEPTION_H
#define UPDATINGEXCEPTION_H

#include "Exception.h"

//******************************************************************************
class UpdatingException : virtual public Exception
{
public:
	UpdatingException();
	UpdatingException(const std::string &description);
	UpdatingException(Exception * const cause);
	UpdatingException(const std::string &description,
		Exception * const cause);
public:
	~UpdatingException();
};
//******************************************************************************

#endif UPDATINGEXCEPTION_H