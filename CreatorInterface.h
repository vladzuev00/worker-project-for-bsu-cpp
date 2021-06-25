#ifndef CREATORINTERFACE_H
#define CREATORINTERFACE_H

#include <vector>
#include <string>
#include "Entity.h"

//*************************************************************************************
class CreatorInterface
{
public:
	CreatorInterface();
public:
	virtual Entity* createObject(
		const std::vector<std::string> &descriptionsOfPropertiesOfObject) const = 0;
public:
	virtual ~CreatorInterface() = 0;
};
//*************************************************************************************

#endif CREATORINTERFACE_H