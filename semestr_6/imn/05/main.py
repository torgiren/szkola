#!/usr/bin/python
import math;
def d2f(r):
	return 4*r*math.exp(-2*r);
def fanal(r):
	return -1+(r+1)*math.exp(-2*r);
def d2f_trojpunktowy(r,dr):
	return (d2f(r-dr)-2*d2f(r)+d2f(r+dr))/(dr*dr)
def d1f(f,fprev,dr):
	return (f-fprev)/dr;
def calk(df,r,f,dr):
	return (0.5*df*df+d2f(r)*f)*dr;
def d2f_wstecz(r,f,dr):
	return f*dr*dr+2*d2f(r)-d2f(r+dr);
def d2f_przod(r,f,dr):
	return f*dr*dr+2*d2f(r)-d2f(r-dr);
def zad1():
	dr=0.1;
	f=[];
	for x in range(0,201):
		f.append(0);
	f[200]=-1;
	f[0]=0;
	wynik=0
	wynik_prev=1;
	e=0.00001;
	while(abs(wynik-wynik_prev)>e):
		wynik_prev=wynik;
		for i in range(1,200):
			f[i]=d2f_trojpunktowy(i*dr,dr)	
		wynik=0;
		for i in range(1,201):
			wynik+=calk(d1f(f[i],f[i-1],dr),i*dr,f[i],dr);
	plik=open("zad1.dat","wb");
	for i in range(0,201):
		plik.write(str(i*dr)+" "+str(f[i])+" "+str((f[i]-fanal(i*dr)))+"\n");
	plik.close();
def zad2():
	dr=0.1;
	f=[];
	for x in range(0,201):
		f.append(0);
	f[200]=-1;
	f[0]=0;
	wynik=0
	wynik_prev=1;
	e=0.00001;
	while(abs(wynik-wynik_prev)>e):
		wynik_prev=wynik;
		for i in range(200,1,-1):
			f[i-2]=d2f_wstecz(i*dr,f[i],dr);
		wynik=0;
		for i in range(1,201):
			wynik+=calk(d1f(f[i],f[i-1],dr),i*dr,f[i],dr);
	plik=open("zad2.dat","wb");
	for i in range(0,201):
		plik.write(str(i*dr)+" "+str(f[i])+" "+str((f[i]-fanal(i*dr)))+"\n");
	plik.close();
def zad3_1():
	dr=0.01;
	f=[];
	for x in range(0,2001):
		f.append(0);
	f[2000]=-1;
	f[0]=0;
	wynik=0
	wynik_prev=1;
	e=0.00001;
	while(abs(wynik-wynik_prev)>e):
		wynik_prev=wynik;
		for i in range(1,2000):
			f[i-2]=d2f_przod(i*dr,f[i],dr);
		wynik=0;
		for i in range(1,2001):
			wynik+=calk(d1f(f[i],f[i-1],dr),i*dr,f[i],dr);
	plik=open("zad3_1.dat","wb");
	for i in range(0,2001):
		plik.write(str(i*dr)+" "+str(f[i])+" "+str((f[i]-fanal(i*dr)))+"\n");
	plik.close();
def zad3_2():
	dr=0.1;
	f=[];
	for x in range(0,201):
		f.append(0);
	f[200]=-1;
	f[0]=0;
	wynik=0
	wynik_prev=1;
	e=0.00001;
	while(abs(wynik-wynik_prev)>e):
		wynik_prev=wynik;
		for i in range(1,200):
			f[i-2]=d2f_przod(i*dr,f[i],dr);
		wynik=0;
		for i in range(1,201):
			wynik+=calk(d1f(f[i],f[i-1],dr),i*dr,f[i],dr);
	plik=open("zad3_2.dat","wb");
	for i in range(0,201):
		plik.write(str(i*dr)+" "+str(f[i])+" "+str((f[i]-fanal(i*dr)))+"\n");
	plik.close();
zad1();
zad2();
zad3_1();
zad3_2();
