#!/usr/bin/env python2.6
#*-* coding: utf-8 *-*
import sys
import numpy as np
if len(sys.argv) < 2:
    print "Usage %s <arg1> [arg2,[...]]" % sys.argv[0]
    exit(1)
print "Zadanie 1"
pkt1 = "".join(sys.argv[1:])
print pkt1

print "Zadanie 2"
pkt2_1 = [x for x in pkt1 if x.islower()]
print pkt2_1
pkt2_2 = [x for x in pkt1 if x.isupper()]
print pkt2_2
pkt2_3 = [int(x) for x in pkt1 if x.isdigit()]
print pkt2_3
pkt2_4 = [x for x in pkt1 if not x.isalpha()]
print pkt2_4

print "Zadanie 3"
pkt3_1 = [x for x in set(pkt2_1)]
pkt3_1.sort()
print pkt3_1
pkt3_2 = [(x, pkt2_1.count(x)) for x in pkt3_1]
print pkt3_2

print "Zadanie 4"


def my_comp(a, b):
    if a[1] == b[1]:
        return 0
    elif a[1] > b[1]:
        return 1
    else:
        return -1
pkt4 = pkt3_2[:]
pkt4.sort(my_comp, reverse=True)
print pkt4

print "Zadanie 5"
pkt5_a = sum([1 for x in pkt1 if x in 'aiueo'])
pkt5_b = sum([1 for x in pkt1 if x not in 'aiueo' and x.isalpha()])
print "y=%dx+%d" % (pkt5_a, pkt5_b)
pkt5 = [(x, pkt5_a * x + pkt5_b) for x in pkt2_3]
print pkt5

print "Zadanie 6"
tmp = np.array(pkt5)
pkt6_x = tmp[:, 0]
pkt6_y = tmp[:, 1]
del tmp
D = sum((pkt6_x - pkt6_x.mean()) ** 2)
pkt6_x.mean()
a = (1. / D) * (pkt6_y * (pkt6_x - pkt6_x.mean())).sum()
b = pkt6_y - a * pkt6_x
print a, b[0]
