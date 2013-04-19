#!/usr/bin/env python
#*-* coding: utf8 *-*
from image_anal import ImageAnal
img = ImageAnal()
img.open('12-b.bmp')
img.segment1('seg1_1')

img.open('12-t2.bmp')
img.segment1('seg1_2')

img.open('12-b.bmp')
img.segment2('seg2_1')

img.open('12-t2.bmp')
img.segment2('seg2_2')
