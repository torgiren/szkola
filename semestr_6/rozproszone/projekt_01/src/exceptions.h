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
