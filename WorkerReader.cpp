#include "stdafx.h"
#include "WorkerReader.h"
#include <fstream>
#include "ReadingException.h"

using std::ifstream;

//*******************************************************
const char WorkerReader::LINE_SEPARATOR = '\n\r';
//**************************************************************************************************
WorkerReader::WorkerReader()
{

}
//*******************************************************
vector<string>* WorkerReader::read(const string &filePath, const string &fileName) const
{
	ifstream inputFileStream(filePath + ReaderInterface::findFileSeparator() + fileName);
	if (!inputFileStream.is_open())
	{
		throw new ReadingException("Impossible to open file: " + filePath + fileName);
	}
	vector<string>* workersDescriptions = new vector<string>();
	string workerDescription;
	while (getline(inputFileStream, workerDescription, WorkerReader::LINE_SEPARATOR))
	{
		workersDescriptions->push_back(workerDescription);
	}
	inputFileStream.close();
	return workersDescriptions;
}
//*******************************************************
WorkerReader::~WorkerReader()
{

}
//*******************************************************
