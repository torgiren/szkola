#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;
double f(double u);
double df(double u);
double F1(double U1, double U2,double un1, double dt,vector<double> a);
double F2(double U1, double U2,double un1, double dt,vector<double> a);
double dF1dU1(double U1, double a11, double dt);
double dF1dU2(double U2, double a12, double dt);
double dF2dU1(double U1, double a21, double dt);
double dF2dU2(double U2, double a22, double dt);
vector<double> GenPochodne(double U1, double U2, vector<double> a, double dt);
vector<double> GenWolne(double U1, double U2, double un1, double dt, vector<double> a);
pair<double,double> met_wyznacznik(vector<double> A,vector<double> B);
int main()
{
	ofstream plik;
	float dt=0.2f;
//	double u0=1.5f;
	double U11=1.5f;
	double U12=1.5f;
	double e;
	double tol=0.001f;
	vector<double> a;
	a.push_back(1.0f/4.0f);
	a.push_back(1.0f/4.0f+sqrt(3)/6.0f);
	a.push_back(1.0f/4.0f-sqrt(3)/6.0f);
	a.push_back(1.0f/4.0f);
	double b1,b2;
	b1=b2=1.0f/2.0f;

	
//	pair<double,double> U=met_wyznacznik(GenPochodne(U11,U12,a,dt),GenWolne(U11,U12,u0,dt,a));
	
//	pair<double,double> U_nowe=met_wyznacznik(GenPochodne(U.first,U.second,a,dt),GenWolne(U.first,U.second,u0,dt,a));
	double t;
	char path[255];
	int iu0;
	double u;
	for(iu0=0;iu0<=20;iu0+=2)
	{
			double u0=(double)iu0/10.0f;
			sprintf(path,"zad2_02_%d.txt",(iu0));
			plik.open(path);
			u=u0;
			for(t=0;t<=4;t+=dt)
			{
				pair<double,double> U=pair<double,double>(U11,U12);
				pair<double,double> dU=met_wyznacznik(GenPochodne(U11,U12,a,dt),GenWolne(U11,U12,u,dt,a));
				int x=0;
				do
				{
					dU=met_wyznacznik(GenPochodne(U.first,U.second,a,dt),GenWolne(U.first,U.second,u,dt,a));
					U.first+=dU.first;
					U.second+=dU.second;
			/*
					cout<<"-------------------------------------------"<<endl;
					cout<<"U1: "<<U.first<<"\tU2: "<<U.second<<endl;
					cout<<"dU1: "<<dU.first<<"\tdU2: "<<dU.second<<endl;
					cout<<"-------------------------------------------"<<endl;
					cout<<endl;
			*/
				}
				while(((((fabs(dU.first)>tol)||(fabs(dU.second)>tol)))));
				u=u+dt*(b1*f(U.first)+b2*f(U.second));
				plik<<t<<" "<<u<<endl;
			};
			plik.close();
	};

};
double f(double u)
{
	return u*(u-1)*(u-2);
};
double F1(double U1, double U2,double un1, double dt,vector<double> a)
{
	return U1-un1-dt*(a[0]*f(U1)+a[2]*f(U2));
};
double F2(double U1, double U2,double un1, double dt,vector<double> a)
{
	return U2-un1-dt*(a[1]*f(U1)+a[3]*f(U2));
};
double df(double u)
{
//	return 3*u*u-4*u;
	return 3*u*u-6*u+2;
};
double dF1dU1(double U1, double a11, double dt)
{
	return 1-dt*a11*df(U1);
};
double dF1dU2(double U2, double a12, double dt)
{
	return -dt*a12*df(U2);
};
double dF2dU1(double U1, double a21, double dt)
{
	return -dt*a21*df(U1);
};
double dF2dU2(double U2, double a22, double dt)
{
	return 1-dt*a22*df(U2);	
};
pair<double,double> met_wyznacznik(vector<double> A,vector<double> B)
{
	double W=A[0]*A[3]-A[1]*A[2];
	double W1=B[0]*A[3]-B[1]*A[2];
	double W2=A[0]*B[1]-A[1]*B[0];
	return pair<double,double>(W1/W,W2/W);
};
vector<double> GenPochodne(double U1, double U2, vector<double> a, double dt)
{
	vector<double> wynik;
	wynik.push_back(dF1dU1(U1,a[0],dt));
	wynik.push_back(dF2dU1(U1,a[1],dt));
	wynik.push_back(dF1dU2(U2,a[2],dt));
	wynik.push_back(dF2dU2(U2,a[3],dt));
/*
	cout<<"GenPochodne:"<<endl;
	cout<<wynik[0]<<"\t"<<wynik[2]<<endl;
	cout<<wynik[1]<<"\t"<<wynik[3]<<endl;
	cout<<"**************"<<endl;
*/
	return wynik;
};
vector<double> GenWolne(double U1, double U2, double un1, double dt, vector<double> a)
{
	vector<double> wynik;
	wynik.push_back(-F1(U1,U2,un1,dt,a));
	wynik.push_back(-F2(U1,U2,un1,dt,a));
/*
	cout<<"GenWolne:"<<endl;
	cout<<wynik[0]<<endl;
	cout<<wynik[1]<<endl;
	cout<<"**************"<<endl;
*/
	return wynik;
};
