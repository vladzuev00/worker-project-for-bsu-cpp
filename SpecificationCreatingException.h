#ifndef SPECIFICATIONCREATINGEXCEPTION_H
#define SPECIFICATIONCREATINGEXCEPTION_H

#include "SpecificationException.h"
#include "CreatingException.h"

//***************************************************************************************
class SpecificationCreatingException : public SpecificationException,
	public CreatingException
{
public:
	SpecificationCreatingException();
	SpecificationCreatingException(const std::string &description);
	SpecificationCreatingException(Exception * const cause);
	SpecificationCreatingException(const std::string &description,
		Exception * const cause);
public:
	virtual ~SpecificationCreatingException() override;
};
//***************************************************************************************

#endif SPECIFICATIONCREATINGEXCEPTION_H