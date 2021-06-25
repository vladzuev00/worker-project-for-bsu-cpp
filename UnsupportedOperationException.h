#ifndef UNSUPPORTEDOPERATIONEXCEPTION_H
#define UNSUPPORTEDOPERATIONEXCEPTION_H

#include "Exception.h"

//****************************************************************************
class UnsupportedOperationException : public Exception
{
public:
	UnsupportedOperationException();
	UnsupportedOperationException(const std::string &description);
	UnsupportedOperationException(Exception * const cause);
	UnsupportedOperationException(const std::string &description,
		Exception * const cause);
public:
	virtual ~UnsupportedOperationException() override;
};
//****************************************************************************

#endif UNSUPPORTEDOPERATIONEXCEPTION_H