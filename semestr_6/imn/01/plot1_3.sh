#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot1_3.jpg"
set xlabel "t"
set ylabel "wartosc"
set title "trapezow"
#plot "w.dat" using 1:2  title "W6" w l, "w.dat" using 1:3 title "W2" w l
plot "zad1_3.dat" using 1:2  title "Blad" w l
replot
