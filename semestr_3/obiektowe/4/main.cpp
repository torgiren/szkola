
#include "lab03.h"

int main()
{
 Zespolona l1(1,3),l2(2,-4),l3(2,1),l4(2,6);
 Zespolona tmp;

 tmp.przypisz(l1);

 l1.print(); l2.print(); l3.print(); l4.print(); tmp.print();


 std::cout<<"------------"<<std::endl;

 tmp.przypisz(l1);
 tmp.pomnoz(l2);
 tmp.podziel(l3);
 tmp.dodaj(l4);
 tmp.odejmij(l1);
 tmp.print();

 return 0;
}

