#ifndef __KAZIU_H_
#define __KAZIU_H_
#include "client.h"
/**
 * Klasa Pana kazia, obslugujacego klientow
 * @author Marcin Fabrykowski
 */
class Kaziu
{
	public:
		/**
		 * Obsluguje interesanta, tworzac z niego klienta
		 * @return Wskaznik do nowego klienta
		 */
		Client* Obsluz();
	private:
		/**
		 * Ustawia buildera uzywanego do tworzenia kolejnych obiektor
		 */
		void SetBuilder(ClientBuilder* build);
		/**
		 * Przechowuje aktualnie uzywanego buildera
		 */
		ClientBuilder* itsBuild;
};
#endif
