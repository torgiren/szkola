#!/usr/bin/env python
#*-* coding: utf8 *-*

from ps import PS
import math


def podzial_odcinka():
    a = 100.0
    b = (a ** 2 + (a / 2) ** 2) ** 0.5
    c = b - a / 2
    p = PS()
    p.translate(200, 200)
    p.newpath()
    p.moveto(0, 0)
    p.rline(a, 0)
    p.colour(1, 0, 0)
    p.stroke()

    p.newpath()
    p.moveto(a, 0)
    p.rline(c, 0)
    p.colour(0, 1, 0)
    p.stroke()

    p.newpath()
    p.moveto(0, 0)
    p.rline(0, a)
    p.rline(a, 0)
    p.rline(0, -a)
    p.moveto(a / 2, 0)
    p.rline(0, a)
    p.colour(0, 0, 0)
    p.stroke()

    p.newpath()
    p.moveto(a / 2, 0)
    p.line(a, a)
    p.dash()
    p.colour(0, 0, 0)
    p.stroke()

    p.newpath()
    a2 = math.degrees(math.atan(a / (a / 2)))
    p.arc(a / 2, 0, b, 0, a2)
    p.stroke()

    p.setfont()
    p.newpath()
    p.moveto(-5, -10)
    p.text("A")
    p.moveto(a / 2 - 5, -10)
    p.text("B")
    p.moveto(a - 5, -10)
    p.text("C")
    p.moveto(a + c - 5, -10)
    p.text("D")
    p.moveto(a - 5, a + 5)
    p.text("E")

    print p.gen()
    odcinek = open("odcinek.ps", "w")
    odcinek.write(p.gen())
    odcinek.close()


def wpisany():
    a = 100.0
    h = a * math.sqrt(3) / 2.0
    R = h * 2.0 / 3.0
    A = (0.0, 0.0)
    B = (a, 0)
    C = (a / 2, h)
    G = (a / 2.0, h / 3.0)
    D = (math.cos(math.radians(60)) * a / 2.0,
         math.sin(math.radians(60)) * a / 2.0)
    E = (B[0] + math.cos(math.radians(120)) * a / 2.0,
         B[1] + math.sin(math.radians(120)) * a / 2.0)
    Fx = a / 2 + math.sqrt(R ** 2  - (D[0] - G[1] ) ** 2) - 1
    F = (Fx, D[1])


    p = PS()
    p.translate(200, 200)
    p.setfont()
    p.moveto(0, 0)
    p.line(*B)
    p.line(*C)
    p.line(*A)
    p.stroke()
    p.arc(G[0], G[1], R, 0, 360)
    p.stroke()
    p.arc(G[0], G[1], 0.1, 0, 360)
    p.stroke()
    p.colour(1, 0, 0)
    p.moveto(*D)
    p.line(*E)
    p.stroke()
    p.colour(0, 1, 0)
    p.moveto(*E)
    p.line(*F)
    p.stroke()

    p.colour(0, 0, 0)
    p.moveto(*A)
    p.rmoveto(-10, -10)
    p.text("A")
    p.moveto(*B)
    p.rmoveto(5, -10)
    p.text("B")
    p.moveto(*C)
    p.rmoveto(0, 5)
    p.text("C")
    p.moveto(*D)
    p.rmoveto(5, -10)
    p.text("D")
    p.moveto(*E)
    p.rmoveto(-10, -10)
    p.text("E")
    p.moveto(*F)
    p.rmoveto(-10, -10)
    p.text("F")

    print p.gen()
    with open("wpisany.ps", "w") as wpisany:
        wpisany.write(p.gen())



podzial_odcinka()
wpisany()
