#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot.jpg"
set xlabel "pokolenie"
set ylabel "dopasowanie"
plot "convergence.txt" using 1:2  title "srednia" w l, "convergence.txt" using 1:3 title "najlepsze" w l
replot

