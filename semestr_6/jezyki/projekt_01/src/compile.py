#!/usr/bin/python
import sys
def wczytaj_plik(nazwa):
	plik=open(nazwa,"r");
	linie=[];
	for i in plik:
		linie.append(i.rstrip());
#	linie=plik.readlines()
	plik.close()
	return linie;
def error_header(line,line_nr):
	print "Compile error."
	print "Line %d: %s" %(line_nr,line.rstrip());
def arguments(exploded_line,num):
	if len(exploded_line)<num:
		print "Argument missing"
	else:
		print "Too many arguments"
def unknow_symbol(symbol):
	print "Unknow symbol: %s"%symbol
def unquote(tekst):
	return tekst[1:-1]
def isQuoted(tekst):
	return (tekst[0]=='"')&(tekst[-1]=='"')
linie=wczytaj_plik(sys.argv[1])
zmienne={}
wyjscie=[]
x=0;
for linia in linie:
	x+=1;
#	print linia;
	tmp=linia.rstrip().split(" ",1)
	if tmp[0]=="string" :
		if len(tmp)!=2 :
			error_header(linia,x)
			arguments(tmp,2)
			exit(1);
		inicjacja=tmp[1].split("=");
		zmienne[inicjacja[0]]=(len(wyjscie),'s')
		cmd="db";
		if len(inicjacja)==2:
			cmd+=" "+unquote(inicjacja[1])
		wyjscie.append(cmd);
	elif tmp[0]=="num":
		if len(tmp)!=2:
			error_header(linia,x)
			arguments(tmp,2)
			exit(1)
		inicjacja=tmp[1].split("=")
		cmd="db"
		zmienne[inicjacja[0]]=(len(wyjscie),'n')
		if len(inicjacja)==2:
			cmd+=" "+inicjacja[1]
		wyjscie.append(cmd);
	elif tmp[0]=="wczytaj":
		if len(tmp)!=2:
			error_header(linia,x)
			arguments(tmp,2)
			exit(1)
		wyjscie.append("mov ax 2")
		wyjscie.append("mov bx %d" % zmienne[tmp[1]][0]);
		wyjscie.append("int 1");
	elif tmp[0]=="wypisz":
		if len(tmp)!=2:
			error_header(line,x)
			arguments(tmp,2)
			exit(1)
		wyjscie.append("mov ax 1")
		wyjscie.append("mov bx %d"%zmienne[tmp[1]][0])
		wyjscie.append("int 1")
	elif tmp[0]=="copy":
		args=tmp[1].split(",");
		if len(tmp)!=2:
			error_header(linia,x)
			arguments(tmp,2)
			exit(1)
		wyjscie.append("mov ax 4")
		wyjscie.append("mov bx %d" % zmienne[args[0]][0])
		wyjscie.append("mov cx %d" % zmienne[args[1]][0])
		wyjscie.append("int 2")
	else:
		tmp=linia.rstrip().split("=",1)
		if tmp[0] in zmienne:
			if tmp[1] in zmienne:
				wyjscie.append("mov ax 4")
				wyjscie.append("mov bx %d"%zmienne[tmp[0]][0])
				wyjscie.append("mov cx %d"%zmienne[tmp[1]][0])
			else:
				if isQuoted(tmp[1]):
					tmp_nr=len(wyjscie)
					wyjscie.append("db "+unquote(tmp[1]))
					wyjscie.append("mov ax 4")
					wyjscie.append("mov bx %d"%zmienne[tmp[0]][0])
					wyjscie.append("mov cx %d"%tmp_nr)
					wyjscie.append("int 2")
				else:
					error_header(linia,x);
					unknow_symbol(tmp[1])
					exit(1)

print "Compiled:"
plik=open("out.asm","w")
for linia in wyjscie:
	print linia
	plik.write(linia+"\n")
