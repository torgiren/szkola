rm *.dat
rm *.raw
mut="0.01 0.05 0.1 0.2 0.4"
cros="0.9 0.4 0.5 0.6 0.7 0.8 0.3"
pop="100 30 50 70 90 10 200"
#gen="10 30 50 70 90 100 200"
for m in $mut
do
	for c in $cros
	do
#		for g in $gen
#		do
			for p in $pop
			do



				param="-m $m -c $c -p $p"
				sufix=$m-$c-$p
				echo $param
				for x in `seq 1 10`
				do
					./main $param
				done
					for i in `seq 1 99`
					do
						for j in `seq 1 5`
						do
							./calc_median_etc.sh tmp_`printf %04d $i`.raw $j|tr '\n' ' '|sed 's/$/\n/' >> tmp_`printf %04d $i`.$j.dat
						done
					done
				cp wynik.raw wynik_$sufix.dat
				rm *.raw
				for i in `seq 1 99`
				do
					for j in `seq 1 5`
					do
						nr=`printf %04d $i`
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
						echo $i $data >> data_$sufix.$j.dat
					done
				done
				rm tmp*.dat



			done
#		done
	done
done
