//Tego pliku nie wolno modyfikowac!

//...tak to SA dwie identyczne dyrektywy...
#include "lab01.h"
#include "lab01.h"

int main(void)
{
 int *ptr1=NULL,*ptr2=NULL;
 int size1=3,size2=10;
 void (*func)(int *&,int);

 std::cout<<"-------------------"<<std::endl;
 init_ptr(ptr1,size1,4);
 init_ptr(ptr2,size2,5);

 std::cout<<"-------------------"<<std::endl;
 func=&print_norm_func;
 func(ptr1,size1);

 std::cout<<"-------------------"<<std::endl;
 func=&print_oposite_func;
 func(ptr2,size2);

 std::cout<<"-------------------"<<std::endl;

 free_ptr(ptr1);
 free_ptr(ptr2);

 return 0;
}

//wyjscie programu wyglada tak:
/*
-------------------
Tablica[3] zaalokowana i wpisane do niej wartosci od 4 do 6
Tablica[10] zaalokowana i wpisane do niej wartosci od 5 do 14
-------------------
Normalne wypisywanie:
4,5,6,
-------------------
Wypisywanie wspak:
14,13,12,11,10,9,8,7,6,5,
-------------------
zwolnilem pamiec
zwolnilem pamiec
*/
