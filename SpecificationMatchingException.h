#ifndef SPECIFICATIONMATCHINGEXCEPTION_H
#define SPECIFICATIONMATCHINGEXCEPTION_H

#include "SpecificationException.h"

//********************************************************************************************
class SpecificationMatchingException : public SpecificationException
{
public:
	SpecificationMatchingException();
	SpecificationMatchingException(const std::string &description);
	SpecificationMatchingException(Exception * const cause);
	SpecificationMatchingException(const std::string &description,
		Exception * const cause);
public:
	virtual ~SpecificationMatchingException() override;
};
//********************************************************************************************

#endif SPECIFICATIONMATCHINGEXCEPTION_H