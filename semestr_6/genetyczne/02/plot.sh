#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot.jpg"
set xlabel "q"
set ylabel "wyzanacznik"
plot "wyniki.dat" using 1:2  title "Liczba schematow" w l
replot

