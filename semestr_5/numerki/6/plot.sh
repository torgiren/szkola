#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot.jpg"
set xlabel "q"
set ylabel "wartosc"
plot "w.dat" using 1:2  title "W6" w l, "w.dat" using 1:3 title "W2" w l
replot
