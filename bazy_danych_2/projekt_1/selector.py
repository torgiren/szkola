#!/usr/bin/env python
import curses
stdscr=curses.initscr()
win=curses.newwin(20,40,10,10)
win.border()
x=win.getstr(1,1)
win.addstr(5,1,x)
win.getch()
curses.endwin()
