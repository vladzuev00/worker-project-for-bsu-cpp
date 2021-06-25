#ifndef SPECIFICATIONEXCEPTION_H
#define SPECIFICATIONEXCEPTION_H

#include "Exception.h"

//*****************************************************************************
class SpecificationException : virtual public Exception
{
public:
	SpecificationException();
	SpecificationException(const std::string &description);
	SpecificationException(Exception * const cause);
	SpecificationException(const std::string &description, Exception * const cause);
public:
	virtual ~SpecificationException() override;
};
//*****************************************************************************

#endif SPECIFICATIONEXCEPTION_H