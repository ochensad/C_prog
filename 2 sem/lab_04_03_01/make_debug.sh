gcc -Wall -Werror -Wpedantic -Wextra -Wvla -g3 -c main.c
gcc -Wall -Werror -Wpedantic -Wextra -Wvla -g3 -c word.c
gcc main.o word.o -o app.exe