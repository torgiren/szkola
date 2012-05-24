#!/usr/bin/gnuplot
# set terminal pngcairo  transparent enhanced font "arial,10" fontscale 1.0 size 500, 350 
# set output 'candlesticks.5.png'
set term jpeg
set out "plot_template.jpg"
set boxwidth 0.2 absolute
set bars 4.0
 set style fill empty
plot 'data_0.01-0.7-50.1.dat' using 1:3:2:6:5 with candlesticks lt 3 lw 2 title 'Quartiles',      ''                 using 1:4:4:4:4 with candlesticks lt -1 lw 2

