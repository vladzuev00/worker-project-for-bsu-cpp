#include "stdafx.h"
#include "Writer.h"
#include <fstream>

//*****************************************************************************************
char Writer::findFileSeparator()     //� ReaderInterface ����� �� �����
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
void Writer::writeObjects(const std::vector<Writeable*> &objects,   //����� ������� ��������� Writeable �� ������
	const std::string &pathOfDocument, const std::string &nameOfDocument,
	const std::string &separatorOfObjects) const 
{
	std::ofstream outputFileStream;
	outputFileStream.open(pathOfDocument + Writer::findFileSeparator() + nameOfDocument);
	if (!outputFileStream.is_open()) 
	{
		//throw WritingException();
	}
	for (std::vector<Writeable*>::const_iterator runner = objects.begin();          //�������� ����� ��� ����� �� const_iterator ��� �����
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