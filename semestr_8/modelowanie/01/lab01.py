#!/usr/bin/env python
#*-* coding: utf8 *-*
import numpy as np
import random
import matplotlib.pyplot as plt
from scipy import stats
from scipy import polyfit
size = 10000
print "Generowanie przesunięć"
r = [random.gauss(0, 1) for x in range(size)]
print "Obliczanie trajektorii"
trajekt = np.zeros(size)
for x in xrange(1, size):
    trajekt[x] = trajekt[x - 1] + r[x]
sred = np.ones(size) * trajekt.mean()

print "Plotowanie trajektorii"
plt.figure(1)
plt.plot(range(size), trajekt)
plt.plot(range(size), sred)
plt.savefig("remote/out.png")

print "Plotowanie korelacji przesuniętej o 1"
plt.figure(2)
traj2 = trajekt[1:]
(a, b, r, p ,e) = stats.linregress(trajekt[: - 1], traj2)
print "Regresja: %fx+ %f, r^2= %f" % (a, b, r )
x = np.linspace(trajekt.min(), trajekt.max())
y = a *x + b
plt.plot(trajekt[:-1], traj2, 'ro')
plt.plot(x, y)
plt.savefig("remote/out1.png")

print "Plotowanie korelacji przesuniętej o 10"
plt.figure(3)
traj2 = trajekt[10:]
(a, b, r, p ,e) = stats.linregress(trajekt[: - 10], traj2)
print "Regresja: %fx+ %f, r^2= %f" % (a, b, r )
x = np.linspace(trajekt.min(), trajekt.max())
y = a *x + b
plt.plot(trajekt[:-10], traj2, 'ro')
plt.plot(x, y)
plt.savefig("remote/out10.png")

print "Plotowanie korelacji przesuniętej o 1000"
plt.figure(4)
traj2 = trajekt[1000:]
(a, b, r, p ,e) = stats.linregress(trajekt[: - 1000], traj2)
print "Regresja: %fx+ %f, r^2= %f" % (a, b, r )
x = np.linspace(trajekt.min(), trajekt.max())
y = a *x + b
plt.plot(trajekt[:-1000], traj2, 'ro')
plt.plot(x, y)
plt.savefig("remote/out1000.png")
