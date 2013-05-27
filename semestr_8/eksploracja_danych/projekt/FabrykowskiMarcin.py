#!/usr/bin/env python
#*-* coding: utf8 *-*
OK = "\033[1;32mOK\033[1;m"
print "Ładownie modułów: ",
import sys
try:
	import scipy
except(ImportError):
	print "Warning: Brak modulu scipy"
try:
	import Orange
except(ImportError):
	print "Error: Brak modułu Orange"
	sys.exit(-1)
try:
	import pygraphviz as pgv
except(ImportError):
	print "Error: Brak modułu pygraphviz"
	sys.exit(-1)
print OK

opts={'m_pruning':2, 'max_depth':10}

print "Wczytywanie danych: ",
sys.stdout.flush()
data = Orange.data.Table("winequality-white.csv")
print OK
print "Tworzenie drzewa: ",
sys.stdout.flush()
tree = Orange.classification.tree.TreeLearner(data, **opts)
print OK
print "Generowanie pliku .dot: ", 
sys.stdout.flush()
tree.dot(file_name="FabrykowskiMarcin.dot", leaf_shape='box')
print OK
print "Generowanie wykresu: ",
sys.stdout.flush()
G = pgv.AGraph("FabrykowskiMarcin.dot")
G.layout(prog='dot')
G.draw(path="FabrykowskiMarcin.png", prog='dot')
print OK
print "Generowanie staystyk: ",
sys.stdout.flush()
learners = [Orange.classification.tree.TreeLearner(**opts)]
res = Orange.evaluation.testing.cross_validation(learners, data, folds=5)
print OK
print "CA: %.2f\nAUC: %.2f" % (Orange.evaluation.scoring.CA(res)[0], Orange.evaluation.scoring.AUC(res)[0])
