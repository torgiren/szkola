#ifndef __CLIENT_H_
#define __CLIENT_H_
#include <string>
/**
 * Klasa klienta strzelnicy
 * @author Marcin Fabrykowski
 */
class Client
{
	public:
		/**
		 * Konstruktor
		 */
		Client();
		/**
		 * Funkcja symulujaca strzelanie z broni
		 */
		void Strzelaj();
		/**
		 * Funkcja zwracajaca ilosc pozostalych naboi
		 * @return Liczba pozostalych napoi
		 */
		int RetShotsLeft();
		/**
		 * Funkcja zwracajaca aktualna bron klienta
		 * @return Nazwa broni
		 */
		std::string RetBron();
		/**
		 * Daje bron klientowi
		 * @param bron Nazwa broni
		 */
		void SetBron(std::string bron);
		/**
		 * Zwraca numer klienta
		 * @return Numer klienta
		 */
		int RetLp() {return itsLp;};
	private:
		/**
		 * Numer klienta
		 */
		int itsLp;
		/**
		 * Liczba pozostalych strzalow
		 */
		int itsStrzalow;
		/**
		 * Posiadana bron
		 */
		std::string itsBron;
};
/**
 * Builder klas Klientow
 * @author Marcin Fabrykowski
 */
class ClientBuilder
{
	public:
		/**
		 * Tworzenie klienta
		 */
		void CreateClient();
		/**
		 * Zwraca stworzonego klienta
		 * @return Wskaznik do utworzonego klienta
		 */
		Client* RetClient() {return itsClient;};
		/**
		 * Wirtualna funkcja ustawiania broni
		 */
		virtual void SetBron()=0;
	protected:
		/**
		 * Wstaznik na utworzonego klienta
		 */
		Client* itsClient;
};
/**
 * Budowniczy Klienta z pistoletem
 * @author Marcin Fabrykowski
 */
class PistolClientBuilder: public ClientBuilder
{
	public:
		/**
		 * Ustawia pistolet jako bron klienta
		 */
		void SetBron();
};
/**
 * Budowniczy Klienta z kusza
 * @author Marcin Fabrykowski
 */
class CrossbowClientBuilder: public ClientBuilder
{
	public:
		/**
		 * Ustawia kusze jako bron klienta
		 */
		void SetBron();
};
/**
 * Budowniczy Klienta z karabinem
 * @author Marcin Fabrykowski
 */
class RifleClientBuilder: public ClientBuilder
{
	public:
		/**
		 * Ustawia karabin jako bron
		 */
		void SetBron();
};
#endif
