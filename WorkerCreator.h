#ifndef WORKERCREATOR_H
#define WORKERCREATOR_H

#include "CreatorInterface.h"
#include "Worker.h"

//*************************************************************************************
class WorkerCreator : public CreatorInterface
{
private:
	static const WorkerValidator WORKER_VALIDATOR;
	static const unsigned int INDEX_OF_DESCRIPTION_OF_FIRST_NAME;
	static const unsigned int INDEX_OF_DESCRIPTION_OF_LAST_NAME;
	static const unsigned int INDEX_OF_DESCRIPTION_OF_PATRONYMIC;
	static const unsigned int INDEX_OF_DESCRIPTION_OF_POSITION;
	static const unsigned int INDEX_OF_DESCRIPTION_OF_YEAR_OF_START_WORKING;
	static const unsigned int INDEX_OF_DESCRIPTION_OF_SALARY;
public:
	WorkerCreator();
public:
	virtual Entity* createObject(
		const std::vector<std::string> &descriptionsOfPropertiesOfWorker) const override;
public:
	virtual ~WorkerCreator() override;
};
//*************************************************************************************

#endif WORKERCREATOR_H