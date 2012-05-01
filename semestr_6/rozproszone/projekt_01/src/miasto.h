#ifndef __MIASTO_H
#define __MIASTO_H
#include<vector>
class Miasto
{
	public:
		void AddRoad(int num);
		std::vector<int>* RetDrogi();
		char* Dump();
		void Load(char* data);
	private:
		std::vector<int> itsDrogi;
};
#endif
