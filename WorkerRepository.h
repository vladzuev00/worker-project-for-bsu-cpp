#ifndef WORKERREPOSITORY_H
#define WORKERREPOSITORY_H

#include "Worker.h"
#include "Repository.h"

//**************************************************************************************
class WorkerRepository : public Repository
{
private:
	static const WorkerValidator WORKER_VALIDATOR;
private:
	WorkerRepository();
	WorkerRepository(const WorkerRepository &other);
private:
	const WorkerRepository& operator=(const WorkerRepository &other);
public:
	virtual vector<Entity*>* findObjects(const Specification &specification) const override;
public:
	static WorkerRepository& getLearnerRepository();
public:
	virtual ~WorkerRepository() override;
};
//**************************************************************************************

#endif WORKERREPOSITORY_H