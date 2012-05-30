#!/usr/bin/gnuplot
set term png
set out "plot_1_2.png"
set xlabel "i"
set ylabel "j"
set grid
show grid
#set zlabel "potencjal"
#set contour both
#set contour
#show contour
#unset surface
#set view map
#set cntrparam levels 1000
#unset key
#set palette defined (0.85 "blue", 0.9 "white", 1 "red")
plot "strumienie.dat" using 1:2,\
	'' using 1:3
