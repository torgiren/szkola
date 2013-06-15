#!/usr/bin/env python2.7
#*-* coding: utf8 *-*
from image_anal import ImageAnal
img = ImageAnal()
img.open("czcionki.png")
img.segment2('fonty_png')
