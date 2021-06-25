#ifndef ENTITYUPDATINGEXCEPTION_H
#define ENTITYUPDATINGEXCEPTION_H

#include "EntityException.h"
#include "UpdatingException.h"

//********************************************************************************
class EntityUpdatingException : public EntityException, public UpdatingException
{
public:
	EntityUpdatingException();
	EntityUpdatingException(const std::string &description);
	EntityUpdatingException(Exception * const cause);
	EntityUpdatingException(const std::string &description, Exception * const cause);
public:
	virtual ~EntityUpdatingException() override;
};
//********************************************************************************

#endif ENTITYUPDATINGEXCEPTION_H