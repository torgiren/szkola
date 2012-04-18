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
