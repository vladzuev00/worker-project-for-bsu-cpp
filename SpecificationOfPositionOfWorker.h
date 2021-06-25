#ifndef SPECIFICATIONOFPOSITIONOFWORKER_H
#define SPECIFICATIONOFPOSITIONOFWORKER_H

#include "Specification.h"
#include "Worker.h"

//***************************************************************************************
class SpecificationOfPositionOfWorker : public Specification
{
private:
	string *requiredPosition;
private:
	static const WorkerValidator WORKER_VALIDATOR;
public:
	SpecificationOfPositionOfWorker(const string &requiredPosition);
	SpecificationOfPositionOfWorker(const SpecificationOfPositionOfWorker &other);
public:
	void setRequiredPosition(const string &requiredPosition);
	const string& getRequiredPosition() const;
public:
	virtual bool isMatch(const Entity &researchObject) const override;
public:
	const SpecificationOfPositionOfWorker& operator=(const SpecificationOfPositionOfWorker &other);
public:
	virtual ~SpecificationOfPositionOfWorker() override;
};
//***************************************************************************************

#endif SPECIFICATIONOFPOSITIONOFWORKER_H