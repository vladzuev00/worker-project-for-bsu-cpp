#include "stdafx.h"
#include "WorkerParser.h"
#include <iostream>
#include "ParsingException.h"

//***********************************************************************************
WorkerParser::WorkerParser()
{

}
//***********************************************************************************
std::vector<std::string>* WorkerParser::parseDescription(const std::string &workerDescription) const
{   
	if (!WorkerParser::WORKER_PARSER_VALIDATOR.isValidWorkerDescription(workerDescription))
	{
		throw new ParsingException("Impossible to parse given description of worker.");
	}
	std::vector<std::string> *workerDescriptionByProperties = new std::vector<std::string>();
	int workerDescriptionLength = workerDescription.size();
	int startIndexPropertyDescription = 0;
	for (int i = 0; i < workerDescriptionLength; i++)
	{
		if (workerDescription[i] == WorkerParser::PROPERTY_SEPARATOR || i == workerDescriptionLength - 1)
		{
			workerDescriptionByProperties->push_back(workerDescription.substr(startIndexPropertyDescription,
				(i != workerDescriptionLength - 1)
				? i - startIndexPropertyDescription
				: i - startIndexPropertyDescription + 1));
			startIndexPropertyDescription = i + 1;
		}
	}
	return workerDescriptionByProperties;
}
//***********************************************************************************
const char WorkerParser::PROPERTY_SEPARATOR = ' ';
//***********************************************************************************
const WorkerParserValidator WorkerParser::WORKER_PARSER_VALIDATOR = WorkerParserValidator();
//***********************************************************************************
WorkerParser::~WorkerParser()
{

}
//***********************************************************************************
bool WorkerParserValidator::isValidWorkerDescription(
	const std::string &researchWorkerDescription) const
{
	return std::regex_match(researchWorkerDescription,
		WorkerParserValidator::REGULAR_EXPRESSION_OF_WORKER_DESCRIPTION);
}
//***********************************************************************************
const std::regex WorkerParserValidator::REGULAR_EXPRESSION_OF_WORKER_DESCRIPTION
	= std::regex(R"(([A-Za-z]+ ){4}\d{4} \d+)");
//***********************************************************************************
