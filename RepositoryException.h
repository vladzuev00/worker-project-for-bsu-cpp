#ifndef REPOSITORYEXCEPTION_H
#define REPOSITORYEXCEPTION_H

#include "Exception.h"

//**********************************************************************************************
class RepositoryException : virtual public Exception
{
public:
	RepositoryException();
	RepositoryException(const std::string &description);
	RepositoryException(Exception * const cause);
	RepositoryException(const std::string &description, Exception * const cause);
public:
	virtual ~RepositoryException() override;
};
//**********************************************************************************************

#endif REPOSITORYEXCEPTION_H