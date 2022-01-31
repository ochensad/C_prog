rm *.o *.exe
gcc -Wall -Werror -Wpedantic -Wextra -g3 -c main.c
gcc -Wall -Werror -Wpedantic -Wextra -g3 -c product.c
gcc -Wall -Werror -Wpedantic -Wextra -g3 -c my_func.c
gcc main.o product.o my_func.o -o app.exe