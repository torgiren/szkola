/*****************************************************************************/
/* TEGO PLIKU, ABSOLUTNIE POD ZADNYM POZOREM NIE MODYFIKUJEMY !!!            */
/*****************************************************************************/
/*****************************************************************************/
/* Autor generatora:  Robert Musia³ek (2006)                                 */
/* Funkcje dodatkowe: Jacek Tarasiuk (2007)                                  */
/*****************************************************************************/

#ifndef RND_H
#define RND_H 1

/*funkcja inicjalizujaca generator, przyjmuje wartosc od 0 do 2^25           */
/*0 - pobieranie seed'a z pliku:"RND_Init.dat"                               */
/*kazda inna wartosc powoduje ustawienie seed'a na ta wartosc                */
void rnd_init(unsigned int seed=0);

/*zapis seed'a do pliku:"RND_Init.dat"                                       */
void rnd_save();

/*losuje float'a z zakresu (0,1)                                             */
double rnd_float();

/*losuje int'a z przedzialu [min,max)                                        */
/* UWAGA: najpierw jest max pozniej jest min !!!                             */ 
int rnd_int(int max, int min=0);

/*losuje wartoœæ bool, true z prawdopodobienstwem p                          */
bool rnd_bool(float p);

#endif
