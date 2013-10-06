#!/usr/bin/env python
#*-* coding: utf8 *-*
import mystat
from glob import glob
import cesar


def zad1():
    pliki = glob("*.dat")
    for plik in pliki:
        with open(plik, "r") as f:
            wartosci = f.xreadlines()
            wartosci = [float(x) for x in wartosci]
            print "Plik \"", plik, "\"",
            if len(wartosci) > 10:
                print ">10"
                print "Srednia:", mystat.avg(wartosci)
                print "Odchylenie:", mystat.odchylenie(wartosci)
            else:
                print "<10"
                print "Mediana:", mystat.mediana(wartosci)
                print "Rozstep:", mystat.rozstep(wartosci)


def zad3():
    liczba = "LIX"
    wynik = 0
    wartosci = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500,
                'M': 1000}

    double = {'IV': 4, 'IX': 9, 'XL': 40, 'XC': 90, 'CD': 400, 'CM': 900}
    for d in double.items():
        tmp = liczba.count(d[0])
        wynik += d[1] * tmp
        liczba = liczba.replace(d[0], '')
    for i in liczba:
        wynik += wartosci[i]
    print wynik


def zad4():
    with open("pt.txt") as f:
        text = ''.join(f.xreadlines())

    tmp = cesar.code(text, 1)
    print tmp
    print cesar.decode(tmp)

zad3()
