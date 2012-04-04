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
def d2f_numerowa(dr,r,f,f_nextprev):
	return dr*dr*(d2f(r+dr)+10*d2f(r)+d2f(r-1))/12+2*f-f_nextprev;
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
		plik.write(str(i*dr)+" "+str(f[i])+" "+str((f[i]-fanal(i*dr)))+" "+str(fanal(i*dr))+"\n");
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
		plik.write(str(i*dr)+" "+str(f[i])+" "+str((f[i]-fanal(i*dr)))+" "+str(fanal(i*dr))+"\n");
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
			f[i-2]=-d2f_przod(i*dr,f[i],dr);
		wynik=0;
		for i in range(1,2001):
			wynik+=calk(d1f(f[i],f[i-1],dr),i*dr,f[i],dr);
	plik=open("zad3_1.dat","wb");
	for i in range(0,2001):
		plik.write(str(i*dr)+" "+str(f[i])+" "+str((f[i]-fanal(i*dr)))+" "+str(fanal(i*dr))+"\n");
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
			f[i-2]=-d2f_przod(i*dr,f[i],dr);
		wynik=0;
		for i in range(1,201):
			wynik+=calk(d1f(f[i],f[i-1],dr),i*dr,f[i],dr);
	plik=open("zad3_2.dat","wb");
	for i in range(0,201):
		plik.write(str(i*dr)+" "+str(f[i])+" "+str((f[i]-fanal(i*dr)))+" "+str(fanal(i*dr))+"\n");
	plik.close();
def zad4_1():
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
			f[i-2]=d2f_numerowa(dr,i*dr,f[i],f[i-1]);
		wynik=0;
		for i in range(1,201):
			wynik+=calk(d1f(f[i],f[i-1],dr),i*dr,f[i],dr);
	plik=open("zad4_1.dat","wb");
	for i in range(0,201):
		plik.write(str(i*dr)+" "+str(f[i])+" "+str((f[i]-fanal(i*dr)))+" "+str(fanal(i*dr))+"\n");
	plik.close();
def zad4_2():
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
			f[i+1]=d2f_numerowa(dr,i*dr,f[i],f[i-1]);
		wynik=0;
		for i in range(1,201):
			wynik+=calk(d1f(f[i],f[i-1],dr),i*dr,f[i],dr);
	plik=open("zad4_2.dat","wb");
	for i in range(0,201):
		plik.write(str(i*dr)+" "+str(f[i])+" "+str((f[i]-fanal(i*dr)))+" "+str(fanal(i*dr))+"\n");
	plik.close();
def zad4_3():
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
			f[i+1]=d2f_numerowa(dr,i*dr,f[i],f[i-1]);
		wynik=0;
		for i in range(1,2001):
			wynik+=calk(d1f(f[i],f[i-1],dr),i*dr,f[i],dr);
	plik=open("zad4_3.dat","wb");
	for i in range(0,2001):
		plik.write(str(i*dr)+" "+str(f[i])+" "+str((f[i]-fanal(i*dr)))+" "+str(fanal(i*dr))+"\n");
	plik.close();
def func1(t,u1,u2):
	return 0;
def func2(t,u1,u2):
	return 0;
def U4(f1,f2,y1,y2,t,dt):
	k11=f1(t,y1,y2);
	k21=f2(t,y1,y2);
	k12=f1(t,y1+dt/2*k11,y2+dt/2*k21);
	k22=f2(t,y1+dt/2*k11,y2+dt/2*k21);
	k13=f1(t,y1+dt/2*k12,y2+dt/2*k22);
	k23=f2(t,y1+dt/2*k12,y2+dt/2*k22);
	k14=f1(t,y1+dt*k13,y2+dt*k23);
	k24=f2(t,y1+dt*k13,y2+dt*k23);
	return y1+dt/6*(k11+2*k12+2*k13+k14),y2+dt/6*(k21+2*k22+2*k23+k24);
def RK(n,t,E,y1_0,y2_0,dt,S):
	
def zad5():
	return 1,2;	
zad1();
zad2();
zad3_1();
zad3_2();
zad4_1();
zad4_2();
zad4_3();
U4(func1,func2,0,0,0,0.1);
