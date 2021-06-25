#include "stdafx.h"
#include "SpecificationOfPositionOfWorker.h"
#include "SpecificationCreatingException.h"
#include "SpecificationUpdatingException.h"
#include "SpecificationMatchingException.h"

//***************************************************************************************
SpecificationOfPositionOfWorker::SpecificationOfPositionOfWorker(const string &requiredPosition)
	: Specification::Specification()
{
	if (!SpecificationOfPositionOfWorker::WORKER_VALIDATOR.isValidPosition(requiredPosition))
	{
		throw new SpecificationCreatingException("Impossible to create specification-object "
			"with given 'requiredPosition' = " + requiredPosition);
	}
	this->requiredPosition = new string(requiredPosition);
}
//***************************************************************************************
const WorkerValidator SpecificationOfPositionOfWorker::WORKER_VALIDATOR = WorkerValidator();
//***************************************************************************************
SpecificationOfPositionOfWorker::SpecificationOfPositionOfWorker(
	const SpecificationOfPositionOfWorker &other) 
	: requiredPosition(new string(*other.requiredPosition))
{

}
//***************************************************************************************
bool SpecificationOfPositionOfWorker::isMatch(const Entity &researchObject) const
{
	const Worker *researchWorker = dynamic_cast<const Worker*>(&researchObject);
	if (researchWorker == 0)
	{
		throw new SpecificationMatchingException("Given object isn't worker. Given object : "
			+ researchObject.toString());
	}
	return researchWorker->getPosition() == *this->requiredPosition;
}
//***************************************************************************************
void SpecificationOfPositionOfWorker::setRequiredPosition(const string &requiredPosition)
{
	if (!SpecificationOfPositionOfWorker::WORKER_VALIDATOR.isValidPosition(requiredPosition)) 
	{
		throw new SpecificationUpdatingException("Impossible to update specification-object "
			"with given 'requiredPosition' = " + requiredPosition);
	}
	*this->requiredPosition = requiredPosition;
}
//***************************************************************************************
const string&  SpecificationOfPositionOfWorker::getRequiredPosition() const 
{
	return *this->requiredPosition;
}
//***************************************************************************************
const SpecificationOfPositionOfWorker& SpecificationOfPositionOfWorker::operator=(
	const SpecificationOfPositionOfWorker &other) 
{
	if (this == &other) 
	{
		return *this;
	}
	*this->requiredPosition = *other.requiredPosition;
	return *this;
}
//***************************************************************************************
SpecificationOfPositionOfWorker::~SpecificationOfPositionOfWorker()
{
	delete this->requiredPosition;
}
//***************************************************************************************