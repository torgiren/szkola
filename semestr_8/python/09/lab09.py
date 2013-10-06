#!/usr/bin/env python
from stack import Stack
from flexstack import FlexStack
from wektor import Wektor


def zad1(n):
    s = Stack()
    while n > 0:
        s.push(n % 2)
        n /= 2
    return str(s)


def zad2():
    s = FlexStack()
    s.push(3)
    s.push(4)
    s.push(6)
    s.push(8)
    print s
    print s[1]
    print s
    s[1] = 66
    print s
#    s[10] = 10
#    print s
    del s[1]
    print s
    print 55 in s
    s.push(55)
    print 55 in s


def zad3():
    w = Wektor([1, 2, 6])
    v = Wektor([1, 2, 7])
    print w + w
    print w + 1
    print w * v
    print v * w
    print w.len()
    print w
    print w * 2
    print 2 * w
    w = w * 2
    print w

zad3()
