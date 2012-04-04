#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot_3_2.jpg
set xlabel "t"
set ylabel "wartosc"
plot "zad3_2.dat" using 1:2  title "f" w l, "zad3_2.dat" using 1:3 title "blad" w l, "zad3_2.dat" using 1:4 title "orig"
