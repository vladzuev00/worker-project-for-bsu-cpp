#include "stdafx.h"
#include "SpecificationOfBiggerSalaryOfWorker.h"
#include "SpecificationCreatingException.h"
#include "SpecificationUpdatingException.h"
#include "SpecificationMatchingException.h"

//****************************************************************************************
SpecificationOfBiggerSalaryOfWorker::SpecificationOfBiggerSalaryOfWorker(
	const double minimalRequiredSalary) : Specification::Specification()
{
	if (!SpecificationOfBiggerSalaryOfWorker::WORKER_VALIDATOR
		.isValidSalary(minimalRequiredSalary)) 
	{
		throw new SpecificationCreatingException("Impossible to create specification with"
			" given 'minimalRequiredSalary' = " + std::to_string(minimalRequiredSalary));
	}
	this->minimalRequiredSalary = minimalRequiredSalary;
}
//****************************************************************************************
const WorkerValidator SpecificationOfBiggerSalaryOfWorker::WORKER_VALIDATOR = WorkerValidator();
//****************************************************************************************
void SpecificationOfBiggerSalaryOfWorker::setMinimalRequiredSalary(
	const double newMinimalRequiredSalary)
{
	if (!SpecificationOfBiggerSalaryOfWorker::WORKER_VALIDATOR
		.isValidSalary(newMinimalRequiredSalary))
	{
		throw new SpecificationCreatingException("Impossible to update specification by"
			" given 'minimalRequiredSalary' = " + std::to_string(newMinimalRequiredSalary));
	}
	this->minimalRequiredSalary = newMinimalRequiredSalary;
}
//****************************************************************************************
double SpecificationOfBiggerSalaryOfWorker::getMinimalRequiredSalary() const 
{
	return this->minimalRequiredSalary;
}
//****************************************************************************************
bool SpecificationOfBiggerSalaryOfWorker::isMatch(const Entity &researchObject) const
{
	const Worker *researchWorker = dynamic_cast<const Worker*>(&researchObject);
	if (researchWorker == 0)
	{
		throw new SpecificationMatchingException("Given object isn't worker. Given object : "
			+ researchObject.toString());
	}
	return researchWorker->getSalary() >= this->minimalRequiredSalary;
}
//****************************************************************************************
SpecificationOfBiggerSalaryOfWorker::~SpecificationOfBiggerSalaryOfWorker()
{

}
//****************************************************************************************