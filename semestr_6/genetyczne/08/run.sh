rm *.dat
rm *.raw
rm plot_0.*.sh
rm *.png
export GDFONTPATH=./
mut="0.01 0.05 0.1 0.2 0.4"
cros="0.9 0.4 0.5 0.6 0.7 0.8 0.3"
pop="100 30 50 70 90 10 200"
selections="roulette tournament rank"
crossmetod="onepoint twopoint evenodd uniform"
#gen="10 30 50 70 90 100 200"
for m in $mut
do
	for c in $cros
	do
#		for g in $gen
#		do
			for p in $pop
			do
				for s in $selections
				do
					for cm in $crossmetod
					do


						param="-m $m -c $c -p $p -S $s -C $cm"
						sufix=$m-$c-`printf %03d $p`-$s-$cm
#						echo $param
						for x in `seq 1 100`
						do
							./main $param
						done
						for i in `seq 0 99`
						do
							nr=`printf %04d $i`
							for j in `seq 1 5`
							do
								./calc_median_etc.sh tmp_$nr.raw $j|tr '\n' ' '|sed 's/$/\n/' >> tmp_$nr.$j.dat
							done
						done
						cp wynik.raw wynik_$sufix.dat
						rm *.raw
						for i in `seq 0 99`
						do
							nr=`printf %04d $i`
							for j in `seq 1 5`
							do
#						data=`cat tmp_$nr.$j.dat|tr "," "."|./mean.sh`
								plik=tmp_$nr.$j.dat
								data=0;
								data=`cat $plik`

#						if [ $j == 1 ]
#						then
#							echo $plik
#							echo $data
#						fi
						#		cat tmp_$nr.$j.dat
								echo $i $data |tr "," "." >> data_$sufix.$j.dat
							done
						done
						echo "gen dla: " $sufix
						opis="pCross=$c pMut=$m popsize=$p selector=$s krzyzowanie=$cm"
						./gen_plot.sh $sufix "$opis"
						./plot_$sufix.sh
						rm tmp*.dat
					done
				done

			done
#		done
	done
done
