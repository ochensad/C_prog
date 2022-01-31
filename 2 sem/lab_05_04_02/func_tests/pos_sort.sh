#!/bin/sh

../app.exe cr pos_s${1}_in.bin < pos_s${1}_in.txt

../app.exe sb pos_s${1}_in.bin out.bin
../app.exe rb out.bin > out.txt
echo "POS ${1} SORT"
S1=$(md5sum out.txt | cut -d \  -f 1)
S2=$(md5sum pos_s${1}_out.txt | cut -d \  -f 1)

if [ "$S1" = "$S2" ]; then 
	echo "[PASSED]" 
else
    echo "[FAILED]"
fi
rm pos_s${1}_in.bin out.txt out.bin