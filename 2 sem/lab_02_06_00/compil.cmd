@ECHO OFF
CHCP 65001
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra main_01.c -o app_01.exe
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra main_02.c -o app_02.exe
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra main_03.c -o app_03.exe
