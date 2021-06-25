#include "stdafx.h"
#include "UnsupportedOperationException.h"

//****************************************************************************
UnsupportedOperationException::UnsupportedOperationException() : Exception::Exception()
{

}
//****************************************************************************
UnsupportedOperationException::UnsupportedOperationException(const std::string &description) 
	: Exception::Exception(description)
{

}
//****************************************************************************
UnsupportedOperationException::UnsupportedOperationException(Exception * const cause)
	: Exception::Exception(cause)
{

}
//****************************************************************************
UnsupportedOperationException::UnsupportedOperationException(
	const std::string &description, Exception * const cause)
	: Exception::Exception(description, cause)
{

}
//****************************************************************************
UnsupportedOperationException::~UnsupportedOperationException()
{

}
//****************************************************************************