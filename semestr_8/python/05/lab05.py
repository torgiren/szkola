#!/usr/bin/env python
#*-* coding:utf-8 *-*
import numpy as np
def pow(val, stop):
    wynik=val
    for i in range(stop):
        yield wynik
        wynik = wynik * val

def zero_count(seq):
    while len(seq):
        pos = 0
        while not seq[0]:
            pos += 1
            seq = seq[1:]
            if not len(seq): break
        yield pos
        seq = seq[1:]


def fib():
    a, b = 1, 1
    yield 1
    yield 1
    while True:
       a, b = a + b, a
       yield a

def fib2(seq, parz=1):
    for f in seq:
        if (not f%2 and parz) or (f%2 and not parz):
            yield f

def fib3(seq, stop):
    for i in seq:
        if i > stop:
            break;
        yield i

def my_range(start=0, stop=100, step=1):
    val = start
    if (start > stop) and step > 0:
        return
    if (start < stop) and step < 0:
        return
    if step == 0:
        return
    while True:
        if (step > 0) and (val >= stop):
            return;
        if (step < 0) and (val <= stop):
            return;
        yield float(val)
        val += step

def my_rand():
    old = 0
    while True:
        x = np.random.rand()
        if x < 0.1:
            break;
        if np.fabs(x - old) < 0.4:
            old = x
            yield x


def rek(a = 0.05):
    u, x = 0.0, 1.0
    while True:
        u, x = u + a / x, x + a
        yield u


def zad1():
    for i in pow(3, 10):
        print i


def zad2(N):
    los = np.random.randn(N)
    los = (los > 0) * 1
    print np.average([i for i in zero_count(los)])


def zad3(N):
    s = fib()
    for i in xrange(N):
        print s.next()

    print "fib2"
    s = fib2(fib(),0)
    for i in xrange(N):
        print s.next()

    print "fib3"
    for i in fib3(fib(),100):
        print i

def zad4():
    print np.sum(fib3(fib2(fib(),1), 100))

def zad5():
    for i in my_range(0,10):
        print i
    for i in my_range(10, 1, -0.5):
        print i

def zad6():
    for i in my_rand():
        print i

def zad7():
    s = rek()
    for i in xrange(10):
        print s.next()

zad6()
