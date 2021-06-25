// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include "WorkerReader.h"
#include "WorkerParser.h"
#include "WorkerCreator.h"
#include "Worker.h"
#include "WorkerRepository.h"
#include "SpecificationOfBiggerSalaryOfWorker.h"
#include "SpecificationOfPositionOfWorker.h"
#include "SpecificationOfWorkingExperienceOfWorker.h"
#include "Writer.h"

using namespace std;

int main()
{
	//reader
	ReaderInterface *reader = new WorkerReader();
	vector<string> *descriptionsOfWorkers = reader->read("data",
		"descriptionsofworkers.txt");
	for (vector<string>::iterator runner = descriptionsOfWorkers->begin();
		runner != descriptionsOfWorkers->end(); runner++)
	{
		cout << *runner << endl;
	}
	delete reader;
	//parser
	ParserInterface *parser = new WorkerParser();
	vector<vector<string>*> *descriptionOfWorkersByProperties = new vector<vector<string>*>(); //delete
	for (vector<string>::iterator runner = descriptionsOfWorkers->begin();
		runner != descriptionsOfWorkers->end(); runner++)
	{
		descriptionOfWorkersByProperties->push_back(
			parser->parseDescription(*runner));
	}
	delete parser;
	delete descriptionsOfWorkers;
	//creator
	CreatorInterface *creator = new WorkerCreator();
	vector<Worker*> *workers = new vector<Worker*>();  
	for (vector<vector<string>*>::iterator runner = descriptionOfWorkersByProperties->begin();
		runner != descriptionOfWorkersByProperties->end(); runner++)
	{
		Entity *object = creator->createObject(**runner);
		Worker *worker = static_cast<Worker*>(object);
		workers->push_back(worker);
	}
	delete creator;
	//repository
	Repository &repository = WorkerRepository::getLearnerRepository();  
	for (vector<Worker*>::iterator runner = workers->begin();
		runner != workers->end(); runner++)
	{
		repository.add(**runner);
	}
	//writer
	const string requiredPosition = "manager";
	Specification *specificationOfPositionOfWorker 
		= new SpecificationOfPositionOfWorker(requiredPosition);      //delete
	vector<Entity*> *workersOfPositionOfSpecification
		= repository.findObjects(*specificationOfPositionOfWorker);
	vector<Writeable*> *writeableWorkers = new vector<Writeable*>();
	for (vector<Entity*>::iterator runner = workersOfPositionOfSpecification->begin();
		runner != workersOfPositionOfSpecification->end();
		runner++) 
	{
		writeableWorkers->push_back(static_cast<Writeable*>(*runner));
	}
	Writer *writer = new Writer();          //delete
	writer->writeObjects(*writeableWorkers, "data", "firstsubtask.txt", "\n");

	const double minimalRequiredSalary = 80000;
	Specification *specificationOfMinimalRequiredSalary
		= new SpecificationOfBiggerSalaryOfWorker(minimalRequiredSalary); //delete
	vector<Entity*> *workersOfMinimalRequiredSalaryOfSpecification
		= repository.findObjects(*specificationOfMinimalRequiredSalary);
	delete writeableWorkers;
    writeableWorkers = new vector<Writeable*>();  
	for (vector<Entity*>::iterator runner = workersOfMinimalRequiredSalaryOfSpecification->begin();
		runner != workersOfMinimalRequiredSalaryOfSpecification->end();
		runner++)
	{
		writeableWorkers->push_back(static_cast<Writeable*>(*runner));
	}
	writer->writeObjects(*writeableWorkers, "data", "secondsubtask.txt", "\n");

	const unsigned int minimalRequiredExperience = 10;
	Specification *specificationOfMinimalRequiredExperience
		= new SpecificationOfWorkingExperienceOfWorker(minimalRequiredExperience);
	vector<Entity*> *workersOfMinimalRequiredExperienceOfSpecification
		= repository.findObjects(*specificationOfMinimalRequiredExperience);
	delete writeableWorkers;
	writeableWorkers = new vector<Writeable*>();   //delete
	for (vector<Entity*>::iterator runner = workersOfMinimalRequiredExperienceOfSpecification->begin();
		runner != workersOfMinimalRequiredExperienceOfSpecification->end();
		runner++)
	{
		writeableWorkers->push_back(static_cast<Writeable*>(*runner));
	}
	writer->writeObjects(*writeableWorkers, "data", "thirdsubtask.txt", "\n");



	system("pause");
    return 0;
}

