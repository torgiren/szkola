#ifndef __GAMMACZ_H
#define __GAMMACZ_H
#include <map>
class Gammacz
{
	public:
		double Policz(float n);
	private:
		std::map<float,double> itsWartosci;
};
#endif
