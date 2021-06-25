#ifndef SEARCHEXCEPTION_H
#define SEARCHEXCEPTION_H

#include "Exception.h"

//************************************************************************************************************
class SearchException : virtual public Exception
{
public:
	SearchException();
	SearchException(const std::string &description);
	SearchException(Exception * const cause);
	SearchException(const std::string &description, Exception * const cause);
public:
	virtual ~SearchException() override;
};
//************************************************************************************************************

#endif SEARCHEXCEPTION_H