#ifndef __MIASTO_H
#define __MIASTO_H
#include<vector>
class Miasto
{
	public:
		void AddRoad(int num);
		std::vector<int>* RetDrogi();
	private:
		std::vector<int> itsDrogi;
};
#endif
