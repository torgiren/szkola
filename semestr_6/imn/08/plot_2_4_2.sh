#!/usr/bin/gnuplot
set term jpeg
set out "plot_2_4_2.jpg"
set xlabel "i"
set ylabel "j"
set title "k=4"
set ticslevel 0
set pm3d map
set palette defined (-15 "blue", 0 "white", 15 "red")
splot "zad2_4_2.dat" with pm3d
