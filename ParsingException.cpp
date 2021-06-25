#include "stdafx.h"
#include "ParsingException.h"

//*************************************************************************
ParsingException::ParsingException() : Exception::Exception()
{

}
//*************************************************************************
ParsingException::ParsingException(const std::string &description)
	: Exception::Exception(description)
{

}
//*************************************************************************
ParsingException::ParsingException(Exception * const cause) 
	: Exception::Exception(cause)
{

}
//*************************************************************************
ParsingException::ParsingException(const std::string &description, Exception * const cause) 
	: Exception::Exception(description, cause)
{

}
//*************************************************************************
ParsingException::~ParsingException()
{

}
//*************************************************************************