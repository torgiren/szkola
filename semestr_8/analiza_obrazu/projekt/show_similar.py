#!/usr/bin/env python
#*-* coding: utf8 *-*
from rozpoznaj import gen_baze, porownaj
from scipy import misc
from pprint import pprint

dane = gen_baze()

pprint(porownaj(dane, 'wynik/00047x00173x00018x00192.png')[:30])
