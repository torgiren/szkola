/*****************************************************************************/
/* TEGO PLIKU, ABSOLUTNIE POD ZADNYM POZOREM NIE MODYFIKUJEMY !!!            */
/*****************************************************************************/
/*****************************************************************************/
/* Autor generatora:  Robert Musia³ek (2006)                                 */
/* Funkcje dodatkowe: Jacek Tarasiuk (2007)                                  */
/*****************************************************************************/

#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib> //!!! Na niektorych komputerach nie dzialalo
#include "random.h"

unsigned long int lastrand=335544;
unsigned long int g;
unsigned long int M;

void rnd_init(unsigned int seed){

//M=2^25
M=33554432;
//najblizsza M liczba taka ze g<M oraz reszta z dzielenia g przez 8 
//wynosi 3 lub 5
g=33554429;

//pobranie seed'a z pliku
 if(seed==0){
  std::ifstream FileIn;
  FileIn.open("RND_Init.dat");
  std::string mystr;
  getline(FileIn,mystr);
  unsigned int tmp=std::atoi(mystr.c_str());
  if(tmp!=0)
   lastrand=tmp;
 }
//pobranie seed'a z parametru wywolania funkcji
 else{
   lastrand=seed;
 }
}

void rnd_save(){

 std::ofstream tmp("RND_Init.dat");
 tmp << lastrand << std::endl;
 tmp.close();

}

//liniowy generator kongruencyjny
double rnd_float(){

 int newrand=g*lastrand%M;
 lastrand=newrand;
 return (double)(newrand)/M;

}


int rnd_int(int max, int min){

 if(min==0){
  double prawd=1/(double)max;
  double temp=0;
  double r=rnd_float();
  for(int i=1;i<max+1;i++){
   temp+=prawd;
   if(temp>r){
    return --i;
	break;
   }
  }
 }
 else{
  if(min>0){
   double prawd=1/(double)(max-min);
   double temp=0;
   double r=rnd_float();
   for(int i=min+1;i<max+1;i++){
    temp+=prawd;
    if(temp>r){
     return --i;
	 break;
    }
   }
  }
 else{
  double prawd=1/(double)(max-min);
  double temp=0;
  double r=rnd_float();
  for(int i=1;i<max+1-min;i++){
   temp+=prawd;
   if(temp>r){
    return i-1+min;
	break;
   }
  }
 }
}
}

bool rnd_bool(float p)
{
 return (rnd_float()<p);
}
