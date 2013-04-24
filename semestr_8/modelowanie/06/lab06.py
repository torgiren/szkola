#!/usr/bin/env python
#*-* coding: utf8 *-*
import numpy as np
from scipy.optimize import fsolve
from matplotlib import pyplot as plt


Pow = 510072 * 10 ** 6
S = 1366.0
ran = np.linspace(0.8 * S, 1.2 * S)


def zad1():
    A = 0.3
    sig = 5.67 * 12 ** -8
    return (S * (1 - A) / 4.0 / sig) ** (1.0 / 4.0)


def zad2():
    ta = 0.53
    a_s = 0.19
    c = 2.7
    sig = 5.67 * 10 ** -8
    aap = 0.31
    aa = 0.30
    tap = 0.06

    def  Tfunc1(T, S):
        return [-ta * (
            1 - a_s) * S / 4.0 + c * (
                T[0] - T[1]) + sig * T[0] ** 4 * (1 - aap) - sig * T[1] ** 4,
            -(1 - aa - ta + a_s * ta) * S / 4.0 - c * (T[0] - T[1]) -
            sig * T[0] ** 4 * (1 - tap - aap) + 2.0 * sig * T[1] ** 4]
    Ts = []
    Ta = []
    for s in ran:
        x, y = fsolve(Tfunc1, [273, 273], s)
        Ts.append(x)
        Ta.append(y)
    plt.figure(1)
    plt.plot(ran, Ts, ran, Ta)
    plt.savefig('zad2.png')


print "Zad 1:", zad1()
print "Zad 2:", zad2()
