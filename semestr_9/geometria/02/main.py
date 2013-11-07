#!/usr/bin/env python
#*-* conding: utf8 *-*
from ps import PS
import math

def trojkat(p):
    a = 100.0
    p.newpath()
    B = (0, 0)
    C = (a, 0)
    A = (a / 3, a / 2)
    p.moveto(0, 0)
    p.line(*C)
    p.line(*A)
    p.line(*B)
    p.stroke()
    Cp = ((A[0] + B[0]) / 2.0, (A[1] + B[1]) / 2)
    Ap = ((C[0] + B[0]) / 2.0, (C[1] + B[1]) / 2)
    Bp = ((C[0] + A[0]) / 2.0, (A[1] + C[1]) / 2)
    p.newpath()
    p.colour(255, 0, 0)
    p.moveto(*Cp)
    p.line(*C)
    p.stroke()

    p.newpath()
    p.colour(0, 255, 255)
    p.moveto(*Ap)
    p.line(*A)
    p.stroke()

    p.newpath()
    p.colour(0, 0, 255)
    p.moveto(*Bp)
    p.line(*B)
    p.stroke()

def zad1():
    ps = PS()
    ps.translate(200, 200)
    trojkat(ps)
    print ps.gen()
    with open("cevy.ps", "w") as cevy:
        cevy.write(ps.gen())
zad1()
