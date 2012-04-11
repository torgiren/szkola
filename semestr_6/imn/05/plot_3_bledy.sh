#!/usr/bin/gnuplot
set term jpeg
set title "zad 3 - bledy"
set size square
set out "plot_3_bledy.jpg
set xlabel "t"
set ylabel "wartosc"
plot "zad1.dat" using 1:3 title "relaksacja" w l,\
"zad2.dat" using 1:3 title "wstecz" w l,\
"zad3_1.dat" using 1:3 title "wprzod dr=0.01" w l
#"zad3_2.dat" using 1:3 title "wprzod dr=0.1" w l
