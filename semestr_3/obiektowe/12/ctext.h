#ifndef __CTEXT__
#define __CTEXT__
#include <vector>
#include <string>
using namespace std;
class CText
{
	public:
		CText operator+(CText& elem);
	public:
		CText() {};
		CText(string path);
		void WypiszN();
		void WypiszW();
	private:
		vector<string> itsText;
};
#endif
