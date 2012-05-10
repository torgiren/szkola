#!/usr/bin/gnuplot
set term jpeg
set out "plot_2.jpg"
set xlabel "i"
set ylabel "j"
set zlabel "potencjal"
set contour both
show contour
unset surface
set view map
set cntrparam levels 50
unset key
splot "zad2.dat" using 1:2:3 w l
