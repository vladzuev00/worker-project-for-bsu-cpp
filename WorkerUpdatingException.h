#ifndef WORKERUPDATINGEXCEPTION_H
#define WORKERUPDATINGEXCEPTION_H

#include "WorkerException.h"
#include "UpdatingException.h"

//****************************************************************
class WorkerUpdatingException : public WorkerException, public UpdatingException
{
public:
	WorkerUpdatingException();
	WorkerUpdatingException(const std::string &description);
	WorkerUpdatingException(Exception * const cause);
	WorkerUpdatingException(const std::string &description, 
		Exception * const cause);
public:
	virtual ~WorkerUpdatingException() override;
};
//****************************************************************

#endif WORKERUPDATINGEXCEPTION_H