#!/bin/sh

../app.exe cr pos_f${1}_in.bin < pos_f${1}_in.txt

../app.exe fb pos_f${1}_in.bin abcd > out.txt
echo "POS ${1} FILT"
S1=$(md5sum out.txt | cut -d \  -f 1)
S2=$(md5sum pos_f${1}_out.txt | cut -d \  -f 1)

if [ "$S1" = "$S2" ]; then 
	echo "[PASSED]" 
else
    echo "[FAILED]"
fi
rm pos_f${1}_in.bin out.txt