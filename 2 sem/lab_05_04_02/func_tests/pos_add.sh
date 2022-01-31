#!/bin/sh

../app.exe cr pos_a${1}_in.bin < pos_a${1}_in.txt

../app.exe ab pos_a${1}_in.bin < add_test.txt
../app.exe rb pos_a${1}_in.bin > out.txt
echo "POS ${1} ADD"
S1=$(md5sum out.txt | cut -d \  -f 1)
S2=$(md5sum pos_a${1}_out.txt | cut -d \  -f 1)

if [ "$S1" = "$S2" ]; then 
	echo "[PASSED]" 
else
    echo "[FAILED]"
fi
rm pos_a${1}_in.bin out.txt