#!/usr/bin/env python
#*-* coding: utf8 *-*
from image_anal import ImageAnal
img = ImageAnal()
print "Sol 0.05"
img.open('tux.png')
img.szum(prop=0.05, method='solpieprz')
img.save('tux_solpieprz05.png')

print "Sol 0.10"
img.open('tux.png')
img.szum(prop=0.10, method='solpieprz')
img.save('tux_solpieprz10.png')

print "Sol 0.15"
img.open('tux.png')
img.szum(prop=0.15, method='solpieprz')
img.save('tux_solpieprz15.png')

print "Rownomierny1 0.05"
img.open('tux.png')
img.szum(prop=0.05, method='rownomierny1')
img.save('tux_rowno1_05.png')

print "Rownomierny1 0.10"
img.open('tux.png')
img.szum(prop=0.10, method='rownomierny1')
img.save('tux_rowno1_10.png')

print "Rownomierny1 0.15"
img.open('tux.png')
img.szum(prop=0.15, method='rownomierny1')
img.save('tux_rowno1_15.png')

print "Rownomierny2 0.05"
img.open('tux.png')
img.szum(prop=0.05, method='rownomierny2')
img.save('tux_rowno2_05.png')

print "Rownomierny2 0.10"
img.open('tux.png')
img.szum(prop=0.10, method='rownomierny2')
img.save('tux_rowno2_10.png')

print "Rownomierny2 0.15"
img.open('tux.png')
img.szum(prop=0.15, method='rownomierny2')
img.save('tux_rowno2_15.png')
