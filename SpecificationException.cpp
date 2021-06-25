#include "stdafx.h"
#include "SpecificationException.h"

//*****************************************************************************
SpecificationException::SpecificationException() : Exception::Exception()
{

}
//*****************************************************************************
SpecificationException::SpecificationException(const std::string &description)
	: Exception::Exception(description)
{

}
//*****************************************************************************
SpecificationException::SpecificationException(Exception * const cause) 
	: Exception::Exception(cause)
{

}
//*****************************************************************************
SpecificationException::SpecificationException(
	const std::string &description, Exception * const cause)
	: Exception::Exception(description, cause)
{

}
//*****************************************************************************
SpecificationException::~SpecificationException()
{

}
//*****************************************************************************