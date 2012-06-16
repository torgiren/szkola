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
def unknow_operator(symbol):
	print "Unknow operator: %s"%symbol
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
	if tmp[0]=="noop":
		wyjscie.append("noop")
	elif tmp[0]=="string" :
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
				if zmienne[tmp[0]][1]=='n':
#					print "numeryczna"
					sep=('+','-')
					old=0;
					wyjscie.append("push ax")
					wyjscie.append("push bx")
					wyjscie.append("push cx")
					wyjscie.append("push dx")
					wyjscie.append("mov ebp esp")
					wyjscie.append("alloc 2")
					czynnikow=0;
					for i in range(0,len(tmp[1])):
						if tmp[1][i] in sep:
							val=tmp[1][old:i]
							if val in zmienne:
						#		print "val %s jest zmiennych"%val
							#	wyjscie.append("%s %d"%(app,zmienne[val][0]))
								wyjscie.append("mov ax 1")
								wyjscie.append("mov bx %d"%zmienne[val][0])
								wyjscie.append("int 2")
								wyjscie.append("push cx")
								wyjscie.append("push dx")
								czynnikow+=1
							elif val.replace(".","",1).isdigit()==False:
								error_header(linie,x)
								unknow_symbol(tmp[1])
								exit(1)
							else:
								wyjscie.append('db %f'%(float(val)))
								nr=len(wyjscie)-1
								wyjscie.append("mov ax 1")
								wyjscie.append("mov bx %d"%nr)
								wyjscie.append("int 2")
								wyjscie.append("push cx")
								wyjscie.append("push dx")
								czynnikow+=1
#							print "val: "+val
#							print "sep: "+tmp[1][i]
							old=i+1;
						if tmp[1][i]=='+':
							wyjscie.append("push 1")
							app="add "
						elif tmp[1][i]=='-':
							wyjscie.append("push 2")
							app="sub"
						elif tmp[1][i]=='*':
							wyjscie.append("push 3")
							app="mul"
						elif tmp[1][i]=='/':
							wyjscie.append("push 4")
							app="div"
#					print "val: "+tmp[1][old:]
					wyjscie.append("mov ax 1")
					val=tmp[1][old:]
					if val in zmienne:
				#		print "val %s jest zmiennych"%val
					#	wyjscie.append("%s %d"%(app,zmienne[val][0]))
						wyjscie.append("mov ax 1")
						wyjscie.append("mov bx %d"%zmienne[val][0])
						wyjscie.append("int 2")
						wyjscie.append("mov [ebp+0] cx")
						wyjscie.append("mov [ebp+1] dx")
					elif val.replace(".","",1).isdigit()==False:
						error_header(linie,x)
						unknow_symbol(tmp[1])
						exit(1)
					else:
						print "Koncowe val: %s\n"%val
						wyjscie.append('db %f'%(float(val)))
						nr=len(wyjscie)-1
						wyjscie.append("mov ax 1")
						wyjscie.append("mov bx %d"%nr)
						wyjscie.append("int 2")
						wyjscie.append("mov [ebp+0] cx")
						wyjscie.append("mov [ebp+1] dx")



					for i in range(0,czynnikow):
						wyjscie.append("pop dx")
						wyjscie.append("pop cx")
						wyjscie.append("pop bx")


						wyjscie.append("mov ax [ebp+0]")
					
						wyjscie.append("cmp dx 1")
						wyjscie.append("jnz %d"%(len(wyjscie)+2))
						wyjscie.append("add bx")
						wyjscie.append("cmp dx 2")
						wyjscie.append("jnz %d"%(len(wyjscie)+2))
						wyjscie.append("sub bx")
#						wyjscie.append("cmp dx 3")
#						wyjscie.append("jnz %d"%(len(wyjscie)+2))
#						wyjscie.append("mul bx")
#						wyjscie.append("cmp dx 4")
#						wyjscie.append("jnz %d"%(len(wyjscie)+2))
#						wyjscie.append("div bx")

						wyjscie.append("mov [ebp+0] ax")


						wyjscie.append("mov ax [ebp+1]")
					
						wyjscie.append("cmp dx 1")
						wyjscie.append("jnz %d"%(len(wyjscie)+2))
						wyjscie.append("add cx")
						wyjscie.append("cmp dx 2")
						wyjscie.append("jnz %d"%(len(wyjscie)+2))
						wyjscie.append("sub cx")
						wyjscie.append("cmp dx 3")
						wyjscie.append("jnz %d"%(len(wyjscie)+2))
						wyjscie.append("mul cx")
						wyjscie.append("cmp dx 4")
						wyjscie.append("jnz %d"%(len(wyjscie)+2))
						wyjscie.append("div cx")
						
						wyjscie.append("jnc %d"%(len(wyjscie)+6))
						wyjscie.append("mov [ebp+1] ax")
						wyjscie.append("mov ax [ebp+0]")
						wyjscie.append("inc ax")
						wyjscie.append("mov [ebp+0] ax")
						wyjscie.append("jmp %d"%(len(wyjscie)+2))

						wyjscie.append("mov [ebp+1] ax")



					wyjscie.append("mov ax 2")
					wyjscie.append("mov bx %d"%zmienne[tmp[0]][0])
					wyjscie.append("mov cx [ebp+0]")
					wyjscie.append("mov dx [ebp+1]")
					wyjscie.append("int 2")
#					//TODO
#					/*
#						Wczytywanie do ax [esp+0], a potem pop bx i add bx i zapis do [esp+0]
#						potem to samo dla +1 
#					*/
					wyjscie.append("pop dx")
					wyjscie.append("pop cx")
					wyjscie.append("pop bx")
					wyjscie.append("pop ax")
					
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
