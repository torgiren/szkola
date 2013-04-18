#!/usr/bin/env python
#*-* coding: utf-8 *-*
from image_anal import ImageAnal
img = ImageAnal()
files = ['12-t1', '12-t2', '12-t3', '12-t4']
for f in files:
    img.open(f+".bmp")
    img.KKM()
    img.save(f+'_kkm.png')

    img.open(f+".bmp")
    img.maska()
    img.save(f+'_maska.png')
