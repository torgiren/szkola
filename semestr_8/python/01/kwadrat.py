"""Obliczanie funkcji kwadratorej"""
import sys
import numpy as np
if len(sys.argv) < 4:
    print "Usage %s <a> <b> <c>" % (sys.argv[0])
A = float(sys.argv[1])
B = float(sys.argv[2])
C = float(sys.argv[3])

DELTA = B ** 2 - 4 * A * C

if DELTA < 0:
    DELTA = complex(DELTA)

PIERW = np.sqrt(DELTA)
print "Delta=", DELTA
print "Pierwiastek z delty=", PIERW
X1 = (-B + PIERW) / (2 * A)
X2 = (-B + PIERW) / (2 * A)
print "Pierwiastki to:\nx1=%f %fi\nx2=%f %fi" % (X1.real, X1.imag, X2.real, X2.imag)
