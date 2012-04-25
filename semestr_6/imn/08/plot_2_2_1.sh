#!/usr/bin/gnuplot
set term jpeg
set out "plot_2_2_1.jpg"
set xlabel "iter"
set ylabel "ak"
set title "k=2"
plot "zad2_2_1.dat" using 1:2 w l
