#!/usr/bin/gnuplot
set term jpeg
set out "plot_1_1.jpg"
set xlabel "w"
set ylabel "iter"
plot "zad1_1.dat" using 1:2 w l
