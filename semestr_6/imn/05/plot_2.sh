#!/usr/bin/gnuplot
set term jpeg
set title "metoda wstecz"
set size square
set out "plot_2.jpg
set xlabel "t"
set ylabel "wartosc"
plot "zad2.dat" using 1:2  title "f" w l, "zad2.dat" using 1:3 title "blad" w l, "zad2.dat" using 1:4 title "orig"
