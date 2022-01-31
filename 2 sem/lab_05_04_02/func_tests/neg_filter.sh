#!/bin/sh

../app.exe cr neg_f${1}_in.bin < neg_f${1}_in.txt

../app.exe fb neg_f${1}_in.bin > out.txt
echo "NEG ${1} FILT"
S1=$(md5sum out.txt | cut -d \  -f 1)
S2=$(md5sum neg_f${1}_out.txt | cut -d \  -f 1)

if [ "$S1" = "$S2" ]; then 
	echo "[PASSED]" 
else
    echo "[FAILED]"
fi
rm neg_f${1}_in.bin out.txt