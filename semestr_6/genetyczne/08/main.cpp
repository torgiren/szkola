#include <iostream>
#include <cmath>
#include <ga/ga.h>
using namespace std;
double funkcja(double x, double y)
{
	const double a=1,b=2;
	return y*b*sin(y*y)+x*sin(a*x);
};
float objective(GAGenome& gen);
int main(int argc, char* argv[])
{
	GABin2DecPhenotype map;
	map.add(30,0,10);
	map.add(30,0,10);
	GABin2DecGenome genome(map,objective);
	GASimpleGA ga(genome);
	return 0;
};
float objective(GAGenome& gen)
{
	return funkcja(1,2);
};
