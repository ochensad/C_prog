#!/bin/sh

j=01
while [ -f "pos_${j}_in.bin" ] 
do
	./pos_test.sh $j
	echo
	j=$(printf "%02d" $(( ${j#0} + 1 )))
done

i=01
while [ -f "neg_${i}_in.bin" ] 
do
	./neg_test.sh $i
	echo
	i=$(printf "%02d" $(( ${i#0} + 1 )))
done

rm out.txt
