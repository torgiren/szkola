#!/usr/bin/env python
import bazowiec
import interface
sel_baza=None
sel_table=None
def mainWindow(face,actBaza=None,actTabela=None):
	title=face.newwin("title",3,70,1,1)
	face.addstr("title","Baza: %s, tabela: %s"%(actBaza,actTabela))

def selectDatabase(baza,face):
	OPTS=baza.listDatabases()
	sel=face.menu("bazy","Bazy:",15,30,4,1,2,1,OPTS)
	baza.setDatabase(sel)
	return sel
def selectTable(baza,face):
	OPTS=baza.listTables()
	sel=face.menu("tabele","Tabele",15,30,4,1,2,1,OPTS)
	return sel
def selectColumn(baza,face,table):
	OPTS=baza.listColumns(table)
	sel=face.menu("columny","Columny:",15,30,4,1,2,1,("%s - %s"%(row[0],row[1]) for row in OPTS))
	return sel
baza= bazowiec.Bazowiec()
baza.connect()
face=interface.Interface()
mainWindow(face,sel_baza,sel_table)
sel_baza=selectDatabase(baza,face)
mainWindow(face,sel_baza,sel_table)
sel_table=selectTable(baza,face)
mainWindow(face,sel_baza,sel_table)
selectColumn(baza,face,sel_table)
face.__del__()
print sel_baza
