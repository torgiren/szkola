for x in `seq 0 9`
do
	./main
	./plot.sh
	cp plot.jpg plot_$1_$x.jpg
done
