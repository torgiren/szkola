#!/usr/bin/gnuplot
set term postscript color enhanced eps
set size square
set out "f.eps"
set xlabel "x"
set ylabel "f(x)"
set grid
show grid
plot "f.dat" using 1:2  title "f(x)" w l
replot
