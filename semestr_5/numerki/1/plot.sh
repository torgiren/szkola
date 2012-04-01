#!/usr/bin/gnuplot
set term postscript  color enhanced eps
set out "plot.eps"
set key left top
set size square
set xlabel "czas"
set ylabel "y(t)"
plot "dane.dat" using 1:2 title "wykres czegostam" w l
replot
