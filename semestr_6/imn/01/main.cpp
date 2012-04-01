#include <iostream>
using namespace std;
float f(float t, float u);
float jawny(float n,float dt);
int main()
{
/*
	int x=0;
	for(x=0;x<100;x++)
	{
		cout<<x<<" "<<x*x<<" "<<jawny(x,1)<<endl;
	};
*/
	float x=0;
	for(x=1.0f/(2*2*2*2);x<=1;x*=2)
	{
		cout<<x<<" "<<jawny(10,x)<<endl;
	};
	return 0;
};
float f(float t, float u)
{
	return 2*t;
};
float jawny(float n,float dt)
{
	if(n==0)
		return 0;
	float u_1=jawny(n-1,dt);
	return u_1+dt*f(n-1,u_1);
};
