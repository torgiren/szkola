#!/usr/bin/gnuplot
set term jpeg
set out "750.jpg"
set xlabel "czas"
set ylabel "masa"
set logscale x
set logscale y
plot "dane.txt" using 1:2 w l smooth bezier,\
	"dane.txt" using 1:2 w p
#	"750.dat" using 1:2 w l smooth csplines,\
