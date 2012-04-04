#!/usr/bin/gnuplot
set term jpeg
set title "metoda relaksacji"
set size square
set out "plot_1.jpg
set xlabel "t"
set ylabel "wartosc"
plot "zad1.dat" using 1:2  title "f" w l, "zad1.dat" using 1:3 title "blad" w l, "zad1.dat" using 1:4 title "orig" w l
