#!/usr/bin/env python
import numpy as np
import matplotlib.pyplot as plt
import sys
if len(sys.argv)==1:
	print "Brak pliku z danymi"
	print "Usage: %s <data_file>"%sys.argv[0]
	class NotEnoughtParameters(Exception):
		pass
	raise NotEnoughtParameters
plik=open(sys.argv[1],"rt")
lines=plik.readlines()
plik.close()
wynik=[]
for x in lines:
	tmp=x.split()
	for x in range(len(tmp)):
		tmp[x]=float(tmp[x])
	s=1.*tmp[2]/tmp[1]
	wynik.append([tmp[0],tmp[0]+273,1./(tmp[0]+273),tmp[1],tmp[2]/1000.,s,np.log(s),1./s])
for x in wynik:
	print "%f, %f, %f, %f, %f, %f, %f %f"%(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7])
