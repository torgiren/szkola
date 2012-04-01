#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
class vec
{
	public:
		vec(float x,float y, float z):
			itsX(x),itsY(y),itsZ(z)
		{
		};
		vec operator-(const vec& co) const
		{
			vec wynik(*this);
			wynik.itsX-=co.itsX;
			wynik.itsY-=co.itsY;
			wynik.itsZ-=co.itsZ;
			return wynik;
		};
		//mnozenie skalarne
		vec operator*(const vec& co) const 
		{
			vec wynik(0,0,0);
			wynik.itsX=this->itsX*co.itsX;
			wynik.itsY=this->itsY*co.itsY;
			wynik.itsZ=this->itsZ*co.itsZ;
			return wynik;

		};
		operator float()
		{
			return sqrt(itsX*itsX+itsY*itsY+itsZ*itsZ);
		};
//	private:
		float itsX;
		float itsY;
		float itsZ;
};
float r(const vec& r1, const vec& r2, const vec& ri)
{

	float wynik=0;
	wynik=((float)(r1-ri)*(float)(r1-ri))*((float)(r2-r1)*(float)(r2-r1));
	wynik-=(float)((r1-ri)*(r2-r1))*(float)((r1-ri)*(r2-r1));
	wynik/=((float)(r2-r1)*(float)(r2-r1));
	wynik=sqrt(wynik);
	if(wynik>sqrt(3))
	{
		cout<<ri.itsX<<","<<ri.itsY<<","<<ri.itsZ<<" - "<<wynik<<endl;
	};

/*
	float wynik;
	float tmp1=(r1-ri);
	tmp1=tmp1*tmp1;
	float tmp2=(r2-r1);
	tmp2=tmp2*tmp2;
	float tmp3=(vec(r1-ri)*vec(r2-r1));
	tmp3=tmp3*tmp3;
	float tmp4=r2-r1;
	tmp4=tmp4*tmp4;
	wynik=(tmp1*tmp2-tmp3)/tmp4;
	wynik=sqrt(wynik);
*/

	return wynik;
};
bool isIn(float x, float y, float z, float Ox, float Oy, float Oz)
{
//	cout<<x<<","<<y<<","<<z<<"\t"<<Ox<<","<<Oy<<","<<Oz<<endl;
	return ((fabs(Ox)>fabs(x))&&
	  	(fabs(Oy)>fabs(y))&&
		(fabs(Oz)>fabs(z)));
};
float los()
{
	return (float)rand()/RAND_MAX;
};
int main()
{
	srand(time(NULL));
	register int i;
	float Vx=2, Vy=2, Vz=2;
	float Ox=1, Oy=1, Oz=1;
	float I=0;
	float V=8*Ox*Ox*Ox;
	float N=1000;
	const vec r1(-1,-1,-1);
	const vec r2(1,1,1);
	for(i=0;i<N;i++)
	{
		float tmpX=los()*Vx*2-Vx;
		float tmpY=los()*Vy*2-Vy;
		float tmpZ=los()*Vz*2-Vz;
		vec tmp(tmpX,tmpY,tmpZ);
		if(isIn(tmpX,tmpY,tmpZ,Ox,Oy,Oz))
		{
//			cout<<tmpX<<","<<tmpY<<","<<tmpZ<<endl;
			float rTmp=r(r1,r2,tmp);
//			cout<<rTmp<<endl;
			I+=(rTmp*rTmp);
		};
	};
	I*=V;
	I=I/N;
	cout<<I<<endl;
};
