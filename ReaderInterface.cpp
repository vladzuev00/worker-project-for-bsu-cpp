#include "stdafx.h"
#include "ReaderInterface.h"

//**************************************************************************************************
ReaderInterface::ReaderInterface()
{

}
//**************************************************************************************************
char ReaderInterface::findFileSeparator()
{
#ifdef _WIN32
	return '\\';
#else
	return '/';
#endif
}
//*******************************************************
ReaderInterface::~ReaderInterface()
{

}
//*******************************************************