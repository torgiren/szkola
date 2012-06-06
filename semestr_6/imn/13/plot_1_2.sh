#!/usr/bin/gnuplot
set term png
set out "plot_2.png"
set xlabel "i"
set ylabel "j"
set yrange [-1:1]
plot "zad1_100.dat"
