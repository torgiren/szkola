#!/usr/bin/gnuplot
set term jpeg
set out "plot_3_2.jpg"
set xlabel "i"
set ylabel "j"
set zlabel "potencjal"
splot "zad3_2.dat" using 1:2:3 w l
