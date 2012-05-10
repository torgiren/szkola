#!/usr/bin/gnuplot
set term jpeg
set out "plot_3.jpg"
set xlabel "i"
set ylabel "j"
set zlabel "potencjal"
#set contour both
unset contour
#show contour
#unset surface
set view map
set cntrparam levels 1000
unset key
set palette defined (0.85 "blue", 0.9 "white", 1 "red")
splot "zad3.dat" using 1:2:3 w pm3d
replot
