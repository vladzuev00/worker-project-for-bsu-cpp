#ifndef SPECIFICATIONOFWORKINGEXPERIENCEOFWORKER_H
#define SPECIFICATIONOFWORKINGEXPERIENCEOFWORKER_H

#include "Specification.h"

//********************************************************************************
class SpecificationOfWorkingExperienceOfWorker : public Specification
{
private:
	unsigned int minimalRequiredWorkingExperience;
public:
	SpecificationOfWorkingExperienceOfWorker(
		const unsigned int minimalRequiredWorkingExperience);
public:
	void setMinimalRequiredWorkingExperience(
		const unsigned int newMinimalRequiredWorkingExperience);
	unsigned int getMinimalRequiredWorkingExperience() const;
public:
	virtual bool isMatch(const Entity &researchObject) const override;
public:
	virtual ~SpecificationOfWorkingExperienceOfWorker() override;
};
//********************************************************************************

#endif SPECIFICATIONOFWORKINGEXPERIENCEOFWORKER_H
