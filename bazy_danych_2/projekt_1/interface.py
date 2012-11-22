import curses
from window import Window
from menu import Menu
class Interface:
	def __init__(self):
		self.stdscr=curses.initscr()
		self.stdscr.keypad(1)
		curses.noecho()
		curses.curs_set(0)
		curses.cbreak()
		curses.start_color()
		curses.init_pair(1,curses.COLOR_WHITE,curses.COLOR_BLUE)
		curses.init_pair(2,curses.COLOR_RED,curses.COLOR_BLACK)
		self.windows={}
	def __del__(self):
		curses.endwin()
	def newwin(self,name,sizeY,sizeX,offsetY,offsetX, border=False):
		self.windows[name]=Window(sizeY,sizeX,offsetY,offsetX,border)
		return self.windows[name]
	def newmenu(self,name,sizeY,sizeX,offsetY,offsetX):
		self.windows[name]=Menu(sizeY,sizeX,offsetY,offsetX,False)
		return self.windows[name]
	def menu(self,name,title,sizeY,sizeX,offsetY,offsetX,menuOffsetY,menuOffsetX,options):
		self.refresh()
		self.windows[name]=Window(sizeY,sizeX,offsetY, offsetX,True)
		self.windows[name].addstr(title)
		self.windows[name].refresh()
		self.windows["%s_menu"%name]=Menu(sizeY-menuOffsetY-3,sizeX-2,menuOffsetY+offsetY,offsetX+menuOffsetX,False)
		men=self.windows["%s_menu"%name]
		for o in options:
			men.addopt(o)
		men.redraw()
		return men.run(self.stdscr)
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
