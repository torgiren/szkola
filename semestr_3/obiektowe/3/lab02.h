#ifndef __LAB02__
#define __LAB02__
#include <iostream>
#include <list>
using namespace std;
class Liczby
{
	public:
		void init() {};
		void push(int co);
		void push(int tab[],int size);
		void pop();
		void print_to_cout();
		int size();
		void sort();
		void clean_up() {};
	private:
		list<int> itsLista;	
};

#endif
