#!/usr/bin/env python
#*-* coding: utf8 *-*
import glob
from scipy import misc
from image_anal import ImageAnal
from pprint import pprint
from PIL import Image, ImageFont, ImageDraw


def gen_baze():

    dane = glob.glob("dana/*/*")
    litery = glob.glob("dana/*")
    litery = [unicode(i.split('/')[1], 'utf-8')[4] for i in litery]
    dane = {}
    print litery

    for l in litery:
        tmp = []
        print "wczytuję literę: ", l
        for z in glob.glob(u"dana/znak%s/*.png" % l):
            print "wczytuje znak ", z
            tmp.append(misc.imread(z, flatten=1))
        dane[l] = tmp
    return dane


def porownaj(dane, p):
    wyniki = []
    test = misc.imresize(misc.imread(p), (50, 50))
    for l, k in dane.items():
        for z in k:
            wyniki.append([abs(test - z).sum(), l])
    wyniki.sort()

#    znak = wyniki[0][1].split('/')[1].decode('utf-8')[4]
    return wyniki

if __name__ == "__main__":

    img = ImageAnal()
    print "Wczytuje obraz"
    img.open("ocr1.png")
    rozmiar = img.shape()
    wynik = Image.new('RGB', (2 * rozmiar[1], 2 * rozmiar[0]), 'white')
    font = ImageFont.truetype('fonts/arial.ttf', 12)
    draw = ImageDraw.Draw(wynik)
#img.open("tekst_jd.jpg")
    print "Zaczynam segmentacje"
    img.segment2('wynik')

    dane = gen_baze()
    pliki = glob.glob('wynik/*')
    pliki.sort()
    tekst = []
    i = 0
    for p in pliki:
        wyniki = porownaj(dane, p)
        znak = wyniki[0][1]
        val = p.split('x')[1]
        tekst.append((val, znak))
#    if znak=='.':
#        tekst.append(' ')
#    if znak==',':
#        tekst.append(' ')
        i += 1
        pos = p.split('/')[1].split('x')[:4]
        draw.text(
            (int(pos[1]), int(pos[0])), text=znak, font=font, fill='black')
        print str(i) + "/" + str(len(pliki))

    wynik.save('rozpoznane.png')
    tekst.sort()
    pprint(tekst)
    tekst = [i[1] for i in tekst]
    print "".join(tekst)
