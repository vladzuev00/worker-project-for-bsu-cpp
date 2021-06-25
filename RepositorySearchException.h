#ifndef REPOSITORYSEARCHEXCEPTION_H
#define REPOSITORYSEARCHEXCEPTION_H

#include "RepositoryException.h"
#include "SearchException.h"

//***************************************************************************************************
class RepositorySearchException : public RepositoryException, public SearchException
{
public:
	RepositorySearchException();
	RepositorySearchException(const std::string &description);
	RepositorySearchException(Exception * const cause);
	RepositorySearchException(const std::string &description,
		Exception * const cause);
public:
	virtual ~RepositorySearchException() override;
};
//***************************************************************************************************

#endif REPOSITORYSEARCHEXCEPTION_H