import curses
from window import Window
from menu import Menu
class Interface:
	def __init__(self):
		self.stdscr=curses.initscr()
		self.stdscr.keypad(1)
		curses.noecho()
		curses.curs_set(0)
		curses.start_color()
		curses.init_pair(1,curses.COLOR_WHITE,curses.COLOR_BLUE)
		self.windows={}
	def __del__(self):
		curses.endwin()
	def newwin(self,name,sizeY,sizeX,offsetY,offsetX, border=False):
		self.windows[name]=Window(sizeY,sizeX,offsetY,offsetX,border)
		return self.windows[name]
	def addstr(self,name,string):
		self.windows[name].addstr(string)
	def refresh(self):
		self.stdscr.refresh()
		for (i,k) in self.windows.items():
			k.refresh()
	def getch(self):
		return self.stdscr.getch()
	def clear(self):
		self.stdscr.clear()
		for (i,k) in self.windows.items():
			k.clear()
