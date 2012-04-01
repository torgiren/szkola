//Mamy taki oto plik zrodlowy:
#include <iostream>

using namespace std;

class wydatkiMiesieczne
{
   public:
		wydatkiMiesieczne():cenaChleb(2),cenaMleko(3),cenaGazeta(2),zakupChleba(false),zakupMleka(false),zakupGazety(false),pensja(0),sumaWydatkowMiesiecznych(0),czyWystarczaNaMiesiac(false) {};
      //w tym miejscu wpisz brakujace metody klasy
	  void zarobek(int kwota) {pensja=kwota;};
	  void czyKupujeChleb(bool state) {zakupChleba=state;};
	  void czyKupujeMleko(bool state) {zakupMleka=state;};
	  void czyKupujeGazete(bool state) {zakupGazety=state;};
	  void obliczanieWydatkowMiesiecznych() {sumaWydatkowMiesiecznych=30*(zakupChleba?cenaChleb:0)+30*(zakupMleka?cenaMleko:0)+30*(zakupGazety?cenaGazeta:0);};
	  bool czyWystarczaPieniedzyNaWydatkiMiesieczne() {return pensja>sumaWydatkowMiesiecznych;};

   private:
      int cenaChleb;  //
      int cenaMleko;  //ceny produktow (przypisz je w konstruktorze)
      int cenaGazeta; //

      bool zakupChleba; //
      bool zakupMleka;  //zmienne true/false
      bool zakupGazety; //

      int pensja; //pensja obiektu (czlowieka)
      int sumaWydatkowMiesiecznych; //zmienna ktora sumuje wydatki
      bool czyWystarczaNaMiesiac; //zmienna przechowuje true jesli pensja jest wieksza niz wydatki; jesli jest odwrotnie - false
};

int main(int argc, char** argv)
{
   wydatkiMiesieczne Marian;
   Marian.zarobek(200);
   Marian.czyKupujeChleb(true);
   Marian.czyKupujeMleko(true);
   Marian.czyKupujeGazete(true);
   Marian.obliczanieWydatkowMiesiecznych();
   cout << "Pensja Mariana " << (Marian.czyWystarczaPieniedzyNaWydatkiMiesieczne() ? "jest wystarczajaca" : "nie jest wystarczajaca");
   cout << " na pokrycie kosztow codziennych zakupow" << endl;

   wydatkiMiesieczne* Jadwiga = new wydatkiMiesieczne;
   Jadwiga->zarobek(12000);
   Jadwiga->czyKupujeChleb(true);
   Jadwiga->czyKupujeMleko(true);
   Jadwiga->czyKupujeGazete(false);
   Jadwiga->obliczanieWydatkowMiesiecznych();
   cout << "Pensja Jadwigi " << (Jadwiga->czyWystarczaPieniedzyNaWydatkiMiesieczne() ? "jest wystarczajaca" : "nie jest wystarczajaca");
   cout << " na pokrycie kosztow codziennych zakupow" << endl;
   delete Jadwiga;

   getchar();
   return 0;
}
/*
Program ten oblicza czy pensja, ktora dostaje czlowiek zdefiniowany jako obiekt klasy wydatkiMiesieczne, jest w stanie pokryc uproszczone wydatki miesieczne. Jednak program nie jest kompletny. Uzupelnij brakujace pola klasy w sekcji public stosujac sie do ponizszych instrukcji:
Uzyj konstruktora do przypisania wartosci polom danych:
   +-----------+-----------------+
   |nazwa pola |wartosc ktora ma |
   |  danych   |zostac przypisana|
   +-----------+-----------------+
   | cenaChleb |         2       |
   | cenaMleko |         3       |
   | cenaGazeta|         2       |
   |           |                 |
   | sumaWydat-|                 |
   | kowMiesie-|         0       |
   | cznych    |   (opcjonalnie) |
   +-----------+-----------------+
Pamietaj ze zmienne cenaChleb, cenaMleko i cenaGazeta reprezentuja cene za jedna sztuke danego produktu, a my bedziemy potrzebowac ceny za zakup tych towarow przez caly miesiac (przyjmijmy ze miesiac ma 30 dni).
Nie tworz innych funkcji w sekcji public niz te, ktore zostaly wywolane w funkcji main().
Funkcja zarobek() ma pobierac liczbe reprezentujaca zarobek danej osoby (w zl) i wpisywac ta wartosc w zmienna pensja.
Funkcje z przedrostkami czyKupuje- maja przypisywac wartosc (true - jesli kupuje dany produkt; false - jesli nie) do swoich odpowiednikow z sekcji private (np. funkcja czyKupujeMleko() przypisze wartosc zmiennej zakupMleka).
Funkcja obliczanieWydatkowMiesiecznych() ma obliczyc kwote jaka bedzie wydana przez miesiac kupowania ustalonych przez obiekt produktow i przypisac wynik zmiennej sumaWydatkowMiesiecznych.
Funkcja czyWystarczaPieniedzyNaWydatkiMiesieczne() ma obliczyc czy pensja danego obiektu jest wystarczajaca na pokrycie kosztow zakupow, przekazac wynik true, albo false do zmiennej czyWystarczaNaMiesiac i zwrocic go.
*/
