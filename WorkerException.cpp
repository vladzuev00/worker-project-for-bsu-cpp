#include "stdafx.h"
#include "WorkerException.h"

//**********************************************************************************
WorkerException::WorkerException() : Exception::Exception()
{

}
//**********************************************************************************
WorkerException::WorkerException(const std::string &description) 
	: Exception::Exception(description)
{

}
//**********************************************************************************
WorkerException::WorkerException(Exception * const cause) 
	: Exception::Exception(cause)
{

}
//**********************************************************************************
WorkerException::WorkerException(const std::string &description, Exception * const cause)
	: Exception::Exception(description, cause)
{

}
//**********************************************************************************
WorkerException::~WorkerException()
{

}
//**********************************************************************************