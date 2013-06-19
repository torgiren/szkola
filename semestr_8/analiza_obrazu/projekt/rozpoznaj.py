#!/usr/bin/env python
#!/usr/bin/env python
#*-* coding: utf8 *-*
import glob
from scipy import misc
from image_anal import ImageAnal
img = ImageAnal()
print "Wczytuje obraz"
img.open("tekst_jd.jpg")
print "Zaczynam segmentacje"
img.segment1('wynik')

dane = glob.glob("dana/*/*")

pliki = glob.glob('wynik/*')
pliki.sort()
tekst = []
i = 0
for p in pliki:
    wyniki = []
    test = misc.imread(p)
    for f in dane:
        d = misc.imread(f)
        wyniki.append([abs(test - d).sum(), f])
    wyniki.sort()

    znak = wyniki[0][1].split('/')[1].decode('utf-8')[4]
    tekst.append(znak)
    if znak=='.':
        tekst.append(' ')
    if znak==',':
        tekst.append(' ')
    i+=1
    print str(i)+"/"+str(len(pliki))

print "".join(tekst)
