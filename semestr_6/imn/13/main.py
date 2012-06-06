#!/usr/bin/python
import math
def u0_1(x,t):
	return math.sin(math.pi*x)*math.cos(math.pi*t)+0.5*math.sin(2.0*math.pi*x)*math.sin(2*math.pi*t);
def siatka(x,y):
	a=[];
	for i in range(0,x+1):
		b=[];
		for j in range(0,y+1):
			b.append(0);
		a.append(b);
	return a;
dx=0.01;
dy=0.02;
def zad1():
	V=siatka(101,201);
	U=siatka(101,201);
	A=siatka(101,201);
	for i in range(0,101):
		for j in range(0,201):
			V[i][j]=u0_1(i/100.0,j/200.0);
	print V;
	for iter in range(0,200):
		for i in range(1,100):
			for j in range(1,200):
				V[i][j+1]=V[i][j]+dy/2.0*A[i][j];
				U[i][j+2]=U[i][j]+dy*V[i,j+1]
				V[i][j+2]=V[i][j+1]+dy/2.0*A[i,j+2];
				A[i][j]=(U[i+dx][j]+U[i-dx][j]-2.0*U[i][j])/(dx*dx)
zad1()
	
	


