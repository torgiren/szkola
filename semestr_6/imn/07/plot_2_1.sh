#!/usr/bin/gnuplot
set term jpeg
set out "plot_2_1.jpg"
set size square
set yrange [-0.2:2]
set pointsize 2
set xlabel "i"
set ylabel "j"
set zlabel "potencjal"
plot "zad2_1.dat" using 1:2 w l, "zad2_1.dat" using 1:3 w p
