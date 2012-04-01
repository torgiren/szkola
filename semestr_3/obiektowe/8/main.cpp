#include "lab07.h"

int main() {
	int i;
	cout << "Podaj liczbe calkowita i= ";
	cin >> i;

	cout << " -- 1 --\n";

	CWektor p(1*i,2*i);
	CWektor q(3*i,4*i,2);
	CWektor s = q;

	cout << " -- 2 --\n";

	p.print();
	q.print();
	s.print();

	cout << " -- 3 --\n";

	CWektor r = q.toScaledCWektor();
	r.print();

	cout << " -- 4 --\n";

	double f = 1./sqrt(5.0);
	double x = f * p;
	cout << "Dlugosc wektora p pomnozona przez " << f << " wynosi ";
	cout << x << "\n";

	cout << " -- 5 --\n";

	return 0;
}

// Wyniki uruchomienia
// (na przykladzie kilku wybranych wartosci i=1,-10,3):

/*
Podaj liczbe calkowita i= 1
 -- 1 --
Tworze wektor = (1,2), skala = 1
Tworze wektor = (3,4), skala = 2
Przy kopiowaniu zawsze ustawiam skale = 1.0
 -- 2 --
(1,2)  // = (1,2) * 1;
(6,8)  // = (3,4) * 2;
(3,4)  // = (3,4) * 1;
 -- 3 --
Tworze wektor = (6,8), skala = 1
(6,8)  // = (6,8) * 1;
 -- 4 --
Konwersja do double, czyli wyliczenie dlugosci wektora
Dlugosc wektora p pomnozona przez 0.447214 wynosi 1
 -- 5 --
*/

/*
Podaj liczbe calkowita i= -10
 -- 1 --
Tworze wektor = (-10,-20), skala = 1
Tworze wektor = (-30,-40), skala = 2
Przy kopiowaniu zawsze ustawiam skale = 1.0
 -- 2 --
(-10,-20)  // = (-10,-20) * 1;
(-60,-80)  // = (-30,-40) * 2;
(-30,-40)  // = (-30,-40) * 1;
 -- 3 --
Tworze wektor = (-60,-80), skala = 1
(-60,-80)  // = (-60,-80) * 1;
 -- 4 --
Konwersja do double, czyli wyliczenie dlugosci wektora
Dlugosc wektora p pomnozona przez 0.447214 wynosi 10
 -- 5 --
*/

/*
Podaj liczbe calkowita i= 3
 -- 1 --
Tworze wektor = (3,6), skala = 1
Tworze wektor = (9,12), skala = 2
Przy kopiowaniu zawsze ustawiam skale = 1.0
 -- 2 --
(3,6)  // = (3,6) * 1;
(18,24)  // = (9,12) * 2;
(9,12)  // = (9,12) * 1;
 -- 3 --
Tworze wektor = (18,24), skala = 1
(18,24)  // = (18,24) * 1;
 -- 4 --
Konwersja do double, czyli wyliczenie dlugosci wektora
Dlugosc wektora p pomnozona przez 0.447214 wynosi 3
 -- 5 --
*/
