#include "wyjatki.h"
#include "cwym.h"
ostream& operator<<(ostream& out, CWym& co)
{
	out<<co.itsL<<"/"<<co.itsM;
	return out;
};
CWym::CWym(int l,int m):
itsL(l),itsM(m)
{
		if(m==0) throw EDzielZero();
};
CWym CWym::operator+(CWym& wym)
{
	int m;
	m=itsM*wym.itsM;
	int l1,l2;
	l1=itsL*wym.itsM;
	l2=wym.itsL*itsM;
	return CWym(l1+l2,m);
};
