#!/bin/sh

../app.exe cr neg_s${1}_in.bin < neg_s${1}_in.txt

../app.exe sb negs_${1}_in.bin out.bin
../app.exe rb out.bin > out.txt 
echo "NEG ${1} SORT"
S1=$(md5sum out.txt | cut -d \  -f 1)
S2=$(md5sum neg_s${1}_out.txt | cut -d \  -f 1)

if [ "$S1" = "$S2" ]; then 
	echo "[PASSED]" 
else
    echo "[FAILED]"
fi
rm neg_s${1}_in.bin out.bin out.txt