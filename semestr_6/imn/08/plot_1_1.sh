#!/usr/bin/gnuplot
set term jpeg
set out "plot_1_1.jpg"
set xlabel "iter"
set ylabel "ak"
set title "k=1"
plot "zad1_1.dat" using 1:2 w l
