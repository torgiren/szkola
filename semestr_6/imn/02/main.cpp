#include <iostream>
#include <fstream>
#include <utility>
#include <cmath>
#include <string>
using namespace std;

float f1(float y1,float y2,float l1, float l2);
float f2(float y1,float y2,float l1, float l2);
pair<float,float> U_2(float (*f_1)(float, float, float, float),float (*f_2)(float,float,float,float),float y1, float y2, float dt);
pair<float,float> U_4(float (*f_1)(float, float, float, float),float (*f_2)(float,float,float,float),float y1, float y2, float dt);
void RK(string path,pair<float,float> (*U)(float (*f_1)(float, float, float, float),float (*f_2)(float,float,float,float),float y1, float y2, float dt),float n,float t, float E,float y1_0, float y2_0,float dt,float S);

int main()
{
	RK("wyniki_1_1.dat",U_2,3,3000,0.0001,0,1,1,0.75);
	RK("wyniki_2_1.dat",U_4,5,3000,0.0001,0,1,1,0.75);
	return 0;
};

float f1(float y1,float y2, float l1, float l2)
{
	return -l1*y1+l2*y2+l1/2.0f;
};
float f2(float y1,float y2, float l1, float l2)
{
	return -l2*y2;
};
pair<float,float> U_2(float (*f_1)(float, float, float, float),float (*f_2)(float,float,float,float),float y1, float y2, float dt)
{
	float l1=1.0f/10.0f;
	float l2=1.0f/1000.0f;
	float k11=f_1(y1,y2,l1,l2);
	float k21=f_2(y1,y2,l1,l2);
	float k12=f_1(y1+dt*k11,y2+dt*k21,l1,l2);
	float k22=f_2(y1+dt*k11,y2+dt*k21,l1,l2);
	return pair<float,float>(y1+dt/2.0f*k11+dt/2.0f*k12,y2+dt/2.0*k21+dt/2.0f*k22);
};
pair<float,float> U_4(float (*f_1)(float, float, float, float),float (*f_2)(float,float,float,float),float y1, float y2, float dt)
{
	float l1=1.0f/10.0f;
	float l2=1.0f/1000.0f;
	float k11=f_1(y1,y2,l1,l2);
	float k21=f_2(y1,y2,l1,l2);
	float k12=f_1(y1+dt*k11,y2+dt*k21,l1,l2);
	float k22=f_2(y1+dt*k11,y2+dt*k21,l1,l2);
	float k13=f_1(y1+dt*k12,y2+dt*k22,l1,l2);
	float k23=f_2(y1+dt*k21,y2+dt*k22,l1,l2);
	float k14=f_1(y1+dt*k13,y2+dt*k23,l1,l2);
	float k24=f_2(y1+dt*k13,y2+dt*k23,l1,l2);
	return pair<float,float>(y1+dt/6.0f*(k11+2*k12+2*k13+k14),y2+dt/6.0*(k21+2*k22+2*k23+k24));
};
void RK(string path,pair<float,float> (*U)(float (*f_1)(float, float, float, float),float (*f_2)(float,float,float,float),float y1, float y2, float dt),float n,float t, float E,float y1_0, float y2_0,float dt,float S)
{
	ofstream plik;
	plik.open(path.c_str());
	float i=0;
	pair<float,float> y=pair<float,float>(y1_0,y2_0);
	float e,e1,e2;
	float dt1,dt2;
	pair<float,float> y_1;
	pair<float,float> y_21;
	pair<float,float> y_22;

	for(i=0;i<t;i+=dt)
	{
		y_1=U(f1,f2,y.first,y.second,dt);
		y_21=U(f1,f2,y.first,y.second,dt/2.0f);
		y_22=U(f1,f2,y_21.first,y_21.second,dt/2.0f);
		e1=fabs(y_22.first-y_1.first)/3.0f;
		e2=fabs(y_22.second-y_1.second)/3.0f;
		cout<<"e12: "<<e1<<" "<<e2<<endl;
		n=pow(2,n)-1;
		dt1=pow(S*E/e1,1.0f/3.0f)*dt;
		dt2=pow(S*E/e2,1.0f/3.0f)*dt;
		e=e1>=e2?e1:e2;
		if(dt1<dt2)
			dt=dt1;
		else
			dt=dt2;
		cout<<"dt: "<<dt<<endl;
		if(e>E)
		{
			cout<<"eE: "<<e<<" "<<E<<endl;
			i-=dt;
		}
		else
		{
			y=y_22;
			plik<<i<<" "<<y.first<<" "<<y.second<<" "<<dt/2.0f<<endl;
		};
		cout<<endl;
	};
	plik.close();
};
