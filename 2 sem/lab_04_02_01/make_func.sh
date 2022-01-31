#!/bin/sh
rm ./*.exe ./*.o
gcc -Wall -Werror -Wpedantic -Wextra -Wvla  -O0 --coverage main.c word.c -o app.exe

echo ".....TESTING....."
cd func_tests

./all_test.sh

cd ..
echo ".....COVERAGE....."
gcov main.c word.c
rm -f out.txt 