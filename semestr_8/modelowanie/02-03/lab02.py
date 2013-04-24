#!/usr/bin/env python
#*-* coding: utf8 *-*
import numpy as np
from matplotlib import cm
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt

np.seterr(all='raise')


def poczatkowe1(plytka):
    plytka[0, :] = 0
    plytka[-1, :] = 0
    plytka[:, 0] = 0
    plytka[:, -1] = 0
    plytka[plytka.shape[0] / 2 - B / 2:plytka.shape[0] / 2 + B / 2,
           plytka.shape[1] / 2 - B / 2:plytka.shape[1] / 2 + B / 2] = 100
#    print plytka.shape[0] / 2, plytka.shape[0] / 2 + scale, plytka.shape[1] / 2, plytka.shape[1] / 2 + scale
    return plytka


def propagacja(plytka, Wx, Wy):
    plytka[1:-1, 1:-1] = plytka[1:-1, 1:-1] +\
    Wx * (plytka[2:, 1:-1] - 2 * plytka[1:-1, 1:-1] + plytka[:-2, 1:-1]) +\
    Wy * (plytka[1:-1, 2:] - 2 * plytka[1:-1, 1:-1] + plytka[1:-1, :-2])
    return plytka
A = 0.06
NX = 60
NY = 60
B = NX / 6
K = 401.0
cw = 380
ro = 8920
dx = A / NX
dy = A / NY
dt = 1
scale = NX
plytka = np.zeros((NX, NX), dtype=np.float64)
Wx = K * dt / (cw * ro * dx)
Wy = K * dt / (cw * ro * dy)
plytka = poczatkowe1(plytka)
print Wx, Wy
quit = False
diff = 1
i = 0
X = np.arange(plytka.shape[0])
Y = np.arange(plytka.shape[1])
X, Y = np.meshgrid(X, Y)
while abs(diff) > 0.001:
    print "iter ", i
    plytka = poczatkowe1(plytka)
    old = plytka.copy()
    plytka = propagacja(plytka, Wx, Wy)
    diff = (plytka - old).max()
    print diff

    if not i%100:
        fig = plt.figure()
        ax = fig.add_subplot(111, projection='3d')
        ax.plot_surface(X, Y, plytka, rstride=1, cstride=1, cmap=cm.jet, linewidth=0, antialiased=False)
        plt.savefig('plots_01/plot_%05d.png'%i)
    i+=1
print plytka
