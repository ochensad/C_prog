#!/bin/sh
gcc -Wall -Werror -Wpedantic -Wextra -Wvla -c main.c
gcc -Wall -Werror -Wpedantic -Wextra -Wvla -c product.c
gcc -Wall -Werror -Wpedantic -Wextra -Wvla -c my_func.c
gcc main.o my_func.o product.o -o app.exe
