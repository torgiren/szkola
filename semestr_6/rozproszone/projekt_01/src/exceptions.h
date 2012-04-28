#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H
#include <string>
class FileOpenError
{
	public:
		FileOpenError(std::string path):
			itsPath(path)
		{
		};
		std::string itsPath;
};
class FileSyntaxError
{
	public:
		FileSyntaxError(std::string path,std::string line,std::string desc="no description")
		{
			itsPath=path;
			itsLine=line;
			itsDesc=desc;
		};
		std::string itsPath;
		std::string itsLine;
		std::string itsDesc;
};
class OutOfBound
{
	public:
		OutOfBound(std::string desc)
		{
			itsDesc=desc;
		};
		std::string itsDesc;
};
#endif
