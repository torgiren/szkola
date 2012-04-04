#!/usr/bin/gnuplot
set term jpeg
set size square
set title "wprzod d=0.1, f1 z relaksacyjnej"
set out "plot_3_3.jpg
set xlabel "t"
set ylabel "wartosc"
plot "zad3_3.dat" using 1:2  title "f" w l, "zad3_3.dat" using 1:3 title "blad" w l, "zad3_3.dat" using 1:4 title "orig" w l
