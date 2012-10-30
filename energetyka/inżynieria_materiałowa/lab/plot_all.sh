#!/usr/bin/gnuplot
set term jpeg
set out "all.jpg"
set xlabel "czas"
set ylabel "masa"
set logscale x
set logscale y
plot "dane.txt" using 1:2 w l smooth bezier title "750",\
	"dane.txt" using 1:2 w p title "750",\
	"dane.txt" using 1:3 w l smooth bezier title "800",\
	"dane.txt" using 1:3 w p title "800",\
	"dane.txt" using 1:4 w l smooth bezier title "850",\
	"dane.txt" using 1:4 w p title "850"
#	"750.dat" using 1:2 w l smooth csplines,\
