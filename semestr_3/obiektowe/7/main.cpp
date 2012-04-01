#include "lab06.h"
#include <iostream>
using namespace std;
int main()
{
 int i;
 IntTab a=IntTab(10),b,c=IntTab(10),d=IntTab(10);

 for (i=0;i<12;i++) a(i)=i*2;
 //() error - index out of bound (max index:9,try to access index:10)
 //() error - index out of bound (max index:9,try to access index:11)
 a(0)=1;

 a.print();
 //(1,2,4,6,8,10,12,14,16,18)
 b=a;
 //IntTab's are different sizes!
 b.print();
 //Nothing to print!
 c=-a;
 c.print();
 //(-1,-2,-4,-6,-8,-10,-12,-14,-16,-18)
 d=a-c;
 d.print();
 //(2,4,8,12,16,20,24,28,32,36)

	return 0;
}

/*
I caly output:

() error - index out of bound (max index:9,try to access index:10)
() error - index out of bound (max index:9,try to access index:11)
(1,2,4,6,8,10,12,14,16,18)
IntTab's are different sizes!
Nothing to print!
(-1,-2,-4,-6,-8,-10,-12,-14,-16,-18)
(2,4,8,12,16,20,24,28,32,36)

*/
