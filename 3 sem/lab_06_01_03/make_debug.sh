rm *.o *.exe
gcc -Wall -Werror -Wpedantic -Wextra -g3 -c main.c
gcc -Wall -Werror -Wpedantic -Wextra -g3 -c product.c
gcc -Wall -Werror -Wpedantic -Wextra -g3 -c array_func.c
gcc main.o product.o array_func.o -o app.exe