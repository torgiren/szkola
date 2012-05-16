#!/usr/bin/gnuplot
set term jpeg
set out "plot_1_u_0.jpg"
set xlabel "i"
set ylabel "j"
plot "zad1_u_0.dat" using 2:3 w l
