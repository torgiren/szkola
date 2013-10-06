#!/usr/bin/env python
f=open("data_dobre.dat","r")
while True:
	line=f.readline()
	if not line:
		break;
	line=line.split()
	print line[0], 
	print 1.0/(0.0004*float(line[1])/(0.00000016*float(line[2])))
