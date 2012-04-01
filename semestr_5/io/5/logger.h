#ifndef __LOGGER_H_
#define __LOGGER_H_
#include <string>
#include <fstream>
#include <pthread.h>
/**
 * Klasa logujaca wydarzenia w strzelnicy
 * @author Marcin Fabrykowski
 */
class Logger
{
	public:
		/**
		 * Zwraca instancje singletona
		 * @return Wskaznik na jedyna instancje
		 */
		static Logger* GetInstance() { static Logger* base=NULL; if(!base) base=new Logger(); return base;};
		/**
		 * Ustawia sciezke do pliku logow. Jesli plik istnieje, zostanie nadpisany
		 * @param path sciezka do pliku
		 */
		void SetPath(std::string path)
		{
			Lock();
			itsPath=path;
			Reopen();
			Unlock();
		};
		/**
		 * Ustawia moemnt od ktorego bedzie liczony czas w logach
		 */
		void StartTimer() {time (&itsStart);;};
		/**
		 * Loguje zadany ciag znakow. Automatycznie dodaje znak konca lini
		 * @param data Dane do zalogowania
		 */
		void Log(std::string data);
	private:
		/**
		 * Prywatny konstrukto
		 */
		Logger();
		/**
		 * Blokuje mutexa w celu unikniecia kolizji watkow
		 */
		void Lock() {pthread_mutex_lock(&itsMutex);};
		/**
		 * Odblokowywuje mutexa
		 */
		void Unlock() {pthread_mutex_unlock(&itsMutex);};
		/**
		 * Sciezka do pliku logow
		 */
		std::string itsPath;
		/**
		 * Ponownie otwiera plik z logami po zmianie nazwy pliku docelowego
		 */
		void Reopen();
		/**
		 * Strumien do pliku logow
		 */
		std::ofstream itsStream;
		/**
		 * Mutex bezpieczenstwa
		 */
		pthread_mutex_t itsMutex;
		/**
		 * Czas poczatkowy do wyliczania czasu w logach
		 */
		time_t itsStart;
};
#endif
