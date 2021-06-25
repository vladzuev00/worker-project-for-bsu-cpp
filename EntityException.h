#ifndef ENTITYEXCEPTION_H
#define ENTITYEXCEPTION_H

#include "Exception.h"

//*************************************************************************************
class EntityException : virtual public Exception
{
public:
	EntityException();
	EntityException(const std::string &description);
	EntityException(Exception * const cause);
	EntityException(const std::string &description,
		Exception * const cause);
public:
	virtual ~EntityException() override;
};
//*************************************************************************************

#endif ENTITYEXCEPTION_H