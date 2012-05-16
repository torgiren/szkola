#!/usr/bin/gnuplot
set term jpeg
set out "plot_1_zeta_0.7.jpg"
set xlabel "i"
set ylabel "j"
plot "zad1_zeta_0.7.dat" using 2:3 w l,"zad1_zeta_0.7.dat" using 2:4 w l
