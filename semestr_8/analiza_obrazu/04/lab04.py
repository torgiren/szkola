#!/usr/bin/env python
#*-* coding: utf8 *-*
from image_anal import ImageAnal
img = ImageAnal()
img.open('tux.png')
img.szum(prop=0.05, method='solpieprz')
img.save('tux_solpieprz05.png')

img.open('tux.png')
img.szum(prop=0.10, method='solpieprz')
img.save('tux_solpieprz10.png')

img.open('tux.png')
img.szum(prop=0.15, method='solpieprz')
img.save('tux_solpieprz15.png')
