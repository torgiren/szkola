#!/usr/bin/python
#*-* coding: utf8 *-*
import random


def zad1(param):
    return {k: "%.3f" % eval('param * k') for k in [random.random() for j in range(random.randrange(20))]}


def zad2(*args):
    wynik = []
    for i in args[0]:
        for j in args[1:]:
            if i not in j: break;
        else:
            wynik.append(i)
    return wynik


def zad3(s1, s2, param=True):
    wynik = []
    if param:
        if len(s1) < len(s2):
            s = s1
        else:
            s = s2
        s.extend([None] * abs(len(s1) - len(s2)))
    m = min((len(s1), len(s2)))
    for x in range(m):
        wynik.append((s1[x], s2[x]))
    return wynik

def zad4(f, *args):
    args =list(args)
    args.sort(cmp=f)
    return (min(args), max(args))

def zad5(kwota, nominaly=[10,5,2]):
    wynik = []
    for i in nominaly:
        wynik.append(kwota/i)
        kwota = kwota%i
    if kwota == 0:
        return wynik
    else:
        return False

def zad6(szukana, left, right, method='r'):
    l = 0
    l = random.randint(left, right)
    kroki = 0
    while szukana <> l:
        kroki += 1
        if method=='r':
            l = random.randrange(left, right)
        elif method=='b':
            mid = (left + right ) /2
            if szukana < mid:
                right = mid
            else:
                left = mid
            l = left
    return kroki
print "Zad 1"
#print zad1('4')
print "Zad 2"
print zad2([1,2,3,4], (4,5,6,3,7), [4,6,2])

print "Zad3"
print zad3([1,2,3], [5,4,3,2,1,8,9], True)
print zad3([1,2,3], [5,4,3,2,1,8,9], False)

def comparator(a, b):
    if a<b:
        return -1
    elif a>b:
        return 1
    else:
        return 0

print "Zad 4"
print zad4(comparator, 4,6,7,2,1,6,8,4,1,55)

print "Zad 5"
print zad5(27)

print "Zad 6"
print zad6(123, 0 , 1000, 'r')
print zad6(123, 0 , 1000, 'b')
