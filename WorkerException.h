#ifndef WORKEREXCEPTION_H
#define WORKEREXCEPTION_H

#include "Exception.h"

//**********************************************************************************
class WorkerException : virtual public Exception
{
public:
	WorkerException();
	WorkerException(const std::string &description);
	WorkerException(Exception * const cause);
	WorkerException(const std::string &description,
		Exception * const cause);
public:
	virtual ~WorkerException() override;
};
//**********************************************************************************

#endif WORKEREXCEPTION_H