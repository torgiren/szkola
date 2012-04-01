#ifndef __STRZELNICA_H_
#define __STRZELNICA_H_
#include <list>
#include <pthread.h>
#include "client.h"
#include "kaziu.h"
/**
 * Klasa zajmujaca sie obsluga strzelnicy
 * @author Marcin Fabrykowski
 */
class Strzelnica
{
	public:
		/**
		 * Zwraca wskaznik na instancje singletona
		 * @return Wskaznik na instancje Strzelnicy
		 */
		static Strzelnica* GetInstance() {static Strzelnica* base=new Strzelnica(10);return base;};
		/**
		 * Symuluje nowego interesanta
		 */
		void Nowy();
		/**
		 * Zamyka strzelnice. Oczekuje do skonczenia strzelania klientow w strzelnicy
		 */
		void Zamknij() {itsOtwarte=false;};
		/**
		 * Glowna petla pobierajaca klientow z kolejki i umieszczajaca ich na odpowiednich torach
		 * @param ptr nieuzywane
		 */
		static void* MainLoop(void* ptr);
		/**
		 * Zwraca id watku glowej petli strzelnicy
		 * @return id watku MainLoop
		 */
		pthread_t RetMainLoopThread() {return itsMainLoopThread;};	
	private:
		/**
		 * Prywatny konstruktor
		 * @param tory Liczba torow w strzelnicy
		 */
		Strzelnica(int tory);	
		/**
		 * Funkcja uruchamiana dla kazdego klienta w osobnym watku
		 * @param top Numer toru ktory ma byc obsluzony przez funkcje
		 */
		static void* Obsluz(void* tor);
		/**
		 * Przydziela danego klienta do zadanego toru
		 * @param client Wskaznik do klienta
		 * @param tor numer toru na ktory przydzielany jest klient
		 */
		void Przydziel(Client* client,int tor);
		/**
		 * Znajduje pierwszy wolny tor i rezerwuje go
		 * @return Numer pierwszego wolnego toru, badz -1 w przypadku jego braku
		 */
		int FirstFree();
		/**
		 * Blokuje mutex odpowiedzialny za pilnowanie kolejki
		 */
		void Lock() {pthread_mutex_lock(&itsMutex);};
		/**
		 * Odblokowuje mutexa odpowiedzialnego za pilnowanie kolejki
		 */
		void Unlock() {pthread_mutex_unlock(&itsMutex);};
		/**
		 * Wartosc wskazujaca czy strzelnica nadal przyjmuje interesantow
		 */
		bool itsOtwarte;
		/**
		 * Wartosc wskazujaca ile jest torow w strzelnicy
		 */
		int itsIleTorow;
		/**
		 * Kolejka interesantow czekajacych na dojscie do torow
		 */
		std::list<Client*> itsKolejka;
		/**
		 * Mutex pilnujacy kolejki klientow
		 */
		pthread_mutex_t itsMutex;
		/**
		 * Tablica mutexow pinujacych poszczegolne tory
		 */
		pthread_mutex_t *itsMutexTory;
		/**
		 * Tablica przyporzadkowujaca wskazniki klientow do poszczegolnych torow
		 */
		Client** itsKlientTory;
		/**
		 * Wskaznik na obsluge strzelnicy (Pan Kaziu)
		 */
		Kaziu itsObsluga;
		/**
		 * Id watku glownej petli
		 */
		pthread_t itsMainLoopThread;
		/**
		 * Liczba ludzi w strzelnicy
		 */
		int itsLiczbaLudzi;

};
#endif
