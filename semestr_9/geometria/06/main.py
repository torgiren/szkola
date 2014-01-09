#!/usr/bin/env python
#*-* conding: utf8 *-*
from ps import PS
import math
import functions
from pprint import pprint

def myatan2(x,y):
    a = math.atan2(y,x)
    if a<0:
        a+= 2*math.pi
    return a

pkt = [(1, 1), (0,1), (0.5, 2), (-5, 0), (-1, -1), (0, 4), (0, -5), (-1, 1)]
pkt = [(6,4), (4,5), (3, 4), (0,6), (-2, 3), (-2 ,2), (-6, 1), (0, 0), (-3, -2), (3, -2)]
print pkt


pkt2 = pkt[:]
lowest = pkt2[0]
for i in pkt2:
    if i[1] < lowest[1]:
        lowest = i
#pkt2.remove(lowest)
pkt3 = [(i, myatan2(i[0], i[1])) for i in pkt2]
print pkt3
print pkt3.sort(key=lambda x: x[1])
pkt3 = pkt3[1:]
pprint(pkt3)



stos = [pkt3[0], pkt3[1]]
for i in pkt3[2:]:
    print "Dodaje", i
    stos.append(i)
    print stos[-2], stos[-1]
    #a = math.atan2(stos[-1][0][1] -stos[-2][0][1], stos[-1][0][0] - stos[-2][0][0])
    #if a<0:
    #    a+= math.pi * 2
    #b = math.atan2(stos[-2][0][1] -stos[-3][0][1], stos[-2][0][0] - stos[-3][0][0])
    #if b<0:
    #    b+= math.pi * 2
    a = 1
    b = 2
    while a<b:
        start = stos[-3][0]
        first = stos[-2][0]
        sec = stos[-1][0]
        first = (first[0] - start[0], first[1] - start[1])
        sec =(sec[0] - start[0], sec[1] - start[1])
        print start, first, sec
        a = math.atan2(*first)
        b = math.atan2(*sec)
        if a<0:
            a+= math.pi * 2
        if b<0:
            b+= math.pi * 2
        print math.degrees(a), math.degrees(b)
        #while not stos[-3][1] <= stos[-2][1] and not stos[-2][1] <= stos[-1][1]:
        if a<b:
            print "Usuwam", stos[-2]
            del(stos[-2])
        print ""
    print "****"
pprint(stos)



factor = 15


p = PS()
p.setfont()
p.translate(200, 200)

for i in pkt:
    p.newpath()
    p.arc(factor * i[0], factor * i[1], 2, 0, 360)
    p.stroke()

p.newpath()
print stos[0][0][0]
p.moveto(factor * stos[0][0][0], factor * stos[0][0][1])
for i in stos[1:]:
    i = i[0]
    p.line(factor * i[0], factor * i[1])
    p.stroke()
    p.newpath()
    p.moveto(factor * i[0], factor * i[1] )
p.line(factor * stos[0][0][0], factor * stos[0][0][1])
p.stroke()

with open("otoczka.ps", "w") as otoczka:
    otoczka.write(p.gen())
