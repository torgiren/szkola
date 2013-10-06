#!/usr/bin/env python
#*-* coding: utf8 *-*
"""Modul symulujacy dzialanie GNU wc"""
from sys import argv


def slowa(lines):
    """Funkcja zlicznajaca slowa w vektorze"""
    lines = ''.join(lines)
    return lines.count(' ') + lines.count('\n')


def znaki(lines):
    """Funkcja zliczajaca znaki w wektorze"""
    lines = ''.join(lines)
    return len(lines)


def linie(lines):
    """Funkcja zwracajaca linie"""
    return len(lines)

func = []
pliki = []
for x in argv[1:]:
    if x == '-c':
        func.append(znaki)
    elif x == '-l':
        func.append(linie)
    elif x == '-w':
        func.append(slowa)
    else:
        pliki.append(x)
#print "pliki: ", pliki
#print "func: ", func
suma = {}
for plik in pliki:
    with open(plik) as f:
        lines = f.readlines()
        for fun in func:
            tmp = fun(lines)
            if suma.has_key(fun):
                suma[fun] += tmp
            else:
                suma[fun] = tmp
            print tmp,
    print plik
for f in func:
    print suma[f],
print
