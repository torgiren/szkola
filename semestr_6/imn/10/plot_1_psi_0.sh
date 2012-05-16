#!/usr/bin/gnuplot
set term jpeg
set out "plot_1_psi_0.jpg"
set xlabel "i"
set ylabel "j"
plot "zad1_psi_0.dat" using 2:3 w l,"zad1_psi_0.dat" using 2:4 w l
