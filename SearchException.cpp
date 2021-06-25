#include "stdafx.h"
#include "SearchException.h"

//************************************************************************************************************
SearchException::SearchException() : Exception::Exception()
{

}
//************************************************************************************************************
SearchException::SearchException(const std::string &description) 
	: Exception::Exception(description)
{

}
//************************************************************************************************************
SearchException::SearchException(Exception * const cause) : Exception::Exception(cause)
{

}
//************************************************************************************************************
SearchException::SearchException(const std::string &description, Exception * const cause) 
	: Exception::Exception(description, cause)
{

}
//************************************************************************************************************
SearchException::~SearchException()
{

}
//************************************************************************************************************