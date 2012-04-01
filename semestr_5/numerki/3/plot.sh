#!/usr/bin/gnuplot
set term postscript  color enhanced eps
set out "plot.eps"

set xlabel "q"
set ylabel "wyzanacznik"
plot "dane.dat" using 1:2  title "wyznacznik od q" w l
replot
