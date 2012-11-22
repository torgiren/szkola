#!/usr/bin/env python
# -*- coding: utf-8
import bazowiec
import interface
sel_baza=None
sel_table=None
wheres=[]
selects=[]
def makeQuery():
	cmd="select "
	for i,s in enumerate(selects):
		if i!=0:
			cmd+=","
		cmd+=s
	cmd+="\nfrom %s where\n"%sel_table
	for s in wheres:
		cmd+=s
	return cmd	
def mainWindow(face):
	global selects
	title=face.newwin("title",8,70,1,1)
	face.addstr("title","Baza: %s, tabela: %s\n"%(sel_baza,sel_table))
	cmd=makeQuery()
	face.addstr("title",cmd)
def selectDatabase(baza,face):
	OPTS=baza.listDatabases()
	sel=face.menu("bazy","Bazy:",15,40,9,1,2,1,OPTS)
	baza.setDatabase(sel)
	return sel

def selectTable(baza,face):
	OPTS=baza.listTables()
	sel=face.menu("tabele","Tabele",15,40,9,1,2,1,OPTS)
	return sel
def selectColumn(baza,face,table,title):
	OPTS=baza.listColumns(table)
	sel=face.menu("columny",title,15,40,9,1,2,1,("%s:%s"%(row[0],row[1]) for row in OPTS),True)
	return sel

def selectType(baza,face):
	OPTS=['=','!=','>','<','like']
	sel=face.menu("typ","Typ warunku",11,20,12,4,2,1,OPTS,False)
	return sel

def selectComp(baza,face):
	OPTS=['and','or']
	sel=face.menu("typ","Kombinacja",11,20,12,4,2,1,OPTS,False)
	return sel
	
baza= bazowiec.Bazowiec()
baza.connect()
face=interface.Interface()
mainWindow(face)
sel_baza=selectDatabase(baza,face)
mainWindow(face)
sel_table=selectTable(baza,face)
while 1:
	mainWindow(face)
	sel=selectColumn(baza,face,sel_table,'Co wyselekcjonowac')
	if sel=="_DONE_":
		break
	else:
		global selects
		selects.append(sel.split(':')[0])
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
face.__del__()
for i in baza.query(makeQuery()):
	print i

