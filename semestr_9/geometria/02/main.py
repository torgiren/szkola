#!/usr/bin/env python
#*-* conding: utf8 *-*
from ps import PS
import math

def trojkat(p, A, B, C):
    p.newpath()
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
    a = 100.0
    B = (0, 0)
    C = (a, 0)
    A = (a / 3, a / 2)
    ps = PS()
    ps.translate(200, 200)
    trojkat(ps, A, B, C)
    print ps.gen()
    with open("cevy.ps", "w") as cevy:
        cevy.write(ps.gen())


def srodek(A, B):
    return ((A[0] + B[0]) / 2.0, (A[1] + B[1]) / 2.0)

def prostopadla(A, B, C):
    vec = (B[0]- A[0], B[1]- A[1])
    ob = - math.pi /2.0
    #ob = 0
    vec =  (vec[0] * math.cos(ob) - vec[1] * math.sin(ob), vec[0] * math.sin(ob) + vec[1] * math.cos(ob))
    vec = (vec[0] * 1.5, vec[1] * 1.5)
    vec = (vec[0] + C[0] , vec[1] + C[1])
    return vec

def trojkat2(p, A, B, C):
    p.newpath()
    p.moveto(*C)
    p.line(*prostopadla(A, B, C))
    p.stroke()

    p.newpath()
    p.moveto(*A)
    p.line(*prostopadla(B, C, A))
    p.stroke()

    p.newpath()
    p.moveto(*B)
    p.line(*prostopadla(C, A, B))
    p.stroke()


    p.colour(1,0,1)
    p.newpath()
    T = srodek(B, C)
    p.moveto(*T)
    p.line(*prostopadla(C, B, T))
    p.stroke()

    p.newpath()
    T = srodek(A, B)
    p.moveto(*T)
    p.line(*prostopadla(B, A, T))
    p.stroke()

    p.newpath()
    T = srodek(C, A)
    p.moveto(*T)
    p.line(*prostopadla(A, C, T))
    p.stroke()
    pass



def zad2():
    a = 100.0
    B = (0, 0)
    C = (a, 0)
    A = (a / 3, a / 2)
    ps = PS()
    ps.translate(200, 200)
    trojkat(ps, A, B, C)
    trojkat2(ps, A, B, C)
    print ps.gen()
    with open("euler.ps", "w") as euler:
        euler.write(ps.gen())

zad1()
zad2()
