#!/bin/sh

j=01
while [ -f "pos_a1_${j}_in.txt" ] 
do
	./pos_a_test.sh $j
	echo
	j=$(printf "%02d" $(( ${j#0} + 1 )))
done
rm out.txt
touch out.txt

j=01
while [ -f "pos_m1_${j}_in.txt" ] 
do
	./pos_m_test.sh $j
	echo
	j=$(printf "%02d" $(( ${j#0} + 1 )))
done
rm out.txt
touch out.txt

j=01
while [ -f "pos_o_${j}_in.txt" ] 
do
	./pos_o_test.sh $j
	echo
	j=$(printf "%02d" $(( ${j#0} + 1 )))
done
rm out.txt
touch out.txt

i=01
while [ -f "neg_${i}_in.txt" ] 
do
	./neg_test.sh $i
	echo
	i=$(printf "%02d" $(( ${i#0} + 1 )))
done

rm out.txt
