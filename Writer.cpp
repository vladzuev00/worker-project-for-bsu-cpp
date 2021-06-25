#include "stdafx.h"
#include "Writer.h"
#include <fstream>

//*****************************************************************************************
char Writer::findFileSeparator()     //в ReaderInterface такой же метод
{
#ifdef _WIN32
	return '\\';
#else
	return '/';
#endif
}
//*****************************************************************************************
Writer::Writer()
{

}
//*****************************************************************************************
void Writer::writeObjects(const std::vector<Writeable*> &objects,   //лучше принять указатель Writeable на массив
	const std::string &pathOfDocument, const std::string &nameOfDocument,
	const std::string &separatorOfObjects) const 
{
	std::ofstream outputFileStream;
	outputFileStream.open(pathOfDocument + Writer::findFileSeparator() + nameOfDocument);
	if (!outputFileStream.is_open()) 
	{
		//throw WritingException();
	}
	for (std::vector<Writeable*>::const_iterator runner = objects.begin();          //заменить везде где нужно на const_iterator как здесь
		runner != objects.end(); runner++)
	{
		outputFileStream << (*runner)->toString() << separatorOfObjects;
	}
}
//*****************************************************************************************
Writer::~Writer()
{

}
//*****************************************************************************************