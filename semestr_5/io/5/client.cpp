#include "client.h"
#include <cstdlib>
#include <iostream>
using namespace std;
Client::Client()
{
	itsStrzalow=10;
	itsBron="piesci";
	static int ktory=0;
	itsLp=ktory++;
};
std::string Client::RetBron()
{
	return itsBron;
};
void Client::SetBron(std::string bron)
{
	itsBron=bron;
};
void ClientBuilder::CreateClient()
{
	itsClient=new Client();	
};
void CrossbowClientBuilder::SetBron()
{
	itsClient->SetBron("Kusza");
};
void PistolClientBuilder::SetBron()
{
	itsClient->SetBron("Pistolet");
};
void RifleClientBuilder::SetBron()
{
	itsClient->SetBron("Karabin");
};
void Client::Strzelaj()
{
	itsStrzalow--;
};
int Client::RetShotsLeft()
{
	return itsStrzalow;
};

