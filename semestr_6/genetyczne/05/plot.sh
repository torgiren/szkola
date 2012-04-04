#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot.jpg"
set xlabel "pokolenie"
set ylabel "dopasowanie"
set title "mutacja=0.00001, cross=0.3, population=100"
plot "convergence.txt" using 1:2  title "srednia" w l, "convergence.txt" using 1:3 title "najlepsze" w l
replot

