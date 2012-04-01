#!/usr/bin/gnuplot
set term jpeg
set size square
set out "f.jpg"
set xlabel "x"
set ylabel "f(x)"
set grid
show grid
plot "f.dat" using 1:2  title "f(x)" w l
replot
