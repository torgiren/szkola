#!/usr/bin/gnuplot
set term jpeg
set size square
set out "f.jpg"
set xlabel "x"
set ylabel "g(x,y)"
set grid
set contour
set cntrparam levels 200
set view map
set palette defined (0 'white', 400 'black')
unset key
#unset surface
show grid
splot "plot.dat" using 1:2:3  title "f(x,y)" w pm3d
replot
