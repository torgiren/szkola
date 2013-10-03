#!/usr/bin/env python
#*-* coding: utf-8 *-*
import Image
import shutil
import glob
import time
files = glob.glob("1/*.png")
files.sort()
litera = ""
for f in files:
    if not litera:
        litera = raw_input(f+": ").decode('utf-8')
    l = litera[0]
    litera = litera[1:]
    dst = u"dana/znak%s/%s.png"%(l,unicode(int(time.time())))
    f = unicode(f)
    shutil.move(f, dst)
    print "%s %s"%(f, dst)
