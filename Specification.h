#ifndef SPECIFICATION_H
#define SPECIFICATION_H

#include "Entity.h"

//************************************************************************
class Specification
{
public:
	Specification();
public:
	virtual bool isMatch(const Entity &researchObject) const = 0;
public:
	virtual ~Specification() = 0;
};
//************************************************************************

#endif SPECIFICATION_H