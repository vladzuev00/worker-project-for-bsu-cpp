#ifndef WORKERREADER_H
#define WORKERREADER_H

#include "ReaderInterface.h"

//*******************************************************
class WorkerReader : public ReaderInterface
{
private:
	static const char LINE_SEPARATOR;
public:
	WorkerReader();
public:
	virtual vector<string>* read(const string &filePath, const string &fileName) const override;
public:
	virtual ~WorkerReader() override;
};
//*******************************************************
#endif WORKERREADER_H
