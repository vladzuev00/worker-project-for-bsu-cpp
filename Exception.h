#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

//********************************************************************************
class Exception                            
{
private:
	std::string *description;
	Exception *cause;
private:
	static const std::string NOT_DEFINED_DESCRIPTION;
public:
	Exception();
	Exception(const std::string &description);
	Exception(Exception * const cause);
	Exception(const std::string &description, Exception * const cause);
	//TODO Exception::Exception(const Exception&) in all hierarchy
public:
	const std::string& getDescription() const;
	Exception* getCause() const;
	//TODO Exception::operator=(const Exception&) in all hierarchy
public:
	virtual ~Exception() = 0;
};
//********************************************************************************

#endif EXCEPTION_H