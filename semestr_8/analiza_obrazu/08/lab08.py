#!/usr/bin/env python
#*-* coding: utf8 *-*
from image_anal import ImageAnal

img = ImageAnal()
img.open('a01.bmp')
img.KKM()
img.charakterystyczne_01()
img.save('char_a01_01.png')

img.open('a01.bmp')
img.KKM()
img.charakterystyczne_02()
img.save('char_a01_02.png')
