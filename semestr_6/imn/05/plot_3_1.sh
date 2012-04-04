#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot_3_1.jpg
set xlabel "t"
set ylabel "wartosc"
plot "zad3_1.dat" using 1:2  title "f" w l, "zad3_1.dat" using 1:3 title "blad" w l, "zad3_1.dat" using 1:4 title "orig" w l
