#!/usr/bin/env gnuplot
set terminal jpeg
set out "370.jpg"
f(x) = a*x + b
fit f(x) "370.dat" via a,b
plot "370.dat" w lp, f(x) title "regresja"

