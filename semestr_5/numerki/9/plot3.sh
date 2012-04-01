#!/usr/bin/gnuplot
set term jpeg
#set size square
set out "f3.jpg"
set xlabel "x"
set ylabel "f(x)"
set grid
set xrange [0:80]
show grid
plot "f3.dat" using 1:2  title "f(x)" w l, "f4.dat" using 1:2 title "f2(x)" w l
#plot "f4.dat" using 1:2 title "f2(x)" w l
replot
