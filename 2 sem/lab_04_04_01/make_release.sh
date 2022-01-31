gcc -Wall -Werror -Wpedantic -Wextra -Wvla -c main.c
gcc -Wall -Werror -Wpedantic -Wextra -Wvla -c word.c
gcc main.o word.o -o app.exe