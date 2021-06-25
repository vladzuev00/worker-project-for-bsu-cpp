#ifndef WORKER_H
#define WORKER_H

#include <string>
#include <regex>
#include <vector>
#include "Entity.h"

using std::string;
using std::regex;
using std::vector;

//*******************************************************************************************
class WorkerValidator;
//*******************************************************************************************
class Worker : public Entity
{
private:
	string *firstName;
	string *lastName;
	string *patronymic;
	string *position;
	unsigned int yearOfStartWorking;
	double salary;
private:
	static const string VALUE_OF_NOT_DEFINED_FIRST_NAME;
	static const string VALUE_OF_NOT_DEFINED_LAST_NAME;
	static const string VALUE_OF_NOT_DEFINED_PATRONYMIC;
	static const string VALUE_OF_NOT_DEFINED_POSITION;
	static const unsigned int VALUE_OF_NOT_DEFINED_YEAR_OF_START_WORKING;
	static const double VALUE_OF_NOT_DEFINED_SALARY;
	static const WorkerValidator WORKER_VALIDATOR;
private:
	static unsigned int findCurrentYear();
public:
	Worker();
	Worker(const string &firstName, const string &lastName, const string &patronymic,
		const string &position, const unsigned int yearOfStartWorking, const double salary);
	Worker(const Worker &other);
public:
	void setFirstName(const string &newFirstName);
	const string& getFirstName() const;
	void setLastName(const string &newLastName);
	const string& getLastName() const;
	void setPatronymic(const string &newPatronymic);
	const string& getPatronymic() const;
	void setPosition(const string &newPosition);
	const string& getPosition() const;
	void setYearOfStartWorking(const unsigned int newYearOfStartWorking);
	unsigned int getYearOfStartWorking() const;
	void setSalary(const double newSalary);
	double getSalary() const;
	unsigned int findWorkingExperience() const;
	virtual string toString() const override;
public:
	bool operator==(const Worker &other) const;
	const Worker& operator=(const Worker &other);
public:
	virtual ~Worker() override;
};
//*******************************************************************************************
class WorkerValidator 
{
private:
	static const regex REGULAR_EXPRESSION_OF_FIRST_NAME;
	static const unsigned int MINIMAL_ALLOWABLE_LENGTH_OF_FIRST_NAME;
	static const unsigned int MAXIMAL_ALLOWABLE_LENGTH_OF_FIRST_NAME;
	static const regex REGULAR_EXPRESSION_OF_LAST_NAME;
	static const unsigned int MINIMAL_ALLOWABLE_LENGTH_OF_LAST_NAME;
	static const unsigned int MAXIMAL_ALLOWABLE_LENGTH_OF_LAST_NAME;
	static const regex REGULAR_EXPRESSION_OF_PATRONYMIC;
	static const unsigned int MINIMAL_ALLOWABLE_LENGTH_OF_PATRONYMIC;
	static const unsigned int MAXIMAL_ALLOWABLE_LENGTH_OF_PATRONYMIC;
	static const regex REGULAR_EXPRESSION_OF_POSITION;
	static const unsigned int MINIMAL_ALLOWABLE_LENGTH_OF_POSITION;
	static const unsigned int MAXIMAL_ALLOWABLE_LENGTH_OF_POSITION;
	static const unsigned int MINIMAL_ALLOWABLE_YEAR_OF_START_WORKING;
	static const unsigned int MAXIMAL_ALLOWABLE_YEAR_OF_START_WORKING;
	static const double MINIMAL_ALLOWABLE_SALARY;
	static const double MAXIMAL_ALLOWABLE_SALARY;
	static const unsigned int ALLOWABLE_AMOUNT_OF_PROPERTIES_OF_WORKER;
	static const unsigned int INDEX_OF_DESCRIPTION_OF_FIRST_NAME;
	static const unsigned int INDEX_OF_DESCRIPTION_OF_LAST_NAME;
	static const unsigned int INDEX_OF_DESCRIPTION_OF_PATRONYMIC;
	static const unsigned int INDEX_OF_DESCRIPTION_OF_POSITION;
	static const unsigned int INDEX_OF_DESCRIPTION_OF_YEAR_OF_START_WORKING;
	static const unsigned int INDEX_OF_DESCRIPTION_OF_SALARY;
private:
	static unsigned int findCurrentYear();
public:
	bool isValidFirstName(const string &researchFirstName) const;
	bool isValidLastName(const string &researchLastName) const;
	bool isValidPatronymic(const string &researchPatronymic) const;
	bool isValidYearOfStartWorking(const unsigned int researchYearOfStartWorking) const;
	bool isValidSalary(const double researchSalary) const;
	bool isValidPosition(const string &researchPosition) const;
	bool areValidDescriptionsOfPropertiesOfWorker(
		const vector<string> &descriptionsOfPropertiesOfWorker) const;
	bool isValidDescriptionOfYearOfStartWorking(const string &researchDescription) const;
	bool isValidDescriptionOfSalary(const string &researchDescription) const;
};
//*******************************************************************************************

#endif WORKER_H