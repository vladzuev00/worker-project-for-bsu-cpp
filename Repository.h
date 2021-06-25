#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include "Specification.h"
#include "Entity.h"

using std::vector;

//*************************************************************************************
class IdGenerator;
//*************************************************************************************
class Repository       
{
private:
	vector<Entity*> *objects;
	IdGenerator *idGenerator;
private:
	static const EntityValidator ENTITY_VALIDATOR;
private:
	Entity& findObjectByIdByBinarySearch(const unsigned long int idOfObject,
		const unsigned int startIndexSearch, const unsigned int endIndexSearch) const;
	unsigned int findIndexInCollectionOfObjectById(const unsigned long int idOfObject) const;
protected:
	vector<Entity*>* getObjects() const;
public:
	Repository();
public:
	virtual void add(Entity &newObject);
	virtual Entity& find(const unsigned long int idOfObject) const;
	virtual unsigned int findAmountOfObjects() const;
	virtual void remove(const Entity &deletedObject);
	virtual void remove(const unsigned long int idOfDeletedObject);
	virtual bool isEmpty() const;
	virtual vector<Entity*>* findObjects(const Specification &specification) const;
	virtual bool isObjectInRepository(const unsigned long int idOfResearchObject) const;
	virtual bool isObjectInRepository(const Entity &researchObject) const;
public:
	virtual ~Repository() = 0;
};
//*************************************************************************************
class IdGenerator
{
private:
	unsigned long int nextGeneratedId;
private:
	static const unsigned long INITIAL_NEXT_GENERATED_ID;
public:
	IdGenerator();
public:
	unsigned long int generateId();
public:
	~IdGenerator();
};
//**************************************************************************************

#endif REPOSITORYINTERFACE_H