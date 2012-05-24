#!/bin/sh
cat $1|tr "." ","|sort -g -k$2|\
awk -v col=$2 '{count[i++]=$col} END{print count[0]; print count[int((i)/4)]; print count[int((i)/2)]; print count[int(3*(i)/4)];print count[i-1]}'
