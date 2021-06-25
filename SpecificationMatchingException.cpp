#include "stdafx.h"
#include "SpecificationMatchingException.h"

//********************************************************************************************
SpecificationMatchingException::SpecificationMatchingException() 
	: SpecificationException::SpecificationException()
{

}
//********************************************************************************************
SpecificationMatchingException::SpecificationMatchingException(const std::string &description)
	: SpecificationException::SpecificationException(description)
{

}
//********************************************************************************************
SpecificationMatchingException::SpecificationMatchingException(Exception * const cause)
	: SpecificationException::SpecificationException(cause)
{

}
//********************************************************************************************
SpecificationMatchingException::SpecificationMatchingException(
	const std::string &description, Exception * const cause)
	: SpecificationException::SpecificationException(description, cause)
{

}
//********************************************************************************************
SpecificationMatchingException::~SpecificationMatchingException()
{

}
//********************************************************************************************