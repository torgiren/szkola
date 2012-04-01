#ifndef __CWYM__
#define __CWYM__
#include <iostream>
using namespace std;
class CWym
{
	public:
		friend class CTabWym;
		friend ostream& operator<<(ostream& out, CWym& co);
		CWym(int l=0,int m=1);
		CWym operator+(CWym& wym);
	private:
		int itsL;
		int itsM;
};
#endif
