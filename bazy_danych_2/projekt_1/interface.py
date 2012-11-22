import curses
class Interface:
	class Window:
		def __init__(self,sizeY,sizeX,offsetY,offsetX,border):
			self.itsBorder=border
			self.itsSizeX=sizeX
			self.itsSizeY=sizeY
			self.itsOffsetY=offsetY
			self.itsOffsetX=offsetX
			if self.itsBorder:
				self.itsWindowBorder=curses.newwin(sizeY,sizeX,offsetY,offsetX)
				self.itsWindowBorder.border()
				self.itsWindow=curses.newwin(sizeY-1,sizeX-1,offsetY+1,offsetX+1)
			else:
				self.itsWindow=curses.newwin(sizeY,sizeX,offsetY,offsetX)
		def addstr(self,string):
			self.itsWindow.addstr(string)
		def refresh(self):
			if self.itsBorder:
				self.itsWindowBorder.border()
				self.itsWindowBorder.refresh()
			self.itsWindow.refresh()
		def clear(self):
			if self.itsBorder:
				self.itsWindowBorder.clear()
			self.itsWindow.clear()
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
		self.windows[name]=self.Window(sizeY,sizeX,offsetY,offsetX,border)
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
