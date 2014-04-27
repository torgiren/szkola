#!/usr/bin/env python
#*-* conding: utf8 *-*
from ps import PS


def pole(a, b, c):
    return (b[0] - a[0]) * (c[1] - a[1]) - (c[0] - a[0]) * (b[1] - a[1])
n = int(raw_input("POdaj liczbe wierzcholkow: "))
w = []
for i in range(n):
    tmp = raw_input("Podaj w%d w formacie x,y np: 6,8: ")
    tmp = tmp.split(',')
    print tmp
    w.append((float(tmp[0].strip()), float(tmp[1].strip())))

suma = 0
for i in range(n - 1):
    suma += pole(w[0], w[i], w[i + 1])
suma /= 2.0
print suma
p = PS()
p.setfont()
p.translate(200, 200)
p.newpath()
p.moveto(*w[0])
for i in w:
    p.line(*i)
p.line(*w[0])
p.stroke()
p.moveto(0,-50)
p.text("Pole = %f" % suma)
with open("pole.ps", "w") as pole:
    pole.write(p.gen())
