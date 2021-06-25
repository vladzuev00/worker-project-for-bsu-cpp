#include "stdafx.h"
#include "Repository.h"
#include "RepositoryUpdatingException.h"
#include "RepositorySearchException.h"

//подправить методы
//*********************************************************************************************
vector<Entity*>* Repository::getObjects() const 
{
	return this->objects;
}
//*********************************************************************************************
Repository::Repository() 
	: objects(new vector<Entity*>()),
	  idGenerator(new IdGenerator())
{

}
//*********************************************************************************************
void Repository::add(Entity &newObject) 
{
	if (this->isObjectInRepository(newObject))
	{
		std::string descriptionOfException = "Adding ";
		descriptionOfException.append(newObject.toString());
		descriptionOfException.append(" in repository is impossible, "
			"because it is already in repository.");
		throw new RepositoryUpdatingException(descriptionOfException);
	}
	newObject.setId(this->idGenerator->generateId());
	this->objects->push_back(&newObject);
}
//*********************************************************************************************
Entity& Repository::find(const unsigned long int idOfObject) const
{
	const unsigned int startSearchIndex = 0;
	const unsigned int endSearchIndex = this->objects->size() - 1;
	try 
	{
		return this->findObjectByIdByBinarySearch(idOfObject, startSearchIndex, endSearchIndex);
	}
	catch (RepositorySearchException * const exception) 
	{
		throw exception;
	}
}
//*********************************************************************************************
const EntityValidator Repository::ENTITY_VALIDATOR = EntityValidator();
//*********************************************************************************************
Entity& Repository::findObjectByIdByBinarySearch(const unsigned long int idOfObject,
	const unsigned int startIndexSearch, const unsigned int endIndexSearch) const
{
	if (!Repository::ENTITY_VALIDATOR.isValidId(idOfObject))
	{
		throw new RepositorySearchException("Finding object with given "
			"not valid 'id' is impossible. Given 'id' = " + std::to_string(idOfObject));
	}
	if (this->isEmpty())
	{
		throw new RepositorySearchException("Finding object in empty repository "
			"is impossible.");
	}
	int currentIndexSearch = (startIndexSearch + endIndexSearch) / 2;
	Entity &currentLearner = *this->objects->at(currentIndexSearch);
	if (currentLearner.getId() == idOfObject)
	{
		return currentLearner;
	}
	else if (startIndexSearch > endIndexSearch)
	{
		throw new RepositorySearchException("Object with given 'id' is not found. Given 'id' = " 
			+ std::to_string(idOfObject));
	}
	else
	{
		return (idOfObject < currentLearner.getId())
			? this->findObjectByIdByBinarySearch(idOfObject, startIndexSearch,
				currentIndexSearch - 1)
			: this->findObjectByIdByBinarySearch(idOfObject, currentIndexSearch + 1,
				endIndexSearch);
	}
}
//*********************************************************************************************
unsigned int Repository::findAmountOfObjects() const
{
	return this->objects->size();
}
//*********************************************************************************************
void Repository::remove(const Entity &deletedObject)
{
	this->remove(deletedObject.getId());
}
//*********************************************************************************************
void Repository::remove(const unsigned long int idOfDeletedObject)
{
	if (!Repository::ENTITY_VALIDATOR.isValidId(idOfDeletedObject))
	{
		throw new RepositoryUpdatingException("Removing object with given "
			"not valid 'id' is impossible. Given 'id' = " + std::to_string(idOfDeletedObject) + ".");
	}
	if (this->isEmpty())
	{
		throw new RepositoryUpdatingException("Removing object in empty repository "
			"is impossible. Given 'id' = " + std::to_string(idOfDeletedObject) + ".");
	}
	unsigned int indexInCollectionOfDeletedLearner;
	try
	{
		indexInCollectionOfDeletedLearner
			= this->findIndexInCollectionOfObjectById(idOfDeletedObject);
	}
	catch (RepositorySearchException * const exception)
	{
		throw new RepositoryUpdatingException(exception);
	}
	this->objects->erase(this->objects->begin()
		+ indexInCollectionOfDeletedLearner);
}
//*********************************************************************************************
unsigned int Repository::findIndexInCollectionOfObjectById(
	const unsigned long int idOfObject) const
{
	const int amountOfObjects = this->objects->size();
	int runnerIndex = 0;
	while (runnerIndex < amountOfObjects)
	{
		if (this->objects->at(runnerIndex)->getId() == idOfObject)
		{
			return runnerIndex;
		}
		runnerIndex++;
	}
	throw new RepositorySearchException("Impossible to find object "
		"with given 'id'. Given 'id' = " + std::to_string(idOfObject) + ".");
}
//*********************************************************************************************
bool Repository::isEmpty() const
{
	return this->objects->empty();
}
//*********************************************************************************************
vector<Entity*>* Repository::findObjects(const Specification &specification) const
{
	vector<Entity*> *suitableObjects = new vector<Entity*>();
	for (vector<Entity*>::iterator runner = this->objects->begin();
		runner != this->objects->end(); runner++) 
	{
		if (specification.isMatch(**runner)) 
		{
			suitableObjects->push_back(*runner);
		}
	}
	return suitableObjects;
}
//*********************************************************************************************
bool Repository::isObjectInRepository(const unsigned long int idOfResearchObject) const
{
	if (this->isEmpty())
	{
		return false;
	}
	bool isExceptionArised = false;
	try
	{
		this->findObjectByIdByBinarySearch(idOfResearchObject, 0, this->objects->size() - 1);
	}
	catch (RepositorySearchException * const exception)
	{
		isExceptionArised = true;
	}
	return !isExceptionArised;
}
//*********************************************************************************************
bool Repository::isObjectInRepository(const Entity &researchObject) const
{
	return this->isObjectInRepository(researchObject.getId());
}
//*********************************************************************************************
Repository::~Repository()
{
	for (vector<Entity*>::iterator runnerIterator = this->objects->begin();
		runnerIterator < this->objects->end();
		runnerIterator++)
	{
		delete *runnerIterator;
	}
	delete this->objects;
	delete this->idGenerator;
}
//*********************************************************************************************
IdGenerator::IdGenerator()
	: nextGeneratedId(IdGenerator::INITIAL_NEXT_GENERATED_ID)
{

}
//*********************************************************************************************
const unsigned long int IdGenerator::INITIAL_NEXT_GENERATED_ID = 1;
//*********************************************************************************************
unsigned long int IdGenerator::generateId()
{
	return this->nextGeneratedId++;
}
//*********************************************************************************************
IdGenerator::~IdGenerator()
{

}
//*********************************************************************************************