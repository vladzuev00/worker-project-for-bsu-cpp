#include "stdafx.h"
#include "WorkerRepository.h"
#include "UnsupportedOperationException.h"

//**************************************************************************************
WorkerRepository::WorkerRepository(const WorkerRepository &other)
{
	throw new UnsupportedOperationException("Impossible to copy repository.");
}
//**************************************************************************************
const WorkerRepository& WorkerRepository::operator=(const WorkerRepository &other)
{
	throw new UnsupportedOperationException("Impossible to copy repository.");
}
//**************************************************************************************
WorkerRepository::WorkerRepository() : Repository::Repository()
{

}
//**************************************************************************************
vector<Entity*>* WorkerRepository::findObjects(const Specification &specification) const
{
	vector<Entity*> *workersInRepository = this->getObjects();
	vector<Entity*> *suitableWorkers = new vector<Entity*>();
	Worker *runnerWorker;
	for (vector<Entity*>::iterator runnerObject = workersInRepository->begin();
		runnerObject != workersInRepository->end(); runnerObject++)
	{
		runnerWorker = static_cast<Worker*>(*runnerObject);
		if (specification.isMatch(*runnerWorker))
		{
			suitableWorkers->push_back(runnerWorker);
		}
	}
	return suitableWorkers;
}
//**************************************************************************************
WorkerRepository& WorkerRepository::getLearnerRepository() 
{
	static WorkerRepository workerRepository;
	return workerRepository;
}
//**************************************************************************************
WorkerRepository::~WorkerRepository()
{

}
//**************************************************************************************