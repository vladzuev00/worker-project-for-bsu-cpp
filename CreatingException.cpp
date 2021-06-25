#include "stdafx.h"
#include "CreatingException.h"

//***************************************************************************************
CreatingException::CreatingException() 
	: Exception::Exception()
{

}
//***************************************************************************************
CreatingException::CreatingException(const std::string &description)
	: Exception::Exception(description)
{

}
//***************************************************************************************
CreatingException::CreatingException(Exception * const cause)
	: Exception::Exception(cause)
{

}
//***************************************************************************************
CreatingException::CreatingException(const std::string &description, Exception * const cause)
	: Exception::Exception(description, cause)
{

}
//***************************************************************************************
CreatingException::~CreatingException()
{

}
//***************************************************************************************