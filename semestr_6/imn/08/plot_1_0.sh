#!/usr/bin/gnuplot
set term jpeg
set out "plot_1_0.jpg"
set xlabel "w"
set ylabel "iter"
splot "zad1_0.dat" using 1:2:3
