#!/usr/bin/python
import math
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
bilans=10;
print math.fabs(bilans)
pole_nowe=deepcopy(pole)
pole_tmp=deepcopy(pole_nowe);
x=0;
strumienie=open("strumienie2.dat","w")
h=0.1
while math.fabs(bilans)>0.0001:
	x=x+1;
	for przyb in range(1,100):
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
			pole_tmp[29][j]=pole_nowe[28][j]/(h+1)
		for j in range(1,15):
			pole_tmp[15][j]=pole_nowe[16][j]/(h+1)
		for i in range(1,16):
			pole_tmp[i][15]=pole_nowe[i][16]/(h+1)
		for i in range(2,30):
			pole_tmp[i][29]=pole_nowe[i][28]/(h+1)
		pole_tmp[15][15]=1.41*pole_nowe[16][16]/(h+1.41)
		pole_tmp[29][29]=1*41*pole_nowe[28][28]/(h+1.41)
		pole_nowe=deepcopy(pole_tmp);
	pole=deepcopy(pole_nowe);

	if x>300:
		break;
	print "iteracja ",x
	sum=0
	for i in range(15,29):
		sum+=pole[i][3]-pole[i][2]
	print "Sasiad dolny - strumien= "+str(-sum)
	bilans=sum
	sum2=0
	for j in range(15,29):
		sum2+=pole[3][j]-pole[2][j]
	print "Sasiad boczny - strumien= "+str(-sum2)
	bilans+=sum2
	print ""
	strumienie.write(str(x)+" "+str(sum)+" "+str(sum2)+"\n")

strumienie.close()


file =open("data2.dat","w")


for i in range(1,30):
	text=""
	for j in range(1,30):
		text=str(i)+" "+str(j)+" "+str(pole[i][j])+"\n"
		file.write(text)
	file.write("\n")
file.close()
