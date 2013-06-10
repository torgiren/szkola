#!/usr/bin/env python
#*-* coding: utf8 *-*
from image_anal import ImageAnal
img = ImageAnal()
print "Wczytuje obraz"
img.open("ocr1.png")
print "Zaczynam segmentacje"
img.segment1('1')
