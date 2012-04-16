#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot.jpg"
set xlabel "x"
set ylabel "y"
plot "rozklad.dat" using 1:2  title "x" w l
replot

