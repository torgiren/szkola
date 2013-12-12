#!/usr/bin/env python
#*-* conding: utf8 *-*
from ps import PS
import math
import functions

def cmp(x,y):
    a = math.atan2(x[1],x[0])
    if a < 0:
        a+=2*math.pi
    b = math.atan2(y[1], y[0])
    if b < 0:
        b+=2*math.pi
    c = a -b
    if c > 0:
        return 1
    elif c < 0:
        return -1
    else:
        return 0


pkt = [(1, 1), (0.5, 2), (-5, 0), (-1, -1), (0, 4), (0, -5), (-1, 1)]
print pkt


pkt2 = pkt[:]
lowest = pkt2[0]
for i in pkt2:
    if i[1] < lowest[1]:
        lowest = i
pkt2.remove(lowest)



pkt2.sort(cmp=cmp)
print pkt2


a = pkt2[0]
b = pkt2[1]
pro = functions.prosta(a,b)
print pro[0] * pkt2[2][0] + pro[1], pkt2[2][1]

print pro

exit(0)






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
    print i
    p.line(*i)
p.line(*w[0])
p.stroke()
p.moveto(0,-50)
p.text("Pole = %f" % suma)

for i in w[1:-1]:
    p.newpath()
    p.moveto(*w[0])
    p.dash()
    p.line(*i)
    p.stroke()

with open("trig.ps", "w") as pole:
    pole.write(p.gen())
