#!/usr/bin/env python
#*-* coding: utf8 *-*
from glob import glob
from PIL import Image, ImageFont, ImageDraw
from image_anal import ImageAnal
import shutil
import time
anal = ImageAnal()
text = "A B C D E F G H I J K L M N O P Q R S T U W X Y Z a b c d e f g h i j k l m n o p q r s t u w x y z 0 1 2 3 4 5 6 7 8 9 . ,"
text_arr = text.split()
files = glob("fonts/*.ttf")
arial = ImageFont.truetype('fonts/arial.ttf', 20)
for i, f in enumerate(files):
	print "Tworze obrazek i fonty"
	font = ImageFont.truetype(f, 40)
	img = Image.new("RGB", (40*len(text), 80), 'white')
	draw = ImageDraw.Draw(img)
	print f
	draw.text((10,10), text=text, font=font, fill='black')
	print "Zapisuję obrazek"
	img.save("czcionki.png")
	del img
	print "Otwieram w analizatorze"
	anal.open("czcionki.png")
	print "Segmentuje"
	anal.segment2('fonty_png')
	print "Tworze liste do przeniesienia"
	to_move = glob("fonty_png/*.png")
	if len(to_move) != len(text_arr):
		print "Blad segmentacji. liczba wykrytych liter nie zgadza się z rzeczywistą"
		print "Do przeniesienia: ",len(to_move)
		print "Rzeczywista: ", len(text_arr)
		for k in range(len(to_move)):
			co = raw_input("Co to jest %s? "%k)
			src = "fonty_png/%05d.png"%k
			dst = "dana/znak%s/%s.png"%(co, unicode((time.time())))
#			obraz = ImageAnal()
#			obraz.open(src)
#			obraz.save('do_kkma.png')
#			obraz.negative()
#			obraz.kkm2()
#			obraz.save(src)
			shutil.move(src, dst)
			print src, dst
	else:
		for i,j in enumerate(text_arr):
			src = "fonty_png/%05d.png"%i
#			obraz = ImageAnal()
#			obraz.open(src)
#			obraz.save('do_kkma.png')
#			obraz.negative()
#			obraz.kkm2()
#			obraz.save(src)
			dst = "dana/znak%s/%s.png"%(j, unicode((time.time())))
			shutil.move(src, dst)
			print src, dst
