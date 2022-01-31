
gcc -Wall -Werror -Wpedantic -Wextra -Wvla -g3 -c main.c
gcc -Wall -Werror -Wpedantic -Wextra -Wvla -g3 -c my_file.c
gcc main.o my_file.o -o app.exe
