#include "stdafx.h"
#include "WorkerUpdatingException.h"

//****************************************************************
WorkerUpdatingException::WorkerUpdatingException() 
	: WorkerException::WorkerException(), UpdatingException::UpdatingException()
{

}
//****************************************************************
WorkerUpdatingException::WorkerUpdatingException(const std::string &description)
	: WorkerException::WorkerException(description), 
	  UpdatingException::UpdatingException(description)
{

}
//****************************************************************
WorkerUpdatingException::WorkerUpdatingException(Exception * const cause)
	: WorkerException::WorkerException(cause),
	  UpdatingException::UpdatingException(cause)
{

}
//****************************************************************
WorkerUpdatingException::WorkerUpdatingException(
	const std::string &description, Exception * const cause)
	: WorkerException::WorkerException(description, cause), 
	  UpdatingException::UpdatingException(description, cause)
{

}
//****************************************************************
WorkerUpdatingException::~WorkerUpdatingException()
{

}
//****************************************************************