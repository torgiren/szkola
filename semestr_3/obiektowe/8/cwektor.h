#ifndef __CWEKTOR__
#define __CWEKTOR__
///klasa wektor
class CWektor
{
	public:
		/**
		konstruktor klasy CWektor
		@param x wspolrzedna x
		@param y wspolrzedna y
		@param scale skala (domyslnie 1)
		*/
		CWektor(int x,int y,int scale=1);
		///konstruktor kopiujacy
		CWektor(const CWektor& orig);
		///Wypisywanie wektora na ekran
		void print() const;
		///Zwraca wektor o skali 1
		CWektor toScaledCWektor() const;
		///operator konwertujacy, zwracajacy dl. wektora
		operator double() const;
	private:
		int itsX,itsY;
		int itsScale;
};
#endif
