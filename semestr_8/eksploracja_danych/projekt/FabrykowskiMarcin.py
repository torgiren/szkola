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

SCORING = False
print "Wczytywanie danych: ",
sys.stdout.flush()
data = Orange.data.Table("winequality-white.csv")
print OK

if SCORING:
    opts=[{'m_pruning':0, 'max_depth':10},
          {'m_pruning':0, 'max_depth':50},
          {'m_pruning':0, 'max_depth':100},
          {'m_pruning':0, 'max_depth':200},
          {'m_pruning':0, 'max_depth':300},
          {'m_pruning':0, 'max_depth':400},
          {'m_pruning':0, 'max_depth':500},
          {'m_pruning':0, 'max_depth':1000},
          {'m_pruning':1, 'max_depth':10},
          {'m_pruning':1, 'max_depth':50},
          {'m_pruning':1, 'max_depth':100},
          {'m_pruning':1, 'max_depth':200},
          {'m_pruning':1, 'max_depth':300},
          {'m_pruning':1, 'max_depth':400},
          {'m_pruning':1, 'max_depth':500},
          {'m_pruning':1, 'max_depth':1000},
          {'m_pruning':10, 'max_depth':10},
          {'m_pruning':10, 'max_depth':50},
          {'m_pruning':10, 'max_depth':100},
          {'m_pruning':10, 'max_depth':200},
          {'m_pruning':10, 'max_depth':300},
          {'m_pruning':10, 'max_depth':400},
          {'m_pruning':10, 'max_depth':500},
          {'m_pruning':10, 'max_depth':1000}]
    print "Generowanie staystyk: "
    sys.stdout.flush()
    for opt in opts:
        print opt,
        learners = [Orange.classification.tree.TreeLearner(**opt)]
        res = Orange.evaluation.testing.cross_validation(learners, data, folds=10)
        print "CA: %.4f" % \
            (Orange.evaluation.scoring.CA(res)[0])
#    print "CA: %.4f\nAUC: %.4f\nIS: %.4f \n" % \
#        (Orange.evaluation.scoring.CA(res)[0],
#        Orange.evaluation.scoring.AUC(res)[0],
#        Orange.evaluation.scoring.IS(res)[0])
    print OK

opts = {'m_pruning':10, 'max_depth':300}
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
