#include "stdafx.h"
#include "RepositoryException.h"

//**********************************************************************************************
RepositoryException::RepositoryException() : Exception::Exception()
{

}
//**********************************************************************************************
RepositoryException::RepositoryException(const std::string &description) 
	: Exception::Exception(description)
{

}
//**********************************************************************************************
RepositoryException::RepositoryException(Exception * const cause)
	: Exception::Exception(cause)
{

}
//**********************************************************************************************
RepositoryException::RepositoryException(
	const std::string &description, Exception * const cause)
	: Exception::Exception(description, cause)
{

}
//**********************************************************************************************
RepositoryException::~RepositoryException()
{

}
//**********************************************************************************************