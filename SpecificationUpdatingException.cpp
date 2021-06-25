#include "stdafx.h"
#include "SpecificationUpdatingException.h"

//****************************************************************************************
SpecificationUpdatingException::SpecificationUpdatingException() 
	: SpecificationException::SpecificationException(),
	  UpdatingException::UpdatingException()
{

}
//****************************************************************************************
SpecificationUpdatingException::SpecificationUpdatingException(const std::string &description)
	: SpecificationException::SpecificationException(description),
	  UpdatingException::UpdatingException(description)
{

}
//****************************************************************************************
SpecificationUpdatingException::SpecificationUpdatingException(Exception * const cause)
	: SpecificationException::SpecificationException(cause),
	  UpdatingException::UpdatingException(cause)
{

}
//****************************************************************************************
SpecificationUpdatingException::SpecificationUpdatingException(
	const std::string &description, Exception * const cause)
	: SpecificationException::SpecificationException(description, cause),
	  UpdatingException::UpdatingException(description, cause)
{

}
//****************************************************************************************
SpecificationUpdatingException::~SpecificationUpdatingException()
{

}
//****************************************************************************************