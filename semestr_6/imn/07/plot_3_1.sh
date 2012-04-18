#!/usr/bin/gnuplot
set term jpeg
set out "plot_3_1.jpg"
set xlabel "w"
set ylabel "iter"
plot "zad3_1.dat" using 1:2 w l
