#include "stdafx.h"
#include "ReadingException.h"

//**********************************************************************************
ReadingException::ReadingException() : Exception::Exception()
{

}
//**********************************************************************************
ReadingException::ReadingException(const std::string &description)
	: Exception::Exception(description)
{

}
//**********************************************************************************
ReadingException::ReadingException(Exception * const cause) 
	: Exception::Exception(cause)
{

}
//**********************************************************************************
ReadingException::ReadingException(const std::string &description, Exception * const cause) 
	: Exception::Exception(description, cause)
{

}
//**********************************************************************************
ReadingException::~ReadingException()
{

}
//**********************************************************************************