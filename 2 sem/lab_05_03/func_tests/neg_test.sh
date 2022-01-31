#!/bin/sh

cp neg_${1}_in.bin in.bin
../app.exe s in.bin
../app.exe p in.bin > out.bin
echo "NEG ${1}"
S1=$(md5sum out.bin | cut -d \  -f 1)
S2=$(md5sum neg_${1}_out.bin | cut -d \  -f 1)

if [ "$S1" = "$S2" ]; then 
	echo "[PASSED]" 
else
    echo "[FAILED]"
fi
rm in.bin out.bin