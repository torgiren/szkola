#ifndef __SILNIACZ_H
#define __SILNIACZ_H
#include <map>
class Silniacz
{
	public:
		static Silniacz* GetInstance() {static Silniacz* base=new Silniacz();return base;};
		long long Policz(int n);
	private:
		Silniacz();
		long long Wylicz(int n);
		std::map<int,long> itsWartosci;
		
};
#endif
