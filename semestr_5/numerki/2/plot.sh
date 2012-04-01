#!/usr/bin/gnuplot
set term postscript  color enhanced eps
set out "plot.eps"

set xlabel "czas"
set ylabel "y(t)"
plot "dane.dat" using 1:2 title "x(t)" w l
replot
