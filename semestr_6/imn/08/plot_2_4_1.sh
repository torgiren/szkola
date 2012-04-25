#!/usr/bin/gnuplot
set term jpeg
set out "plot_2_4_1.jpg"
set xlabel "iter"
set ylabel "ak"
set title "k=4"
plot "zad2_4_1.dat" using 1:2 w l
