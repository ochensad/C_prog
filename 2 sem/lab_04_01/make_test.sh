#!/bin/sh

gcc -Wall -Werror -Wpedantic -Wextra -Wvla  -O0 --coverage main.c str.c -o app.exe

./app.exe

echo "....COVERAGE...."
gcov -r -f main.c str.c