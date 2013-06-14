#!/usr/bin/env python
#*-* coding: utf8 *-*
from random import random

n1 = 4
n2 = 3


class ParamError(Exception):
    pass


class Siatka:
    def __init__(self, rozmiar=(5, 5)):
        self.rozmiar = rozmiar

    @staticmethod
    def get_sasiedzi(punkt, ilu):
        if ilu == 4:
            wynik = [(punkt[0] - 1, punkt[1]),
                     (punkt[0] + 1, punkt[1]),
                     (punkt[0], punkt[1] - 1),
                     (punkt[0], punkt[1] + 1)]
        elif ilu == 8:
            wynik = [(punkt[0] - 1, punkt[1]),
                     (punkt[0] + 1, punkt[1]),
                     (punkt[0], punkt[1] - 1),
                     (punkt[0], punkt[1] + 1),
                     (punkt[0] - 1, punkt[1] - 1),
                     (punkt[0] + 1, punkt[1] - 1),
                     (punkt[0] - 1, punkt[1] + 1),
                     (punkt[0] + 1, punkt[1] + 1)]
        else:
            raise ParamError
        return wynik


class Iter(Siatka):
    def __init__(self, rozmiar=(5, 5)):
        Siatka.__init__(self, rozmiar)
#        super(Siatka,self).__init__(rozmiar)
        self.lista = []

    def __iter__(self):
        return self

    def brzegi(self):
        self.lista = [(i, j) for i in (0, self.rozmiar[0] - 1) for j in range(self.rozmiar[1])] +\
                     [(i, j) for j in (0, self.rozmiar[
                                       1] - 1) for i in range(1, self.rozmiar[0] - 1)]
        return self

    def wnetrze(self):
        self.lista = [(i, j) for i in range(
            1, self.rozmiar[0] - 1) for j in range(1, self.rozmiar[1] - 1)]
        return self

    def next(self):
        if self.lista:
            return self.lista.pop()
        raise StopIteration


class Automat:
    def __init__(self, rozmiar=(5, 5), sasiedzi=4):
        self.iter = Iter(rozmiar)
        self.nowy = {}
        self.last = {}
        self.sasiedzi = sasiedzi
        self.start()

    def start(self):
        for i in self.iter.brzegi():
            if random() >= 0.2:
                self.nowy[i] = 1
        self.poczatkowe = self.nowy.copy()
        self.poczatkowe_ilosc = len(self.poczatkowe)

    def krok(self):
        self.last = self.nowy.copy()
        self.nowy = self.poczatkowe.copy()
        for p in self.iter.wnetrze():
            ilu = sum([1 for i in self.iter.get_sasiedzi(
                p, self.sasiedzi) if i in self.last])
            if p in self.last:
                if ilu < n1:
                    self.nowy[p] = 1
            else:
                if ilu > n2:
                    self.nowy[p] = 1

    def wypisz(self):
        print self.nowy.keys()

    def policz(self):
        return len(self.nowy) - self.poczatkowe_ilosc

    def tabela(self):
        for i in range(self.iter.rozmiar[0]):
            for j in range(self.iter.rozmiar[1]):
                if (i,j) in self.last:
                    print 1,
                else:
                    print 0,
            print ""

automat = Automat((100, 100), 8)
automat.wypisz()
for i in range(100):
    automat.krok()
#    automat.tabela()
    print "\t\t\t%d: %d"%(i,automat.policz())
