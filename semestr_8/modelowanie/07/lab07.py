#!/usr/bin/env python
#*-* coding: utf8 *-*
import math


class stan:
    def __init__(self, m, a, b, u):
        self.m = m
        self.a = a
        self.b = b
        self.u = u
stany = []
stany.append(stan(0.08, 0.888, 1.284, 3))
stany.append(stan(0.143, 0.865, 1.108, 5))
stany.append(stan(0.196, 0.845, 0.978, 8))
stany.append(stan(0.27, 0.818, 0.822, 11))
stany.append(stan(0.363, 0.784, 0.660, 5))
stany.append(stan(0.44, 0.756, 0.551, 4))
Eg = 2.7 * 10 ** 6
H = 120.0
h = H
x = 13.3 * 10 ** 3
for s in stany:
    m = s.m
    a = s.a
    b = s.b
    u = s.u

    z0 = 2.0
#    usr = u * a * (300.0 / 14) ** m
    usr = u * (h / 14.0) ** m
    B = 0.38 * m ** 1.3 * (8.7 - math.log(H / z0))
    A = 0.088 * (6.0 * m ** -0.3 + 1 - math.log(H / z0))
    sigy = A * x ** a
    sigz = B * x ** b

    Sx = Eg / (math.pi * usr * sigz * sigy) * math.exp(- H ** 2.0 / (2.0 *
                                                                     sigz ** 2)) * 1000.0
    print "Dla stanu: a=", a, "b=", b, " m=", m, "u=", u
    print Sx
