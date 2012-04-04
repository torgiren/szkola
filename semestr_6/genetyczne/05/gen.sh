for x in `seq -w 1 20`
do
	./main 800 1200 55 70
	./plot.sh
	cp plot.jpg plot_$x.jpg
done
