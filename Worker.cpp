#include "stdafx.h"
#include "Worker.h"
#include <climits>
#include "WorkerCreatingException.h"
#include "WorkerUpdatingException.h"

//*******************************************************************************************
Worker::Worker() 
	: Entity::Entity(),
	  firstName(new string(Worker::VALUE_OF_NOT_DEFINED_FIRST_NAME)),
	  lastName(new string(Worker::VALUE_OF_NOT_DEFINED_LAST_NAME)),
	  patronymic(new string(Worker::VALUE_OF_NOT_DEFINED_PATRONYMIC)),
	  position(new string(Worker::VALUE_OF_NOT_DEFINED_POSITION)),
	  yearOfStartWorking(Worker::VALUE_OF_NOT_DEFINED_YEAR_OF_START_WORKING),
	  salary(Worker::VALUE_OF_NOT_DEFINED_SALARY)
{

}
//*******************************************************************************************
const string Worker::VALUE_OF_NOT_DEFINED_FIRST_NAME = "isn't defined";
//*******************************************************************************************
const string Worker::VALUE_OF_NOT_DEFINED_LAST_NAME = "isn't defined";
//*******************************************************************************************
const string Worker::VALUE_OF_NOT_DEFINED_PATRONYMIC = "isn't defined";
//*******************************************************************************************
const string Worker::VALUE_OF_NOT_DEFINED_POSITION = "isn't defined";
//*******************************************************************************************
const unsigned int Worker::VALUE_OF_NOT_DEFINED_YEAR_OF_START_WORKING = -1;
//*******************************************************************************************
const double Worker::VALUE_OF_NOT_DEFINED_SALARY = -1;
//*******************************************************************************************
const WorkerValidator Worker::WORKER_VALIDATOR = WorkerValidator();
//*******************************************************************************************
Worker::Worker(const string &firstName, const string &lastName, const string &patronymic,
	const string &position, const unsigned int yearOfStartWorking, const double salary) 
	: Entity::Entity()
{
	if ( !(Worker::WORKER_VALIDATOR.isValidFirstName(firstName)
		&& Worker::WORKER_VALIDATOR.isValidLastName(lastName)
		&& Worker::WORKER_VALIDATOR.isValidPatronymic(patronymic)
		&& Worker::WORKER_VALIDATOR.isValidPosition(position)
		&& Worker::WORKER_VALIDATOR.isValidYearOfStartWorking(yearOfStartWorking)
		&& Worker::WORKER_VALIDATOR.isValidSalary(salary)))
	{
		throw new WorkerCreatingException("Impossible to create worker with given properties.");
	}
	this->firstName = new string(firstName);
	this->lastName = new string(lastName);
	this->patronymic = new string(patronymic);
	this->position = new string(position);
	this->yearOfStartWorking = yearOfStartWorking;
	this->salary = salary;
}
//*******************************************************************************************
Worker::Worker(const Worker &other) 
	: Entity::Entity(),
	  firstName(new string(*other.firstName)),
	  lastName(new string(*other.lastName)),
	  patronymic(new string(*other.patronymic)),
	  position(new string(*other.position)),
	  yearOfStartWorking(other.yearOfStartWorking),
	  salary(other.salary)
{

}
//*******************************************************************************************
void Worker::setFirstName(const string &newFirstName)
{
	if (!Worker::WORKER_VALIDATOR.isValidFirstName(newFirstName))
	{
		throw new WorkerUpdatingException("Impossible to update 'firstName' of worker"
			" by '" + newFirstName + "'.");
	}
	*this->firstName = newFirstName;
}
//*******************************************************************************************
const string& Worker::getFirstName() const 
{
	return *this->firstName;
}
//*******************************************************************************************
void Worker::setLastName(const string &newLastName) 
{
	if (!Worker::WORKER_VALIDATOR.isValidLastName(newLastName))
	{
		throw new WorkerUpdatingException("Impossible to update 'lastName' of worker"
			" by '" + newLastName + "'.");
	}
	*this->lastName = newLastName;
}
//*******************************************************************************************
const string& Worker::getLastName() const 
{
	return *this->lastName;
}
//*******************************************************************************************
void Worker::setPatronymic(const string &newPatronymic) 
{
	if (!Worker::WORKER_VALIDATOR.isValidPatronymic(newPatronymic))
	{
		throw new WorkerUpdatingException("Impossible to update 'patronymic' of worker"
			" by '" + newPatronymic + "'.");
	}
	*this->patronymic = newPatronymic;
}
//*******************************************************************************************
const string& Worker::getPatronymic() const 
{
	return *this->patronymic;
}
//*******************************************************************************************
void Worker::setPosition(const string &newPosition)
{
	if (!Worker::WORKER_VALIDATOR.isValidPosition(newPosition))
	{
		throw new WorkerUpdatingException("Impossible to update 'position' of worker"
			" by '" + newPosition + "'.");
	}
	*this->position = newPosition;
}
//*******************************************************************************************
const string& Worker::getPosition() const
{
	return *this->position;
}
//*******************************************************************************************
void Worker::setYearOfStartWorking(const unsigned int newYearOfStartWorking) 
{
	if (!Worker::WORKER_VALIDATOR.isValidYearOfStartWorking(newYearOfStartWorking))
	{
		throw new WorkerUpdatingException("Impossible to update 'yearOfStartWorking' of worker"
			" by '" + std::to_string(newYearOfStartWorking) + "'.");
	}
	this->yearOfStartWorking = newYearOfStartWorking;
}
//*******************************************************************************************
unsigned int Worker::getYearOfStartWorking() const 
{
	return this->yearOfStartWorking;
}
//*******************************************************************************************
void Worker::setSalary(const double newSalary) 
{
	if (!Worker::WORKER_VALIDATOR.isValidSalary(newSalary))
	{
		throw new WorkerUpdatingException("Impossible to update 'salary' of worker"
			" by '" + std::to_string(newSalary) + "'.");
	}
	this->salary = newSalary;
}
//*******************************************************************************************
double Worker::getSalary() const 
{
	return this->salary;
}
//*******************************************************************************************
unsigned int Worker::findWorkingExperience() const
{
	return Worker::findCurrentYear() - this->yearOfStartWorking;
}
//*******************************************************************************************
unsigned int Worker::findCurrentYear()
{
	tm ptr;
	time_t lt = time(nullptr);
	localtime_s(&ptr, &lt);
	const unsigned int startingPoint = 1900;
	return ptr.tm_year + startingPoint;
}
//*******************************************************************************************
string Worker::toString() const
{
	string descriptionOfWorker = this->Entity::toString();
	descriptionOfWorker.append("[firstName = " + *this->firstName);
	descriptionOfWorker.append(", lastName = " + *this->lastName);
	descriptionOfWorker.append(", patronymic = " + *this->patronymic);
	descriptionOfWorker.append(", position = " + *this->position);
	descriptionOfWorker.append(", yearOfStartWorking = "
		+ (this->yearOfStartWorking != Worker::VALUE_OF_NOT_DEFINED_YEAR_OF_START_WORKING
			? std::to_string(this->yearOfStartWorking) : "isn't defined"));
	descriptionOfWorker.append(", salary = " 
		+ (this->salary != Worker::VALUE_OF_NOT_DEFINED_SALARY
		? std::to_string(this->salary) : "isn't defined"));
	descriptionOfWorker.append("]");
	return descriptionOfWorker;
}
//*******************************************************************************************
bool Worker::operator==(const Worker &other) const 
{
	if (this == &other) 
	{
		return true;
	}
    
	return *this->firstName == *other.firstName
		&& *this->lastName == *other.lastName
		&& *this->patronymic == *other.patronymic
		&& *this->position == *other.position
		&& this->yearOfStartWorking == other.yearOfStartWorking
		&& this->salary == other.salary;
}
//*******************************************************************************************
const Worker& Worker::operator=(const Worker &other) 
{
	if (this == &other)
	{
		return *this;
	}
	*this->firstName = *other.firstName;
	*this->lastName = *other.lastName;
	*this->patronymic = *other.patronymic;
	*this->position = *other.position;
	this->yearOfStartWorking = other.yearOfStartWorking;
	this->salary = other.salary;
	return *this;
}
//*******************************************************************************************
Worker::~Worker() 
{
	delete this->firstName;
	delete this->lastName;
	delete this->patronymic;
}
//*******************************************************************************************
using std::regex_match;
//*******************************************************************************************
bool WorkerValidator::isValidFirstName(const string &researchFirstName) const 
{
	return regex_match(researchFirstName, WorkerValidator::REGULAR_EXPRESSION_OF_FIRST_NAME)
		&& WorkerValidator::MINIMAL_ALLOWABLE_LENGTH_OF_FIRST_NAME <= researchFirstName.length()
		&& researchFirstName.length() <= WorkerValidator::MAXIMAL_ALLOWABLE_LENGTH_OF_FIRST_NAME;
}
//*******************************************************************************************
const regex WorkerValidator::REGULAR_EXPRESSION_OF_FIRST_NAME = regex(R"([A-Za-z]+)");
//*******************************************************************************************
const unsigned int WorkerValidator::MINIMAL_ALLOWABLE_LENGTH_OF_FIRST_NAME = 2;
//*******************************************************************************************
const unsigned int WorkerValidator::MAXIMAL_ALLOWABLE_LENGTH_OF_FIRST_NAME = 20;
//*******************************************************************************************
bool WorkerValidator::isValidLastName(const string &researchLastName) const 
{
	return regex_match(researchLastName, WorkerValidator::REGULAR_EXPRESSION_OF_LAST_NAME)
		&& WorkerValidator::MINIMAL_ALLOWABLE_LENGTH_OF_LAST_NAME <= researchLastName.length()
		&& researchLastName.length() <= WorkerValidator::MAXIMAL_ALLOWABLE_LENGTH_OF_LAST_NAME;
}
//*******************************************************************************************
const regex WorkerValidator::REGULAR_EXPRESSION_OF_LAST_NAME = regex(R"([A-Za-z]+)");
//*******************************************************************************************
const unsigned int WorkerValidator::MINIMAL_ALLOWABLE_LENGTH_OF_LAST_NAME = 2;
//*******************************************************************************************
const unsigned int WorkerValidator::MAXIMAL_ALLOWABLE_LENGTH_OF_LAST_NAME = 20;
//*******************************************************************************************
bool WorkerValidator::isValidPatronymic(const string &researchPatronymic) const
{
	return regex_match(researchPatronymic, WorkerValidator::REGULAR_EXPRESSION_OF_PATRONYMIC)
		&& WorkerValidator::MINIMAL_ALLOWABLE_LENGTH_OF_PATRONYMIC <= researchPatronymic.length()
		&& researchPatronymic.length() <= WorkerValidator::MAXIMAL_ALLOWABLE_LENGTH_OF_PATRONYMIC;
}
//*******************************************************************************************
const regex WorkerValidator::REGULAR_EXPRESSION_OF_PATRONYMIC = regex(R"([A-Za-z]+)");
//*******************************************************************************************
const unsigned int WorkerValidator::MINIMAL_ALLOWABLE_LENGTH_OF_PATRONYMIC = 2;
//*******************************************************************************************
const unsigned int WorkerValidator::MAXIMAL_ALLOWABLE_LENGTH_OF_PATRONYMIC = 20;
//*******************************************************************************************
bool WorkerValidator::isValidPosition(const string &researchPosition) const
{
	return regex_match(researchPosition, WorkerValidator::REGULAR_EXPRESSION_OF_POSITION)
		&& WorkerValidator::MINIMAL_ALLOWABLE_LENGTH_OF_POSITION <= researchPosition.length()
		&& researchPosition.length() <= WorkerValidator::MAXIMAL_ALLOWABLE_LENGTH_OF_POSITION;
}
//*******************************************************************************************
const regex WorkerValidator::REGULAR_EXPRESSION_OF_POSITION = regex(R"([A-Za-z]+)");
//*******************************************************************************************
const unsigned int WorkerValidator::MINIMAL_ALLOWABLE_LENGTH_OF_POSITION = 2;
//*******************************************************************************************
const unsigned int WorkerValidator::MAXIMAL_ALLOWABLE_LENGTH_OF_POSITION = 20;
//*******************************************************************************************
bool WorkerValidator::isValidYearOfStartWorking(const unsigned int researchYearOfStartWorking) const
{
	return WorkerValidator::MINIMAL_ALLOWABLE_YEAR_OF_START_WORKING <= researchYearOfStartWorking
		&& researchYearOfStartWorking <= WorkerValidator::MAXIMAL_ALLOWABLE_YEAR_OF_START_WORKING;
}
//*******************************************************************************************
const unsigned int WorkerValidator::MINIMAL_ALLOWABLE_YEAR_OF_START_WORKING 
	= WorkerValidator::findCurrentYear() - 100;
