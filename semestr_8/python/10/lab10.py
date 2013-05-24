#!/usr/bin/env python
from pprint import pprint
import glob
import numpy as np


class Zad1:
    def __init__(self, *args):
        try:
            self.gen = (x for x in args)
        except Exception:
            self.gen = (random.ranint(3, 100) for x in xrange(100))

    def _przez_11(self, val):
        parz = sum(int(x) for x in str(val)[0::2])
        nieparz = sum(int(x) for x in str(val)[1::2])
        if not (parz-nieparz)%11:
            return True
        else:
            return False

    def _przez_7(self, val):
        first = int(str(val)[0:3])
        sec = int(str(val)[3:6])
        if not (first-sec)%7:
            return True
        else:
            return False

    def zad1_2(self):
#        for i in self.gen:
        lista = list(self.gen)
        wynik1 = filter(self._przez_11, lista)
        wynik2 = filter(self._przez_7, lista)
        print wynik1;
        print wynik2;
        l = len(lista)
        print "Wspolczynnik podzielnosci przez 7 i 11:",
        print float(len(wynik1))/l,
        print float(len(wynik2))/l

class Zad2:
    def __init__(self, path, ext):
        self.pliki = glob.glob(path+"*."+ext)

    def get_p_q(self):
        for i in self.pliki:
            with open(i,"r") as f:
                slownik = {}
                line = "start"
                while line:
                    line = f.readline()
                    if ('p' in line) and ('q' in line):
                        line = line.split('_')[1:3]
                        try:
                            p = int(line[0][1:])
                            q = int(line[1][1:])
                            line = f.readline().split()
                            line = [(float(line[0])), (float(line[1]))]
                            if not slownik.has_key((p,q)):
                                slownik[(p,q)] = []
                            slownik[(p,q)].append(line)
#                            print p, q
                        except Exception:
                            pass
#                pprint(slownik)
                with open("wynik.out", "a+") as out:
                    for s in slownik:
                        arr = np.array(slownik[s])
#                    print arr
#                    print arr
                        #print np.average(arr)
                        avg = np.average(arr, axis=0)
                        out.write("%s %d %d %f %f\n"%(i, s[0], s[1], avg[0], avg[1]))

    pass

    def srednie(self):
        for i in self.pliki:
            with open(i, "r") as f:
                with open("wynik.out", "w") as out:
                    line = "start"
                    while line:
                        line = f.readline()
                        try:
                            line = [int(x) for x in line.split()]
                            if len(line) >= 2:
                                avg = float(line[0] + line[1]) / 2
                                print avg
                        except Exception:
                            pass


def zad1():
    x = Zad1(879732, 258016, 123432)
    x.zad1_2()

def zad2():
    x = Zad2("./", "out")
    x.get_p_q()

def zad2b():
    x = Zad2("./", "dat")
    x.srednie()

zad2()
