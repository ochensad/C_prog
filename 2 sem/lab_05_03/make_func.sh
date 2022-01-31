#!/bin/sh
rm ./*.exe ./*.o
gcc -Wall -Werror -Wpedantic -Wextra -Wvla  -O0 --coverage main.c my_func.c -o app.exe

cd func_tests

./all_test.sh

cd ..

gcov main.c my_func.c
rm -f out.txt
