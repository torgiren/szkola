#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot3.jpg"
set xlabel "t"
set ylabel "wartosc"
set title "bledy - niejawny"
#plot "w.dat" using 1:2  title "W6" w l, "w.dat" using 1:3 title "W2" w l
plot "zad3_1.dat" using 1:4  title "dt=0.01" w l,\
"zad3_2.dat" using 1:4 title "dt=0.1" w l,\
"zad3_3.dat" using 1:4 title "dt=0.2" w l,\
"zad3_4.dat" using 1:4 title "dt=0.21" w l,\
"zad3_5.dat" using 1:4 title "dt=1" w l
replot
