#ifndef __READER_H
#define __READER_H
#include <string>
#include "kontener.h"
#include "exceptions.h"
namespace Reader
{
	Kontener* ReadMap(std::string path);
};
#endif

