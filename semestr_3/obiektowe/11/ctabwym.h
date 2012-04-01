#ifndef __CTABWYM__
#define __CTABWYM__
#include "cwym.h"
class CTabWym
{
	public:
		CTabWym(int i);
		~CTabWym();
		CWym& operator[](int i);
		double toDouble(int i);
		CWym Calc();
		void Print(int i);
	private:
		CWym* itsTab;
		int itsSize;
		
};
#endif
