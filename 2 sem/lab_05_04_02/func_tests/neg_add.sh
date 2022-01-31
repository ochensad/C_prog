#!/bin/sh

../app.exe cr neg_a${1}_in.bin < neg_a${1}_in.txt

../app.exe ab neg_a${1}_in.bin < add_neg_test.txt
../app.exe rb neg_a${1}_in.bin > out.txt
echo "NEG ${1} ADD"
S1=$(md5sum out.txt | cut -d \  -f 1)
S2=$(md5sum neg_a${1}_out.txt | cut -d \  -f 1)

if [ "$S1" = "$S2" ]; then 
	echo "[PASSED]" 
else
    echo "[FAILED]"
fi
rm neg_a${1}_in.bin out.txt