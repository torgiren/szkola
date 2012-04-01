#include "logger.h"
#include <sstream>
#include <ctime>
#include <iostream>
Logger::Logger():
itsMutex(PTHREAD_MUTEX_INITIALIZER)
{
	SetPath("out.log");
//	itsMutex=PTHREAD_MUTEX_INITIALIZER;
};
void Logger::Reopen()
{
	itsStream.close();
	itsStream.open(itsPath.c_str(),std::ios::out);
};
void Logger::Log(std::string data)
{
	std::stringstream ss;
	time_t now;
	time(&now);
	ss<<(difftime(now,itsStart))<<": "<<data<<std::endl;
	Lock();
	itsStream<<ss.str();
	itsStream.flush();
	Unlock();
};
