#!/usr/bin/env python
#*-* coding: utf8 *-*
from image_anal import ImageAnal
im = ImageAnal()

print "Generuje negatyw"
im.load_image("tux.png")
im.convert("RGB")
im.negative()
im.save("negative.png")

print "Generuje odcień szarości 1"
im.load_image("tux.png")
im.convert("RGB")
im.grayscale(method=1)
im.save("grayscale1.png")

print "Generuje odcień szarości 2"
im.load_image("tux.png")
im.convert("RGB")
im.grayscale(method=2)
im.save("grayscale2.png")

print "Normalizuje"
im.load_image("tux.png")
im.convert("RGB")
im.normalize()
im.save("normalize.png")
