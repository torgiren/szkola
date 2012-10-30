#!/usr/bin/env python
import sys
import math
if len(sys.argv)<2:
	print "Podaj plik z danymi"
	exit(1)
plik=open(sys.argv[1])
lines=plik.readlines()
l=lines[0]
l=l.split(" ")
m1_old=float(l[1])
m2_old=float(l[2])
m3_old=float(l[3])
del lines[0]
for line in lines:
	line=line[:len(line)-1]
	line=line.split(" ")
	n1_sr=0
	n2_sr=0
	n3_sr=0
	dm1=(float(line[1])-m1_old)
	dm2=(float(line[2])-m2_old)
	dm3=(float(line[3])-m3_old)
	m1_old=float(line[1])
	m2_old=float(line[2])
	m3_old=float(line[3])
	if dm1<=0:
		n1="blad pomiarowy"
	else:
		n1=math.log10(float(line[0]))/math.log10(dm1/8.8)
	if dm2<=0:
		n2="blad pomiarowy"
	else:
		n2=math.log10(float(line[0]))/math.log10(dm2/8.8)
	if dm3<=0:
		n3="blad pomiarowy"
	else:
		n3=math.log10(float(line[0]))/math.log10(dm3/8.8)
	print str(line[0])+" "+str(n1)+" "+str(n2)+" "+str(n3)

