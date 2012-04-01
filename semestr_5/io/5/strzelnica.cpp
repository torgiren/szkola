#include "strzelnica.h"
#include <sstream>
#include <iostream>
#include "logger.h"
#include <cstdlib>
Strzelnica::Strzelnica(int ileTorow)
{
	itsOtwarte=true;
	itsIleTorow=ileTorow;
	itsMutexTory=new pthread_mutex_t[itsIleTorow];
	itsKlientTory=new Client*[itsIleTorow];
	itsLiczbaLudzi=0;
	pthread_create(&itsMainLoopThread,NULL, MainLoop,NULL);

};
void Strzelnica::Nowy()
{

	Client* nowy=itsObsluga.Obsluz();
	Lock();
	itsKolejka.push_back(nowy);
	Unlock();
	std::stringstream ss;
//	ss<<"Klient "<<nowy->RetLp()<<" stanal w kolejce";
//	Logger::GetInstance()->Log(ss.str());

};
void* Strzelnica::MainLoop(void* ptr)
{
	Strzelnica* strzel=Strzelnica::GetInstance();
	while((strzel->itsOtwarte)||(strzel->itsLiczbaLudzi))
	{
		if(strzel->itsKolejka.size())
		{
			int first=strzel->FirstFree();
			if(first!=-1)
			{
				strzel->Lock();
				Client* tmp=strzel->itsKolejka.front();
				strzel->itsKolejka.pop_front();
				++strzel->itsLiczbaLudzi;
				strzel->Unlock();
				strzel->itsKlientTory[first]=tmp;
				std::stringstream ss;
				ss<<"Klient "<<tmp->RetLp()<<" stanal na torze "<<first;
				Logger::GetInstance()->Log(ss.str());
				pthread_t t;
				pthread_create(&t,NULL,Obsluz,(void*)&first);
				continue;
			};
		};
		sleep(1);
	};
	std::cout<<"Wychodze"<<std::endl;
	return 0;
};
int Strzelnica::FirstFree()
{
	int i;
	for(i=0;i<itsIleTorow;i++)
	{
		if(!pthread_mutex_trylock(&itsMutexTory[i]))
		{
			return i;
		};
	};
	return -1;
};
void* Strzelnica::Obsluz(void* ptr)
{
	int tor=*(int*)ptr;
	std::stringstream ss;
	Strzelnica* strzel=Strzelnica::GetInstance();
	Client* strzelec=strzel->itsKlientTory[tor];
	int strzal=0;
	do
	{
		ss.str("");
		ss<<"Klient nr: "<<strzelec->RetLp()<<" oddaje "<<++strzal<<" strzal na torze: "<<tor;
		Logger::GetInstance()->Log(ss.str());
		strzelec->Strzelaj();
		sleep(rand()%3+1);
	}while(strzelec->RetShotsLeft());
	ss.str("");
	ss<<"Klient nr: "<<strzelec->RetLp()<<" skonczyl strzelac i wychodzi";
	Logger::GetInstance()->Log(ss.str());
	strzel->itsKlientTory[tor]=0;
	pthread_mutex_unlock(&strzel->itsMutexTory[tor]);
	strzel->Lock();
	--strzel->itsLiczbaLudzi;
	strzel->Unlock();
	return 0;
};
