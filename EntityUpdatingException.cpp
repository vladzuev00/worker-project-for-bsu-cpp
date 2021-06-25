#include "stdafx.h"
#include "EntityUpdatingException.h"

//********************************************************************************
EntityUpdatingException::EntityUpdatingException() 
	: EntityException::EntityException(),
	  UpdatingException::UpdatingException()
{

}
//********************************************************************************
EntityUpdatingException::EntityUpdatingException(const std::string &description)
	: EntityException::EntityException(description),
	  UpdatingException::UpdatingException(description)
{

}
//********************************************************************************
EntityUpdatingException::EntityUpdatingException(Exception * const cause)
	: EntityException::EntityException(cause),
	  UpdatingException::UpdatingException(cause)
{

}
//********************************************************************************
EntityUpdatingException::EntityUpdatingException(
	const std::string &description, Exception * const cause)
	: EntityException::EntityException(description, cause),
      UpdatingException::UpdatingException(description, cause)
{

}
//********************************************************************************
EntityUpdatingException::~EntityUpdatingException()
{

}
//********************************************************************************