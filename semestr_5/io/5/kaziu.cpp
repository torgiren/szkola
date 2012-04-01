#include "kaziu.h"
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "logger.h"
Client* Kaziu::Obsluz()
{
	int x=rand()%3;
	ClientBuilder* build;
	switch(x)
	{
		case 0:
			build=new PistolClientBuilder();
			break;
		case 1:
			build=new CrossbowClientBuilder();
			break;
		case 2:
			build=new RifleClientBuilder();
			break;
	};
	SetBuilder(build);
	itsBuild->CreateClient();
	itsBuild->SetBron();
	std::stringstream ss;
	ss<<"Pan kazio wydal bron: "<<itsBuild->RetClient()->RetBron()<<", klientowi nr: "<<itsBuild->RetClient()->RetLp()<<" i odsyla do koleiki";
	Logger::GetInstance()->Log(ss.str());
	return itsBuild->RetClient();
};
void Kaziu::SetBuilder(ClientBuilder* build)
{
	itsBuild=build;
};
