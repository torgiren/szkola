#ifndef __LAB
#define __LAB
#include <iostream>
#include <stdlib.h>
using namespace std;
/// \file lab01.h
/// \brief pierwsza laborka
/// \author Fabrykowski Marcin

/**
*funkcja inicjuje tablice kolejnymi liczbami naturalnymi, poczawszy od $val
@param ptr referencja do wskaznika do tablicy
@param size rozmiar tablicy
@return val wartosc poczatkowa
*/
void init_ptr(int *&ptr,int size,int val)
{
	ptr=(int*)malloc(size*sizeof(int));
	

	/*
	if(!ptr) return -1;
	*/

	if(!ptr) cout<<"ups"<<endl;
	int x;
	for(x=0;x<size;x++)
	{
		ptr[x]=val+x;
	};
	cout<<"Tablica zaalokowana i wpisane do niej wartosci od "<<val<<" do "<<val+x-1<<endl;

};
void print_norm_func(int * &tab,int size)
{
	int x;
	for(x=0;x<size;x++)
	{
		cout<<tab[x]<<" ";
	};
	cout<<endl;
};
void print_oposite_func(int *&tab,int size)
{
	int x;
	for(x=size-1;x>=0;x--)
	{
		cout<<tab[x]<<" ";
	};
	cout<<endl;
};
void free_ptr(int *ptr)
{

	if(ptr)
	{
		free(ptr);
		cout<<"zwalniam pamiec"<<endl;
	}
	else
	{
		cout<<"nie ma co zwalniac"<<endl;
	};

};
#endif
