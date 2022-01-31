#ifndef MY_FILE
#define MY_FILE


#define ERROR_NO_FILE -1
#define ERROR_INVALID_NUMBERS -2
#define ERROR_INVALID_KEY -3
#define ERROR_EMPTY_FILE -4
#define ERROR_CANT_READ_FILE -5
#define PROCESS_SUCCESS 0

int create_f(FILE *f, int num, const int begin, const int end);
int print_f(FILE *f);
int sort_f(FILE *f);
int get_number_by_pos(FILE *f, int pos, int *num);
int put_number_by_pos(FILE *f, int pos, int num);
#endif