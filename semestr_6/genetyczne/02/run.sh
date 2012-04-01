#!/bin/bash
length=6
tries=10
function calc
{
	result=`./main $1 $2 $3`
	echo $2 $result>>wyniki.dat
};
if [ -e wyniki.dat ]
then
	rm wyniki.dat;
fi
for x in `seq 1 100;seq 110 10 250;seq 300 50 500;seq 600 100 1000`
do
	echo "Obliczam dla x="$x;
	calc $length $x $tries;
done
