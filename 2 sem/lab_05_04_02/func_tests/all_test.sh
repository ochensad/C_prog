#!/bin/sh

echo "....TESTING...."

j=01
while [ -f "pos_s${j}_in.txt" ] 
do
	./pos_sort.sh $j
	echo
	j=$(printf "%02d" $(( ${j#0} + 1 )))
done

k=01
while [ -f "pos_a${k}_in.txt" ] 
do
	./pos_add.sh $k
	echo
	k=$(printf "%02d" $(( ${k#0} + 1 )))
done

m=01
while [ -f "pos_f${m}_in.txt" ] 
do
	./pos_filter.sh $m
	echo
	m=$(printf "%02d" $(( ${m#0} + 1 )))
done

i=01
while [ -f "neg_s${i}_in.txt" ] 
do
	./neg_sort.sh $i
	echo
	i=$(printf "%02d" $(( ${i#0} + 1 )))
done

d=01
while [ -f "neg_a${d}_in.txt" ] 
do
	./neg_add.sh $d
	echo
	d=$(printf "%02d" $(( ${d#0} + 1 )))
done
c=01

while [ -f "neg_f${c}_in.txt" ] 
do
	./neg_filter.sh $c
	echo
	c=$(printf "%02d" $(( ${c#0} + 1 )))
done

rm out.txt
