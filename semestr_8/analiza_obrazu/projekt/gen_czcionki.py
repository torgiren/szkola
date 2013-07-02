#!/usr/bin/env python
#*-* coding: utf8 *-*
from glob import glob
from PIL import Image, ImageFont, ImageDraw
from image_anal import ImageAnal
from scipy import misc
import shutil
import time
import os
anal = ImageAnal()
text = u"A B C D E F G H I J K L M N O P Q R S T U W X Y Z a b c d e f g h i j k l m n o p q r s t u w x y z 0 1 2 3 4 5 6 7 8 9 . , ą ó ł ź ć ś ń ę Ą Ó Ł Ź Ć Ś Ń Ę"
text_arr = text.split()
files = glob("fonts/*.ttf")
files.sort()
arial = ImageFont.truetype('fonts/arial.ttf', 20)
for i, f in enumerate(files):
    shutil.rmtree('fonty_png', ignore_errors=True)
    os.mkdir('fonty_png')
    print "Tworze obrazek i fonty"
    font = ImageFont.truetype(f, 40)
    img = Image.new("RGB", (40 * len(text), 80), 'white')
    draw = ImageDraw.Draw(img)
    print f
    draw.text((10, 10), text=text, font=font, fill='black')
    print "Zapisuję obrazek"
    img.save("czcionki.png")
    del img
    print "Otwieram w analizatorze"
    anal.open("czcionki.png")
    print "Segmentuje"
    anal.segment2('fonty_png')
    print "Tworze liste do przeniesienia"
    to_move = glob("fonty_png/*.png")
    xy = [i.split('x')[1] for i in to_move]
    xy.sort()
    if len(to_move) != len(text_arr):

        print "Blad segmentacji. liczba wykrytych liter nie zgadza się z rzeczywistą"
        print "Do przeniesienia: ", len(to_move)
        print "Rzeczywista: ", len(text_arr)
        print "TODO: Dorobić poprawianie"
        raise Exception
#        for k in range(len(to_move)):
#            co = raw_input("Co to jest %s? " % k)
#            src = "fonty_png/%05d.png" % k
#            dst = "dana/znak%s/%s.png" % (co, unicode((time.time())))
#            shutil.move(src, dst)
#            print src, dst
    else:
        for k in to_move:
            val = k.split('x')[1]
            index = xy.index(val)
            src = k
            dst = "dana/znak%s/%s.png" % (text[2 * index], unicode((time.time())))
            misc.imsave(dst, misc.imresize(misc.imread(src),(50,50)))
#            shutil.move(src, dst)
            print src, dst



#        for i, j in enumerate(text_arr):
#            src = "fonty_png/%05d.png" % i
#            dst = "dana/znak%s/%s.png" % (j, unicode((time.time())))
#            shutil.move(src, dst)
#            print src, dst
