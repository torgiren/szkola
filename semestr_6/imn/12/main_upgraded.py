#!/usr/bin/python
#import pypy
import math
import numpy as np
#from copy import deepcopy


def temp2(stare, nowe):
    val = np.zeros(stare.shape)
    val[1:-1, 1:-1] = stare[1:-1, 1:-1] + 5.0 * (stare[1:-1, :-2] + stare[1:-1, 2:] + stare[:-2, 1:-1] + stare[2:, 1:-1] - 4.0 * stare[1:-1, 1:-1] +
                      nowe[1:-1, :-2] + nowe[1:-1, 2:] + nowe[:-2, 1:-1] + nowe[2:, 1:-1])
    return val / 21.0


def temp(i, j, stare, nowe):
    val = (stare[i, j] + 5.0 * (stare[i, j - 1] + stare[i, j + 1] + stare[i - 1, j] + stare[i + 1, j] - 4.0 * stare[i, j] +
           nowe[i, j - 1] + nowe[i, j + 1] + nowe[i - 1, j] + nowe[i + 1, j]))
    return val / 21.0
pole = np.zeros((30, 30))
pole[15:30, 1] = 30.0
pole[1, 15:30] = 10.0
bilans = 10
print math.fabs(bilans)
pole_nowe = pole.copy()
pole_tmp = pole.copy()
x = 0
strumienie_data = []
while math.fabs(bilans) > 0.0001:
    x += 1
    for przyb in xrange(1, 100):
        pole_tmp[16:29, 2:16] = temp2(pole[15:30, 1:17], pole_nowe[15:30, 1:17])[1:-1, 1:-1]

#        for i in xrange(16, 29):
#            for j in xrange(2, 16):
#                pole_tmp[i][j] = temp(i, j, pole, pole_nowe)
        pole_tmp[2:29, 15:29] = temp2(pole[1:30, 14:30], pole_nowe[1:30, 14:30])[1:-1, 1:-1]
#        for i in xrange(2, 15):
#            for j in xrange(15, 29):
#                pole_tmp[i][j] = temp(i, j, pole, pole_nowe)
#        for i in xrange(15, 29):
#            for j in xrange(15, 29):
#                pole_tmp[i][j] = temp(i, j, pole, pole_nowe)

        pole_tmp[29, 1:30] = pole_nowe[28, 1:30]
        pole_tmp[15, 1:15] = pole_nowe[16, 1:15]
        pole_tmp[1:16, 15] = pole_nowe[1:16, 16]
        pole_tmp[2:30, 29] = pole_nowe[2:30, 28]
        pole_tmp[15, 15] = pole_nowe[16, 16]
        pole_tmp[29, 29] = pole_nowe[28, 28]
        pole_nowe = pole_tmp.copy()
    pole = pole_nowe.copy()

    print "iteracja ", x
#    sum = 0
#    for i in range(15, 29):
#        sum += pole[i][3] - pole[i][2]

    sum = pole[15:29, 3].sum() - pole[15:29, 2].sum()
    print "Sasiad dolny - strumien= " + str(-sum)
    bilans = sum
#    sum2 = 0
#    for j in range(15, 29):
#        sum2 += pole[3][j] - pole[2][j]
    sum2 = pole[3, 15:29].sum() - pole[2, 15:29].sum()
    print "Sasiad boczny - strumien= " + str(-sum2)
    bilans += sum2
    print ""
    strumienie_data.append(str(x) + " " + str(sum) + " " + str(sum2))

strumienie_data = "".join(strumienie_data)
strumienie = open("strumienie.dat", "w")
strumienie.write(strumienie_data)
strumienie.close()


file = open("data.dat", "w")


for i in range(1, 30):
    text = ""
    for j in range(1, 30):
        text = str(i) + " " + str(j) + " " + str(pole[i][j]) + "\n"
        file.write(text)
    file.write("\n")
file.close()
