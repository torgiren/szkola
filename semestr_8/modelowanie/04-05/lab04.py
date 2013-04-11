#!/usr/bin/env python
#*-* coding: utf-8 *-*
import numpy as np
import matplotlib.pyplot as plt
dx = 0.1
dt = 0.1
L = 100.0
d = 5.0
h = 1.0
U = 0.1
D = 0.01
x0 = 10.0 / dx
xp = 90.0 / dx
m = 1
Ca = U * dt / dx
Cd = D * dt / dx ** 2
C1 = Cd * (1.0 - Ca) - Ca / 6.0 * (Ca ** 2 - 3.0 * Ca + 2.0)
C2 = Cd * (2.0 - 3.0 * Ca) - Ca / 2.0 * (Ca ** 2 - 2.0 * Ca - 1.0)
C3 = Cd * (1.0 - 3.0 * Ca) - Ca / 2.0 * (Ca ** 2 - Ca - 2.0)
C4 = Cd * Ca + Ca / 6.0 * (Ca ** 2 - 1.0)


def f1():
    return 10


def method1():
    vec = np.zeros(L / dx)
    vec[x0] = f1()
    hist = []
    for x in xrange(10000):
#    print vec
        vec[2:-1] = vec[2:-1] + C1 * vec[3:] - C2 * vec[2:-1] + \
            C3 * vec[1:-2] + C4 * vec[:-3]
        hist.append(vec[xp])
        print x, vec.sum()
        if not x % 50:
            plt.figure(x)
            plt.plot(xrange(len(vec)), vec)
            plt.savefig("plots/%05d.png" % x)
            print "fig"

    plt.figure(x + 1)
    plt.plot(xrange(len(hist)), hist)
    plt.savefig("plots/hist.png")


def method2():
    vec = np.zeros(L / dx)
    vec[x0] = f1()
    hist = []
    C1 = 1.0 + Cd
    C2 = -Cd / 2.0 + Ca / 4.0
    C3 = -Cd / 2.0 - Ca / 4.0
    C4 = 1.0 - Cd
    C5 = Cd / 2.0 - Ca / 4.0
    C6 = Cd / 2.0 + Ca / 4.0

    s = int(L / dx)
    AA = np.diag([C1] * s)
    AA[0:-1, 1:] += np.diag([C2] * (s - 1))
    AA[1:, 0:-1] += np.diag([C3] * (s - 1))
    AA = np.linalg.inv(AA)

    BB = np.diag([C4] * s)
    BB[0:-1, 1:] += np.diag([C5] * (s - 1))
    BB[1:, 0:-1] += np.diag([C6] * (s - 1))

    CC = np.dot(AA, BB)
    vec[x0] = f1()
    vec = vec.transpose()
    for x in xrange(10000):
        print CC.shape
        print vec.shape
        vec = np.dot(CC, vec)
        hist.append(vec[xp])
        print x, vec.sum()
        if not x % 50:
            plt.figure(x)
            plt.plot(xrange(len(vec)), vec)
            plt.savefig("plots2/%05d.png" % x)
            print "fig"

    plt.figure(x + 1)
    plt.plot(xrange(len(hist)), hist)
    plt.savefig("plots2/hist.png")

method2()
