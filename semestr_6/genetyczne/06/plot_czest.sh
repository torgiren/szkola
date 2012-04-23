#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot_czesc.jpg"
set xlabel "x"
set ylabel "y"
plot "czest.dat" using 1:2  title "x" w l
replot

