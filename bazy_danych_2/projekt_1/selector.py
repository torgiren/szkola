#!/usr/bin/env python
import bazowiec
import interface
def mainWindow(face,actBaza=None,actTabela=None):
	pass
def selectDatabase(baza,face):
	OPTS=baza.listDatabases()
	return face.menu("bazy","Bazy:",15,30,1,1,2,1,OPTS)
def main():
	baza= bazowiec.Bazowiec()
	baza.connect()
	face=interface.Interface()
	sel_baza=selectDatabase(baza,face)
	return  sel_baza
print main()
