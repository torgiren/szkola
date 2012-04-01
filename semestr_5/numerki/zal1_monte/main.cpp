#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;
bool theta(float x,float y, float z);
const float r1=0.5;
const float r2=0.7;
const float h=1;
float d(float x,float y);
float los(float a);
int main()
{
	int N_MIN=1000;
	int N_MAX=1000000;
	srand(time(NULL));	

	float a=2; //Bok obszaru V;
	float V=a*a*a;
	int N=N_MAX;
//	for(N=N_MIN;N<N_MAX;N+=100)
	{
			int i;
			float I=0;
			float sum1=0;
			float sum2=0;
			for(i=0;i<N;i++)
			{
				float x=los(a)-a/2;
				float y=los(a)-a/2;
				float z=los(a/2)-a/4;
		//		cout<<"Sprawdzam punkt "<<x<<","<<y<<","<<z<<", i stwierdzam ze thera wynosi: "<<theta(x,y,z)<<endl;
				if(theta(x,y,z))
				{
		//			cout<<"jest"<<endl;
					I+=d(x,y)*d(x,y);
					float tmp=V*d(x,y)*d(x,y);
					sum1+=tmp*tmp;
					sum2+=tmp;
				};
				if(!(i%100))
				{
					cout<<i<<" "<<I*V/i<<" "<<sqrt(((sum1-(sum2*sum2)/i)/(i-1)/i))<<endl;
				};
			};
			I*=V;
			I/=N;
		//	cout<<"Moment bezwladnosci wynosi: "<<I<<endl;
			float s2=sum1-(sum2*sum2)/N;
			s2/=(N-1);
			float s=sqrt(s2/N);
		//	cout<<"Blad s^2="<<s2<<"\ts="<<s<<endl;
//			cout<<N<<" "<<I<<" "<<s<<endl;
	};
/*
	
	V szescian o rymiarach 1x1x1
	I=V*s/N sun r^2*tetha;

	s^2=1/(N-1) [ sum\limits_{i=1}^N (V*\sigma*r_i^2*\Theta_i)^2-1/N(\sum\limits_{i=1}^N V*\sigma*r_i_^2*\Theta)^2
	d=\sqrt((|r1-ri|)^2|r2-r1|^2-[(r1-ri)(r2-r1)]^2 / (|r2-r1|^2))

	I=1/2 m (R1^2+R2^2);
	V=V*sigma;
	V=pi(R2^2-R1^2)*1=0.7536
	m=0.7536
	I=1/2*0.7536*(0.5^2+0.7^2)=0.5842
*/
};
bool theta(float x,float y, float z)
{
	float r=d(x,y);
//	cout<<"r="<<r<<endl;
	if(z>h/2||z<-h/2) return false;	
	if(r<r1||r>r2) return false;
	return true;
};
float los(float a=1)
{
	return a*(float)rand()/(RAND_MAX);
};
float d(float x,float y)
{
	return sqrt(x*x+y*y);
};
