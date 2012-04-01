#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot1_2.jpg"
set xlabel "t"
set ylabel "wartosc"
set title "niejawna"
#plot "w.dat" using 1:2  title "W6" w l, "w.dat" using 1:3 title "W2" w l
plot "zad1_2.dat" using 1:2  title "Blad" w l
replot
