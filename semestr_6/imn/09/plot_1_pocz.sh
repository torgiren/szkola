#!/usr/bin/gnuplot
set term jpeg
set out "plot_1_pocz.jpg"
set xlabel "i"
set ylabel "j"
set zlabel "potencjal"
set contour both
show contour
splot "zad1_pocz.dat" using 1:2:3 w l
