#include "stdafx.h"
#include "UpdatingException.h"

//******************************************************************************
UpdatingException::UpdatingException() : Exception::Exception()
{

}
//******************************************************************************
UpdatingException::UpdatingException(const std::string &description)
	: Exception::Exception(description)
{

}
//******************************************************************************
UpdatingException::UpdatingException(Exception * const cause)
	: Exception::Exception(cause)
{

}
//******************************************************************************
UpdatingException::UpdatingException(const std::string &description,
	Exception * const cause)
	: Exception::Exception(description, cause)
{

}
//******************************************************************************
UpdatingException::~UpdatingException()
{

}
//******************************************************************************