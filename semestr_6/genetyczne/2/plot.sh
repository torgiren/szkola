#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot.jpg"
set xlabel "n"
set ylabel "liczba schematow"
plot "wyniki.dat" using 1:2  title "Liczba schematow" w l
replot

set term jpeg
set size square
set out "plot_log.jpg"
set xlabel "n"
set ylabel "liczba schematow"
set logscale x
plot "wyniki.dat" using 1:2  title "Liczba schematow" w l
replot
