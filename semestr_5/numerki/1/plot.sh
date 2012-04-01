#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot.jpg"
set xlabel "czas"
set ylabel "y(t)"
plot "dane.dat" using 1:2 title "wykres czegostam" w l
replot
