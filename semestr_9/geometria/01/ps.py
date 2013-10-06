#*-* coding: utf8 *-*
class PS:

    def __init__(self):
        self.wynik = []
        self.wynik.append("")

    def translate(self, x, y):
        self.wynik.append("%f %f translate" %(x, y))

    def moveto(self, x, y):
        self.wynik.append("%f %f moveto" % (x, y))

    def line(self, x,y ):
        self.wynik.append("%f %f lineto" % (x, y))

    def rline(self, x,y ):
        self.wynik.append("%f %f rlineto" % (x, y))

    def stroke(self):
        self.wynik.append("stroke")

    def colour(self, r, g, b):
        self.wynik.append("%f %f %f setrgbcolor" % (r, g, b))

    def newpath(self):
        self.wynik.append("newpath")

    def raw(self, r):
        self.wynik.append(r)

    def dash(self):
        self.wynik.append("[3 3] 0 setdash")

    def arc(self, x, y, r, a1, a2):
        self.wynik.append("%f %f %f %f %f arc" % (x, y, r, a1, a2))

    def setfont(self):
        self.wynik.append("/Tomes-Roman findfont")
        self.wynik.append("12 scalefont")
        self.wynik.append("setfont")

    def text(self, string):
        self.wynik.append("(%s) show "% string)

    def gen(self):
        return "\n".join(self.wynik) + "\n"
