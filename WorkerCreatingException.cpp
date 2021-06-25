#include "stdafx.h"
#include "WorkerCreatingException.h"

//***************************************************************************************************
WorkerCreatingException::WorkerCreatingException() 
	: WorkerException::WorkerException(),
	  CreatingException::CreatingException()
{

}
//***************************************************************************************************
WorkerCreatingException::WorkerCreatingException(const std::string &description)
	: WorkerException::WorkerException(description),
	  CreatingException::CreatingException(description)
{

}
//***************************************************************************************************
WorkerCreatingException::WorkerCreatingException(Exception * const cause)
	: WorkerException::WorkerException(cause),
	  CreatingException::CreatingException(cause)
{

}
//***************************************************************************************************
WorkerCreatingException::WorkerCreatingException(
	const std::string &description, Exception * const cause)
	: WorkerException::WorkerException(description, cause),
	CreatingException::CreatingException(description, cause)
{

}
//***************************************************************************************************
WorkerCreatingException::~WorkerCreatingException()
{

}
//***************************************************************************************************
