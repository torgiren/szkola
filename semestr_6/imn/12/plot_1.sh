#!/usr/bin/gnuplot
set term png
set out "plot_1.png"
set xlabel "i"
set ylabel "j"
set zlabel "potencjal"
set contour both
set contour
show contour
#unset surface
set view map
set cntrparam levels 1000
unset key
#set palette defined (0.85 "blue", 0.9 "white", 1 "red")
splot "data.dat" using 1:2:3 w pm3d
replot
