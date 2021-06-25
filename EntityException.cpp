#include "stdafx.h"
#include "EntityException.h"

//*************************************************************************************
EntityException::EntityException() : Exception::Exception()
{

}
//*************************************************************************************
EntityException::EntityException(const std::string &description)
	: Exception::Exception(description)
{

}
//*************************************************************************************
EntityException::EntityException(Exception * const cause)
	: Exception::Exception(cause)
{

}
//*************************************************************************************
EntityException::EntityException(const std::string &description, Exception * const cause) 
	: Exception::Exception(description, cause)
{

}
//*************************************************************************************
EntityException::~EntityException()
{

}
//*************************************************************************************