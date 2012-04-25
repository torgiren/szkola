#!/usr/bin/gnuplot
set term jpeg
set out "plot_1_2.jpg"
set xlabel "w"
set ylabel "iter"
set ticslevel 0
set pm3d map
set palette defined (-15 "blue", 0 "white", 15 "red")
splot "zad1_2.dat" with pm3d
