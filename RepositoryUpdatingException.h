#ifndef REPOSITORYUPDATINGEXCEPTION_H
#define REPOSITORYUPDATINGEXCEPTION_H

#include "RepositoryException.h"
#include "UpdatingException.h"

//**************************************************************************************************
class RepositoryUpdatingException : public RepositoryException, public UpdatingException
{
public:
	RepositoryUpdatingException();
	RepositoryUpdatingException(const std::string &description);
	RepositoryUpdatingException(Exception * const cause);
	RepositoryUpdatingException(const std::string &description, Exception * const cause);
public:
	virtual ~RepositoryUpdatingException() override;
};
//**************************************************************************************************

#endif REPOSITORYUPDATINGEXCEPTION_H