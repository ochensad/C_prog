
gcc -Wall -Werror -Wpedantic -Wextra -Wvla -g3 -c main.c
gcc -Wall -Werror -Wpedantic -Wextra -Wvla -g3 -c my_file.c
gcc -Wall -Werror -Wpedantic -Wextra -Wvla -g3 -c student.c
gcc main.o my_file.o student.o -o app.exe
