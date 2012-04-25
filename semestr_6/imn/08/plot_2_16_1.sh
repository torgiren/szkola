#!/usr/bin/gnuplot
set term jpeg
set out "plot_2_16_1.jpg"
set xlabel "iter"
set ylabel "ak"
set title "k=16"
plot "zad2_16_1.dat" using 1:2 w l
