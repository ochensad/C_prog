#!/bin/sh

../func_tests.exe o pos_o_${1}_in.txt out.txt 
echo "POS DET ${1}"
S1=$(md5sum out.txt | cut -d \  -f 1)
S2=$(md5sum pos_o_${1}_out.txt | cut -d \  -f 1)

if [ "$S1" = "$S2" ]; then 
	echo "[PASSED]" 
else
	echo "[FAILED]"
fi
