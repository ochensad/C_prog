gcc -Wall -Werror -Wpedantic -Wextra -Wvla -c main.c
gcc -Wall -Werror -Wpedantic -Wextra -Wvla -c str.c
gcc main.o str.o -o app.exe