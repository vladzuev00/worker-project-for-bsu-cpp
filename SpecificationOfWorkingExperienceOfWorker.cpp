#include "stdafx.h"
#include "SpecificationOfWorkingExperienceOfWorker.h"
#include "Worker.h"
#include "SpecificationCreatingException.h"
#include "SpecificationMatchingException.h"

//********************************************************************************
bool isValidWorkingExperience(const unsigned int researchWorkingExperience);
//********************************************************************************
SpecificationOfWorkingExperienceOfWorker::SpecificationOfWorkingExperienceOfWorker(
	const unsigned int minimalRequiredWorkingExperience) 
{
	if (!isValidWorkingExperience(minimalRequiredWorkingExperience)) 
	{
		throw new SpecificationCreatingException("Impossible to create specification-object "
			"with given 'minimalRequiredWorkingExperience' = "
			+ minimalRequiredWorkingExperience);
	}
	this->minimalRequiredWorkingExperience = minimalRequiredWorkingExperience;
}
//********************************************************************************
bool isValidWorkingExperience(const unsigned int researchWorkingExperience)
{
	const unsigned int minimalAllowableWorkingExperience = 0;
	const unsigned int maximalAllowableWorkingExperience = 100;
	return minimalAllowableWorkingExperience <= researchWorkingExperience
		&& researchWorkingExperience <= maximalAllowableWorkingExperience;
}
//********************************************************************************
void SpecificationOfWorkingExperienceOfWorker::setMinimalRequiredWorkingExperience(
	const unsigned int newMinimalRequiredWorkingExperience)
{
	if (!isValidWorkingExperience(minimalRequiredWorkingExperience))
	{
		throw new SpecificationCreatingException("Impossible to update specification-object "
			"by given 'minimalRequiredWorkingExperience' = "
			+ minimalRequiredWorkingExperience);
	}
	this->minimalRequiredWorkingExperience = newMinimalRequiredWorkingExperience;
}
//********************************************************************************
unsigned int SpecificationOfWorkingExperienceOfWorker::getMinimalRequiredWorkingExperience() const 
{
	return this->minimalRequiredWorkingExperience;
}
//********************************************************************************
bool SpecificationOfWorkingExperienceOfWorker::isMatch(const Entity &researchObject) const
{
	const Worker *researchWorker = dynamic_cast<const Worker*>(&researchObject);
	if (researchWorker == 0)
	{
		throw new SpecificationMatchingException("Given object isn't worker. Given object : "
			+ researchObject.toString());
	}
	return researchWorker->findWorkingExperience()
		>= this->minimalRequiredWorkingExperience;
}
//********************************************************************************
SpecificationOfWorkingExperienceOfWorker::~SpecificationOfWorkingExperienceOfWorker()
{

}
//********************************************************************************