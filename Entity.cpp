#include "stdafx.h"
#include "Entity.h"
#include "EntityUpdatingException.h"
#include <climits>
#include "UnsupportedOperationException.h"

//**************************************************************************************
Entity::Entity(const Entity &other)  : Writeable::Writeable()
{
	throw new UnsupportedOperationException("Impossible to call Entity::Entity(const Entity&),"
		" because it is error to copy 'id'.");
}
//**************************************************************************************
const Entity& Entity::operator=(const Entity &other) 
{
	throw new UnsupportedOperationException("Impossible to call Entity::operator=(const Entity&),"
		" because it is error to copy 'id'.");
}
//**************************************************************************************
Entity::Entity() : Writeable::Writeable(), id(Entity::VALUE_OF_NOT_DEFINED_ID)
{
	
}
//**************************************************************************************
const unsigned long Entity::VALUE_OF_NOT_DEFINED_ID = 0;
//**************************************************************************************
void Entity::setId(const unsigned long newId)
{
	if (!Entity::ENTITY_VALIDATOR.isValidId(newId)) 
	{
		throw new EntityUpdatingException("Impossible to update entity by given 'id' = "
			+ std::to_string(newId));
	}
	this->id = newId;
}
//**************************************************************************************
const EntityValidator Entity::ENTITY_VALIDATOR = EntityValidator();
//**************************************************************************************
unsigned long Entity::getId() const 
{
	return this->id;
}
//**************************************************************************************
std::string Entity::toString() const 
{
	std::string entityDescription = typeid(*this).name();
	entityDescription.append("[id = " +
		(this->id != Entity::VALUE_OF_NOT_DEFINED_ID
			? std::to_string(this->id) : "isn't defined"));
	entityDescription.append("]");
	return entityDescription;
}
//**************************************************************************************
Entity::~Entity()
{

}
//**************************************************************************************
bool EntityValidator::isValidId(const unsigned long researchId) const 
{
	return EntityValidator::MINIMAL_ALLOWABLE_ID <= researchId
		&& researchId <= EntityValidator::MAXIMAL_ALLOWABLE_ID;
}
//**************************************************************************************
const unsigned long EntityValidator::MINIMAL_ALLOWABLE_ID = 1;
//**************************************************************************************
const unsigned long EntityValidator::MAXIMAL_ALLOWABLE_ID = ULONG_MAX;
//**************************************************************************************
