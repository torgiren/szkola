#!/usr/bin/env python
import curses
stdscr=curses.initscr()
stdscr.keypad(1)
curses.noecho()
curses.curs_set(0)
curses.start_color()
curses.init_pair(1,curses.COLOR_WHITE,curses.COLOR_BLUE)


win=curses.newwin(20,40,10,10)
OPTS=['Raz','Dwa','Trzy']
act=0
while 1:
	win.border()
	win.addstr(1,1,"Menu:")
	for count,o in enumerate(OPTS):
		if count==act:
			style=curses.color_pair(1)|curses.A_BOLD
		else:
			style=curses.color_pair(0)
		win.addstr(3+count,1,o,style)
	stdscr.refresh()
	win.refresh()
	key=stdscr.getch()
	if key==ord('q'):
		break
	elif key==curses.KEY_UP:
		act-=1
	elif key==curses.KEY_DOWN:
		act+=1
	if act<0:
		act+=len(OPTS)
	elif act>len(OPTS)-1:
		act-=len(OPTS)
curses.endwin()
