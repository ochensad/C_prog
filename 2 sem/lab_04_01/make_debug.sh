gcc -Wall -Werror -Wpedantic -Wextra -Wvla -g3 -c main.c
gcc -Wall -Werror -Wpedantic -Wextra -Wvla -g3 -c str.c
gcc main.o str.o -o app.exe