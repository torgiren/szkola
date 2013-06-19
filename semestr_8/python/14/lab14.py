#!/usr/bin/env python
import numpy as np
from scipy import optimize
from scipy.integrate import quad
from scipy.interpolate import interp1d
from matplotlib import pyplot as plt


def zad1(func, startx, stopx, eps=0.01):
    startx = float(startx)
    stopx = float(stopx)
#    print startx, stopx, startx - stopx, startx - stopx > eps
    while (stopx - startx) > eps:
        tmp = (float(startx) + float(stopx)) / 2.0
#        print startx, stopx, tmp
        if np.sign(func(tmp)) == np.sign(func(startx)):
            startx = tmp
        else:
            stopx = tmp
    return startx


def zad2(func, startx, stopx, dx):
    return dx / 2.0 * (sum([2 * func(i) for i in np.arange(startx, stopx + dx, dx)]) - func(startx) - func(stopx))


def zad3(func, startx, stopx):
    pts = np.linspace(startx, stopx, 10)
    val = func(pts, 2.0, 3.0, 1.0)
    print pts
    print val
    popt, pcov = optimize.curve_fit(func, pts, val)
    print popt
    print pcov

def zad4(func, startx, stopx):
    pts = np.linspace(startx, stopx, 10)
    val = func(pts)
    print val
    inter1 = interp1d(pts, val, kind='linear')
    inter2 = interp1d(pts, val, kind='quadratic')
    pts2 = np.linspace(startx, stopx, 100)
    plt.plot(pts2, func(pts2), pts2, inter1(pts2), pts2, inter2(pts2), pts, func(pts), "ro")
    plt.savefig("plot.png")

def func1(x):
    return 2 * np.sin(3.0 * x) + 1


def func2(x):
    return x


def func3(x, a, b, c):
    return a * np.sin(b * x) + c
# 1.2   1.9   3.3
eps = 0.01
#zad1
#print zad1(func1, 0, 1.5, eps), optimize.bisect(func1, 0, 1.5)
#print zad1(func1, 1.5, 3, eps), optimize.bisect(func1, 1.5, 3)
#print zad1(func1, 3, 3.5, eps), optimize.bisect(func1, 3, 3.5)
#zad2
#print zad2(func1, 0, 4, 0.1), quad(func1, 0, 4)[0]
#zad3
zad3(func3, 0, 4)
#zad4
#zad4(func1, 0, 4)
