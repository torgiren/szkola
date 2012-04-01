#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot7_2.jpg"
set xlabel "t"
set ylabel "wartosc"
set title "iloraz roznicowy"
#plot "w.dat" using 1:2  title "W6" w l, "w.dat" using 1:3 title "W2" w l
plot "zad7_2.dat" using 1:2  title "analityczna" w l,\
"zad7_2.dat" using 1:3  title "iloraz" w l
replot
