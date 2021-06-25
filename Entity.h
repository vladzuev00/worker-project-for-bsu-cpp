#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "Writeable.h"

//**************************************************************************************
class EntityValidator;
//**************************************************************************************
class Entity : public Writeable
{
private:
	unsigned long id;
private:
	static const unsigned long VALUE_OF_NOT_DEFINED_ID;
	static const EntityValidator ENTITY_VALIDATOR;
private:
	Entity(const Entity &other);
private:
	const Entity& operator=(const Entity &other);
public:
	Entity();
public:
	void setId(const unsigned long newId);
	unsigned long getId() const;
public:
	virtual std::string toString() const override;
public:
	virtual ~Entity() = 0;
};
//**************************************************************************************
class EntityValidator
{
private:
	static const unsigned long MINIMAL_ALLOWABLE_ID;
	static const unsigned long MAXIMAL_ALLOWABLE_ID;
public:
	bool isValidId(const unsigned long researchId) const;
};
//**************************************************************************************

#endif ENTITY_H