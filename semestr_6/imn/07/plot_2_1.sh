#!/usr/bin/gnuplot
set term jpeg
set out "plot_2_1.jpg"
set xlabel "i"
set ylabel "j"
set zlabel "potencjal"
splot "zad2_1.dat" using 1:2:3 w l
