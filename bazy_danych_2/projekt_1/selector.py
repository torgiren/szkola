#!/usr/bin/env python
import curses
#import bazowiec
import interface
#baza= bazowiec.Bazowiec()
#baza.connect()
#OPTS=baza.listDatabases()
OPTS=["a","b","c","d"]
face=interface.Interface()
win=face.newwin("menu",25,40,10,10,True)
menu=interface.Menu(5,20,15,1,False)
menu.addopt("raz")
menu.addopt("dwa")
menu.addopt("trzy")
menu.redraw()
act=0
while 1:
	face.refresh()
	menu.redraw()
	menu.refresh()
	key=face.getch()
	face.clear()
	if key==ord('q'):
		break
	menu.driver(key)	
curses.endwin()
