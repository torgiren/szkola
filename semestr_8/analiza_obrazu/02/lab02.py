#!/usr/bin/env python
#*-* coding: utf8 *-*
import image_anal as image
img = image.ImageAnal()
print "Skalowanie"
img.load_image("tux.png")
print "Skalowanie w dół"
img.scale(0.4)
img.save("scale_down.png")
print "Skalowanie w górę"
img.scale(2.5)
img.save("scale_up.png")

print "Progowanie"
print "Globalne"
img.load_image("tux.png")
img.progowanie(method="global")
img.save("global.png")

print "Lokalne"
print "5"
img.load_image("tux.png")
img.progowanie(method="local", otoczenie=5)
img.save("local_5.png")
print "11"
img.load_image("tux.png")
img.progowanie(method="local", otoczenie=11)
img.save("local_11.png")
print "15"
img.load_image("tux.png")
img.progowanie(method="local", otoczenie=15)
img.save("local_15.png")
print "21"
img.load_image("tux.png")
img.progowanie(method="local", otoczenie=21)
img.save("local_21.png")
print "25"
img.load_image("tux.png")
img.progowanie(method="local", otoczenie=25)
img.save("local_25.png")

print "Mieszane"
print "Odchylenie 15"
img.load_image("tux.png")
img.progowanie(method="mixed", otoczenie=15, odchylenie=15)
img.save("mixed_15.png")
print "Odchylenie 25"
img.load_image("tux.png")
img.progowanie(method="mixed", otoczenie=15, odchylenie=25)
img.save("mixed_25.png")
print "Odchylenie 35"
img.load_image("tux.png")
img.progowanie(method="mixed", otoczenie=15, odchylenie=35)
img.save("mixed_35.png")

print "Splot"
print "Rozmywajace"
print "1"
img.load_image("tux.png")
img.splot([1,1,1],[1,1,1],[1,1,1])
img.save("splot_1_1.png")
print "1"
img.load_image("tux.png")
img.splot([1,1,1],[1,2,1],[1,1,1])
img.save("splot_1_2.png")
print "3"
img.load_image("tux.png")
img.splot([1,2,1],[2,4,2],[1,2,1])
img.save("splot_1_3.png")

print "Wyostrzające"
print "1"
img.load_image("tux.png")
img.splot([0,-1,0],[-1,5,-1],[0,-1,0])
img.save("splot_2_1.png")
print "2"
img.load_image("tux.png")
img.splot([-1,-1,-1],[-1,9,-1],[-1,-1,-1])
img.save("splot_2_2.png")
print "3"
img.load_image("tux.png")
img.splot([-1,-2,-1],[-2,5,-2],[1,-2,1])
img.save("splot_2_3.png")
