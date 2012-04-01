#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot3_5.jpg"
set xlabel "t"
set ylabel "wartosc"
set title "dt=1"
#plot "w.dat" using 1:2  title "W6" w l, "w.dat" using 1:3 title "W2" w l
plot "zad3_5.dat" using 1:2  title "dokladny" w l, "zad3_5.dat" using 1:3 title "jawny" w l, "zad3_5.dat" using 1:4 title "blad" w l
replot
