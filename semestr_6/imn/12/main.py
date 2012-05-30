#!/usr/bin/python
from copy import copy, deepcopy
def temp(i,j,stare,nowe):
	val=1.0/21.0*(stare[i][j]+5.0*(stare[i][j-1]+stare[i][j+1]+stare[i-1][j]+stare[i+1][j]-4.0*stare[i][j]+nowe[i][j-1]+nowe[i][j+1]+nowe[i-1][j]+nowe[i+1][j]))
#	print "licze dla: "+str(i)+" "+str(j)+" =  "+str(val)+ " stare="+str(stare[i][j]);
	return val;
pole=[]
for i in range(0,30):
	pole.append([]);
	for j in range(0,30):
		pole[i].append(0.0);
for i in range(15,30):
	pole[i][1]=30.0
for i in range(15,30):
	pole[1][i]=10.0

pole_nowe=deepcopy(pole)
pole_tmp=deepcopy(pole_nowe);
for iter in range(1,50):
	for przyb in range(1,160):
		for i in range(16,29):
			for j in range(2,16):
				pole_tmp[i][j]=temp(i,j,pole,pole_nowe);
		for i in range(2,15):
			for j in range(15,29):
				pole_tmp[i][j]=temp(i,j,pole,pole_nowe);
		for i in range(15,29):
			for j in range(15,29):
				pole_tmp[i][j]=temp(i,j,pole,pole_nowe);

		for j in range(1,30):
			pole_tmp[29][j]=pole_nowe[28][j]
		for j in range(1,15):
			pole_tmp[15][j]=pole_nowe[16][j]
		for i in range(1,16):
			pole_tmp[i][15]=pole_nowe[i][16]
		for i in range(2,30):
			pole_tmp[i][29]=pole_nowe[i][28]
		pole_tmp[14][14]=pole_nowe[15][15]
		pole_tmp[29][29]=pole_nowe[28][28]
		pole_nowe=deepcopy(pole_tmp);
	pole=deepcopy(pole_nowe);




for i in range(1,30):
	text=""
	for j in range(1,30):
		print j,30-i,pole[j][30-i]
#		text+=str(pole[j][30-i])+" "
	print ""
