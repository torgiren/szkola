#include "miasto.h"
void Miasto::AddRoad(int num)
{
	itsDrogi.push_back(num);
};
std::vector<int>* Miasto::RetDrogi()
{
	return &itsDrogi;
};
