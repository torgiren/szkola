#!/usr/bin/gnuplot
# set terminal pngcairo  transparent enhanced font "arial,10" fontscale 1.0 size 500, 350 
# set output 'candlesticks.5.png'
set term jpeg
set out "plot.jpg"
set boxwidth 0.2 absolute
set bars 4.0
 set style fill empty
plot 'zbieznosc.dat' using 1:(-10):(-5):(0):(15):(10) with candlesticks
