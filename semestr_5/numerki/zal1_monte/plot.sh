#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot.jpg"
set xlabel "N"
set xtics nomirror rotate by -45
set ylabel "Moment bezwladnosci"
plot "wynik.dat" using 1:2  title "Moment bezwladnosci" w l
replot
