#include "lab02.h"

int main(void)
{
 Liczby s;

 s.init();

 std::cout<<"Rozmiar s:"<<s.size()<<std::endl;

 s.push(2); s.push(13); s.push(1);

 std::cout<<"Rozmiar s:"<<s.size()<<std::endl;
 s.print_to_cout();

 s.pop();

 std::cout<<"Rozmiar s:"<<s.size()<<std::endl;
 s.print_to_cout();

 s.push(6);
 s.push(2);

 s.print_to_cout();

 s.sort();
 s.print_to_cout();

 int size=s.size();
 int tab[]={14,17,6,2,14,32,1};
 for (int i=0;i<size;i++) s.pop();
 std::cout<<"Rozmiar s:"<<s.size()<<std::endl;
 s.push(tab,7);

 s.print_to_cout();

 s.sort();
 s.print_to_cout();

 s.clean_up();

 return 0;
}

/* wyjscie:

Rozmiar s:0
Rozmiar s:3
[2,13,1]
Rozmiar s:2
[2,13]
[2,13,6,2]
[2,2,6,13]
Rozmiar s:0
[14,17,6,2,14,32,1]
[1,2,6,14,14,17,32]

*/



