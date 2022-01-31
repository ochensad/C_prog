rm *.o *.exe
gcc -Wall -Werror -Wpedantic -Wextra -g3 -c main.c
gcc -Wall -Werror -Wpedantic -Wextra -g3 -c my_func.c
gcc main.o my_func.o -o app.exe