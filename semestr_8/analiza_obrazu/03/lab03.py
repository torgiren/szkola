#!/usr/bin/env python
#*-* coding: utf8 *-*
from image_anal import ImageAnal
img = ImageAnal()
print "Jasnosc"
print "-50"
img.open("tux.png")
img.brightness(-50)
img.save("b-50.png")
print "-25"
img.open("tux.png")
img.brightness(-25)
img.save("b-25.png")
print "25"
img.open("tux.png")
img.brightness(25)
img.save("b25.png")
print "50"
img.open("tux.png")
img.brightness(50)
img.save("b50.png")
print "Roberts"
img.open("tux.png")
img.roberts()
img.save("roberts.png")
print "Sobel"
img.open("tux.png")
img.sobel()
img.save("sobel.png")
print "Obrot"
print "Oryginalny"
img.open("tux.png")
img.rotate(35, method="orig")
img.save("rot_orig.png")
