#ifndef WORKERPARSER_H
#define WORKERPARSER_H

#include "ParserInterface.h"
#include <string>
#include <regex>

//***********************************************************************************
class WorkerParserValidator;
//***********************************************************************************
class WorkerParser : public ParserInterface
{
private:
	static const char PROPERTY_SEPARATOR;
	static const WorkerParserValidator WORKER_PARSER_VALIDATOR;
public:
	WorkerParser();
public:
	std::vector<std::string>* parseDescription(
		const std::string &workerDescription) const override; 
public:
	~WorkerParser();
};
//***********************************************************************************
class WorkerParserValidator 
{
private:
	static const std::regex REGULAR_EXPRESSION_OF_WORKER_DESCRIPTION;
public:
	bool isValidWorkerDescription(const std::string &researchWorkerDescription) const;
};
//***********************************************************************************

#endif WORKERPARSER_H