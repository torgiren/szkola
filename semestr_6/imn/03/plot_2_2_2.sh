#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot_2_2_2.jpg"
set xlabel "t"
set nolog xy
set ylabel "wartosc"
set title "krok czasowy - wsteczny euler"
#plot "w.dat" using 1:2  title "W6" w l, "w.dat" using 1:3 title "W2" w l
plot "wyniki_2_2_1.dat" using 1:3  title "tol=0.01" w l,\
	"wyniki_2_2_2.dat" using 1:3  title "tol=0.001" w l,\
	"wyniki_2_2_3.dat" using 1:3  title "tol=0.0001" w l
replot
