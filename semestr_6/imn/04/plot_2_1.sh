#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot_2_1.jpg"
set xlabel "t"
set ylabel "wartosc"
#plot "w.dat" using 1:2  title "W6" w l, "w.dat" using 1:3 title "W2" w l
plot "zad2_01.txt" using 1:2 title "U1" w l, "zad2_01.txt" using 1:3 title "U2" w l
replot
