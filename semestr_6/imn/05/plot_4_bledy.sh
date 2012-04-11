#!/usr/bin/gnuplot
set term jpeg
set size square
set title "metoda numerowa bledy"
set out "plot_4_bledy.jpg
set xlabel "t"
set ylabel "wartosc"
plot "zad4_1.dat" using 1:3 title "wstecz" w l,\
"zad4_2.dat" using 1:3 title "wprzod d=0.1" w l,\
"zad4_3.dat" using 1:3 title "wprzod dr=0.01" w l,\
"zad3_4.dat" using 1:3 title "wprzod dr=0.1, z relaksacyjnej" w l