//*******************************************************************************************
unsigned int WorkerValidator::findCurrentYear() 
{
	tm ptr;
	time_t lt = time(nullptr);
	localtime_s(&ptr, &lt);
	const unsigned int startingPoint = 1900;
	return ptr.tm_year + startingPoint;
}
//*******************************************************************************************
const unsigned int  WorkerValidator::MAXIMAL_ALLOWABLE_YEAR_OF_START_WORKING 
	= WorkerValidator::findCurrentYear();
//*******************************************************************************************
bool WorkerValidator::isValidSalary(const double researchSalary) const
{
	return WorkerValidator::MINIMAL_ALLOWABLE_SALARY <= researchSalary
		&& researchSalary <= WorkerValidator::MAXIMAL_ALLOWABLE_SALARY;
}
//*******************************************************************************************
const double WorkerValidator::MINIMAL_ALLOWABLE_SALARY = 0;
//*******************************************************************************************
const double WorkerValidator::MAXIMAL_ALLOWABLE_SALARY = 999999;
//*******************************************************************************************
bool WorkerValidator::areValidDescriptionsOfPropertiesOfWorker(
	const vector<string> &descriptionsOfPropertiesOfWorker) const
{
	return descriptionsOfPropertiesOfWorker.size() == WorkerValidator::ALLOWABLE_AMOUNT_OF_PROPERTIES_OF_WORKER
		&& this->isValidFirstName(descriptionsOfPropertiesOfWorker[WorkerValidator::INDEX_OF_DESCRIPTION_OF_FIRST_NAME])
		&& this->isValidLastName(descriptionsOfPropertiesOfWorker[WorkerValidator::INDEX_OF_DESCRIPTION_OF_LAST_NAME])
		&& this->isValidPatronymic(descriptionsOfPropertiesOfWorker[WorkerValidator::INDEX_OF_DESCRIPTION_OF_PATRONYMIC])
		&& this->isValidPosition(descriptionsOfPropertiesOfWorker[WorkerValidator::INDEX_OF_DESCRIPTION_OF_POSITION])
		&& this->isValidDescriptionOfYearOfStartWorking(descriptionsOfPropertiesOfWorker[WorkerValidator::INDEX_OF_DESCRIPTION_OF_YEAR_OF_START_WORKING])
		&& this->isValidDescriptionOfSalary(descriptionsOfPropertiesOfWorker[WorkerValidator::INDEX_OF_DESCRIPTION_OF_SALARY]);
}
//*******************************************************************************************
const unsigned int WorkerValidator::ALLOWABLE_AMOUNT_OF_PROPERTIES_OF_WORKER = 6;
//*******************************************************************************************
const unsigned int WorkerValidator::INDEX_OF_DESCRIPTION_OF_FIRST_NAME = 0;
//*************************************************************************************
const unsigned int WorkerValidator::INDEX_OF_DESCRIPTION_OF_LAST_NAME = 1;
//*************************************************************************************
const unsigned int WorkerValidator::INDEX_OF_DESCRIPTION_OF_PATRONYMIC = 2;
//*************************************************************************************
const unsigned int WorkerValidator::INDEX_OF_DESCRIPTION_OF_POSITION = 3;
//*************************************************************************************
const unsigned int WorkerValidator::INDEX_OF_DESCRIPTION_OF_YEAR_OF_START_WORKING = 4;
//*************************************************************************************
const unsigned int WorkerValidator::INDEX_OF_DESCRIPTION_OF_SALARY = 5;
//*******************************************************************************************
bool WorkerValidator::isValidDescriptionOfYearOfStartWorking(const string &researchDescription) const
{
	try 
	{
		std::atoi(researchDescription.data());
	}
	catch (std::exception const &exception) 
	{
		return false;
	}
	return true;
}
//*******************************************************************************************
bool WorkerValidator::isValidDescriptionOfSalary(const string &researchDescription) const 
{
	try
	{
		std::atoi(researchDescription.data());
	}
	catch (std::exception const &exception)
	{
		return false;
	}
	return true;
}
//*******************************************************************************************
