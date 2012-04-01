#!/usr/bin/gnuplot
set term jpeg
set size square
set out "f2.jpg"
set xlabel "x"
set ylabel "Moment bezwladnosci"
plot sin(5*x)*x*x
replot
