#ifndef WORKERCREATINGEXCEPTION_H
#define WORKERCREATINGEXCEPTION_H

#include "WorkerException.h"
#include "CreatingException.h"

//***************************************************************************************************
class WorkerCreatingException : public WorkerException, public CreatingException
{
public:
	WorkerCreatingException();
	WorkerCreatingException(const std::string &description);
	WorkerCreatingException(Exception * const cause);
	WorkerCreatingException(const std::string &description,
		Exception * const cause);
public:
	virtual ~WorkerCreatingException() override;
};
//***************************************************************************************************

#endif WORKERCREATINGEXCEPTION_H