#!/usr/bin/python
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
def unquote(tekst):
	return tekst[1:-1]
linie=wczytaj_plik("hello.jzk")
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
		zmienne[inicjacja[0]]=len(wyjscie)
		cmd="db";
		if len(inicjacja)==2:
			cmd+=" "+unquote(inicjacja[1])
		wyjscie.append(cmd);
	if tmp[0]=="wczytaj":
		if len(tmp)!=2:
			error_header(linia,x)
			arguments(tmp,2)
			exit(1)
		wyjscie.append("mov ax 2")
		wyjscie.append("mov bx %d" % zmienne[tmp[1]]);
		wyjscie.append("int 1");
	if tmp[0]=="wypisz":
		if len(tmp)!=2:
			error_header(line,x)
			arguments(tmp,2)
			exit(1)
		wyjscie.append("mov ax 1")
		wyjscie.append("mov bx %d"%zmienne[tmp[1]])
		wyjscie.append("int 1")
	if tmp[0]=="copy":
		args=tmp[1].split(",");
		if len(tmp)!=2:
			error_header(linia,x)
			arguments(tmp,2)
			exit(1)
		wyjscie.append("mov ax 4")
		wyjscie.append("mov bx %d" % zmienne[args[0]])
		wyjscie.append("mov cx %d" % zmienne[args[1]])
		wyjscie.append("int 2")

	tmp=linia.rstrip().split("=",1)
	if tmp[0] in zmienne:
		print linia


print "Compiled:"
plik=open("out.asm","w")
for linia in wyjscie:
	print linia
	plik.write(linia+"\n")
