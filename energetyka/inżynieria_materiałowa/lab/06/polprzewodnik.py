#!/usr/bin/env python
import math
f=open("data2.dat","r")
while True:
	line=f.readline()
	if not line:
		break;
	line=line.split()
	print 1.0/(float(line[0])+273),
	print math.log((0.0004*1000*float(line[1])/(0.00000016*float(line[2]))),math.e)
