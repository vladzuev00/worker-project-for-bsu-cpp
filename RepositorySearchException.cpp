#include "stdafx.h"
#include "RepositorySearchException.h"

//***************************************************************************************************
RepositorySearchException::RepositorySearchException() 
	: RepositoryException::RepositoryException(),
	  SearchException::SearchException()
{

}
//***************************************************************************************************
RepositorySearchException::RepositorySearchException(const std::string &description)
	: RepositoryException::RepositoryException(description),
	  SearchException::SearchException(description)
{

}
//***************************************************************************************************
RepositorySearchException::RepositorySearchException(Exception * const cause)
	: RepositoryException::RepositoryException(cause),
	  SearchException::SearchException(cause)
{

}
//***************************************************************************************************
RepositorySearchException::RepositorySearchException(
	const std::string &description, Exception * const cause)
	: RepositoryException::RepositoryException(description, cause),
	SearchException::SearchException(description, cause)
{

}
//***************************************************************************************************
RepositorySearchException::~RepositorySearchException()
{

}
//***************************************************************************************************