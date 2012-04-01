#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot_1_1_2_1.jpg"
set xlabel "t"
set ylabel "wartosc"
set title "RK4"
#plot "w.dat" using 1:2  title "W6" w l, "w.dat" using 1:3 title "W2" w l
plot "wyniki_1_1_2.dat" using 1:4  title "Krok czasowy" w l
replot
