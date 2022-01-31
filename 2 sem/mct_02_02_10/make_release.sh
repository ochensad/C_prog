gcc -Wall -Werror -Wpedantic -Wextra -Wvla  -c main.c
gcc -Wall -Werror -Wpedantic -Wextra -Wvla  -c my_file.c
gcc -Wall -Werror -Wpedantic -Wextra -Wvla  -c student.c
gcc main.o my_file.o student.o -o app.exe