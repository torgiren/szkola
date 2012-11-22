import curses
from window import Window
class Menu(Window):
	def __init__(self,sizeY,sizeX,offsetY,offsetX,border):
#		Window.__init__(sizeY,sizeX,offsetY,offsetX,border)
		Window.__init__(self,sizeY+2,sizeX,offsetY,offsetX,border)
		self.itsOpts=[]
		self.itsAct=0
		self.ViewStart=0
	def addopt(self,opt):
		self.itsOpts.append(opt)
	def redraw(self):
		self.itsWindow.clear()
		for i,o in enumerate(self.itsOpts[self.ViewStart:self.ViewStart+self.itsSizeY-2]):
			if self.itsAct==i+self.ViewStart:
				style=curses.color_pair(1)|curses.A_BOLD
			else:
				style=curses.color_pair(0)
			self.itsWindow.addstr(1+i,0,o,style)
			if self.ViewStart>0:
				self.itsWindow.addch(0,0,'^',curses.color_pair(2))
			if self.ViewStart+self.itsSizeY-2<len(self.itsOpts):
				self.itsWindow.addch(self.itsSizeY-1,0,'v',curses.color_pair(2))
	def checkAct(self):
		if self.itsAct>=len(self.itsOpts):
			self.itsAct=len(self.itsOpts)-1
#			self.itsAct-=len(self.itsOpts)
		if self.itsAct<0 :
			self.itsAct=0
#			self.itsAct+=len(self.itsOpts)

		if self.itsAct<self.ViewStart:
			self.ViewStart=self.itsAct
		if self.itsAct>self.ViewStart+self.itsSizeY-3:
			self.ViewStart=self.itsAct-self.itsSizeY+3
	def driver(self,key):
		if key==curses.KEY_UP:
			self.itsAct-=1
		if key==curses.KEY_DOWN:
			self.itsAct+=1
		if key==curses.KEY_NPAGE:
			self.itsAct+=self.itsSizeY-3
		if key==curses.KEY_PPAGE:
			self.itsAct-=self.itsSizeY-3
		if key==curses.KEY_HOME:
			self.itsAct=0
		if key==curses.KEY_END:
			self.itsAct=len(self.itsOpts)-1
		if key==10:
			return self.itsOpts[self.itsAct]
		if key==curses.KEY_F10:
			return "_DONE_"
		self.checkAct()
		self.redraw()
		return None
	def run(self,stdscr):
		self.itsAct=0
		stdscr.refresh()
		self.redraw()	
		self.refresh()
		while 1:
			self.redraw()	
			self.refresh()
			key=stdscr.getch()
			sel=self.driver(key)
			if sel:
				return sel
