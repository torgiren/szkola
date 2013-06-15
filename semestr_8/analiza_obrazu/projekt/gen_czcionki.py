#!/usr/bin/env python
#*-* coding: utf8 *-*
from glob import glob
from PIL import Image, ImageFont, ImageDraw
text = "A B C D E F G H I J K L M N O P Q R S T U W X Y Z a b c d e f g h i j k l m n o p q r s t u w x y z 0 1 2 3 4 5 6 7 8 9 . , -"
files = glob("fonts/*.ttf")
img = Image.new("RGB", (12*len(text), 20*len(files)), 'white')
draw = ImageDraw.Draw(img)
arial = ImageFont.truetype('fonts/arial.ttf', 12)
for i, f in enumerate(files):
	print f
	font = ImageFont.truetype(f, 12)
	draw.text((10,20 * i), text=text, font=font)
img.save("czcionki.png")

