#!/usr/bin/gnuplot
set term jpeg
set size square
set out "plot_1_3_3.jpg"
set nolog xy
set xlabel "t"
set ylabel "wartosc"
set title "metoda trapezow"
#plot "w.dat" using 1:2  title "W6" w l, "w.dat" using 1:3 title "W2" w l
plot "wyniki_1_3.dat" using 1:2  title "y1" w l,\
	"wyniki_1_3.dat" using 1:3  title "y2" w l
replot
