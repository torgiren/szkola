#!/usr/bin/env python
#*-* coding: utf-8 *-*
from image_anal import ImageAnal
img = ImageAnal()
img.open("12-t1.bmp")
#img.open("test.png")
img.KKM()
img.save('kkm.png')
