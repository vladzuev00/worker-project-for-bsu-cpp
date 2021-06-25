#ifndef SPECIFICATIONOFBIGGERSALARYOFWORKER_H
#define SPECIFICATIONOFBIGGERSALARYOFWORKER_H

#include "Specification.h"
#include "Worker.h"

//****************************************************************************************
class SpecificationOfBiggerSalaryOfWorker : public Specification
{
private:
	double minimalRequiredSalary;
private:
	static const WorkerValidator WORKER_VALIDATOR;
public:
	SpecificationOfBiggerSalaryOfWorker(const double minimalRequiredSalary);
public:
	void setMinimalRequiredSalary(const double newMinimalRequiredSalary);
	double getMinimalRequiredSalary() const;
public:
	virtual bool isMatch(const Entity &researchObject) const override;
public:
	virtual ~SpecificationOfBiggerSalaryOfWorker() override;
};
//****************************************************************************************

#endif SPECIFICATIONOFBIGGERSALARYOFWORKER_H