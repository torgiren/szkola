#!/usr/bin/gnuplot
set term jpeg
set size square
set out "f2.jpg"
set xlabel "x"
set ylabel "f(x)"
set grid
show grid
set xrange [0:50]
plot "f2.dat" using 1:2  title "f(x)" w l
replot
