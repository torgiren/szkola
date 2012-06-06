#!/usr/bin/gnuplot
set term png
set out "plot_4.png"
set xlabel "i"
set ylabel "j"
set yrange [-1:1]
plot "zad1_200.dat"
