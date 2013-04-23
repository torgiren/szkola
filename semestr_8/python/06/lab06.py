#!/usr/bin/env python
#*-* coding: utf8 *-*
from glob import glob
import numpy as np


def func1(f, n):
    with open(f) as plik:
        lines = plik.readlines()
        print "Poczatek:"
        print lines[:n]
        print "Koniec:"
        print lines[-n:]
        print "Konkretna"
        print lines[n - 1::n]
        print [(l[n], l.split()[n]) for l in lines]


def func2(f, str1, str2):
    with open(f) as plik:
        lines = plik.read()
        print lines.count(str1)
        print ""
        print "\n".join([i for i in lines.splitlines() if i.startswith(str1)])
        print ""
        print lines.replace(str1, str2)


def func3():
    x = []
    y = []
    for f in glob("*.dat"):
        with open(f) as plik:
            xval = []
            yval = []
            for l in plik.readlines():
                tmp = l.split()
                xval.append(tmp[0])
                yval.append(tmp[1])
            x.append(xval)
            y.append(yval)
    x = zip(*x)
    y = zip(*y)
    x = np.array([i for i in x], dtype=np.int)
    y = np.array([i for i in y], dtype=np.int)
    print x
    print y
    print "srednia"
    wynik1 = x.mean(axis=1)
    print "srodkowa"
    wynik2 = y[:, y.shape[1] / 2]
    print "rozstep"
    wynik3 = y.max(axis=1) - y.min(axis=1)
    with open('wynik.txt', "w") as out:

        wynik = zip(wynik1, wynik2, wynik3)
        print wynik
        out.writelines(["%f %f %f\n" % (w[0], w[1], w[2]) for w in wynik])


def func4():

    out = open('plot.plt', "w")
    out.write('''set term png
set out "plot.png"
plot "1.dat" title "1",\\
"2.dat" title "2",\\
"3.dat" title "3",\\
"wynik.txt" title "wynik"\n''')
    out.close()


def func5():
    wynik = set()
    first = True
    for f in glob("*.py"):
        with open(f) as plik:
            words = set(plik.read().split())
            if first:
                first = False
                wynik = words
            else:
                wynik = wynik.intersection(words)

    print wynik
#func1("proba.txt", 3)
#func2("proba.txt", 'li', '__')
#func2("proba.txt", 'mam', 'Mam')

#func3()
#func4()
func5()
