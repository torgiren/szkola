#include <unistd.h>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include "logger.h"
#include "client.h"
#include "strzelnica.h"
using namespace std;
int main(int argc, char **argv)
{
	if(argc!=2)
	{
		std::cerr<<"Usage: "<<argv[0]<<" <liczba_klientow>"<<std::endl;
		return -1;
	};
	int klientow=atoi(argv[1]);	
	Logger::GetInstance()->SetPath("strzelnica.log");
	Logger::GetInstance()->StartTimer();
	Strzelnica* strzelnica=Strzelnica::GetInstance();
	srand(time(NULL));
	int i;
	for(i=0;i<klientow;i++)
	{
//		cout<<"Klient nr: "<<i<<endl;
		strzelnica->Nowy();
		sleep(1+rand()%4);
	};
	strzelnica->Zamknij();
	std::cout<<"Zamykamy"<<endl;
	pthread_join(strzelnica->RetMainLoopThread(),NULL);
	return 0;
};
