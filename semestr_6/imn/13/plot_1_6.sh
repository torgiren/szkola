#!/usr/bin/gnuplot
set term png
set out "plot_6.png"
set xlabel "i"
set ylabel "j"
set yrange [-1:1]
plot "zad1_300.dat"
