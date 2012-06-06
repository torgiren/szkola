#!/usr/bin/python
import math
import copy
def u0_1(x,t):
	return math.sin(math.pi*x)*math.cos(math.pi*t)+0.5*math.sin(2.0*math.pi*x)*math.sin(2*math.pi*t);
def siatka(x):
	a=[];
	for i in range(0,x+1):
		a.append(0);
	return a;
dx=0.01;
dy=0.005;
pr=[]
for i in range(0,9):
	pr.append(i*2.0/8.0/dy);
	print pr[i]
def zad1():
	V=siatka(101);
	U=siatka(101);
	A=siatka(101);
	for i in range(0,101):
		U[i]=u0_1(i/100.0,0);
#	print V;
	for t in range(0,401):
		V_new=copy.deepcopy(V);
#		U_new=copy.deepcopy(U);
		v_next=[];
		v_next.append(0.0);
		for i in range(1,100):
			v_next.append(V[i]+dy/2.0*A[i]);
		for i in range(1,100):
			U[i]=U[i]+dy*v_next[i];
#		U=copy.deepcopy(U_new);
		for i in range(1,100):
			A[i]=(U[i+1]+U[i-1]-2.0*U[i])/(dx*dx);
		for i in range(1,100):
			V_new[i]=v_next[i]+(dy/2.0)*A[i]
		V=copy.deepcopy(V_new);
		if t in pr:
			file=open('zad1_'+str(t)+'.dat','w')
			for i in range(0,101):
				file.write(str(i)+" "+str(U[i])+"\n");
			file.close()
zad1()
	
	


