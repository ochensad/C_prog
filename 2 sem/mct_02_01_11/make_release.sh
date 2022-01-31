gcc -Wall -Werror -Wpedantic -Wextra -Wvla  -c main.c
gcc -Wall -Werror -Wpedantic -Wextra -Wvla  -c my_file.c
gcc main.o my_file.o -o app.exe