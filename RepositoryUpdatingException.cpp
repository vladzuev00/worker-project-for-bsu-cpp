#include "stdafx.h"
#include "RepositoryUpdatingException.h"

//**************************************************************************************************
RepositoryUpdatingException::RepositoryUpdatingException() 
	: RepositoryException::RepositoryException(),
	  UpdatingException::UpdatingException()
{

}
//**************************************************************************************************
RepositoryUpdatingException::RepositoryUpdatingException(const std::string &description)
	: RepositoryException::RepositoryException(description),
	  UpdatingException::UpdatingException(description)
{

}
//**************************************************************************************************
RepositoryUpdatingException::RepositoryUpdatingException(Exception * const cause)
	: RepositoryException::RepositoryException(cause),
	  UpdatingException::UpdatingException(cause)
{

}
//**************************************************************************************************
RepositoryUpdatingException::RepositoryUpdatingException(
	const std::string &description, Exception * const cause)
	: RepositoryException::RepositoryException(description, cause),
	  UpdatingException::UpdatingException(description, cause)
{

}
//**************************************************************************************************
RepositoryUpdatingException::~RepositoryUpdatingException()
{

}
//**************************************************************************************************