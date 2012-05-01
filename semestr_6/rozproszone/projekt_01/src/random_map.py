#!/usr/bin/python
import random;
miasta=50;
print "c",miasta
for i in range(1,miasta+1):
	for j in range(i,miasta+1):
#		if( random.randint(0,3) !=0 ):
		print "r",i,j,random.randint(1,10);
