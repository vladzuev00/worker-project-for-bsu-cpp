#include "stdafx.h"
#include "SpecificationCreatingException.h"

//***************************************************************************************
SpecificationCreatingException::SpecificationCreatingException() 
	: SpecificationException::SpecificationException(),
	  CreatingException::CreatingException()
{

}
//***************************************************************************************
SpecificationCreatingException::SpecificationCreatingException(const std::string &description)
	: SpecificationException::SpecificationException(description),
	  CreatingException::CreatingException(description)
{

}
//***************************************************************************************
SpecificationCreatingException::SpecificationCreatingException(Exception * const cause)
	: SpecificationException::SpecificationException(cause),
	  CreatingException::CreatingException(cause)
{

}
//***************************************************************************************
SpecificationCreatingException::SpecificationCreatingException(
	const std::string &description, Exception * const cause)
	: SpecificationException::SpecificationException(description, cause),
	  CreatingException::CreatingException(description, cause)
{

}
//***************************************************************************************
SpecificationCreatingException::~SpecificationCreatingException()
{

}
//***************************************************************************************