#!/usr/bin/gnuplot
set term png
set out "plot_5.png"
set xlabel "i"
set ylabel "j"
set yrange [-1:1]
plot "zad1_250.dat"
