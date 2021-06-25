#include "stdafx.h"
#include "WorkerCreator.h"
#include "WorkerCreatingException.h"

//*************************************************************************************
WorkerCreator::WorkerCreator()
{

}
//*************************************************************************************
Entity* WorkerCreator::createObject(                      
	const std::vector<std::string> &descriptionsOfPropertiesOfWorker) const 
{
	if (!WorkerCreator::WORKER_VALIDATOR
		.areValidDescriptionsOfPropertiesOfWorker(descriptionsOfPropertiesOfWorker))
	{
		throw new WorkerCreatingException(
			"Impossible to create worker by given descriptions of properties of worker.");
	}
	const std::string &firstName 
		= descriptionsOfPropertiesOfWorker[WorkerCreator::INDEX_OF_DESCRIPTION_OF_FIRST_NAME];
	const std::string &lastName
		= descriptionsOfPropertiesOfWorker[WorkerCreator::INDEX_OF_DESCRIPTION_OF_LAST_NAME];
	const std::string &patronymic
		= descriptionsOfPropertiesOfWorker[WorkerCreator::INDEX_OF_DESCRIPTION_OF_PATRONYMIC];
	const std::string &position
		= descriptionsOfPropertiesOfWorker[WorkerCreator::INDEX_OF_DESCRIPTION_OF_POSITION];
	unsigned int yearOfStartWorking = std::atoi(
		descriptionsOfPropertiesOfWorker[WorkerCreator::INDEX_OF_DESCRIPTION_OF_YEAR_OF_START_WORKING].data());
	double salary = std::atoi(
		descriptionsOfPropertiesOfWorker[WorkerCreator::INDEX_OF_DESCRIPTION_OF_SALARY].data());
	return new Worker(firstName, lastName, patronymic, position, yearOfStartWorking, salary);
}
//*************************************************************************************
const WorkerValidator WorkerCreator::WORKER_VALIDATOR = WorkerValidator();
//*************************************************************************************
const unsigned int WorkerCreator::INDEX_OF_DESCRIPTION_OF_FIRST_NAME = 0;
//*************************************************************************************
const unsigned int WorkerCreator::INDEX_OF_DESCRIPTION_OF_LAST_NAME = 1;
//*************************************************************************************
const unsigned int WorkerCreator::INDEX_OF_DESCRIPTION_OF_PATRONYMIC = 2;
//*************************************************************************************
const unsigned int WorkerCreator::INDEX_OF_DESCRIPTION_OF_POSITION = 3;
//*************************************************************************************
const unsigned int WorkerCreator::INDEX_OF_DESCRIPTION_OF_YEAR_OF_START_WORKING = 4;
//*************************************************************************************
const unsigned int WorkerCreator::INDEX_OF_DESCRIPTION_OF_SALARY = 5;
//*************************************************************************************
WorkerCreator::~WorkerCreator()
{
	
}
//*************************************************************************************