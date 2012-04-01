#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot2.jpg"
set xlabel "N"
set ylabel "Blad szacowania"
set xtics nomirror rotate by -45
plot "wynik.dat" using 1:3  title "Blad szacowania" w l
replot
