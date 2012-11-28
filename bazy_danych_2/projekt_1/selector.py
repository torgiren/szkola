#!/usr/bin/env python
# -*- coding: utf-8
import bazowiec
import interface
sel_baza=None
sel_table=None
wheres=[]
selects=[]
def makeQuery():
	"""Zbudowanie zapytania używając wybranych column i kryteriów"""
	cmd="select "
	for i,s in enumerate(selects):
		if i!=0:
			cmd+=","
		cmd+=s
	cmd+="\nfrom %s \n"%sel_table
	if(wheres):
		cmd+=" where "
		for s in wheres:
			cmd+=s
	return cmd	
def mainWindow(face):
	"""Tworzenie głównego okna programu"""
	global selects
	title=face.newwin("title",8,70,1,1)
	face.addstr("title","Baza: %s, tabela: %s\n"%(sel_baza,sel_table))
	cmd=makeQuery()
	face.addstr("title",cmd)
def selectDatabase(baza,face):
	"""Tworzenie menu do wybory bazy danych"""
	OPTS=baza.listDatabases()
	sel=face.menu("bazy","Bazy:",15,40,9,1,2,1,OPTS)
	baza.setDatabase(sel)
	return sel

def selectTable(baza,face):
	"""Tworzenie menu do wyboru tablicy w aktualnej bazie banych"""
	OPTS=baza.listTables()
	sel=face.menu("tabele","Tabele",15,40,9,1,2,1,OPTS)
	return sel
def selectColumn(baza,face,table,title):
	"""Tworzenie menu do wyboru kolumny w aktualnej tabeli"""
	OPTS=baza.listColumns(table)
	sel=face.menu("columny",title,15,40,9,1,2,1,("%s:%s"%(row[0],row[1]) for row in OPTS),True)
	return sel

def selectType(baza,face):
	"""Tworzenie menu do wyboru typu kryterium"""
	OPTS=['=','!=','>','<','like']
	sel=face.menu("typ","Typ warunku",11,20,12,4,2,1,OPTS,False)
	return sel

def selectComp(baza,face):
	"""Tworzenie menu do wyboru typu łączenia kryteriów"""
	OPTS=['and','or']
	sel=face.menu("typ","Kombinacja",11,20,12,4,2,1,OPTS,False)
	return sel

#łączenie z bazą danych
baza= bazowiec.Bazowiec()
baza.connect()
#inicjacja interfejsu
face=interface.Interface()
#tworzenie okna głównego
mainWindow(face)
#wybór bazy danych
sel_baza=selectDatabase(baza,face)
mainWindow(face)
#wybór tabeli
sel_table=selectTable(baza,face)

#wybór kolumn do wyselekcjonowania
while 1:
	mainWindow(face)
	sel=selectColumn(baza,face,sel_table,'Co wyselekcjonowac')
	if sel=="_DONE_":
		break
	else:
		global selects
		selects.append(sel.split(':')[0])

#wybór kryteriów do wyselekcjonowania
while 1:
	mainWindow(face)
	sel=selectColumn(baza,face,sel_table,'Kryteria')
	if sel=="_DONE_":
		break;
	else:
		comb=""
		if len(wheres):
			comb=selectComp(baza,face)	
		type=selectType(baza,face)
		prompt=face.newwin('val',3,35,14,5,True)
		prompt.refresh()
		val=face.getstr(15,6)
		global wheres
		wheres.append("%s %s %s '%s' "%(comb,sel.split(':')[0],type,val))
#wyłączenie interfejsu curses
face.__del__()

#wypisanie wygenerowanego zapytania
print "Wynik:\n"
print makeQuery()

#wypisanie wyniku otrzymanego zapytania
for i in baza.query(makeQuery()):
	print i

