import curses
from window import Window
class Menu(Window):
	def __init__(self,sizeY,sizeX,offsetY,offsetX,border):
#		Window.__init__(sizeY,sizeX,offsetY,offsetX,border)
		Window.__init__(self,sizeY,sizeX,offsetY,offsetX,border)
		self.itsHeight=self.itsSizeY
		self.itsOpts=[]
		self.itsAct=0
		self.ViewStart=0
	def addopt(self,opt):
		self.itsOpts.append(opt)
	def redraw(self):
#		self.itsWindow.clear()
		for i,o in enumerate(self.itsOpts[self.ViewStart:self.ViewStart+self.itsSizeY]):
			if self.itsAct==i+self.ViewStart:
				style=curses.color_pair(1)|curses.A_BOLD
			else:
				style=curses.color_pair(0)
			self.itsWindow.addstr(i,0,o,style)
	def Up(self):
		self.itsAct-=1
		self.CheckAct()
		self.redraw()
	def Down(self):
		self.itsAct+=1
		self.CheckAct()
		self.redraw()
	def CheckAct(self):
		if self.itsAct>=len(self.itsOpts):
			self.itsAct-=len(self.itsOpts)
		if self.itsAct<0 :
			self.itsAct+=len(self.itsOpts)

		if self.itsAct<self.ViewStart:
			self.ViewStart=self.itsAct
		if self.itsAct>self.ViewStart+self.itsSizeY-1:
			self.ViewStart=self.itsAct-self.itsSizeY+1
	def driver(self,key):
		if key==curses.KEY_UP:
			self.Up()	
		if key==curses.KEY_DOWN:
			self.Down()
