#!/usr/bin/gnuplot
set term jpeg
set out "plot_2_8_2.jpg"
set xlabel "i"
set ylabel "j"
set title "k=8"
set ticslevel 0
set pm3d map
set palette defined (-15 "blue", 0 "white", 15 "red")
splot "zad2_8_2.dat" with pm3d
