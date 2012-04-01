#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
float f1(float t, float u);
float f2(float t, float u);
float f3(float t, float u);
float f2p();
float f3p(float u);
float f3pi(float t,float u,float du);
float jawny(float (*f)(float,float),float n,float dt,float pocz=0);
float niejawny(float (*f)(float,float),float n, float dt);
float trapezow(float (*f)(float,float),float n, float dt);
float niejawny_3(float t, float dt);
float niejawna_4(float m, float t,float dt);
float niejawna_5(float m, float t, float dt);
float niejawna_6(float m, float t, float dt);
float niejawna_7(float m, float t, float dt);
//float jawny(float n,float dt);
int main()
{
	ofstream plik;
	ofstream plik2;
{
	plik.open("zad1_1.dat");
	int x=0;
	for(x=0;x<100;x++)
	{
		plik<<x<<" "<<(x*x-jawny(f1,x,1))<<endl;
	};
	plik.close();
}
{
	plik.open("zad1_2.dat");
	int x=0;
	for(x=0;x<100;x++)
	{
		plik<<x<<" "<<(x*x-niejawny(f1,x,1))<<endl;
	};
	plik.close();
}
{
	plik.open("zad1_3.dat");
	plik2.open("zad1_3_wartosc.dat");
	int x=0;
	for(x=0;x<100;x++)
	{
		plik2<<x<<" "<<trapezow(f1,x,1)<<" "<<x*x<<endl;
		plik<<x<<" "<<(x*x-trapezow(f1,x,1))<<endl;
	};
	plik.close();
	plik2.close();
}
{
	plik.open("zad1_4.dat");
	float x=0;
	for(x=1.0f/(2*2*2*2);x<=1;x*=2)
	{
		plik<<x<<" "<<jawny(f1,10,x)<<endl;
	};
	plik.close();
}










{
	plik.open("zad2_1.dat");
	float x=0;
	float dt=0.01;
	for(x=0;x<10;x+=dt)
	{
		float dok=x*x+exp(-10.0f*x);
		float jaw=jawny(f2,x,dt,1);
		plik<<x<<" "<<dok<<" "<<jaw<<" "<<dok-jaw<<endl;
	};
	plik.close();
}
{
	plik.open("zad2_2.dat");
	float x=0;
	float dt=0.1;
	for(x=0;x<10;x+=dt)
	{
		float dok=x*x+exp(-10*x);
		float jaw=jawny(f2,x,dt,1);
		plik<<x<<" "<<dok<<" "<<jaw<<" "<<dok-jaw<<endl;
	};
	plik.close();
}
{
	plik.open("zad2_3.dat");
	float x=0;
	float dt=0.2;
	for(x=0;x<10;x+=dt)
	{
		float dok=x*x+exp(-10*x);
		float jaw=jawny(f2,x,dt,1);
		plik<<x<<" "<<dok<<" "<<jaw<<" "<<dok-jaw<<endl;
	};
	plik.close();
}
{
	plik.open("zad2_4.dat");
	float x=0;
	float dt=0.21;
	for(x=0;x<10;x+=dt)
	{
		float dok=x*x+exp(-10*x);
		float jaw=jawny(f2,x,dt,1);
		plik<<x<<" "<<dok<<" "<<jaw<<" "<<dok-jaw<<endl;
	};
	plik.close();
}








{
	plik.open("zad3_1.dat");
	float x=0;
	float dt=0.01;
	for(x=0;x<10;x+=dt)
	{
		float dok=x*x+exp(-10.0f*x);
		float jaw=niejawny_3(x,dt);
		plik<<x<<" "<<dok<<" "<<jaw<<" "<<fabs(dok-jaw)<<endl;
	};
	plik.close();
}
{
	plik.open("zad3_2.dat");
	float x=0;
	float dt=0.1;
	for(x=0;x<10;x+=dt)
	{
		float dok=x*x+exp(-10*x);
		float jaw=niejawny_3(x,dt);
		plik<<x<<" "<<dok<<" "<<jaw<<" "<<fabs(dok-jaw)<<endl;
	};
	plik.close();
}
{
	plik.open("zad3_3.dat");
	float x=0;
	float dt=0.2;
	for(x=0;x<10;x+=dt)
	{
		float dok=x*x+exp(-10*x);
		float jaw=niejawny_3(x,dt);
		plik<<x<<" "<<dok<<" "<<jaw<<" "<<fabs(dok-jaw)<<endl;
	};
	plik.close();
}
{
	plik.open("zad3_4.dat");
	float x=0;
	float dt=0.21;
	for(x=0;x<10;x+=dt)
	{
		float dok=x*x+exp(-10*x);
		float jaw=niejawny_3(x,dt);
		plik<<x<<" "<<dok<<" "<<jaw<<" "<<fabs(dok-jaw)<<endl;
	};
	plik.close();
}
{
	plik.open("zad3_5.dat");
	float x=0;
	float dt=1;
	for(x=0;x<10;x+=dt)
	{
		float dok=x*x+exp(-10*x);
		float jaw=niejawny_3(x,dt);
		plik<<x<<" "<<dok<<" "<<jaw<<" "<<fabs(dok-jaw)<<endl;
	};
	plik.close();
}









{
	plik.open("zad4_1.dat");
	float dt=0.01;
	float um,um1,m;
	m=0;
	um1=niejawna_4(m,dt,dt);
	m++;
	um=niejawna_4(m,dt,dt);
	int i=0;
	while(fabs(um1-um)>0.000009)
	{
		if(++i>15) break;
		um1=um;
		um=niejawna_4(++m,dt,dt);
		plik<<um<<endl;

	};
	plik.close();
}
{
	plik.open("zad4_2.dat");
	float dt=0.1;
	float um,um1,m;
	m=0;
	um1=niejawna_4(m,1,dt);
	m++;
	um=niejawna_4(m,1,dt);
	int i=0;
	while(fabs(um1-um)>0.000009)
	{
		if(++i>15) break;
		um1=um;
		um=niejawna_4(++m,dt,dt);
		plik<<um<<endl;

	};
	plik.close();
}
{
	plik.open("zad4_3.dat");
	float dt=0.11;
	float um,um1,m;
	m=0;
	um1=niejawna_4(m,1,dt);
	m++;
	um=niejawna_4(m,1,dt);
	int i=0;
	while(fabs(um1-um)>0.000009)
	{
		if(++i>15) break;
		um1=um;
		um=niejawna_4(++m,dt,dt);
		plik<<um<<endl;

	};
	plik.close();
}






{
	plik.open("zad5.dat");
	float dt=1;
	float um,um1,m;
	m=0;
	um1=niejawna_5(m,dt,dt);
	m++;
	um=niejawna_5(m,dt,dt);
//	int i=0;
	while(fabs(um1-um)>0.000009)
	{
//		if(++i>15) break;
		um1=um;
		um=niejawna_5(++m,dt,dt);
		plik<<um<<endl;

	};
	plik.close();
}






{
	plik.open("zad6.dat");
	float dt=1;
	float um,um1,m;
	m=0;
	um1=niejawna_6(m,dt,dt);
	m++;
	um=niejawna_6(m,dt,dt);
//	int i=0;
	while(fabs(um1-um)>0.000009)
	{
//		if(++i>15) break;
		um1=um;
		um=niejawna_6(++m,dt,dt);
		plik<<um<<endl;

	};
	plik.close();
}






{
	plik.open("zad7_1.dat");
	float dt=1;
	float um,um1,m;
	m=0;
	um1=niejawna_7(m,dt,dt);
	m++;
	um=niejawna_7(m,dt,dt);
//	int i=0;
	while(fabs(um1-um)>0.000009)
	{
//		if(++i>15) break;
		um1=um;
		um=niejawna_7(++m,dt,dt);
		plik<<um<<endl;

	};
	plik.close();
}
{
	plik.open("zad7_2.dat");
	float du=0.1;
	float u=1;
	for(u=1;u<=2;u+=du)
	{
		plik<<u<<" "<<f3p(u)<<" "<<f3pi(1,u,du)<<" "<<(f3p(u)-f3pi(1,u,du))<<endl;
	};
	plik.close();
}


	return 0;
};	
float f1(float t, float u)
{
	return 2*t;
};
float f2(float t, float u)
{
	return -10.0f*(u-t*t)+2.0f*t;
};
float jawny(float (*f)(float,float),float n,float dt,float pocz)
{
	if(n<=0)
		return pocz;
	float u_1=jawny(f,n-dt,dt,pocz);
	return u_1+dt*f(n-dt,u_1);
};
float niejawny(float (*f)(float,float),float n, float dt)
{
	if(n==0)
		return 0;
	float u_1=niejawny(f,n-1,dt);
	//zakladamy ze w f(t,u) nie wystepuje u...
	return u_1+dt*f(n,0);
};
float trapezow(float (*f)(float,float),float n, float dt)
{
	if(n==0)
		return 0;
	float u_1=trapezow(f,n-1,dt);
	return u_1+dt*(f(n-1,0)+f(n,0))/2;
};
float niejawny_3(float t, float dt)
{
	if(t<=0)
		return 1;
	float u_1=niejawny_3(t-dt,dt);
	return (u_1+10.0f*t*t*dt+2*t*dt)/(1+10.0f*dt);
};
float niejawna_4(float m, float t,float dt)
{
	if(m==0)
		return 1;
	return 1+(-10.0f*(niejawna_4(m-1,t,dt)-t*t)+2.0f*t)*dt;
};
float niejawna_5(float m, float t, float dt)
{
	if(m==0)
		return 1;
	float u_1=niejawna_5(m-1,t,dt);
	return u_1-(u_1-1-dt*f2(t,u_1))/(1-dt*f2p());
};
float niejawna_6(float m, float t, float dt)
{
	if(m==0)
		return 1.2;
	float u_1=niejawna_6(m-1,t,dt);
	return u_1-(u_1-1.2-dt*f3(t,u_1))/(1-dt*f3p(u_1));
};
float niejawna_7(float m, float t, float dt)
{
	if(m==0)
		return 1.2;
	float u_1=niejawna_7(m-1,t,dt);
	return u_1-(u_1-1.2-dt*f3(t,u_1))/(1-dt*f3pi(dt,u_1,0.4));
};
float f2p()
{
	return -10;
};
float f3(float t, float u)
{
	return u*(u-1)*(u-2);
};
float f3p(float u)
{
	return 3*u*u-6*u+2;
};
float f3pi(float t,float u,float du)
{
	return (f3(t,u+du)-f3(t,u-du))/(2*du);
};
