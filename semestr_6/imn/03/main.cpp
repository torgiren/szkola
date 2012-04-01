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
void RK(string path,pair<float,float> (*U)(float (*f_1)(float, float, float, float),float (*f_2)(float,float,float,float),float y1, float y2, float dt),float n,float t, float E,float y1_0, float y2_0,float dt,float S,bool fix=false);
pair<float,float> ytrap(float y1, float y2,float dt, float l1, float l2);
void Trap(string path,pair<float,float> (*Y)(float y1, float y2,float dt, float l1, float l2),float n, float t, float E, float y1_0, float y2_0, float dt, float S);
float u(float u, float t);
float udt(float u,float t,float dt);
void Euler(string path,float (*f)(float, float,float),float n, float t, float E, float y_0, float dt, float S);

int main()
{
	RK("wyniki_1_1_1.dat",U_2,3,30000,0.00001,0,1,1.0f/32.0f,0.75);
	RK("wyniki_1_1_2.dat",U_4,5,30000,0.00001,0,1,1.0f/32.0f,0.75);
	RK("wyniki_1_2.dat",U_2,3,30000,0.00001,0,1,1.0f/32.0f,0.75,true);
	Trap("wyniki_1_3.dat",ytrap,3,30000,0.00001,0,1,1.0f/32.0f,0.75);
	Euler("wyniki_2_2_1.dat",udt,3,2,0.01,2,1.0f,0.75);
	Euler("wyniki_2_2_2.dat",udt,3,2,0.001,2,1.0f,0.75);
	Euler("wyniki_2_2_3.dat",udt,3,2,0.0001,2,1.0f,0.75);
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
	float l2=1.0f/10000.0f;
	float k11=f_1(y1,y2,l1,l2);
	float k21=f_2(y1,y2,l1,l2);
	float k12=f_1(y1+dt*k11,y2+dt*k21,l1,l2);
	float k22=f_2(y1+dt*k11,y2+dt*k21,l1,l2);
	return pair<float,float>(y1+dt/2.0f*k11+dt/2.0f*k12,y2+dt/2.0*k21+dt/2.0f*k22);
};
pair<float,float> U_4(float (*f_1)(float, float, float, float),float (*f_2)(float,float,float,float),float y1, float y2, float dt)
{
	float l1=1.0f/10.0f;
	float l2=1.0f/10000.0f;
	float k11=f_1(y1,y2,l1,l2);
	float k21=f_2(y1,y2,l1,l2);
	float k12=f_1(y1+dt/2.0f*k11,y2+dt/2.0f*k21,l1,l2);
	float k22=f_2(y1+dt/2.0f*k11,y2+dt/2.0f*k21,l1,l2);
	float k13=f_1(y1+dt/2.0f*k12,y2+dt/2.0f*k22,l1,l2);
	float k23=f_2(y1+dt/2.0f*k12,y2+dt/2.0f*k22,l1,l2);
	float k14=f_1(y1+dt*k13,y2+dt*k23,l1,l2);
	float k24=f_2(y1+dt*k13,y2+dt*k23,l1,l2);
	return pair<float,float>(y1+dt/6.0f*(k11+2*k12+2*k13+k14),y2+dt/6.0*(k21+2*k22+2*k23+k24));
};
void RK(string path,pair<float,float> (*U)(float (*f_1)(float, float, float, float),float (*f_2)(float,float,float,float),float y1, float y2, float dt),float n,float t, float E,float y1_0, float y2_0,float dt,float S,bool fix)
{
	ofstream plik;
	plik.open(path.c_str());
	float i=0;
	pair<float,float> y=pair<float,float>(y1_0,y2_0);
	float e,e1,e2;
	float dt1,dt2,olddt;
	pair<float,float> y_1;
	pair<float,float> y_21;
	pair<float,float> y_22;
	n=pow(2,n-1)-1;

	for(i=0;i<t;i+=dt)
	{
		cout<<"i: "<<i<<endl;
		y_1=U(f1,f2,y.first,y.second,dt);
		y_21=U(f1,f2,y.first,y.second,dt/2.0f);
		y_22=U(f1,f2,y_21.first,y_21.second,dt/2.0f);
//		cout<<"n: "<<n<<endl;
		e1=fabs(y_22.first-y_1.first)/n;
		e2=fabs(y_22.second-y_1.second)/n;
		e=e1>=e2?e1:e2;
		if(e==0)
			e=E/10;
//		cout<<"e012: "<<e<<" "<<e1<<" "<<e2<<endl;
		dt1=pow(S*E/e,1.0f/n)*dt;
		dt2=pow(S*E/e,1.0f/n)*dt;
		olddt=dt;
		dt=dt1>dt2?dt2:dt1;
		if(fix)
		{
			if(i>=10000)
			{			
				cout<<"fix"<<endl;
				dt=100;
			}
		}
		else
//		cout<<"dt: "<<dt<<endl;
		if(e>E)
		{
//			cout<<"eE: "<<e<<" "<<E<<endl;
			i-=olddt;
			continue;
		}

		y=y_22;
		plik<<i<<" "<<y.first<<" "<<y.second<<" "<<dt/2.0f<<endl;
	};
	plik.close();
};
pair<float,float> ytrap(float y1, float y2,float dt, float l1, float l2)
{
	float a1,a2,b1;
	a1=y1*(1.0f-((l1*dt)/2.0f))/(1.0f+(l1*dt)/2.0f);
	a2=(dt/2.0f)*((2*l2*y2+l1)/(1.0f+(l1*dt)/2.0f));
	b1=y2*(1.0f-(l2*dt)/2.0f)/(1.0f+(l2*dt)/2);
	return pair<float,float>(a1+a2,b1);
};
void Trap(string path,pair<float,float> (*Y)(float y1, float y2,float dt, float l1, float l2),float n, float t, float E, float y1_0, float y2_0, float dt, float S)
{
	ofstream plik;
	plik.open(path.c_str());
	float i=0;
	pair<float,float> y=pair<float,float>(y1_0,y2_0);
	float e,e1,e2;
	float dt1,dt2,olddt;
	pair<float,float> y_1;
	pair<float,float> y_21;
	pair<float,float> y_22;
	n=pow(2,n-1)-1;

	float l1=1.0f/10.0f;
	float l2=1.0f/10000.0f;

	for(i=0;i<t;i+=dt)
	{
		cout<<"i: "<<i<<endl;
		y_1=Y(y.first,y.second,dt,l1,l2);
		y_21=Y(y.first,y.second,dt/2.0f,l1,l2);
		y_22=Y(y_21.first,y_21.second,dt/2.0f,l1,l2);
		cout<<"n: "<<n<<endl;
		e1=fabs(y_22.first-y_1.first)/n;
		e2=fabs(y_22.second-y_1.second)/n;
		e=e1>=e2?e1:e2;
		if(e==0)
			e=E/1000;
		cout<<"e012: "<<e<<" "<<e1<<" "<<e2<<endl;
		dt1=pow(S*E/e,1.0f/n)*dt;
		dt2=pow(S*E/e,1.0f/n)*dt;
		olddt=dt;
		dt=dt1>dt2?dt2:dt1;
		cout<<"dt: "<<dt<<" "<<dt1<<" "<<dt2<<endl;
		if(e>E)
		{
			cout<<"eE: "<<e<<" "<<E<<endl;
			i-=olddt;
			if(i<0) i=0;
			cout<<endl;
			continue;
		}

		y=y_22;
		plik<<i<<" "<<y.first<<" "<<y.second<<" "<<dt/2.0f<<endl;
		cout<<endl;
	};
	plik.close();
};
float u(float u, float t)
{
	return -100*(u-cos(t))-sin(t);
};
float udt(float u,float t,float dt)
{
	return (u+dt*(100*cos(t+dt)-sin(t+dt)))/(1+100*dt);
};

void Euler(string path,float (*f)(float, float,float),float n, float t, float E, float y_0, float dt, float S)
{
	ofstream plik;
	plik.open(path.c_str());
	float i=0;
	float y=y_0;
	float e;
	float olddt;
	float y_1;
	float y_21;
	float y_22;
	n=pow(2,n-1)-1;

	for(i=0;i<t;i+=dt)
	{
//		cout<<"i: "<<i<<endl;
		y_1=f(y,i,dt);
		y_21=f(y,i,dt/2.0f);
		y_22=f(y_21,i,dt/2.0f);
//		cout<<"n: "<<n<<endl;
		e=fabs(y_22-y)/n;
		if(e==0)
			e=E/1000;
		olddt=dt;
		dt=pow(S*E/e,1.0f/n)*dt;
		if(e>E)
		{
			cout<<"eE: "<<e<<" "<<E<<endl;
			i-=olddt;
			if(i<0) i=0;
			cout<<endl;
			continue;
		}

		y=y_22;
		plik<<i<<" "<<y<<" "<<dt/2.0f<<endl;
		cout<<endl;
	};
	plik.close();
};
