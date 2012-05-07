#!/usr/bin/python
import random;
import sys;
if(len(sys.argv)<2):
	print "Podaj liczbe miast";
else:
	miasta=int(sys.argv[1]);
	print "c",miasta
	for i in range(1,miasta+1):
		for j in range(i+1,miasta+1):
#		if( random.randint(0,3) !=0 ):
			print "r",i,j,random.randint(5,10);
