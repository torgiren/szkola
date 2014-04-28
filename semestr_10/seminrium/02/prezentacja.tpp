--title Dokumenty z treścią opartą o bazę danych
--author Marcin Fabrykiwski
--date today
--header                                         
--withborder
---
--newpage Spis treści
--footer Marcin Fabrykowski
--header Dokumenty z treścią opartą o bazę danych
--heading Spis treści
--withborder

+ Opis
|
+ Technologie
|\
| + Aplikacja
| |
| + Baza danych
|/
+ Struktura danych
|
+ Postęp prac
---
--newpage Opis
--heading Opis
--withborder

Opis pracy był już przedstawainy na poprzedniej prezentacji

--newpage Technologie
--heading Technologie
--withborder

+ Aplikacja
|
+ GUI

--newpage Technologie/ Aplikacja
--heading Technologie/ Aplikacja
--withborder

Backend: Python

Frontend: HTML + Javascript

--newpage Technologie/ Baza danych
--heading Technologie/ Baza danych
--withborder

+ PostgreSQL
---
|\
| + Niewygodny
|/
---
+ MongoDB
---
|\
| + Idealne rozwiązanie
|/

--newpage Struktura danych
--heading Struktura danych
--withborder

+ Formatki
|\
| + _id: ...
| + nazwa: nazwa formularza
| + template: jinja2 formularza
| + pola: lista pól
| |\ 
| | + nazwa: ...
| | + typ: input, checkbox
| | + TODO
| |/
|/
---
+ Wpisy
|\
| + _id: ...
| + formatka: id formatki
| + pola: wpisane wartości
| |\
| | + nazwa: ...
| | + wartosc: ...
| |/
|/

--newpage Postęp prac
--heading Postęp prac
--withborder

+ Zrobione:
||
| + Wstępny edytor do formularzy
| |
| + Wyświetlanie formularzy
|/
---
+ Do zrobienia:
|| 
| + Edycja formularzy
| |
| + Wypełnianie formularzy
| |
| + Przeglądanie formularzu
| |
| + Filtrowanie wyników
|/
