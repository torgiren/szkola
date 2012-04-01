#include <iostream>
#include <cstring>
using namespace std;
class Schemat
{
public:
	friend ostream& operator<<(ostream& out,const Schemat& schema);
	Schemat(string values)
	{
		itsWartosci=values;
	};
	Schemat(const Schemat& schema)
	{
		itsWartosci=schema.itsWartosci;
	};
	int RetDlugosc() const {return itsWartosci.size();};
	bool operator<(const Schemat & schema) const
	{
		unsigned int x;
		for(x=0;x<itsWartosci.size();x++)
		{
			if(itsWartosci[x]<schema.itsWartosci[x])
			{
				return true;
			};
		};
		return false;
	};
	bool operator==(const Schemat& schema) const
	{
		return itsWartosci==schema.itsWartosci;
	};
	bool operator!=(const Schemat& schema) const
	{
		return !(*this==schema);
	};
	void operator=(const Schemat& schema)
	{
		itsWartosci=schema.itsWartosci;
	};
	int RetRzad()
	{
		int count=0;
		unsigned x;
		for(x=0;x<itsWartosci.size();x++)
		{
			if(itsWartosci[x]!='*')
				count++;
		}
		return count;
	};
	int RetRozpietosc()
	{
		int first=-1;
		int last=-1;
		unsigned int x;
		for(x=0;x<itsWartosci.size();x++)
		{
			if(itsWartosci[x]!='*')
			{
				if(first==-1)
					first=x;
				last=x;
			};
		};
		return last-first;
	};
	/**
	 * Pawdopodopienstwo przeżycia mutacji
	 */
	float RetPrawdPrzezMut()
	{
	/*
		float prawd=1;
		unsigned int x;
		for(x=0;x<itsWartosci.size();x++)
		{
			if(itsWartosci[x]!='*')
				prawd-=PrawdMut;
		};
		return prawd;
	*/
		float prawd=(float)PrawdMut;
		int x;
		for(x=0;x<RetRzad();x++)
		{
			prawd*=PrawdMut;
			cout<<prawd<<endl;
		};
		return (float)1-prawd;

	};
	static float PrawdMut;
	/**
	 * Prawdopobieństwo przeżycia krzyżowania
	 */
	float RetPrawdPrzezKrzyz(const Schemat& schema)
	{
		float prawd=0;
		unsigned int x;
		int sum=0;
		int live=0;
		if(itsWartosci.size()!=schema.itsWartosci.size())
			return -1;
		for(x=1;x<itsWartosci.size();x++)
		{
			string a,b;
			a=itsWartosci.substr(0,x)+schema.itsWartosci.substr(x,itsWartosci.size()-x);
			b=schema.itsWartosci.substr(0,x)+itsWartosci.substr(x,itsWartosci.size()-x);
			if(a==itsWartosci||b==itsWartosci)
			{
				live++;
			};
			sum+=2;
		};
		prawd=(float)live/sum;
		return prawd;
	};
private:
	string itsWartosci;
};
float Schemat::PrawdMut=0.1;
ostream& operator<<(ostream& out,const Schemat& schema)
{
	out<<schema.itsWartosci;
	return out;
};
int main()
{
	string tmp;
	cin>>tmp;
	Schemat aa(tmp);
	cin>>tmp;
	Schemat bb(tmp);
	cout<<"Rzad: "<<aa.RetRzad()<<endl;
	cout<<"Rozpietosc: "<<aa.RetRozpietosc()<<endl;
	cout<<"Prawd. przezyciai ?mutacji: "<<aa.RetPrawdPrzezMut()<<endl;
	cout<<"Prawd. przezycia krzyzowania: "<<aa.RetPrawdPrzezKrzyz(bb)<<endl;
};
