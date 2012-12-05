import curses
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
			self.itsWindow=curses.newwin(sizeY-2,sizeX-2,offsetY+1,offsetX+1)
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

