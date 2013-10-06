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
    p.moveto(a/2, 0)
    p.rline(0, a)
    p.colour(0, 0, 0)
    p.stroke()

    p.newpath()
    p.moveto(a/2, 0)
    p.line(a, a)
    p.dash()
    p.colour(0, 0, 0)
    p.stroke()

    p.newpath()
    a2 = math.degrees(math.atan(a / (a / 2)))
    p.arc(a/2, 0, b, 0, a2)
    p.stroke()

    p.setfont()
    p.newpath()
    p.moveto(-5, -10)
    p.text("A")
    p.moveto(a /2 - 5, -10)
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

podzial_odcinka()
