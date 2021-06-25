#include "stdafx.h"
#include "Exception.h"

//********************************************************************************
Exception::Exception() 
	: description(new std::string(Exception::NOT_DEFINED_DESCRIPTION)),
	  cause(0)
{

}
//********************************************************************************
const std::string Exception::NOT_DEFINED_DESCRIPTION = "Not defined.";
//********************************************************************************
Exception::Exception(const std::string &description) 
	: description(new std::string(description)),
	  cause(0)
{

}
//********************************************************************************
Exception::Exception(Exception * const cause)
	: description(new std::string(Exception::NOT_DEFINED_DESCRIPTION)),
	  cause(cause)
{

}
//********************************************************************************
Exception::Exception(const std::string &description, Exception * const cause)
	: description(new std::string(description)),
	  cause(cause)
{

}
//********************************************************************************
const std::string& Exception::getDescription() const
{
	return *this->description;
}
//********************************************************************************
Exception* Exception::getCause() const 
{
	return this->cause;
}
//********************************************************************************
Exception::~Exception()
{
	delete this->description;
	delete this->cause;
}
//********************************************************************************