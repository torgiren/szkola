#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot.jpg"
set xlabel "q"
set ylabel "wyzanacznik"
plot "dane.dat" using 1:2  title "wyznacznik od q" w l
replot
