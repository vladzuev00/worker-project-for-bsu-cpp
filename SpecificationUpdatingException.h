#ifndef SPECIFICATIONUPDATINGEXCEPTION_H
#define SPECIFICATIONUPDATINGEXCEPTION_H

#include "SpecificationException.h"
#include "UpdatingException.h"

//****************************************************************************************
class SpecificationUpdatingException : public SpecificationException,
	public UpdatingException
{
public:
	SpecificationUpdatingException();
	SpecificationUpdatingException(const std::string &description);
	SpecificationUpdatingException(Exception * const cause);
	SpecificationUpdatingException(const std::string &description,
		Exception * const cause);
public:
	virtual ~SpecificationUpdatingException() override;
};
//****************************************************************************************

#endif SPECIFICATIONUPDATINGEXCEPTION_H