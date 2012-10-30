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
	dm1=(float(line[1])-m1_old)*1000
	dm2=(float(line[2])-m2_old)*1000
	dm3=(float(line[3])-m3_old)*1000
	m1_old=float(line[1])
	m2_old=float(line[2])
	m3_old=float(line[3])
	
	if dm1<=0:
		da1=99
	else:
		da1=math.log10(dm1/8.8)
	if dm2<=0:
		da2=99
	else:
		da2=math.log10(dm2/8.8)
	if dm3<=0:
		da3=99
	else:
		da3=math.log10(dm3/8.8)

	print "%s %.1f %.1f %.1f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\\\\"%(line[0],float(line[1])*1000,float(line[2])*1000,float(line[3])*1000,dm1,dm2,dm3,da1,da2,da3,math.log10(float(line[0])))
#	print str(line[0])+" "+str(line[1])+" "+str(line[2])+" "+str(line[3])+" "+str(dm1)+" "+str(dm2)+" "+str(dm3)+" "+str(da1)+" "+str(da2)+" "+str(da3)+" "+str(math.log10(float(line[0])))

