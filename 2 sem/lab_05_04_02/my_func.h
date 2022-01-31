#ifndef FILE_FUNC
#define FILE_FUNC

#define ERROR_ARGV 53

#define ERROR_FILE_OPEN -1
#define ERROR_READING_FILE -2
#define ERROR_SIZE_OF_FILE -3
#define ERROR_ZERO_LEN -4
#define ERROR_INVALID_STRUCT -5

#define FB_ERROR -6
#define CR_ERROR -7
#define SB_ERROR -8
#define AB_ERROR -9

int size_of_file(FILE *f, size_t *size);
int print_product_filter(FILE *f_in, name_t str);
int size_check(FILE *f, size_t *len);
int create_file(FILE *f);
int copy_file(FILE *f_in, FILE *f_out);
int file_sort(FILE *f);
int find_pos(FILE *f, product_t *new_product, size_t *new_pos, size_t len);
int insert_by_pos(FILE *f, size_t new_pos, product_t *new_product);
int file_add(FILE *f);
int print_file(FILE *f);
#endif